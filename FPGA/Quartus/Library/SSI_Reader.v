module SSI_Reader #(
	parameter CLOCK_FREQ = 50_000_000, // Default 50MHz
	parameter SSI_CLK_PERIOD = 0.000_001, // Default 1us (20us timeout)
	parameter SSI_SAMPLE_RATE = 50, // Default 10 samp/s
	parameter SSI_RES = 10 // Default 10 bits
)(
	input clk,
	input DataIn, //DATA I/O
	input magHIGH,
	input magLOW,
	
	output reg SSI_CLK,  //Serial Clock
	output reg NCS, //CHIP Select
	output [SSI_RES-1:0] DataOut
);
	// Helping local params
	localparam num_start_states = 2;
	localparam num_end_states = 1;
	localparam num_statues = SSI_RES + num_start_states + num_end_states;
	
	localparam bit_select = SSI_RES + num_start_states;
	localparam SSI_STATE_SIZE = `log2(num_statues);
	
	localparam integer SSI_CLK_COUNT_CYCLES = SSI_CLK_PERIOD * CLOCK_FREQ;
	localparam SSI_CLK_COUNTER_SIZE = `log2(SSI_CLK_COUNT_CYCLES);
	
	localparam integer SSI_SAMPLE_CYCLES = CLOCK_FREQ / SSI_SAMPLE_RATE;
	localparam SSI_SAMPLE_COUNTER_SIZE = `log2(SSI_SAMPLE_CYCLES);
	
	// Registers for SSI
	reg start_read = 0;
	reg [SSI_RES-1:0] read_data = 0;
	reg [SSI_STATE_SIZE-1:0] curr_state = 0;
	reg [SSI_CLK_COUNTER_SIZE-1:0] SSI_CLK_COUNTER = 0;
	reg [SSI_SAMPLE_COUNTER_SIZE-1:0] SSI_SAMPLE_COUNTER = 0;
	
	// Assigns
	assign DataOut = read_data;

	// SSI CLK GEN
	always@(posedge clk) begin
		SSI_CLK_COUNTER <= (SSI_CLK_COUNT_CYCLES < SSI_CLK_COUNTER) ? 0 : SSI_CLK_COUNTER + 1;
		SSI_CLK <= (SSI_CLK_COUNTER == SSI_CLK_COUNT_CYCLES) ? !SSI_CLK : SSI_CLK;
	end
	
	// Sample Start GEN
	always@(posedge clk) begin
		SSI_SAMPLE_COUNTER <= (SSI_SAMPLE_CYCLES < SSI_SAMPLE_COUNTER) ? 0 : SSI_SAMPLE_COUNTER + 1;
		start_read <= (SSI_SAMPLE_CYCLES == SSI_SAMPLE_COUNTER) || (start_read && !SSI_CLK);
	end

	// Step through the states (bits)
	always @(posedge SSI_CLK) begin
		if (start_read) curr_state <= 0;
		else if (curr_state < num_statues) curr_state <=  curr_state + 1;
		else curr_state <= curr_state;
	end

	// Read value from device
	always@(*) begin
		case(curr_state) 
			0 : NCS = 1;
			1 : NCS = 0;
			(num_statues-1) : NCS = 1;
			default : read_data[bit_select - curr_state] = DataIn;
		endcase
	end
endmodule