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
Sheet 2 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R5
U 1 1 5A47110E
P 2300 1850
AR Path="/5A51075D/5A47110E" Ref="R5"  Part="1" 
AR Path="/5A5113FC/5A47110E" Ref="R20"  Part="1" 
F 0 "R20" V 2380 1850 50  0000 C CNN
F 1 "1K" V 2300 1850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 2230 1850 50  0001 C CNN
F 3 "" H 2300 1850 50  0001 C CNN
	1    2300 1850
	-1   0    0    1   
$EndComp
$Comp
L R R6
U 1 1 5A47115A
P 2950 3700
AR Path="/5A51075D/5A47115A" Ref="R6"  Part="1" 
AR Path="/5A5113FC/5A47115A" Ref="R21"  Part="1" 
F 0 "R21" V 3030 3700 50  0000 C CNN
F 1 "10K" V 2950 3700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 2880 3700 50  0001 C CNN
F 3 "" H 2950 3700 50  0001 C CNN
	1    2950 3700
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 5A4711AC
P 3850 3700
AR Path="/5A51075D/5A4711AC" Ref="R10"  Part="1" 
AR Path="/5A5113FC/5A4711AC" Ref="R25"  Part="1" 
F 0 "R25" V 3930 3700 50  0000 C CNN
F 1 "10K" V 3850 3700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 3780 3700 50  0001 C CNN
F 3 "" H 3850 3700 50  0001 C CNN
	1    3850 3700
	1    0    0    1   
$EndComp
$Comp
L Q_NPN_EBC Q3
U 1 1 5A4712B8
P 2200 2400
AR Path="/5A51075D/5A4712B8" Ref="Q3"  Part="1" 
AR Path="/5A5113FC/5A4712B8" Ref="Q16"  Part="1" 
F 0 "Q16" H 2400 2450 50  0000 L CNN
F 1 "2N3904" H 2400 2350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 2400 2500 50  0001 C CNN
F 3 "" H 2200 2400 50  0001 C CNN
	1    2200 2400
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q5
U 1 1 5A4713DB
P 2850 4200
AR Path="/5A51075D/5A4713DB" Ref="Q5"  Part="1" 
AR Path="/5A5113FC/5A4713DB" Ref="Q18"  Part="1" 
F 0 "Q18" H 3050 4250 50  0000 L CNN
F 1 "2N3904" H 3050 4150 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 3050 4300 50  0001 C CNN
F 3 "" H 2850 4200 50  0001 C CNN
	1    2850 4200
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q7
U 1 1 5A47143E
P 3750 4200
AR Path="/5A51075D/5A47143E" Ref="Q7"  Part="1" 
AR Path="/5A5113FC/5A47143E" Ref="Q20"  Part="1" 
F 0 "Q20" H 3950 4250 50  0000 L CNN
F 1 "2N3904" H 3950 4150 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 3950 4300 50  0001 C CNN
F 3 "" H 3750 4200 50  0001 C CNN
	1    3750 4200
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J3
U 1 1 5A472033
P 7500 900
AR Path="/5A51075D/5A472033" Ref="J3"  Part="1" 
AR Path="/5A5113FC/5A472033" Ref="J10"  Part="1" 
F 0 "J10" H 7500 1000 50  0000 C CNN
F 1 "Conn_01x01" H 7500 800 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2-5mmDrill" H 7500 900 50  0001 C CNN
F 3 "" H 7500 900 50  0001 C CNN
	1    7500 900 
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x01 J6
U 1 1 5A4720C1
P 8200 900
AR Path="/5A51075D/5A4720C1" Ref="J6"  Part="1" 
AR Path="/5A5113FC/5A4720C1" Ref="J13"  Part="1" 
F 0 "J13" H 8200 1000 50  0000 C CNN
F 1 "Conn_01x01" H 8200 800 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2-5mmDrill" H 8200 900 50  0001 C CNN
F 3 "" H 8200 900 50  0001 C CNN
	1    8200 900 
	0    -1   -1   0   
$EndComp
$Comp
L D D5
U 1 1 5A472771
P 7400 2050
AR Path="/5A51075D/5A472771" Ref="D5"  Part="1" 
AR Path="/5A5113FC/5A472771" Ref="D13"  Part="1" 
F 0 "D13" H 7400 2150 50  0000 C CNN
F 1 "1N4007" H 7400 1950 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P12.70mm_Horizontal" H 7400 2050 50  0001 C CNN
F 3 "" H 7400 2050 50  0001 C CNN
	1    7400 2050
	0    1    1    0   
$EndComp
$Comp
L D D7
U 1 1 5A472949
P 8300 2050
AR Path="/5A51075D/5A472949" Ref="D7"  Part="1" 
AR Path="/5A5113FC/5A472949" Ref="D15"  Part="1" 
F 0 "D15" H 8300 2150 50  0000 C CNN
F 1 "1N4007" H 8300 1950 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P12.70mm_Horizontal" H 8300 2050 50  0001 C CNN
F 3 "" H 8300 2050 50  0001 C CNN
	1    8300 2050
	0    1    1    0   
$EndComp
$Comp
L D D8
U 1 1 5A4729DB
P 8300 2650
AR Path="/5A51075D/5A4729DB" Ref="D8"  Part="1" 
AR Path="/5A5113FC/5A4729DB" Ref="D16"  Part="1" 
F 0 "D16" H 8300 2750 50  0000 C CNN
F 1 "1N4007" H 8300 2550 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P12.70mm_Horizontal" H 8300 2650 50  0001 C CNN
F 3 "" H 8300 2650 50  0001 C CNN
	1    8300 2650
	0    1    1    0   
