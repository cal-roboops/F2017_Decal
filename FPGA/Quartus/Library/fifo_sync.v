`include "util.vh"

module pos_edge_det1 ( 
    input sig,
    input clk,
    output pe
);
reg sig_dly;
assign pe = sig & ~sig_dly;

always @ (posedge clk) begin
    sig_dly <= sig;
end
  
endmodule 

module fifo_sync #(
    parameter data_width = 8,
    parameter fifo_depth = 32,
    parameter addr_width = `log2(fifo_depth)
) (
    input clk, rst,

    // Write side
    input wr_en,
    input [data_width-1:0] din,
    output full,

    // Read side
    input rd_en,
    output [data_width-1:0] dout,
    output empty
);  
    wire pos_rd_en;
    wire pos_wr_en;

    pos_edge_det1 rd_detect (
        .sig(rd_en),
        .clk(clk),
        .pe(pos_rd_en)
    );

    pos_edge_det1 wr_detect (
        .sig(wr_en),
        .clk(clk),
        .pe(pos_wr_en)
    );


    // Create regs
    reg [data_width-1:0] data [fifo_depth-1:0];
    reg [addr_width-1:0] rPtr = 0, wPtr = 0;
    reg rPtrL = 0, wPtrL = 0;
    reg [data_width-1:0] ddo = 0;
    // Assign outputs
    assign full = ((rPtrL != wPtrL) && (rPtr == wPtr));
    assign empty = ((rPtrL == wPtrL) && (rPtr == wPtr));
    assign dout = ddo;

    always @ (posedge clk) begin
        if (rst) begin
            rPtr <= 0;
            wPtr <= 0;
            rPtrL <= 0;
            wPtrL <= 0;
        end
        else begin
            if (pos_rd_en && !empty) begin
                ddo <= data[rPtr];
                if (fifo_depth-1 <= rPtr) begin
                    rPtr <=  0;
                    rPtrL <= !rPtrL;
                end
                else rPtr <=  rPtr + 1;
            end

            if (pos_wr_en && !full) begin
                data[wPtr] <= din;
                if (fifo_depth-1 <= wPtr) begin
                    wPtr <=  0;
                    wPtrL <= !wPtrL;
                end
                else wPtr <=  wPtr + 1;
            end
        end
    end


endmodule
