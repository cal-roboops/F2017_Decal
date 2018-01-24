-- Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2017.3.1 (win64) Build 2035080 Fri Oct 20 14:20:01 MDT 2017
-- Date        : Wed Jan 24 15:33:56 2018
-- Host        : DESKTOP-M5L7GPO running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub
--               g:/XILINX/EchoSmall/EchoSmall.srcs/sources_1/bd/BaseSystem/ip/BaseSystem_Buttons2LEDs_0_1/BaseSystem_Buttons2LEDs_0_1_stub.vhdl
-- Design      : BaseSystem_Buttons2LEDs_0_1
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity BaseSystem_Buttons2LEDs_0_1 is
  Port ( 
    clk : in STD_LOGIC;
    pushButtons : in STD_LOGIC_VECTOR ( 3 downto 0 );
    switches : in STD_LOGIC_VECTOR ( 1 downto 0 );
    buttonLEDs : out STD_LOGIC_VECTOR ( 3 downto 0 );
    rgbLEDs : out STD_LOGIC_VECTOR ( 5 downto 0 )
  );

end BaseSystem_Buttons2LEDs_0_1;

architecture stub of BaseSystem_Buttons2LEDs_0_1 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "clk,pushButtons[3:0],switches[1:0],buttonLEDs[3:0],rgbLEDs[5:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "Buttons2LEDs,Vivado 2017.3.1";
begin
end;
