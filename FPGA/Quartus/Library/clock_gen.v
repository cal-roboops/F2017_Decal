module CLOCK_GEN #(
  parameter INPUT_CLK_FREQ = 50_000_000, // Default 50MHz
  parameter OUTPUT_CLK_FREQ = 1_000_000 // Default 1MHz
)(
  input clk_in,
  output clk_out
);
  // Local params for helping
  localparam integer OUTPUT_CLK_PERIOD = INPUT_CLK_FREQ / (2 * OUTPUT_CLK_FREQ);
  localparam CLK_COUNTER_SIZE = `log2(OUTPUT_CLK_PERIOD);

  // Clock counter register
  reg clk_out_reg = 1'b0;
  reg [CLK_COUNTER_SIZE-1:0] CLK_COUNTER = 0;
  
  // Assign output clock
  assign clk_out = clk_out_reg;

  // CLOCK GEN
  always @(posedge clk_in) begin
    if (OUTPUT_CLK_PERIOD <= CLK_COUNTER) begin
      clk_out_reg <= !clk_out_reg;
      CLK_COUNTER <= 0;
    end
    else CLK_COUNTER <= CLK_COUNTER + 1;
  end

endmodule