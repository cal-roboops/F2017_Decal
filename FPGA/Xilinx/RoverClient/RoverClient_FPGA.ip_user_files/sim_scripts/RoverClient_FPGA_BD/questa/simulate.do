onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -lib xil_defaultlib RoverClient_FPGA_BD_opt

do {wave.do}

view wave
view structure
view signals

do {RoverClient_FPGA_BD.udo}

run -all

quit -force
