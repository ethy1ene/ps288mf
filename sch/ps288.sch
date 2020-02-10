EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5E4114F4
P 3850 3550
F 0 "A1" H 3850 2461 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 3850 2370 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 4000 2600 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 3850 2550 50  0001 C CNN
	1    3850 3550
	1    0    0    -1  
$EndComp
$Comp
L Connector:Mini-DIN-6 J1
U 1 1 5E412EE1
P 1650 3000
F 0 "J1" H 1650 3367 50  0000 C CNN
F 1 "Mini-DIN-6" H 1650 3276 50  0000 C CNN
F 2 "Connector_DIN:mdin6" H 1650 3000 50  0001 C CNN
F 3 "http://service.powerdynamics.com/ec/Catalog17/Section%2011.pdf" H 1650 3000 50  0001 C CNN
	1    1650 3000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0101
U 1 1 5E42AF9A
P 2300 3900
F 0 "#PWR0101" H 2300 3750 50  0001 C CNN
F 1 "+5V" V 2315 4028 50  0000 L CNN
F 2 "" H 2300 3900 50  0001 C CNN
F 3 "" H 2300 3900 50  0001 C CNN
	1    2300 3900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5E42BC91
P 2300 3800
F 0 "#PWR0102" H 2300 3550 50  0001 C CNN
F 1 "GND" V 2305 3672 50  0000 R CNN
F 2 "" H 2300 3800 50  0001 C CNN
F 3 "" H 2300 3800 50  0001 C CNN
	1    2300 3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1950 2900 2800 2900
Wire Wire Line
	2800 2900 2800 3250
Wire Wire Line
	2800 3250 3350 3250
Wire Wire Line
	1950 3100 2750 3100
Wire Wire Line
	2750 3100 2750 3350
Wire Wire Line
	2750 3350 3350 3350
$Comp
L power:GND #PWR0103
U 1 1 5E42F614
P 1950 3000
F 0 "#PWR0103" H 1950 2750 50  0001 C CNN
F 1 "GND" V 1955 2872 50  0000 R CNN
F 2 "" H 1950 3000 50  0001 C CNN
F 3 "" H 1950 3000 50  0001 C CNN
	1    1950 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5E42FC5F
P 1350 3000
F 0 "#PWR0104" H 1350 2850 50  0001 C CNN
F 1 "+5V" V 1365 3128 50  0000 L CNN
F 2 "" H 1350 3000 50  0001 C CNN
F 3 "" H 1350 3000 50  0001 C CNN
	1    1350 3000
	0    -1   -1   0   
$EndComp
NoConn ~ 3350 2950
NoConn ~ 3350 3050
NoConn ~ 3350 3150
NoConn ~ 3350 3450
NoConn ~ 3350 3650
NoConn ~ 3350 3750
NoConn ~ 3350 3850
NoConn ~ 3350 3950
NoConn ~ 3350 4050
NoConn ~ 3350 4150
NoConn ~ 3350 4250
NoConn ~ 4350 4250
NoConn ~ 4350 3550
NoConn ~ 4350 3650
NoConn ~ 4350 3750
NoConn ~ 4350 3850
NoConn ~ 4350 3950
NoConn ~ 4350 4050
NoConn ~ 4350 4150
NoConn ~ 4350 3350
NoConn ~ 4350 3050
NoConn ~ 4350 2950
NoConn ~ 3950 2550
NoConn ~ 3750 2550
$Comp
L power:+5V #PWR0105
U 1 1 5E43308B
P 4050 2550
F 0 "#PWR0105" H 4050 2400 50  0001 C CNN
F 1 "+5V" H 4065 2723 50  0000 C CNN
F 2 "" H 4050 2550 50  0001 C CNN
F 3 "" H 4050 2550 50  0001 C CNN
	1    4050 2550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5E4331ED
P 3950 4550
F 0 "#PWR0106" H 3950 4300 50  0001 C CNN
F 1 "GND" H 3955 4377 50  0000 C CNN
F 2 "" H 3950 4550 50  0001 C CNN
F 3 "" H 3950 4550 50  0001 C CNN
	1    3950 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4550 3950 4550
Connection ~ 3950 4550
$Comp
L Connector:Conn_01x03_Female J2
U 1 1 5E43883A
P 2100 3800
F 0 "J2" H 2128 3826 50  0000 L CNN
F 1 "Conn_01x03_Female" H 2128 3735 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2100 3800 50  0001 C CNN
F 3 "~" H 2100 3800 50  0001 C CNN
	1    2100 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	2300 3700 3050 3700
Wire Wire Line
	3050 3700 3050 3550
Wire Wire Line
	3050 3550 3350 3550
$Comp
L Device:CP1 C1
U 1 1 5E441F62
P 5700 2650
F 0 "C1" H 5815 2696 50  0000 L CNN
F 1 "CP1" H 5815 2605 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P1.50mm" H 5700 2650 50  0001 C CNN
F 3 "~" H 5700 2650 50  0001 C CNN
	1    5700 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E442740
P 6100 2650
F 0 "C2" H 6215 2696 50  0000 L CNN
F 1 "C" H 6215 2605 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 6138 2500 50  0001 C CNN
F 3 "~" H 6100 2650 50  0001 C CNN
	1    6100 2650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0107
U 1 1 5E442BF3
P 5700 2500
F 0 "#PWR0107" H 5700 2350 50  0001 C CNN
F 1 "+5V" H 5715 2673 50  0000 C CNN
F 2 "" H 5700 2500 50  0001 C CNN
F 3 "" H 5700 2500 50  0001 C CNN
	1    5700 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5E4434DD
P 5700 2800
F 0 "#PWR0108" H 5700 2550 50  0001 C CNN
F 1 "GND" H 5705 2627 50  0000 C CNN
F 2 "" H 5700 2800 50  0001 C CNN
F 3 "" H 5700 2800 50  0001 C CNN
	1    5700 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 2500 6100 2500
Connection ~ 5700 2500
Wire Wire Line
	6100 2800 5700 2800
Connection ~ 5700 2800
$EndSCHEMATC
