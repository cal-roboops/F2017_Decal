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
Sheet 1 5
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
S 4300 1800 1050 900 
U 5A51075D
F0 "MotorControlUnit_1" 60
F1 "MotorControlUnit.sch" 60
F2 "VBAT" I L 4300 2050 60 
F3 "VG" I R 5350 2050 60 
F4 "VSW" I R 5350 2400 60 
F5 "VFUSE" B L 4300 2250 60 
F6 "VGND" B L 4300 2450 60 
$EndSheet
$Comp
L GND #PWR8
U 1 1 5A5181EA
P 4150 2500
F 0 "#PWR8" H 4150 2250 50  0001 C CNN
F 1 "GND" H 4150 2350 50  0000 C CNN
F 2 "" H 4150 2500 50  0001 C CNN
F 3 "" H 4150 2500 50  0001 C CNN
	1    4150 2500
	1    0    0    -1  
$EndComp
$Sheet
S 4300 3000 1050 900 
U 5A5113FC
F0 "MotorControlUnit_2" 60
F1 "MotorControlUnit.sch" 60
F2 "VBAT" I L 4300 3250 60 
F3 "VG" I R 5350 3250 60 
F4 "VSW" I R 5350 3600 60 
F5 "VFUSE" B L 4300 3450 60 
F6 "VGND" B L 4300 3650 60 
$EndSheet
$Comp
L GND #PWR10
U 1 1 5A511402
P 4150 3700
F 0 "#PWR10" H 4150 3450 50  0001 C CNN
F 1 "GND" H 4150 3550 50  0000 C CNN
F 2 "" H 4150 3700 50  0001 C CNN
F 3 "" H 4150 3700 50  0001 C CNN
	1    4150 3700
	1    0    0    -1  
$EndComp
$Sheet
S 7200 1800 1000 900 
U 5A51A0A8
F0 "26VUnit" 60
F1 "26VUnit.sch" 60
F2 "VIN" I R 8200 2100 60 
F3 "VOUT" O L 7200 2100 60 
F4 "VGND" B L 7200 2500 60 
$EndSheet
$Sheet
S 7200 2950 1000 950 
U 5A51A114
F0 "5VUnit" 60
F1 "5VUnit.sch" 60
F2 "VIN" I R 8200 3200 60 
F3 "VOUT" O L 7200 3200 60 
F4 "VGND" B L 7200 3650 60 
$EndSheet
$Comp
L GND #PWR11
U 1 1 5A51F50D
P 7050 2550
F 0 "#PWR11" H 7050 2300 50  0001 C CNN
F 1 "GND" H 7050 2400 50  0000 C CNN
F 2 "" H 7050 2550 50  0001 C CNN
F 3 "" H 7050 2550 50  0001 C CNN
	1    7050 2550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR12
U 1 1 5A521A49
P 7050 3700
F 0 "#PWR12" H 7050 3450 50  0001 C CNN
F 1 "GND" H 7050 3550 50  0000 C CNN
F 2 "" H 7050 3700 50  0001 C CNN
F 3 "" H 7050 3700 50  0001 C CNN
	1    7050 3700
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J15
U 1 1 5A527328
P 9250 2600
F 0 "J15" H 9250 2700 50  0000 C CNN
F 1 "Conn_01x02" H 9250 2400 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B02B-XH-A_02x2.50mm_Straight" H 9250 2600 50  0001 C CNN
F 3 "" H 9250 2600 50  0001 C CNN
	1    9250 2600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR13
U 1 1 5A5276C7
P 8900 2800
F 0 "#PWR13" H 8900 2550 50  0001 C CNN
F 1 "GND" H 8900 2650 50  0000 C CNN
F 2 "" H 8900 2800 50  0001 C CNN
F 3 "" H 8900 2800 50  0001 C CNN
	1    8900 2800
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F1
U 1 1 5A52806E
P 8750 2600
F 0 "F1" V 8650 2600 50  0000 C CNN
F 1 "Polyfuse" V 8850 2600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 8800 2400 50  0001 L CNN
F 3 "" H 8750 2600 50  0001 C CNN
	1    8750 2600
	0    1    1    0   
$EndComp
$Comp
L Conn_01x02 J16
U 1 1 5A51C114
P 6750 2850
F 0 "J16" H 6750 2950 50  0000 C CNN
F 1 "Conn_01x02" H 6750 2650 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B02B-XH-A_02x2.50mm_Straight" H 6750 2850 50  0001 C CNN
F 3 "" H 6750 2850 50  0001 C CNN
	1    6750 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2450 4150 2450
