`include "util.vh"

module uart_transmitter #(
    parameter CLOCK_FREQ = 33_000_000,
    parameter BAUD_RATE = 115_200,
    parameter DATA_WIDTH = 8
) (
    input clk,
    input reset,

    input [DATA_WIDTH-1:0] data_in,
    input data_in_valid,
    output data_in_ready,

    output serial_out
);
    // See diagram in the lab guide
    localparam SYMBOL_EDGE_TIME = CLOCK_FREQ / BAUD_RATE;
    localparam CLOCK_COUNTER_WIDTH = `log2(SYMBOL_EDGE_TIME);
    localparam DATA_WIDTH_BITS = `log2(DATA_WIDTH);

    wire symbol_edge;
    wire start;
    wire tx_running;

    reg bit_out = 1;
    reg [DATA_WIDTH+1:0] tx_shift = 0;
    reg [DATA_WIDTH_BITS:0] bit_counter = 0;
    reg [CLOCK_COUNTER_WIDTH-1:0] clock_counter = 0;

    //--|Signal Assignments|------------------------------------------------------

    // Goes high at every symbol edge
    assign symbol_edge = clock_counter == (SYMBOL_EDGE_TIME - 1);

    // Goes high when ready to receive more data
    assign data_in_ready = !tx_running;

    // Goes high when it is time to start transmitting a new character
    assign start = data_in_valid && !tx_running;

    // Goes high while we are transmitting a character
    assign tx_running = bit_counter != 4'd0;

    // Carries the current bit to transmit
    assign serial_out = bit_out;

    //--|Counters|----------------------------------------------------------------
    always @ (posedge clk) begin
        clock_counter <= (start || reset || symbol_edge) ? 0 : clock_counter + 1;
    end

    // Counts down from DATA_WIDTH+2 bits for every character
    always @ (posedge clk) begin
        if (reset) begin
            bit_counter <= 0;
        end else if (start) begin
            bit_counter <= DATA_WIDTH + 2;
        end else if (symbol_edge && tx_running) begin
            bit_counter <= bit_counter - 1;
        end
    end

    //--|Shift Register|----------------------------------------------------------
    always @ (posedge clk) begin
        if (start) tx_shift <= {1'd1, data_in[7:0], 1'd0};
    end

    //--|Transmit|----------------------------------------------------------------
    always @ (posedge symbol_edge) begin
        bit_out <= (tx_running) ? tx_shift[10-bit_counter] : 1;
    end


endmodule
