`include "util.vh"

module pos_edge_det ( 
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

// Grey code module
module g2bcode #(
    parameter addr_width = 5
) (
    input [addr_width-1:0] gin,

    output [addr_width-1:0] bout
);
    assign bout = ((((gin ^ (gin >> 8)) ^ (gin >> 4)) ^ (gin >> 2)) ^ (gin >> 1));
endmodule

// Grey code module
module b2gcode #(
    parameter addr_width = 5
) (
    input [addr_width-1:0] bin,
    output [addr_width-1:0] gout
);
    assign gout = bin ^ (bin>>1);
endmodule

module fifo_async #(
    parameter data_width = 8,
    parameter fifo_depth = 32,
    parameter addr_width = `log2(fifo_depth)
) (
    input wr_clk,
    input rd_clk,

    input wr_en,
    input rd_en,
    input [data_width-1:0] din,

    output full,
    output empty,
    output [data_width-1:0] dout
);


    wire pos_rd_en;
    wire pos_wr_en;

    pos_edge_det rd_detect (
        .sig(rd_en),
        .clk(rd_clk),
        .pe(pos_rd_en)
    );

    pos_edge_det wr_detect (
        .sig(wr_en),
        .clk(wr_clk),
        .pe(pos_wr_en)
    );

    // Create regs
    reg [data_width-1:0] data [fifo_depth-1:0];
    reg [addr_width-1:0] rPtr = 0, wPtr = 0;
    reg rPtrL = 0, wPtrL = 0, r2wPtrL = 0, w2rPtrL = 0;
    reg [data_width-1:0] ddo = 0;

    wire [addr_width-1:0] wg2b_out, rg2b_out, wwC_b2g, wrC_b2g;
    reg [addr_width-1:0] wC_b2g = 0, wC_g2b = 0, rC_b2g = 0, rC_g2b = 0;

    // Create modules
    b2gcode #(
        .addr_width(addr_width)
    ) wb2g (
        .bin(wPtr),
        .gout(wwC_b2g)
    );

    g2bcode #(
        .addr_width(addr_width)
    ) wg2b (
        .gin(wC_g2b),
        .bout(wg2b_out)
    );

    b2gcode #(
        .addr_width(addr_width)
    ) rb2g (
        .bin(rPtr),
        .gout(wrC_b2g)
    );

    g2bcode #(
        .addr_width(addr_width)
    ) rg2b (
        .gin(rC_b2g),
        .bout(rg2b_out)
    );


    // Assign outputs
    assign full = ((r2wPtrL != wPtrL) && (rg2b_out == wPtr));
    assign empty = ((rPtrL == w2rPtrL) && (rPtr == wg2b_out));
    assign dout = ddo;

    always @ (posedge wr_clk) begin
        wC_b2g <= wwC_b2g;
        rC_g2b <= rC_b2g;
        r2wPtrL <= rPtrL;

        if (pos_wr_en && !full) begin
            data[wPtr] <= din;
            if (fifo_depth-1 <= wPtr) begin
                wPtr <=  0;
                wPtrL <= !wPtrL;
            end
            else wPtr <=  wPtr + 1;
        end
    end

    always @(posedge rd_clk) begin
        rC_b2g <= wrC_b2g;
        wC_g2b <= wC_b2g;
        w2rPtrL <= wPtrL;

        if (pos_rd_en && !empty) begin
            ddo <= data[rPtr];
            if (fifo_depth-1 <= rPtr) begin
                rPtr <=  0;
                rPtrL <= !rPtrL;
            end
            else rPtr <=  rPtr + 1;
        end
    end
endmodule