$EndComp
$Comp
L D D6
U 1 1 5A472A6C
P 7400 2650
AR Path="/5A51075D/5A472A6C" Ref="D6"  Part="1" 
AR Path="/5A5113FC/5A472A6C" Ref="D14"  Part="1" 
F 0 "D14" H 7400 2750 50  0000 C CNN
F 1 "1N4007" H 7400 2550 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P12.70mm_Horizontal" H 7400 2650 50  0001 C CNN
F 3 "" H 7400 2650 50  0001 C CNN
	1    7400 2650
	0    1    1    0   
$EndComp
$Comp
L Conn_01x01 J4
U 1 1 5A472EDB
P 7700 2350
AR Path="/5A51075D/5A472EDB" Ref="J4"  Part="1" 
AR Path="/5A5113FC/5A472EDB" Ref="J11"  Part="1" 
F 0 "J11" H 7700 2450 50  0000 C CNN
F 1 "Conn_01x01" H 7700 2250 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2-5mmDrill" H 7700 2350 50  0001 C CNN
F 3 "" H 7700 2350 50  0001 C CNN
	1    7700 2350
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J5
U 1 1 5A472F6E
P 8000 2350
AR Path="/5A51075D/5A472F6E" Ref="J5"  Part="1" 
AR Path="/5A5113FC/5A472F6E" Ref="J12"  Part="1" 
F 0 "J12" H 8000 2450 50  0000 C CNN
F 1 "Conn_01x01" H 8000 2250 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2-5mmDrill" H 8000 2350 50  0001 C CNN
F 3 "" H 8000 2350 50  0001 C CNN
	1    8000 2350
	-1   0    0    1   
$EndComp
$Comp
L Q_NMOS_GDS Q10
U 1 1 5A4730B0
P 6900 2050
AR Path="/5A51075D/5A4730B0" Ref="Q10"  Part="1" 
AR Path="/5A5113FC/5A4730B0" Ref="Q23"  Part="1" 
F 0 "Q23" H 7100 2100 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 7100 2000 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TO-263-2" H 7100 2150 50  0001 C CNN
F 3 "" H 6900 2050 50  0001 C CNN
	1    6900 2050
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_GDS Q11
U 1 1 5A473172
P 6900 2650
AR Path="/5A51075D/5A473172" Ref="Q11"  Part="1" 
AR Path="/5A5113FC/5A473172" Ref="Q24"  Part="1" 
F 0 "Q24" H 7100 2700 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 7100 2600 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TO-263-2" H 7100 2750 50  0001 C CNN
F 3 "" H 6900 2650 50  0001 C CNN
	1    6900 2650
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_GDS Q13
U 1 1 5A4731E8
P 8800 2650
AR Path="/5A51075D/5A4731E8" Ref="Q13"  Part="1" 
AR Path="/5A5113FC/5A4731E8" Ref="Q26"  Part="1" 
F 0 "Q26" H 9000 2700 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 9000 2600 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TO-263-2" H 9000 2750 50  0001 C CNN
F 3 "" H 8800 2650 50  0001 C CNN
	1    8800 2650
	-1   0    0    -1  
$EndComp
$Comp
L Q_NMOS_GDS Q12
U 1 1 5A473299
P 8800 2050
AR Path="/5A51075D/5A473299" Ref="Q12"  Part="1" 
AR Path="/5A5113FC/5A473299" Ref="Q25"  Part="1" 
F 0 "Q25" H 9000 2100 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 9000 2000 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:TO-263-2" H 9000 2150 50  0001 C CNN
F 3 "" H 8800 2050 50  0001 C CNN
	1    8800 2050
	-1   0    0    -1  
$EndComp
$Comp
L Conn_01x01 J2
U 1 1 5A4738D5
P 7400 3250
AR Path="/5A51075D/5A4738D5" Ref="J2"  Part="1" 
AR Path="/5A5113FC/5A4738D5" Ref="J9"  Part="1" 
F 0 "J9" H 7400 3350 50  0000 C CNN
F 1 "Conn_01x01" H 7400 3150 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2-5mmDrill" H 7400 3250 50  0001 C CNN
F 3 "" H 7400 3250 50  0001 C CNN
	1    7400 3250
	0    1    1    0   
$EndComp
$Comp
L Conn_01x01 J7
U 1 1 5A4739A0
P 8300 3250
AR Path="/5A51075D/5A4739A0" Ref="J7"  Part="1" 
AR Path="/5A5113FC/5A4739A0" Ref="J14"  Part="1" 
F 0 "J14" H 8300 3350 50  0000 C CNN
F 1 "Conn_01x01" H 8300 3150 50  0000 C CNN
F 2 "Wire_Pads:SolderWirePad_single_2-5mmDrill" H 8300 3250 50  0001 C CNN
F 3 "" H 8300 3250 50  0001 C CNN
	1    8300 3250
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 5A473CCB
P 9350 2050
AR Path="/5A51075D/5A473CCB" Ref="R14"  Part="1" 
AR Path="/5A5113FC/5A473CCB" Ref="R29"  Part="1" 
F 0 "R29" V 9430 2050 50  0000 C CNN
F 1 "1Meg" V 9350 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 9280 2050 50  0001 C CNN
F 3 "" H 9350 2050 50  0001 C CNN
	1    9350 2050
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 5A473DDC
P 9350 2650
AR Path="/5A51075D/5A473DDC" Ref="R15"  Part="1" 
AR Path="/5A5113FC/5A473DDC" Ref="R30"  Part="1" 
F 0 "R30" V 9430 2650 50  0000 C CNN
F 1 "10K" V 9350 2650 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 9280 2650 50  0001 C CNN
F 3 "" H 9350 2650 50  0001 C CNN
	1    9350 2650
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 5A4741C0
P 6350 2050
AR Path="/5A51075D/5A4741C0" Ref="R12"  Part="1" 
AR Path="/5A5113FC/5A4741C0" Ref="R27"  Part="1" 
F 0 "R27" V 6430 2050 50  0000 C CNN
F 1 "1Meg" V 6350 2050 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 6280 2050 50  0001 C CNN
F 3 "" H 6350 2050 50  0001 C CNN
	1    6350 2050
	0    -1   -1   0   
