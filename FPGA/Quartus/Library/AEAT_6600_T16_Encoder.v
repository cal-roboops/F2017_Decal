// Module for reading 
// SSI CLK range: Max 1MHz, Min 100KHz
// Sampling rate limited by SSI_CLK and encoder resolution

module AEAT_6600_T16_Encoder #(
  parameter RESOLUTION = 10 // Default 10 bits
)(
  input clk,
  input SSI_CLK,

  // Chip inputs
  input data_in,
  input magHIGH,
  input magLOW,

  // Ready/Valid Interface
  input get_position,
  input data_out_ready,
  output data_out_valid,
  
  // Read register outputs
  output NCS,
  output [RESOLUTION-1:0] data_out
);
  // Local params
  localparam NUM_START_STATES = 2;
  localparam NUM_END_STATES = 1;
  localparam BIT_SELECT = RESOLUTION + NUM_START_STATES - 1;
  localparam NUM_STATES = RESOLUTION + NUM_START_STATES + NUM_END_STATES - 1;
  localparam NUM_STATES_WIDTH = `log2(NUM_STATES);

  // Registers for Encoder
  reg start_read = 1'b0, NCS_reg = 1'b1;
  reg data_out_valid_reg = 1'b0, data_out_valid_prev_reg =1'b0;
  reg [RESOLUTION-1:0] data_out_reg = 0;
  reg [NUM_STATES_WIDTH-1:0] curr_state = 0;

  // Assign wires
  assign NCS = NCS_reg;
  assign data_out = data_out_reg;
  assign data_out_valid = data_out_valid_reg;

  // Sample Start Generator
  always@(posedge clk) begin
    // Restart reading on next SSI clock edge
    start_read <= (get_position || (start_read && !SSI_CLK));
    
    // Pulse valid if in end state, data_out_rdy, and haven't yet
    if (curr_state == NUM_STATES) begin
      data_out_valid_prev_reg <= (data_out_ready) ? 1'b1 : data_out_valid_prev_reg;
      if (!data_out_valid_prev_reg && data_out_ready) data_out_valid_reg <= 1'b1;
      else data_out_valid_reg <= 1'b0;
    end
    else begin
      data_out_valid_reg <= 1'b0;
      data_out_valid_prev_reg <= 1'b0;
    end
  end

  // Step through the states (bits)
  always @(posedge SSI_CLK) begin
    if (start_read) curr_state <= 0;
    else if (curr_state < NUM_STATES) curr_state <=  curr_state + 1;
    else curr_state <= curr_state;
  end

  // Read value from device
  always @(*) begin
    case (curr_state)
      0 : NCS_reg = 1;
      1 : NCS_reg = 0;
      NUM_STATES : NCS_reg = 1;
      default : data_out_reg[BIT_SELECT - curr_state] = data_in;
    endcase
  end
  
 endmodule