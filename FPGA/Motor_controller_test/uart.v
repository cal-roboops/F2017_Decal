module uart #(
    parameter CLOCK_FREQ = 33_000_000,
    parameter BAUD_RATE = 115_200)
(
    input clk,
    input reset,

    input [7:0] data_in,
    input data_in_valid,
    output data_in_ready,

    output [7:0] data_out,
    output data_out_valid,
    input data_out_ready,

    input serial_in,
    output serial_out
);

    // We create these intermediate registers in the UART module
    // that are given the synthesis attribute 'iob'. This tells
    // xst to pack these registers in IOBs (Input/Output Blocks),
    // on the FPGA. These blocks contain flip-flops, similar to those
    // on SLICEs, but the flip-flops on IOBs are sized larger,
    // can drive higher currents, and have higher slew rates.
    reg serial_in_reg, serial_out_reg /* synthesis iob="true" */;
    wire serial_out_tx;
    assign serial_out = serial_out_reg;
    always @ (posedge clk) begin
        serial_out_reg <= reset ? 1'b1 : serial_out_tx;
        serial_in_reg <= reset ? 1'b1 : serial_in;
    end

    uart_transmitter #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uatransmit (
        .clk(clk),
        .reset(reset),
        .data_in(data_in),
        .data_in_valid(data_in_valid),
        .data_in_ready(data_in_ready),
        .serial_out(serial_out_tx)
    );

    uart_receiver #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD_RATE(BAUD_RATE)
    ) uareceive (
        .clk(clk),
        .reset(reset),
        .data_out(data_out),
        .data_out_valid(data_out_valid),
        .data_out_ready(data_out_ready),
        .serial_in(serial_in_reg)
    );
endmodule



module PWM_Gen #(
    parameter DUTY_MAX = 255,
    parameter DUTY_MAX_BITS = 8,
    parameter PWM_PERIOD = 1_000_000, //PWM_PERIOD * DUTY_MAX = DUTY_PERIOD
    parameter CLK_COUNTER_SIZE = 30
)
(
    input clk,
    input [DUTY_MAX_BITS-1:0] DUTY_NUM,
    output PWM 
);
    reg PWM_reg = 0;
    reg [DUTY_MAX_BITS-1:0] DUTY_count = 0;
    reg [CLK_COUNTER_SIZE-1:0] clk_counter = 0;

    assign PWM = PWM_reg;

    always @(posedge clk) begin
        clk_counter <= (clk_counter < PWM_PERIOD) ? clk_counter + 1 : 0;
        if(clk_counter == PWM_PERIOD) begin
            PWM_reg <= (DUTY_count < DUTY_NUM) ? 1 : 0;
            DUTY_count <= (DUTY_count < DUTY_MAX-1) ? DUTY_count + 1 : 0;
        end
    end
endmodule

module PWM_Counter #(
    parameter DUTY_MAX = 255,
    parameter DUTY_MAX_BITS = 8, //log2(duty_max)
    parameter PWM_PERIOD = 1_000_000,
    parameter CLK_COUNTER_SIZE = 30,
    parameter SAMPLE_PERIOD = 10_000
)
(
    input clk,
    input pwm,
    output [DUTY_MAX_BITS-1:0] pwm_value
);
    
    reg [DUTY_MAX_BITS-1:0] counter = 0;
    reg [DUTY_MAX_BITS-1:0] value_reg = 0;
    reg [DUTY_MAX_BITS-1:0] DUTY_count = 0;
    reg [CLK_COUNTER_SIZE-1:0] clk_counter = 0;

    assign pwm_value = value_reg;

    always @(posedge clk) begin
        clk_counter <= (clk_counter < PWM_PERIOD) ? clk_counter + 1: 0;
        if(clk_counter == PWM_PERIOD) begin
            if(DUTY_count < DUTY_MAX-1) begin
                DUTY_count <= DUTY_count + 1;
                if(pwm) counter <= counter + 1;
            end
            else begin
                value_reg <= counter;
                counter <= 0;
                DUTY_count <= 0;
            end
        end
    end
    
endmodule

module PWM_Counter2 #(
    parameter DUTY_MAX = 255,
    parameter DUTY_MAX_BITS = 8, //log2(duty_max)
    parameter PWM_PERIOD = 1_000_000,
    parameter PULSE_PERIOD = PWM_PERIOD/DUTY_MAX,
    parameter CLK_COUNTER_SIZE = 30
)
(
    input clk,
    input pwm,
    output [DUTY_MAX_BITS-1:0] pwm_value
);
    reg [CLK_COUNTER_SIZE-1:0] clk_PWM_freq_counter = 0;
    reg [CLK_COUNTER_SIZE-1:0] pwm_value_reg = 0;
    reg [CLK_COUNTER_SIZE-1:0] collect = 0;
    assign pwm_value = pwm_value_reg[DUTY_MAX_BITS-1:0];

    always @(posedge clk) begin
        clk_PWM_freq_counter <= (clk_PWM_freq_counter < PWM_PERIOD) ? clk_PWM_freq_counter + 1 : 0;
        collect <= (clk_PWM_freq_counter == 0) ? 0 : collect + pwm;
        if (clk_PWM_freq_counter == 0) pwm_value_reg <= collect/PULSE_PERIOD;
    end
    
endmodule