$EndComp
$Comp
L R R13
U 1 1 5A4742BB
P 6350 2650
AR Path="/5A51075D/5A4742BB" Ref="R13"  Part="1" 
AR Path="/5A5113FC/5A4742BB" Ref="R28"  Part="1" 
F 0 "R28" V 6430 2650 50  0000 C CNN
F 1 "10K" V 6350 2650 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 6280 2650 50  0001 C CNN
F 3 "" H 6350 2650 50  0001 C CNN
	1    6350 2650
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR26
U 1 1 5A47499A
P 9600 2050
AR Path="/5A51075D/5A47499A" Ref="#PWR26"  Part="1" 
AR Path="/5A5113FC/5A47499A" Ref="#PWR42"  Part="1" 
F 0 "#PWR42" H 9600 1800 50  0001 C CNN
F 1 "GND" H 9600 1900 50  0000 C CNN
F 2 "" H 9600 2050 50  0001 C CNN
F 3 "" H 9600 2050 50  0001 C CNN
	1    9600 2050
	0    -1   -1   0   
$EndComp
$Comp
L Q_NPN_EBC Q1
U 1 1 5A475931
P 1800 5850
AR Path="/5A51075D/5A475931" Ref="Q1"  Part="1" 
AR Path="/5A5113FC/5A475931" Ref="Q14"  Part="1" 
F 0 "Q14" H 2000 5900 50  0000 L CNN
F 1 "2N3904" H 2000 5800 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 2000 5950 50  0001 C CNN
F 3 "" H 1800 5850 50  0001 C CNN
	1    1800 5850
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q4
U 1 1 5A4759F7
P 2400 5850
AR Path="/5A51075D/5A4759F7" Ref="Q4"  Part="1" 
AR Path="/5A5113FC/5A4759F7" Ref="Q17"  Part="1" 
F 0 "Q17" H 2600 5900 50  0000 L CNN
F 1 "2N3904" H 2600 5800 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 2600 5950 50  0001 C CNN
F 3 "" H 2400 5850 50  0001 C CNN
	1    2400 5850
	-1   0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q9
U 1 1 5A476197
P 4100 5850
AR Path="/5A51075D/5A476197" Ref="Q9"  Part="1" 
AR Path="/5A5113FC/5A476197" Ref="Q22"  Part="1" 
F 0 "Q22" H 4300 5900 50  0000 L CNN
F 1 "2N3904" H 4300 5800 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4300 5950 50  0001 C CNN
F 3 "" H 4100 5850 50  0001 C CNN
	1    4100 5850
	-1   0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q6
U 1 1 5A47619D
P 3500 5850
AR Path="/5A51075D/5A47619D" Ref="Q6"  Part="1" 
AR Path="/5A5113FC/5A47619D" Ref="Q19"  Part="1" 
F 0 "Q19" H 3700 5900 50  0000 L CNN
F 1 "2N3904" H 3700 5800 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 3700 5950 50  0001 C CNN
F 3 "" H 3500 5850 50  0001 C CNN
	1    3500 5850
	1    0    0    -1  
$EndComp
$Comp
L Q_NPN_EBC Q8
U 1 1 5A476A83
P 4400 2400
AR Path="/5A51075D/5A476A83" Ref="Q8"  Part="1" 
AR Path="/5A5113FC/5A476A83" Ref="Q21"  Part="1" 
F 0 "Q21" H 4600 2450 50  0000 L CNN
F 1 "2N3904" H 4600 2350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4600 2500 50  0001 C CNN
F 3 "" H 4400 2400 50  0001 C CNN
	1    4400 2400
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5A476D6D
P 4500 1850
AR Path="/5A51075D/5A476D6D" Ref="R11"  Part="1" 
AR Path="/5A5113FC/5A476D6D" Ref="R26"  Part="1" 
F 0 "R26" V 4580 1850 50  0000 C CNN
F 1 "1K" V 4500 1850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 4430 1850 50  0001 C CNN
F 3 "" H 4500 1850 50  0001 C CNN
	1    4500 1850
	-1   0    0    1   
$EndComp
$Comp
L R R9
U 1 1 5A476F5F
P 4200 2700
AR Path="/5A51075D/5A476F5F" Ref="R9"  Part="1" 
AR Path="/5A5113FC/5A476F5F" Ref="R24"  Part="1" 
F 0 "R24" V 4280 2700 50  0000 C CNN
F 1 "10K" V 4200 2700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 4130 2700 50  0001 C CNN
F 3 "" H 4200 2700 50  0001 C CNN
	1    4200 2700
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5A476191
P 3800 5200
AR Path="/5A51075D/5A476191" Ref="R8"  Part="1" 
AR Path="/5A5113FC/5A476191" Ref="R23"  Part="1" 
F 0 "R23" V 3880 5200 50  0000 C CNN
F 1 "10K" V 3800 5200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 3730 5200 50  0001 C CNN
F 3 "" H 3800 5200 50  0001 C CNN
	1    3800 5200
	1    0    0    1   
$EndComp
$Comp
L R R4
U 1 1 5A4755E8
P 2100 5200
AR Path="/5A51075D/5A4755E8" Ref="R4"  Part="1" 
AR Path="/5A5113FC/5A4755E8" Ref="R19"  Part="1" 
F 0 "R19" V 2180 5200 50  0000 C CNN
F 1 "10K" V 2100 5200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 2030 5200 50  0001 C CNN
F 3 "" H 2100 5200 50  0001 C CNN
	1    2100 5200
	-1   0    0    1   
