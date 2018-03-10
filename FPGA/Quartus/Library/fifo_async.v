`include "util.vh"

module fifo_async #(
    parameter DATA_WIDTH = 8,
    parameter FIFO_DEPTH = 32
) (
    input wr_clk,
    input rd_clk,
    input reset,

    input wr_en,
    input rd_en,
    input [DATA_WIDTH-1:0] data_in,  

    output reg full,
    output reg empty,
    output reg [DATA_WIDTH-1:0] data_out
);
    localparam ADDRESS_WIDTH = `log2(FIFO_DEPTH);

    /////Internal connections & variables//////
    reg Status;
    reg [DATA_WIDTH-1:0] Mem [FIFO_DEPTH-1:0];

    wire [ADDRESS_WIDTH-1:0] pNextWordToWrite, pNextWordToRead;
    wire EqualAddresses;
    wire NextWriteAddressEn, NextReadAddressEn;
    wire Set_Status, Rst_Status;
    wire PresetFull, PresetEmpty;
    
    //////////////Code///////////////
    // 'data_out' logic:
    always @ (posedge rd_clk) begin
        if (rd_en & !empty) begin
            data_out <= Mem[pNextWordToRead];
        end
    end
            
    // 'data_in' logic:
    always @(posedge wr_clk) begin
        if (wr_en & !full) begin
            Mem[pNextWordToWrite] <= data_in;
        end
    end

    // Fifo addresses support logic: 
    assign NextWriteAddressEn = wr_en & ~full;
    assign NextReadAddressEn  = rd_en  & ~empty;

    // 'GrayCounter' logic:
    GrayCounter GrayCounter_pWr (
        .clk(wr_clk),
        .reset(reset),

        .enable(NextWriteAddressEn),

        .GrayCount_out(pNextWordToWrite)
    );
       
    GrayCounter GrayCounter_pRd (
        .clk(rd_clk),
        .reset(reset),

        .enable(NextReadAddressEn),

        .GrayCount_out(pNextWordToRead)
    );

    // 'EqualAddresses' logic:
    assign EqualAddresses = (pNextWordToWrite == pNextWordToRead);

    // 'Quadrant selectors' logic:
    assign Set_Status = (pNextWordToWrite[ADDRESS_WIDTH-2] ~^ pNextWordToRead[ADDRESS_WIDTH-1]) &
                        (pNextWordToWrite[ADDRESS_WIDTH-1] ^ pNextWordToRead[ADDRESS_WIDTH-2]);
                            
    assign Rst_Status = (pNextWordToWrite[ADDRESS_WIDTH-2] ^ pNextWordToRead[ADDRESS_WIDTH-1]) &
                        (pNextWordToWrite[ADDRESS_WIDTH-1] ~^ pNextWordToRead[ADDRESS_WIDTH-2]);
                         
    // 'Status' latch logic:
    always @ (Set_Status, Rst_Status, reset) begin
        if (Rst_Status | reset) Status = 0;  //Going 'Empty'.
        else if (Set_Status) Status = 1;  //Going 'Full'.
    end
            
    // 'full' logic for the writing port:
    assign PresetFull = Status & EqualAddresses;  // 'Full' Fifo.
    
    always @(posedge wr_clk, posedge PresetFull) begin
        if (PresetFull) full <= 1;
        else full <= 0;
    end
            
    // 'empty' logic for the reading port:
    assign PresetEmpty = ~Status & EqualAddresses;  // 'Empty' Fifo.
    
    always @(posedge rd_clk, posedge PresetEmpty)  begin
        if (PresetEmpty) empty <= 1;
        else empty <= 0;
    end
            
endmodule