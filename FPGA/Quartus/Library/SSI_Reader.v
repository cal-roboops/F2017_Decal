module SSI_Reader#(
	parameter POLLWAITMS = 100,
	parameter POLL_COUNTER_SIZE = `log2(POLLWAITMS*CYCLESINMS*2000),
	parameter RES = 10,
	parameter RES_COUNTER_SIZE = `log2(RES),
	parameter CYCLESINMS = 100
)(
	input clk,
	input DataIn, //DATA I/O
	input magHIGH,
	input magLOW, 
	output SSI_CLK,  //Serial Clock
	output NCS, //CHIP Select
	output [RES-1:0] DataOut, 
	output Poll_test
);

	reg [RES-1:0] DataOut_Reg, Temp_Reading;
	reg NCS_Reg = 0;
	reg SSI_CLK_Reg = 0;
	reg [4:0] next_state = 0;

	assign DataOut = DataOut_Reg;
	assign NCS = NCS_Reg;
	assign SSI_CLK = SSI_CLK_Reg;
	assign Poll_test = Read_State;

	
	always@(posedge clk) begin
		Read_Counter <= (Read_Counter > CYCLESINMS) ? 0 : Read_Counter + 1;
		SSI_CLK_Reg <= (Read_Counter == CYCLESINMS) ? !SSI_CLK_Reg : SSI_CLK_Reg;
	end

	always@(posedge SSI_CLK) begin
		next_state <= (next_state < 12) ? next_state + 1: 0;
	end

	always@(*) begin
		case(next_state) 
			0 : NCS_Reg <= 0; 
			11 : begin
				NCS_Reg <= 1;
				DataOut_Reg = Temp_Reading;
			end
			default : begin
				Temp_Reading[11 - next_state ] = DataIn;
			end
		endcase
	end
endmodule