$EndComp
Text Label 2950 3450 0    60   ~ 0
DVG
Text Label 2300 1600 0    60   ~ 0
DVSW
Text Label 2900 2100 0    60   ~ 0
MFB
Text Label 2950 3950 0    60   ~ 0
MFF
Text Label 3850 3950 0    60   ~ 0
MBF
Text Label 4500 1600 0    60   ~ 0
DVSW
Text Label 1650 1000 0    60   ~ 0
DVG
$Comp
L Conn_01x05 J1
U 1 1 5A480F71
P 850 1100
AR Path="/5A51075D/5A480F71" Ref="J1"  Part="1" 
AR Path="/5A5113FC/5A480F71" Ref="J8"  Part="1" 
F 0 "J8" H 850 1400 50  0000 C CNN
F 1 "Conn_01x05" H 850 800 50  0000 C CNN
F 2 "Connectors_JST:JST_XH_B05B-XH-A_05x2.50mm_Straight" H 850 1100 50  0001 C CNN
F 3 "" H 850 1100 50  0001 C CNN
	1    850  1100
	-1   0    0    1   
$EndComp
Text Label 1650 900  0    60   ~ 0
DVSW
Text Label 1450 1200 0    60   ~ 0
Dir
Text Label 1450 1300 0    60   ~ 0
Speed
Text Label 1000 2400 0    60   ~ 0
Dir
Text Label 3300 2400 0    60   ~ 0
Speed
Text Label 5050 2100 0    60   ~ 0
iSpeed
Text Label 2650 5850 0    60   ~ 0
iSpeed
Text Label 6600 2050 0    60   ~ 0
MFF
Text Label 9050 2050 0    60   ~ 0
MBF
Text Label 1500 5850 0    60   ~ 0
MBB
Text Label 2100 4950 0    60   ~ 0
DVG
Text Label 3800 5000 0    60   ~ 0
DVG
$Comp
L GND #PWR20
U 1 1 5A486E99
P 3850 4450
AR Path="/5A51075D/5A486E99" Ref="#PWR20"  Part="1" 
AR Path="/5A5113FC/5A486E99" Ref="#PWR36"  Part="1" 
F 0 "#PWR36" H 3850 4200 50  0001 C CNN
F 1 "GND" H 3850 4300 50  0000 C CNN
F 2 "" H 3850 4450 50  0001 C CNN
F 3 "" H 3850 4450 50  0001 C CNN
	1    3850 4450
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR14
U 1 1 5A487094
P 1600 1100
AR Path="/5A51075D/5A487094" Ref="#PWR14"  Part="1" 
AR Path="/5A5113FC/5A487094" Ref="#PWR30"  Part="1" 
F 0 "#PWR30" H 1600 850 50  0001 C CNN
F 1 "GND" H 1600 950 50  0000 C CNN
F 2 "" H 1600 1100 50  0001 C CNN
F 3 "" H 1600 1100 50  0001 C CNN
	1    1600 1100
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR22
U 1 1 5A48AB2B
P 6100 2050
AR Path="/5A51075D/5A48AB2B" Ref="#PWR22"  Part="1" 
AR Path="/5A5113FC/5A48AB2B" Ref="#PWR38"  Part="1" 
F 0 "#PWR38" H 6100 1800 50  0001 C CNN
F 1 "GND" H 6100 1900 50  0000 C CNN
F 2 "" H 6100 2050 50  0001 C CNN
F 3 "" H 6100 2050 50  0001 C CNN
	1    6100 2050
	0    1    1    0   
$EndComp
$Comp
L GND #PWR21
U 1 1 5A48AF8D
P 4500 2850
AR Path="/5A51075D/5A48AF8D" Ref="#PWR21"  Part="1" 
AR Path="/5A5113FC/5A48AF8D" Ref="#PWR37"  Part="1" 
F 0 "#PWR37" H 4500 2600 50  0001 C CNN
F 1 "GND" H 4500 2700 50  0000 C CNN
F 2 "" H 4500 2850 50  0001 C CNN
F 3 "" H 4500 2850 50  0001 C CNN
	1    4500 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR19
U 1 1 5A48B2CF
P 3800 6250
AR Path="/5A51075D/5A48B2CF" Ref="#PWR19"  Part="1" 
AR Path="/5A5113FC/5A48B2CF" Ref="#PWR35"  Part="1" 
F 0 "#PWR35" H 3800 6000 50  0001 C CNN
F 1 "GND" H 3800 6100 50  0000 C CNN
F 2 "" H 3800 6250 50  0001 C CNN
F 3 "" H 3800 6250 50  0001 C CNN
	1    3800 6250
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR16
U 1 1 5A48B626
P 2100 6250
AR Path="/5A51075D/5A48B626" Ref="#PWR16"  Part="1" 
AR Path="/5A5113FC/5A48B626" Ref="#PWR32"  Part="1" 
F 0 "#PWR32" H 2100 6000 50  0001 C CNN
F 1 "GND" H 2100 6100 50  0000 C CNN
F 2 "" H 2100 6250 50  0001 C CNN
F 3 "" H 2100 6250 50  0001 C CNN
	1    2100 6250
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5A47C7D6
P 3700 2400
AR Path="/5A51075D/5A47C7D6" Ref="R7"  Part="1" 
AR Path="/5A5113FC/5A47C7D6" Ref="R22"  Part="1" 
F 0 "R22" V 3780 2400 50  0000 C CNN
F 1 "10K" V 3700 2400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 3630 2400 50  0001 C CNN
F 3 "" H 3700 2400 50  0001 C CNN
	1    3700 2400
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5A47E69F
P 1450 2400
AR Path="/5A51075D/5A47E69F" Ref="R1"  Part="1" 
AR Path="/5A5113FC/5A47E69F" Ref="R16"  Part="1" 
F 0 "R16" V 1530 2400 50  0000 C CNN
F 1 "10K" V 1450 2400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 1380 2400 50  0001 C CNN
F 3 "" H 1450 2400 50  0001 C CNN
	1    1450 2400
	0    1    1    0   
