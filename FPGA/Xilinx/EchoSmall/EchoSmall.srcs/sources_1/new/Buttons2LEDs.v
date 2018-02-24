`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/24/2018 01:29:52 PM
// Design Name: 
// Module Name: Buttons2LEDs
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module Buttons2LEDs #(
    parameter clk_freq_in = 100000000
)(
    input clk,
    //input rst,
    
    input [3:0] pushButtons,
    input [1:0] switches,
    
    output [3:0] buttonLEDs,
    output [5:0] rgbLEDs
);
    
    localparam integer pwm_period = clk_freq_in * 0.01;
    localparam integer pwm_on = pwm_period / 8;
    
    reg [31:0] count = 0;
    
    assign buttonLEDs = (count < pwm_on) ? pushButtons : 0;
    assign rgbLEDs = (count < pwm_on) ? switches : 0;
    
    always @(posedge clk) begin
        if (count < pwm_period) count <= count + 1;
        else count <= 0;
    end
endmodule
