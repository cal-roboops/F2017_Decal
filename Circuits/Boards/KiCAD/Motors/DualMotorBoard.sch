EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:DualMotorBoard-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 5400 1850 1050 900 
U 5A51075D
F0 "MotorControlUnit_1" 60
F1 "MotorControlUnit.sch" 60
F2 "VBAT" I L 5400 2100 60 
F3 "VGND" O L 5400 2450 60 
$EndSheet
$Comp
L GND #PWR01
U 1 1 5A5181EA
P 5250 2550
F 0 "#PWR01" H 5250 2300 50  0001 C CNN
F 1 "GND" H 5250 2400 50  0000 C CNN
F 2 "" H 5250 2550 50  0001 C CNN
F 3 "" H 5250 2550 50  0001 C CNN
	1    5250 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2450 5250 2450
Wire Wire Line
	5250 2450 5250 2550
$Comp
L +15V #PWR02
U 1 1 5A5182E1
P 5250 2000
F 0 "#PWR02" H 5250 1850 50  0001 C CNN
F 1 "+15V" H 5250 2140 50  0000 C CNN
F 2 "" H 5250 2000 50  0001 C CNN
F 3 "" H 5250 2000 50  0001 C CNN
	1    5250 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2000 5250 2100
Wire Wire Line
	5100 2100 5400 2100
$Sheet
S 5400 3050 1050 900 
U 5A5113FC
F0 "MotorControlUnit_2" 60
F1 "MotorControlUnit.sch" 60
F2 "VBAT" I L 5400 3300 60 
F3 "VGND" O L 5400 3650 60 
$EndSheet
$Comp
L GND #PWR03
U 1 1 5A511402
P 5250 3750
F 0 "#PWR03" H 5250 3500 50  0001 C CNN
F 1 "GND" H 5250 3600 50  0000 C CNN
F 2 "" H 5250 3750 50  0001 C CNN
F 3 "" H 5250 3750 50  0001 C CNN
	1    5250 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3650 5250 3650
Wire Wire Line
	5250 3650 5250 3750
Wire Wire Line
	5100 3300 5400 3300
Wire Wire Line
	5100 2100 5100 3300
Connection ~ 5250 2100
$EndSCHEMATC