$EndComp
$Comp
L GND #PWR17
U 1 1 5A48006F
P 2300 2800
AR Path="/5A51075D/5A48006F" Ref="#PWR17"  Part="1" 
AR Path="/5A5113FC/5A48006F" Ref="#PWR33"  Part="1" 
F 0 "#PWR33" H 2300 2550 50  0001 C CNN
F 1 "GND" H 2300 2650 50  0000 C CNN
F 2 "" H 2300 2800 50  0001 C CNN
F 3 "" H 2300 2800 50  0001 C CNN
	1    2300 2800
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 5A480680
P 2050 2700
AR Path="/5A51075D/5A480680" Ref="R3"  Part="1" 
AR Path="/5A5113FC/5A480680" Ref="R18"  Part="1" 
F 0 "R18" V 2130 2700 50  0000 C CNN
F 1 "10K" V 2050 2700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 1980 2700 50  0001 C CNN
F 3 "" H 2050 2700 50  0001 C CNN
	1    2050 2700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR18
U 1 1 5A483B3C
P 2950 4450
AR Path="/5A51075D/5A483B3C" Ref="#PWR18"  Part="1" 
AR Path="/5A5113FC/5A483B3C" Ref="#PWR34"  Part="1" 
F 0 "#PWR34" H 2950 4200 50  0001 C CNN
F 1 "GND" H 2950 4300 50  0000 C CNN
F 2 "" H 2950 4450 50  0001 C CNN
F 3 "" H 2950 4450 50  0001 C CNN
	1    2950 4450
	1    0    0    -1  
$EndComp
Text Label 2550 4200 0    60   ~ 0
MFB
Text Label 3450 4200 0    60   ~ 0
MBB
Text Label 3850 3450 0    60   ~ 0
DVG
Text Label 4300 5850 0    60   ~ 0
iSpeed
Text Label 3200 5850 0    60   ~ 0
MFB
Text Label 2200 5400 0    60   ~ 0
BBM
Text Label 3900 5400 0    60   ~ 0
FBM
Text Label 6600 2650 0    60   ~ 0
BBM
Text Label 9050 2650 0    60   ~ 0
FBM
$Comp
L D D1
U 1 1 5A490C2E
P 1450 900
AR Path="/5A51075D/5A490C2E" Ref="D1"  Part="1" 
AR Path="/5A5113FC/5A490C2E" Ref="D9"  Part="1" 
F 0 "D9" H 1450 1000 50  0000 C CNN
F 1 "1N4007" H 1450 800 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 1450 900 50  0001 C CNN
F 3 "" H 1450 900 50  0001 C CNN
	1    1450 900 
	-1   0    0    1   
$EndComp
$Comp
L D D2
U 1 1 5A491143
P 1450 1000
AR Path="/5A51075D/5A491143" Ref="D2"  Part="1" 
AR Path="/5A5113FC/5A491143" Ref="D10"  Part="1" 
F 0 "D10" H 1450 1100 50  0000 C CNN
F 1 "1N4007" H 1450 900 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 1450 1000 50  0001 C CNN
F 3 "" H 1450 1000 50  0001 C CNN
	1    1450 1000
	-1   0    0    1   
$EndComp
$Comp
L D D3
U 1 1 5A4912D7
P 1250 1200
AR Path="/5A51075D/5A4912D7" Ref="D3"  Part="1" 
AR Path="/5A5113FC/5A4912D7" Ref="D11"  Part="1" 
F 0 "D11" H 1250 1300 50  0000 C CNN
F 1 "1N4007" H 1250 1100 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 1250 1200 50  0001 C CNN
F 3 "" H 1250 1200 50  0001 C CNN
	1    1250 1200
	-1   0    0    1   
$EndComp
$Comp
L D D4
U 1 1 5A491371
P 1250 1300
AR Path="/5A51075D/5A491371" Ref="D4"  Part="1" 
AR Path="/5A5113FC/5A491371" Ref="D12"  Part="1" 
F 0 "D12" H 1250 1400 50  0000 C CNN
F 1 "1N4007" H 1250 1200 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 1250 1300 50  0001 C CNN
F 3 "" H 1250 1300 50  0001 C CNN
	1    1250 1300
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 5A49A43A
P 1700 3700
AR Path="/5A51075D/5A49A43A" Ref="R2"  Part="1" 
AR Path="/5A5113FC/5A49A43A" Ref="R17"  Part="1" 
F 0 "R17" V 1780 3700 50  0000 C CNN
F 1 "1K" V 1700 3700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 1630 3700 50  0001 C CNN
F 3 "" H 1700 3700 50  0001 C CNN
	1    1700 3700
	-1   0    0    1   
$EndComp
$Comp
L Q_NPN_EBC Q2
U 1 1 5A49A440
P 1600 4200
AR Path="/5A51075D/5A49A440" Ref="Q2"  Part="1" 
AR Path="/5A5113FC/5A49A440" Ref="Q15"  Part="1" 
F 0 "Q15" H 1800 4250 50  0000 L CNN
F 1 "2N3904" H 1800 4150 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 1800 4300 50  0001 C CNN
F 3 "" H 1600 4200 50  0001 C CNN
	1    1600 4200
	1    0    0    -1  
$EndComp
Text Label 1700 3450 0    60   ~ 0
DVSW
Text Label 2250 3900 0    60   ~ 0
MBB
$Comp
L GND #PWR15
U 1 1 5A49A448
P 1700 4450
AR Path="/5A51075D/5A49A448" Ref="#PWR15"  Part="1" 
AR Path="/5A5113FC/5A49A448" Ref="#PWR31"  Part="1" 
F 0 "#PWR31" H 1700 4200 50  0001 C CNN
F 1 "GND" H 1700 4300 50  0000 C CNN
F 2 "" H 1700 4450 50  0001 C CNN
F 3 "" H 1700 4450 50  0001 C CNN
	1    1700 4450
	1    0    0    -1  
