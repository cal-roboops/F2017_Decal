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
$Descr A0 46811 33110
encoding utf-8
Sheet 5 5
Title "22VPowerBoard.sch"
Date "27 DEC 2017"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L GND #PWR48
U 1 1 5A51FC99
P 9400 6400
F 0 "#PWR48" H 9400 6150 50  0001 C CNN
F 1 "GND" H 9400 6250 50  0000 C CNN
F 2 "" H 9400 6400 50  0001 C CNN
F 3 "" H 9400 6400 50  0001 C CNN
	1    9400 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9400 6100 9400 6400
$Comp
L CP1 C5
U 1 1 5A51FCB6
P 9850 6100
F 0 "C5" H 9875 6200 50  0000 L CNN
F 1 "0.1uF" H 9875 6000 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D5.0mm_P2.50mm" H 9888 5950 50  0001 C CNN
F 3 "" H 9850 6100 50  0001 C CNN
	1    9850 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 5800 9100 5800
Wire Wire Line
	8950 5800 8950 5950
Wire Wire Line
	8950 6250 8950 6350
Wire Wire Line
	8950 6350 9850 6350
Connection ~ 9400 6350
Wire Wire Line
	9850 6350 9850 6250
Wire Wire Line
	9700 5800 10000 5800
Wire Wire Line
	9850 5800 9850 5950
Connection ~ 9850 5800
Connection ~ 8950 5800
Text Label 10000 5800 0    60   ~ 0
VOUT
Text Label 8800 5800 0    60   ~ 0
VIN
$Comp
L LM7805_TO220 U2
U 1 1 5A51FED1
P 9400 5800
F 0 "U2" H 9250 5925 50  0000 C CNN
F 1 "LM7805_TO220" H 9400 5925 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-220-3_Vertical" H 9400 6025 50  0001 C CIN
F 3 "" H 9400 5750 50  0001 C CNN
	1    9400 5800
	1    0    0    -1  
$EndComp
$Comp
L CP1 C4
U 1 1 5A520036
P 8950 6100
F 0 "C4" H 8975 6200 50  0000 L CNN
F 1 "0.33uF" H 8975 6000 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D5.0mm_P2.50mm" H 8988 5950 50  0001 C CNN
F 3 "" H 8950 6100 50  0001 C CNN
	1    8950 6100
	1    0    0    -1  
$EndComp
Text HLabel 10750 5500 0    60   Input ~ 0
VIN
Text HLabel 10750 5600 0    60   Output ~ 0
VOUT
Text HLabel 10750 5700 0    60   BiDi ~ 0
VGND
$Comp
L GND #PWR49
U 1 1 5A5201B2
P 10900 5700
F 0 "#PWR49" H 10900 5450 50  0001 C CNN
F 1 "GND" H 10900 5550 50  0000 C CNN
F 2 "" H 10900 5700 50  0001 C CNN
F 3 "" H 10900 5700 50  0001 C CNN
	1    10900 5700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	10750 5700 10900 5700
Text Label 10900 5600 0    60   ~ 0
VOUT
Text Label 10900 5500 0    60   ~ 0
VIN
Wire Wire Line
	10900 5500 10750 5500
Wire Wire Line
	10750 5600 10900 5600
$EndSCHEMATC
