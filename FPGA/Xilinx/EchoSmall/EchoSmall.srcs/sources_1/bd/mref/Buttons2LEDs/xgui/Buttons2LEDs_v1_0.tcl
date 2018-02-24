# Definitional proc to organize widgets for parameters.
proc init_gui { IPINST } {
  ipgui::add_param $IPINST -name "Component_Name"
  #Adding Page
  set Page_0 [ipgui::add_page $IPINST -name "Page 0"]
  ipgui::add_param $IPINST -name "clk_freq_in" -parent ${Page_0}


}

proc update_PARAM_VALUE.clk_freq_in { PARAM_VALUE.clk_freq_in } {
	# Procedure called to update clk_freq_in when any of the dependent parameters in the arguments change
}

proc validate_PARAM_VALUE.clk_freq_in { PARAM_VALUE.clk_freq_in } {
	# Procedure called to validate clk_freq_in
	return true
}


proc update_MODELPARAM_VALUE.clk_freq_in { MODELPARAM_VALUE.clk_freq_in PARAM_VALUE.clk_freq_in } {
	# Procedure called to set VHDL generic/Verilog parameter value(s) based on TCL parameter value
	set_property value [get_property value ${PARAM_VALUE.clk_freq_in}] ${MODELPARAM_VALUE.clk_freq_in}
}