$EndComp
Text Label 1300 4200 0    60   ~ 0
MFB
$Comp
L GND #PWR24
U 1 1 5A49B5D8
P 6100 2650
AR Path="/5A51075D/5A49B5D8" Ref="#PWR24"  Part="1" 
AR Path="/5A5113FC/5A49B5D8" Ref="#PWR40"  Part="1" 
F 0 "#PWR40" H 6100 2400 50  0001 C CNN
F 1 "GND" H 6100 2500 50  0000 C CNN
F 2 "" H 6100 2650 50  0001 C CNN
F 3 "" H 6100 2650 50  0001 C CNN
	1    6100 2650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR28
U 1 1 5A49C0C4
P 9600 2650
AR Path="/5A51075D/5A49C0C4" Ref="#PWR28"  Part="1" 
AR Path="/5A5113FC/5A49C0C4" Ref="#PWR44"  Part="1" 
F 0 "#PWR44" H 9600 2400 50  0001 C CNN
F 1 "GND" H 9600 2500 50  0000 C CNN
F 2 "" H 9600 2650 50  0001 C CNN
F 3 "" H 9600 2650 50  0001 C CNN
	1    9600 2650
	0    -1   -1   0   
$EndComp
Text HLabel 10650 1100 0    60   BiDi ~ 0
VGND
Text HLabel 10650 900  0    60   Input ~ 0
VBAT
$Comp
L GND #PWR25
U 1 1 5A48AC9F
P 7850 3000
AR Path="/5A51075D/5A48AC9F" Ref="#PWR25"  Part="1" 
AR Path="/5A5113FC/5A48AC9F" Ref="#PWR41"  Part="1" 
F 0 "#PWR41" H 7850 2750 50  0001 C CNN
F 1 "GND" H 7850 2850 50  0000 C CNN
F 2 "" H 7850 3000 50  0001 C CNN
F 3 "" H 7850 3000 50  0001 C CNN
	1    7850 3000
	1    0    0    -1  
$EndComp
Text Label 7750 1150 0    60   ~ 0
VBAT
$Comp
L GND #PWR29
U 1 1 5A514B63
P 10800 1100
AR Path="/5A51075D/5A514B63" Ref="#PWR29"  Part="1" 
AR Path="/5A5113FC/5A514B63" Ref="#PWR45"  Part="1" 
F 0 "#PWR45" H 10800 850 50  0001 C CNN
F 1 "GND" H 10800 950 50  0000 C CNN
F 2 "" H 10800 1100 50  0001 C CNN
F 3 "" H 10800 1100 50  0001 C CNN
	1    10800 1100
	0    -1   -1   0   
$EndComp
Text Label 10800 900  0    60   ~ 0
VBAT
Text Label 7400 2350 0    60   ~ 0
VF
Text Label 8300 2350 0    60   ~ 0
VB
Text Label 1800 2400 0    60   ~ 0
DirSel
Text Label 3950 2400 0    60   ~ 0
SpeedSel
Text HLabel 10650 800  0    60   Input ~ 0
VG
Text HLabel 10650 700  0    60   Input ~ 0
VSW
Text Label 10800 700  0    60   ~ 0
VSW
Text Label 10800 800  0    60   ~ 0
VG
Text Label 7850 1800 0    60   ~ 0
VFUSE
Text HLabel 10650 1000 0    60   BiDi ~ 0
VFUSE
Text Label 10800 1000 0    60   ~ 0
VFUSE
Text Label 1150 700  0    60   ~ 0
VSW
Text Label 1100 1000 0    60   ~ 0
VG
$Comp
L Polyfuse F6
U 1 1 5A528AA6
P 8550 1400
AR Path="/5A51075D/5A528AA6" Ref="F6"  Part="1" 
AR Path="/5A5113FC/5A528AA6" Ref="F11"  Part="1" 
F 0 "F11" V 8450 1400 50  0000 C CNN
F 1 "Polyfuse" V 8650 1400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 8600 1200 50  0001 L CNN
F 3 "" H 8550 1400 50  0001 C CNN
	1    8550 1400
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F5
U 1 1 5A528B6D
P 8200 1400
AR Path="/5A51075D/5A528B6D" Ref="F5"  Part="1" 
AR Path="/5A5113FC/5A528B6D" Ref="F10"  Part="1" 
F 0 "F10" V 8100 1400 50  0000 C CNN
F 1 "Polyfuse" V 8300 1400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 8250 1200 50  0001 L CNN
F 3 "" H 8200 1400 50  0001 C CNN
	1    8200 1400
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F4
U 1 1 5A528C16
P 7850 1400
AR Path="/5A51075D/5A528C16" Ref="F4"  Part="1" 
AR Path="/5A5113FC/5A528C16" Ref="F9"  Part="1" 
F 0 "F9" V 7750 1400 50  0000 C CNN
F 1 "Polyfuse" V 7950 1400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 7900 1200 50  0001 L CNN
F 3 "" H 7850 1400 50  0001 C CNN
	1    7850 1400
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F3
U 1 1 5A528CBA
P 7500 1400
AR Path="/5A51075D/5A528CBA" Ref="F3"  Part="1" 
AR Path="/5A5113FC/5A528CBA" Ref="F8"  Part="1" 
F 0 "F8" V 7400 1400 50  0000 C CNN
F 1 "Polyfuse" V 7600 1400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 7550 1200 50  0001 L CNN
F 3 "" H 7500 1400 50  0001 C CNN
	1    7500 1400
	1    0    0    -1  