Wire Wire Line
	4150 2450 4150 2500
Wire Wire Line
	4300 3650 4150 3650
Wire Wire Line
	4150 3650 4150 3700
Wire Wire Line
	4150 1950 4150 2050
Wire Wire Line
	4150 2050 4300 2050
Wire Wire Line
	4150 3150 4150 3250
Wire Wire Line
	4150 3250 4300 3250
Wire Wire Line
	4300 2250 4000 2250
Wire Wire Line
	4000 2250 4000 3450
Wire Wire Line
	4000 3450 4300 3450
Wire Wire Line
	7050 2500 7050 2550
Wire Wire Line
	7200 3650 7050 3650
Wire Wire Line
	7050 3650 7050 3700
Wire Wire Line
	7200 2500 7050 2500
Wire Wire Line
	9050 2700 8900 2700
Wire Wire Line
	8900 2700 8900 2800
Wire Wire Line
	8200 2100 8450 2100
Wire Wire Line
	8450 2100 8450 3200
Wire Wire Line
	8450 3200 8200 3200
Connection ~ 8450 2600
Wire Wire Line
	8900 2600 9050 2600
Wire Wire Line
	8600 2600 8450 2600
Wire Wire Line
	6000 2100 7200 2100
Wire Wire Line
	6000 3200 7200 3200
$Comp
L Polyfuse F12
U 1 1 5A51EB5F
P 6250 2850
F 0 "F12" V 6150 2850 50  0000 C CNN
F 1 "Polyfuse" V 6350 2850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 6300 2650 50  0001 L CNN
F 3 "" H 6250 2850 50  0001 C CNN
	1    6250 2850
	0    1    1    0   
$EndComp
$Comp
L Polyfuse F13
U 1 1 5A51EBF1
P 6250 2950
F 0 "F13" V 6150 2950 50  0000 C CNN
F 1 "Polyfuse" V 6350 2950 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 6300 2750 50  0001 L CNN
F 3 "" H 6250 2950 50  0001 C CNN
	1    6250 2950
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 2950 6550 2950
Wire Wire Line
	6550 2850 6400 2850
Wire Wire Line
	6100 2850 6000 2850
Wire Wire Line
	6000 2850 6000 2100
Wire Wire Line
	6000 3200 6000 2950
Wire Wire Line
	6000 2950 6100 2950
$Comp
L GND #PWR6
U 1 1 5A520157
P 3050 2550
F 0 "#PWR6" H 3050 2300 50  0001 C CNN
F 1 "GND" H 3050 2400 50  0000 C CNN
F 2 "" H 3050 2550 50  0001 C CNN
F 3 "" H 3050 2550 50  0001 C CNN
	1    3050 2550
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR7
U 1 1 5A5202E3
P 4150 1950
F 0 "#PWR7" H 4150 1800 50  0001 C CNN
F 1 "+BATT" H 4150 2090 50  0000 C CNN
F 2 "" H 4150 1950 50  0001 C CNN
F 3 "" H 4150 1950 50  0001 C CNN
	1    4150 1950
	1    0    0    -1  
$EndComp
$Comp
L +BATT #PWR9
U 1 1 5A520413
P 4150 3150
F 0 "#PWR9" H 4150 3000 50  0001 C CNN
F 1 "+BATT" H 4150 3290 50  0000 C CNN
F 2 "" H 4150 3150 50  0001 C CNN
F 3 "" H 4150 3150 50  0001 C CNN
	1    4150 3150
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG2
U 1 1 5A520961
P 3050 2400
F 0 "#FLG2" H 3050 2475 50  0001 C CNN
F 1 "PWR_FLAG" H 3050 2550 50  0000 C CNN
F 2 "" H 3050 2400 50  0001 C CNN
F 3 "" H 3050 2400 50  0001 C CNN
	1    3050 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2400 3050 2550
$Comp
L +BATT #PWR5
U 1 1 5A520B60
P 2700 2400
F 0 "#PWR5" H 2700 2250 50  0001 C CNN
F 1 "+BATT" H 2700 2540 50  0000 C CNN
F 2 "" H 2700 2400 50  0001 C CNN
F 3 "" H 2700 2400 50  0001 C CNN
	1    2700 2400
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG1
U 1 1 5A520BDA
P 2700 2550
F 0 "#FLG1" H 2700 2625 50  0001 C CNN
F 1 "PWR_FLAG" H 2700 2700 50  0000 C CNN
F 2 "" H 2700 2550 50  0001 C CNN
F 3 "" H 2700 2550 50  0001 C CNN
	1    2700 2550
	-1   0    0    1   
