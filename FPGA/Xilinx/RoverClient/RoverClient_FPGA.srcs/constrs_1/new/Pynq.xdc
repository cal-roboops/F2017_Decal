set_property -dict { PACKAGE_PIN M19   IOSTANDARD LVCMOS33 } [get_ports { ARM_UART_rxd }];
set_property -dict { PACKAGE_PIN P14   IOSTANDARD LVCMOS33 } [get_ports { ARM_UART_txd }];

set_property -dict { PACKAGE_PIN M20   IOSTANDARD LVCMOS33 } [get_ports { DRIVE_UART_rxd }];
set_property -dict { PACKAGE_PIN N16   IOSTANDARD LVCMOS33 } [get_ports { DRIVE_UART_txd }];
