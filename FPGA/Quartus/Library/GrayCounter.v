module GrayCounter #(
    parameter COUNTER_WIDTH = 4
) (
    input clk,
    input reset,

    input enable,

    output reg [COUNTER_WIDTH-1:0] GrayCount_out
);
    reg [COUNTER_WIDTH-1:0] BinaryCount;
    
    always @(posedge clk) begin
        if (reset) begin
            BinaryCount <= {COUNTER_WIDTH{1'b 0}} + 1;
            GrayCount_out <= {COUNTER_WIDTH{1'b 0}};
        end
        else if (enable) begin
            BinaryCount <= BinaryCount + 1;
            GrayCount_out <= {BinaryCount[COUNTER_WIDTH-1],
                              BinaryCount[COUNTER_WIDTH-2:0] ^ BinaryCount[COUNTER_WIDTH-1:1]};
        end
    end
    
endmodule