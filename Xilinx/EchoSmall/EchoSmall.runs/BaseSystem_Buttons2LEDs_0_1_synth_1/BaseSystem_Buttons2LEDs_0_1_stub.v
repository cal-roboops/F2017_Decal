// Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2017.3.1 (win64) Build 2035080 Fri Oct 20 14:20:01 MDT 2017
// Date        : Wed Jan 24 15:33:55 2018
// Host        : DESKTOP-M5L7GPO running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
//               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ BaseSystem_Buttons2LEDs_0_1_stub.v
// Design      : BaseSystem_Buttons2LEDs_0_1
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "Buttons2LEDs,Vivado 2017.3.1" *)
module decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix(clk, pushButtons, switches, buttonLEDs, rgbLEDs)
/* synthesis syn_black_box black_box_pad_pin="clk,pushButtons[3:0],switches[1:0],buttonLEDs[3:0],rgbLEDs[5:0]" */;
  input clk;
  input [3:0]pushButtons;
  input [1:0]switches;
  output [3:0]buttonLEDs;
  output [5:0]rgbLEDs;
endmodule