$EndComp
$Comp
L Polyfuse F2
U 1 1 5A528DFC
P 7150 1400
AR Path="/5A51075D/5A528DFC" Ref="F2"  Part="1" 
AR Path="/5A5113FC/5A528DFC" Ref="F7"  Part="1" 
F 0 "F7" V 7050 1400 50  0000 C CNN
F 1 "Polyfuse" V 7250 1400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" H 7200 1200 50  0001 L CNN
F 3 "" H 7150 1400 50  0001 C CNN
	1    7150 1400
	1    0    0    -1  
$EndComp
$Comp
L R R37
U 1 1 5A528A36
P 4950 2450
AR Path="/5A51075D/5A528A36" Ref="R37"  Part="1" 
AR Path="/5A5113FC/5A528A36" Ref="R40"  Part="1" 
F 0 "R40" V 5030 2450 50  0000 C CNN
F 1 "10K" V 4950 2450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 4880 2450 50  0001 C CNN
F 3 "" H 4950 2450 50  0001 C CNN
	1    4950 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3850 4000 3850 3850
Wire Wire Line
	3850 3550 3850 3450
Wire Wire Line
	2950 3850 2950 4000
Wire Wire Line
	2950 3450 2950 3550
Wire Wire Line
	2300 2000 2300 2200
Wire Wire Line
	2300 2600 2300 2800
Wire Wire Line
	7500 1100 7500 1250
Wire Wire Line
	8200 1100 8200 1250
Wire Wire Line
	7150 1150 8550 1150
Connection ~ 8200 1150
Connection ~ 7500 1150
Connection ~ 7850 1150
Wire Wire Line
	7150 1250 7150 1150
Wire Wire Line
	8550 1150 8550 1250
Wire Wire Line
	7150 1550 7150 1650
Wire Wire Line
	7150 1650 8550 1650
Wire Wire Line
	8550 1650 8550 1550
Wire Wire Line
	8200 1550 8200 1650
Connection ~ 8200 1650
Connection ~ 7850 1650
Wire Wire Line
	7500 1550 7500 1650
Connection ~ 7500 1650
Wire Wire Line
	7400 2200 7400 2500
Wire Wire Line
	8300 2200 8300 2500
Wire Wire Line
	7400 2800 7400 3050
Wire Wire Line
	7000 2900 8700 2900
Wire Wire Line
	8300 2800 8300 3050
Wire Wire Line
	8300 1800 8300 1900
Wire Wire Line
	7000 1800 8700 1800
Wire Wire Line
	7400 1800 7400 1900
Connection ~ 7850 1800
Wire Wire Line
	8200 2350 9200 2350
Connection ~ 8300 2350
Connection ~ 7400 2350
Wire Wire Line
	7000 1850 7000 1800
Connection ~ 7400 1800
Wire Wire Line
	8700 1800 8700 1850
Connection ~ 8300 1800
Wire Wire Line
	8700 2250 8700 2450
Connection ~ 8700 2350
Wire Wire Line
	8700 2900 8700 2850
Connection ~ 8300 2900
Wire Wire Line
	7000 2850 7000 2900
Connection ~ 7400 2900
Wire Wire Line
	7000 2250 7000 2450
Connection ~ 7000 2350
Wire Wire Line
	9500 2050 9600 2050
Connection ~ 7850 2900
Wire Wire Line
	1900 5650 1900 5550
Wire Wire Line
	1900 5550 2300 5550
Wire Wire Line
	2300 5550 2300 5650
Wire Wire Line
	1900 6050 1900 6150
Wire Wire Line
	1900 6150 2300 6150
Wire Wire Line
	2300 6150 2300 6050
Wire Wire Line
	2100 6250 2100 6150
Connection ~ 2100 6150
Wire Wire Line
	2100 5350 2100 5550
Connection ~ 2100 5550
Wire Wire Line
	4000 5550 4000 5650
Wire Wire Line
	3600 5550 4000 5550
Wire Wire Line
	3600 5550 3600 5650
Wire Wire Line
	4000 6150 4000 6050
Wire Wire Line
	3600 6150 4000 6150
Wire Wire Line
	3600 6150 3600 6050
Wire Wire Line
	3800 6250 3800 6150
Connection ~ 3800 6150
Wire Wire Line
	3800 5350 3800 5550
Connection ~ 3800 5550
Wire Wire Line
	4500 2600 4500 2850
Wire Wire Line
	4500 2000 4500 2200
Wire Wire Line
	3300 2400 3550 2400
Wire Wire Line
	3300 5850 3200 5850
Wire Wire Line
	4500 1700 4500 1600
Wire Wire Line
	1000 2400 1300 2400
Connection ~ 4500 2100
Wire Wire Line
	1600 2400 2000 2400
Wire Wire Line
	3850 2400 4200 2400
Wire Wire Line
	4500 2100 5050 2100
Wire Wire Line
	2950 4400 2950 4450
Wire Wire Line
	3850 4450 3850 4400
Wire Wire Line
	3550 4200 3450 4200
Wire Wire Line
	1800 2400 1800 2700
Connection ~ 1800 2400
Wire Wire Line
	2200 2700 2750 2700
Connection ~ 2300 2700
Wire Wire Line
	1800 2700 1900 2700
Wire Wire Line
	4350 2700 4950 2700
Connection ~ 4500 2700
Wire Wire Line
	4050 2700 3950 2700
Wire Wire Line
	3950 2700 3950 2400
Connection ~ 3950 2400
Wire Wire Line
	2300 1700 2300 1600
Wire Wire Line
	2300 2100 2900 2100
Connection ~ 2300 2100
Wire Wire Line
	2650 4200 2550 4200
Wire Wire Line
	1600 5850 1500 5850
Wire Wire Line
	2100 5050 2100 4950
