
//=======================================================
//  This code is generated by Terasic System Builder
//=======================================================

module ServoControllerTest(

	//////////// CLOCK //////////
	input 		          		CLOCK_50,

	//////////// LED //////////
	output		     [7:0]		LED,

	//////////// KEY //////////
	input 		     [1:0]		KEY,

	//////////// SW //////////
	input 		     [3:0]		SW,

	//////////// EEPROM //////////
	output		          		I2C_SCLK,
	inout 		          		I2C_SDAT,

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

	
	

//=======================================================
//  UART coding
//=======================================================

	assign GPIOH0[0] = FPGA_SERIAL_TX; //writes to pin0
	assign FPGA_SERIAL_RX = GPIOH0[1]; //reads pin1

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

//=======================================================
//  Structural coding
//=======================================================
	

	
	wire com_pwm, out_pwm, read_pwm;
	wire [7:0] desired_value, controlled_value, read_value;
	
	assign LED[5:0] = desired_value;
	assign LED[7] = com_pwm;
	assign LED[6] = read_pwm;
	
	assign com_pwm = GPIOH0[3];
	assign GPIOH0[5] = out_pwm;
	assign read_pwm = GPIOH0[7];
	assign data_in = (SW[0]) ? read_value : desired_value;
	
	PWM_Counter #(
		.PWM_PERIOD(10_000),
		.DUTY_MAX(255),
		.DUTY_MAX_BITS(8)
	) cnt1(
		.clk(CLOCK_50),
		.pwm(com_pwm),
		.pwm_value(desired_value)
	);
		
	Servo_Controller #(
		.PWM_PERIOD(1000),
		.NUM_BITS(8),
		.DUTY_MAX(255),
		.STEP_TIME(2_500_000)
	) SVC (
		.clk(CLOCK_50),
		.desired_value(desired_value),
		.read_pwm(read_pwm),
		.output_pwm(out_pwm),
		.read_value(read_value)
	);
	
	PWM_Counter #(
		.PWM_PERIOD(5),
		.DUTY_MAX(255),
		.DUTY_MAX_BITS(8)
	) cnt2(
		.clk(CLOCK_50),
		.pwm(out_pwm),
		.pwm_value(controlled_value)
	);
		



endmodule
