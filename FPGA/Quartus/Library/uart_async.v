`include "util.vh"

module uart_async #(
  parameter CLOCK_FREQ = 33_000_000,
  parameter BAUD_RATE = 115_200,
  parameter DATA_WIDTH = 8,
  parameter FIFO_DEPTH = 32
) (
  input uart_clk,
  input interface_clk,
  input reset,

  input data_in_val,
  input data_out_rdy,

  output data_in_rdy,
  output data_out_val,

  input [DATA_WIDTH-1:0] data_in,
  output [DATA_WIDTH-1:0] data_out,

  input serial_in,
  output serial_out
);

  // Define carrying wires
  wire uart_in_rdy, uart_in_fifo_empty, uart_out_fifo_full, uart_out_val;
  wire uart_in_fifo_full, uart_out_fifo_empty;
  wire [DATA_WIDTH-1:0] uart_data_out;
  wire [DATA_WIDTH-1:0] uart_data_in;

  // Assigns
  assign data_in_rdy = !uart_in_fifo_full;
  assign data_out_val = !uart_out_fifo_empty;

  fifo_async #(
    .DATA_WIDTH(DATA_WIDTH),
    .FIFO_DEPTH(FIFO_DEPTH)
  ) uart_in_fifo (
    .wr_clk(interface_clk),
    .rd_clk(uart_clk),

    .wr_en(data_in_val),
    .rd_en(uart_in_rdy),
    .data_in(data_in),

    .full(uart_in_fifo_full),
    .empty(uart_in_fifo_empty),
    .data_out(uart_data_out)
  );

  fifo_async #(
    .DATA_WIDTH(DATA_WIDTH),
    .FIFO_DEPTH(FIFO_DEPTH)
  ) uart_out_fifo (
    .wr_clk(uart_clk),
    .rd_clk(interface_clk),
    .reset(reset),

    .wr_en(uart_out_val),
    .rd_en(data_out_rdy),
    .data_in(uart_data_out),

    .full(uart_out_fifo_full),
    .empty(uart_out_fifo_empty),
    .data_out(data_out)
  );

  uart #(
    .CLOCK_FREQ(CLOCK_FREQ),
    .BAUD_RATE(BAUD_RATE),
    .DATA_WIDTH(DATA_WIDTH)
  ) uart_device (
    .clk(uart_clk),
    .reset(reset),

    .data_in(uart_data_in),
    .data_in_valid(!uart_in_fifo_empty),
    .data_in_ready(uart_in_rdy),

    .data_out(uart_data_out),
    .data_out_valid(uart_out_val),
    .data_out_ready(!uart_out_fifo_full),

    .serial_in(serial_in),
    .serial_out(serial_out)
  );

endmodule