Wire Wire Line
	2600 5850 2650 5850
Wire Wire Line
	4300 5850 4300 5850
Wire Wire Line
	3800 5050 3800 5000
Wire Wire Line
	3800 5400 3900 5400
Connection ~ 3800 5400
Wire Wire Line
	2100 5400 2200 5400
Connection ~ 2100 5400
Wire Wire Line
	1600 900  1650 900 
Wire Wire Line
	1650 1000 1600 1000
Wire Wire Line
	1400 1200 1450 1200
Wire Wire Line
	1400 1300 1450 1300
Wire Wire Line
	1100 1300 1050 1300
Wire Wire Line
	1050 1200 1100 1200
Wire Wire Line
	1050 1000 1300 1000
Wire Wire Line
	1050 900  1300 900 
Wire Wire Line
	1050 1100 1600 1100
Wire Wire Line
	1700 3850 1700 4000
Wire Wire Line
	1700 3550 1700 3450
Wire Wire Line
	1700 4400 1700 4450
Wire Wire Line
	1400 4200 1300 4200
Wire Wire Line
	6100 2650 6200 2650
Wire Wire Line
	6200 2050 6100 2050
Wire Wire Line
	9000 2650 9200 2650
Wire Wire Line
	9500 2650 9600 2650
Wire Wire Line
	6500 2650 6700 2650
Wire Wire Line
	6500 2050 6700 2050
Wire Wire Line
	9000 2050 9200 2050
Wire Wire Line
	7850 1150 7850 1250
Wire Wire Line
	7850 2900 7850 3000
Wire Wire Line
	10650 900  10800 900 
Wire Wire Line
	10800 1100 10650 1100
Wire Wire Line
	10800 700  10650 700 
Wire Wire Line
	10800 800  10650 800 
Wire Wire Line
	7850 1550 7850 1800
Wire Wire Line
	10800 1000 10650 1000
Wire Wire Line
	1150 700  1150 900 
Connection ~ 1150 900 
Wire Wire Line
	4950 2300 4950 2100
Connection ~ 4950 2100
Wire Wire Line
	4950 2700 4950 2600
$Comp
L R R36
U 1 1 5A52976F
P 2750 2450
AR Path="/5A51075D/5A52976F" Ref="R36"  Part="1" 
AR Path="/5A5113FC/5A52976F" Ref="R39"  Part="1" 
F 0 "R39" V 2830 2450 50  0000 C CNN
F 1 "10K" V 2750 2450 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 2680 2450 50  0001 C CNN
F 3 "" H 2750 2450 50  0001 C CNN
	1    2750 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	2750 2300 2750 2100
Connection ~ 2750 2100
Wire Wire Line
	2750 2700 2750 2600
$Comp
L R R35
U 1 1 5A52B30D
P 2150 4200
AR Path="/5A51075D/5A52B30D" Ref="R35"  Part="1" 
AR Path="/5A5113FC/5A52B30D" Ref="R38"  Part="1" 
F 0 "R38" V 2230 4200 50  0000 C CNN
F 1 "10K" V 2150 4200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 2080 4200 50  0001 C CNN
F 3 "" H 2150 4200 50  0001 C CNN
	1    2150 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 4350 2150 4450
Wire Wire Line
	2150 4450 1700 4450
Wire Wire Line
	1700 3900 2250 3900
Wire Wire Line
	2150 3900 2150 4050
Connection ~ 1700 3900
Connection ~ 2150 3900
$Comp
L CP1 C7
U 1 1 5A52BEF2
P 9350 2350
AR Path="/5A51075D/5A52BEF2" Ref="C7"  Part="1" 
AR Path="/5A5113FC/5A52BEF2" Ref="C9"  Part="1" 
F 0 "C9" H 9375 2450 50  0000 L CNN
F 1 "1200uF" H 9375 2250 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D12.0mm_W4.4mm_P7.75mm" H 9350 2350 50  0001 C CNN
F 3 "" H 9350 2350 50  0001 C CNN
	1    9350 2350
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR27
U 1 1 5A52BFED
P 9600 2350
AR Path="/5A51075D/5A52BFED" Ref="#PWR27"  Part="1" 
AR Path="/5A5113FC/5A52BFED" Ref="#PWR43"  Part="1" 
F 0 "#PWR43" H 9600 2100 50  0001 C CNN
F 1 "GND" H 9600 2200 50  0000 C CNN
F 2 "" H 9600 2350 50  0001 C CNN
F 3 "" H 9600 2350 50  0001 C CNN
	1    9600 2350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9600 2350 9500 2350
$Comp
L CP1 C6
U 1 1 5A52C52D
P 6350 2350
AR Path="/5A51075D/5A52C52D" Ref="C6"  Part="1" 
AR Path="/5A5113FC/5A52C52D" Ref="C8"  Part="1" 
F 0 "C8" H 6375 2450 50  0000 L CNN
F 1 "1200uF" H 6375 2250 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D12.0mm_W4.4mm_P7.75mm" H 6350 2350 50  0001 C CNN
F 3 "" H 6350 2350 50  0001 C CNN
	1    6350 2350
	0    1    1    0   
$EndComp
$Comp
L GND #PWR23
U 1 1 5A52C533
P 6100 2350
AR Path="/5A51075D/5A52C533" Ref="#PWR23"  Part="1" 
AR Path="/5A5113FC/5A52C533" Ref="#PWR39"  Part="1" 
F 0 "#PWR39" H 6100 2100 50  0001 C CNN
F 1 "GND" H 6100 2200 50  0000 C CNN
F 2 "" H 6100 2350 50  0001 C CNN
F 3 "" H 6100 2350 50  0001 C CNN
	1    6100 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	6100 2350 6200 2350
Wire Wire Line
	6500 2350 7500 2350
$EndSCHEMATC
