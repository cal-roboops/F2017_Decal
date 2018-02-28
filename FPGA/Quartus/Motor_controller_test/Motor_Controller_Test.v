

//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module Motor_Controller_Test(

	//////////// CLOCK //////////
	input 		          		CLOCK_50,

	//////////// LED //////////
	output		     [7:0]		LED,

	//////////// KEY //////////
	input 		     [1:0]		KEY,

	//////////// SW //////////
	input 		     [3:0]		SW,

	//////////// SDRAM //////////
	output		    [12:0]		DRAM_ADDR,
	output		     [1:0]		DRAM_BA,
	output		          		DRAM_CAS_N,
	output		          		DRAM_CKE,
	output		          		DRAM_CLK,
	output		          		DRAM_CS_N,
	inout 		    [15:0]		DRAM_DQ,
	output		     [1:0]		DRAM_DQM,
	output		          		DRAM_RAS_N,
	output		          		DRAM_WE_N,

	//////////// EPCS //////////
	output		          		EPCS_ASDO,
	input 		          		EPCS_DATA0,
	output		          		EPCS_DCLK,
	output		          		EPCS_NCSO,

	//////////// EEPROM //////////
	output		          		I2C_SCLK,
	inout 		          		I2C_SDAT,

	//////////// ADC //////////
	output		          		ADC_CS_N,
	output		          		ADC_SADDR,
	output		          		ADC_SCLK,
	input 		          		ADC_SDAT,

	//////////// 2x13 GPIO Header //////////
	inout 		    [12:0]		GPIO_2,
	input 		     [2:0]		GPIO_2_IN,

	//////////// GPIO_0, GPIO_0 connect to GPIO Default //////////
	inout 		    [33:0]		GPIOH0,
	input 		     [1:0]		GPIOH0_IN,

	//////////// GPIO_1, GPIO_1 connect to GPIO Default //////////
	inout 		    [33:0]		GPIOH1,
	input 		     [1:0]		GPIOH1_IN
);



//=======================================================
//  REG/WIRE declarations
//=======================================================

	wire rst, FPGA_SERIAL_RX, FPGA_SERIAL_TX;


//=======================================================
//  Structural coding
//=======================================================
	

	assign GPIOH0[0] = FPGA_SERIAL_TX; //writes to pin0
	assign FPGA_SERIAL_RX = GPIOH0[1]; //reads pin1

	reg [7:0] data_in_reg;
    wire [7:0] data_in;
    wire [7:0] data_out;
    wire data_in_valid, data_in_ready, data_out_valid, data_out_ready;

    assign data_in_valid = data_out_valid;


    // This UART is on the FPGA and communicates with your desktop
    // using the FPGA_SERIAL_TX, and FPGA_SERIAL_RX signals. The ready/valid
    // interface for this UART is used on the FPGA design.
    uart # (
        .CLOCK_FREQ(50_000_000),
        .BAUD_RATE(9600)
    ) on_chip_uart (
        .clk(CLOCK_50),
        .reset(rst),
        .data_in(data_in),
        .data_in_valid(data_in_valid),
        .data_in_ready(data_in_ready),
        .data_out(data_out),
        .data_out_valid(data_out_valid),
        .data_out_ready(data_out_ready),
        .serial_in(FPGA_SERIAL_RX),
        .serial_out(FPGA_SERIAL_TX)
    );
	
    wire pwm;
    wire [7:0] pwm_set;
    wire [7:0] pwm_num, average, sum;
	
    wire in_pwm = GPIOH0[3];
	 
    assign data_in = average;
	 
	 assign LED[7:1] = pwm_num;
	 assign LED[0] = SW[0];
	 assign pwm_set[7:0] = pwm_num;
	 assign GPIOH0[5] = pwm;

	//pwms:
	
	
	PWM_Gen #(
		.PWM_PERIOD(5),
		.DUTY_MAX(255),
		.DUTY_MAX_BITS(8)
	) gen1(
		.clk(CLOCK_50),
		.DUTY_NUM(average),
		.PWM(pwm)
	);

	PWM_Counter #(
		.PWM_PERIOD(10_000),
		.DUTY_MAX(255),
		.DUTY_MAX_BITS(8)
	) cnt1(
		.clk(CLOCK_50),
		.pwm(in_pwm),
		.pwm_value(pwm_num)
	);

	averager #(
		.NUM_BITS(8),
		.SAMPLES(64),
		.SAMPLE_BITS(6),
		.SAMPLE_PERIOD(2_500_000)
	) ave(
		.clk(CLOCK_50),
		.value(pwm_num),
		.average(average),
		.sum_out(sum),
		.shift(SW)
	);



endmodule

module averager #(
	parameter NUM_BITS = 8,
	parameter SAMPLES = 8,
	parameter SAMPLE_BITS = `log2(SAMPLES);
	parameter SAMPLE_PERIOD = 25_00_000,
	parameter CLK_COUNTER_SIZE = 30
)(
	input clk,
	input [3:0] shift,
	input [NUM_BITS-1:0] value,
	output [NUM_BITS-1:0] average,
	output [NUM_BITS - 1 + SAMPLE_BITS : 0] sum_out
);
	reg [NUM_BITS-1 + SAMPLE_BITS : 0] sum = 0;
	reg [NUM_BITS-1:0] data [SAMPLES-1:0];
	reg [CLK_COUNTER_SIZE-1:0] clk_counter = 0;
	wire sample;

	assign average = sum >> SAMPLE_BITS;
	assign sum_out = sum;

	integer k;
	initial
		begin
		for (k = 0; k < SAMPLES - 1; k = k + 1) begin
		    data[k] = 0;
		end
	end

	assign sample = (clk_counter == SAMPLE_PERIOD);
	
	always @(posedge clk) begin
		clk_counter <= (clk_counter < SAMPLE_PERIOD) ? clk_counter + 1: 0;
	end

	always @(posedge sample) begin
		data[0] <= value;
		sum <= sum + value - data[SAMPLES-1];
	end

	genvar i;
	generate
	    for (i = 1; i < SAMPLES; i = i + 1) begin: test
	        always @(posedge sample) begin
	            data[i] <= data[i-1];
	        end
	    end
	endgenerate
endmodule
//
//module differentiator #(
//	parameter TIMESTEP = 10_000, //cycles
//	parameter NUM_BITS = 8,
//	parameter DERIVATIVE_MAX_SIZE = 20,
//	parameter CLK_COUNTER_SIZE = 30
//)
//(
//	input clk,
//	input [NUM_BITS-1:0] value,
//	output signed [DERIVATIVE_MAX_SIZE-1:0] derivative
//);
//	reg signed [DERIVATIVE_MAX_SIZE-1:0] d_dt = 0; 
//	reg [VALUE_MAX_SIZE-1:0] prev_value = 0;
//	reg [CLK_COUNTER_SIZE-1:0] clk_counter = 0;
//
//	assign sample = (clk_counter == TIMESTEP);
//
//	always @(posedge clk) begin
//		clk_counter <= (clk_counter < TIMESTEP) ? clk_counter + 1: 0;
//	end
//
//	always @(posedge sample) begin
//		d_dt <= value - prev_value;
//		prev_value <= value;
//	end
//endmodule