$EndComp
Wire Wire Line
	2700 2400 2700 2550
$Comp
L PWR_FLAG #FLG3
U 1 1 5A523699
P 8450 2100
F 0 "#FLG3" H 8450 2175 50  0001 C CNN
F 1 "PWR_FLAG" H 8450 2250 50  0000 C CNN
F 2 "" H 8450 2100 50  0001 C CNN
F 3 "" H 8450 2100 50  0001 C CNN
	1    8450 2100
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J18
U 1 1 5A610638
P 3150 3200
F 0 "J18" H 3150 3300 50  0000 C CNN
F 1 "Conn_01x02" H 3150 3000 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B02B-XH-A_02x2.50mm_Straight" H 3150 3200 50  0001 C CNN
F 3 "" H 3150 3200 50  0001 C CNN
	1    3150 3200
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F14
U 1 1 5A61063E
P 2700 3200
F 0 "F14" V 2600 3200 50  0000 C CNN
F 1 "Polyfuse" V 2800 3200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 2750 3000 50  0001 L CNN
F 3 "" H 2700 3200 50  0001 C CNN
	1    2700 3200
	0    1    1    0   
$EndComp
$Comp
L Polyfuse F15
U 1 1 5A610644
P 2700 3300
F 0 "F15" V 2600 3300 50  0000 C CNN
F 1 "Polyfuse" V 2800 3300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 2750 3100 50  0001 L CNN
F 3 "" H 2700 3300 50  0001 C CNN
	1    2700 3300
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 3300 2950 3300
Wire Wire Line
	2950 3200 2850 3200
Wire Wire Line
	2550 3200 2450 3200
Wire Wire Line
	2450 3300 2550 3300
$Comp
L +BATT #PWR1
U 1 1 5A612841
P 2450 3200
F 0 "#PWR1" H 2450 3050 50  0001 C CNN
F 1 "+BATT" H 2450 3340 50  0000 C CNN
F 2 "" H 2450 3200 50  0001 C CNN
F 3 "" H 2450 3200 50  0001 C CNN
	1    2450 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 5A6128C4
P 2450 3300
F 0 "#PWR2" H 2450 3050 50  0001 C CNN
F 1 "GND" H 2450 3150 50  0000 C CNN
F 2 "" H 2450 3300 50  0001 C CNN
F 3 "" H 2450 3300 50  0001 C CNN
	1    2450 3300
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02 J19
U 1 1 5A60FE63
P 3150 3750
F 0 "J19" H 3150 3850 50  0000 C CNN
F 1 "Conn_01x02" H 3150 3550 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B02B-XH-A_02x2.50mm_Straight" H 3150 3750 50  0001 C CNN
F 3 "" H 3150 3750 50  0001 C CNN
	1    3150 3750
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F16
U 1 1 5A60FE69
P 2700 3750
F 0 "F16" V 2600 3750 50  0000 C CNN
F 1 "Polyfuse" V 2800 3750 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 2750 3550 50  0001 L CNN
F 3 "" H 2700 3750 50  0001 C CNN
	1    2700 3750
	0    1    1    0   
$EndComp
$Comp
L Polyfuse F17
U 1 1 5A60FE6F
P 2700 3850
F 0 "F17" V 2600 3850 50  0000 C CNN
F 1 "Polyfuse" V 2800 3850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 2750 3650 50  0001 L CNN
F 3 "" H 2700 3850 50  0001 C CNN
	1    2700 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	2850 3850 2950 3850
Wire Wire Line
	2950 3750 2850 3750
Wire Wire Line
	2550 3750 2450 3750
Wire Wire Line
	2450 3850 2550 3850
$Comp
L +BATT #PWR3
U 1 1 5A60FE79
P 2450 3750
F 0 "#PWR3" H 2450 3600 50  0001 C CNN
F 1 "+BATT" H 2450 3890 50  0000 C CNN
F 2 "" H 2450 3750 50  0001 C CNN
F 3 "" H 2450 3750 50  0001 C CNN
	1    2450 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 5A60FE7F
P 2450 3850
F 0 "#PWR4" H 2450 3600 50  0001 C CNN
F 1 "GND" H 2450 3700 50  0000 C CNN
F 2 "" H 2450 3850 50  0001 C CNN
F 3 "" H 2450 3850 50  0001 C CNN
	1    2450 3850
	1    0    0    -1  
$EndComp
$EndSCHEMATC
