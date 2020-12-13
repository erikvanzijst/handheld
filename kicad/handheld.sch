EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title "Handheld gaming device"
Date "2020-07-25"
Rev "v0.2"
Comp ""
Comment1 ""
Comment2 ""
Comment3 "Email: erik.van.zijst@gmail.com"
Comment4 "Author: Erik van Zijst"
$EndDescr
$Comp
L Device:C C4
U 1 1 5EFA155D
P 4600 6675
F 0 "C4" V 4348 6675 50  0000 C CNN
F 1 "100nF" V 4439 6675 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4638 6525 50  0001 C CNN
F 3 "~" H 4600 6675 50  0001 C CNN
	1    4600 6675
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR07
U 1 1 5EE456DF
P 3125 1750
F 0 "#PWR07" H 3125 1600 50  0001 C CNN
F 1 "VDD" H 3142 1923 50  0000 C CNN
F 2 "" H 3125 1750 50  0001 C CNN
F 3 "" H 3125 1750 50  0001 C CNN
	1    3125 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5F1E6F61
P 4750 6675
F 0 "#PWR012" H 4750 6425 50  0001 C CNN
F 1 "GND" V 4755 6547 50  0000 R CNN
F 2 "" H 4750 6675 50  0001 C CNN
F 3 "" H 4750 6675 50  0001 C CNN
	1    4750 6675
	0    -1   -1   0   
$EndComp
$Comp
L Graphic:Logo_Open_Hardware_Large #LOGO1
U 1 1 5EE98802
P 1275 7200
F 0 "#LOGO1" H 1275 7700 50  0001 C CNN
F 1 "Logo_Open_Hardware_Large" H 1275 6800 50  0001 C CNN
F 2 "" H 1275 7200 50  0001 C CNN
F 3 "~" H 1275 7200 50  0001 C CNN
	1    1275 7200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 5F8DFF39
P 4200 6675
F 0 "C3" V 3948 6675 50  0000 C CNN
F 1 "100nF" V 4039 6675 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 6525 50  0001 C CNN
F 3 "~" H 4200 6675 50  0001 C CNN
	1    4200 6675
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5F8DFF43
P 4050 6675
F 0 "#PWR010" H 4050 6425 50  0001 C CNN
F 1 "GND" V 4055 6547 50  0000 R CNN
F 2 "" H 4050 6675 50  0001 C CNN
F 3 "" H 4050 6675 50  0001 C CNN
	1    4050 6675
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 6475 4450 6675
Wire Wire Line
	4350 6475 4350 6675
Wire Wire Line
	4450 7525 4450 7475
$Comp
L Connector:AVR-PDI-6 J3
U 1 1 5FDFDAE0
P 6525 6175
F 0 "J3" H 6195 6221 50  0000 R CNN
F 1 "AVR-PDI-6" H 6195 6130 50  0000 R CNN
F 2 "local:AVR_PDI_Header_2x03_P2.54mm_Vertical" V 6275 6125 50  0001 C CNN
F 3 " ~" H 5250 5625 50  0001 C CNN
	1    6525 6175
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6125 6175 5525 6175
Wire Wire Line
	5150 6075 6125 6075
$Comp
L power:GND #PWR013
U 1 1 5FE8EC1D
P 6625 6575
F 0 "#PWR013" H 6625 6325 50  0001 C CNN
F 1 "GND" V 6630 6447 50  0000 R CNN
F 2 "" H 6625 6575 50  0001 C CNN
F 3 "" H 6625 6575 50  0001 C CNN
	1    6625 6575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5F690054
P 4450 2875
F 0 "#PWR011" H 4450 2625 50  0001 C CNN
F 1 "GND" V 4455 2747 50  0000 R CNN
F 2 "" H 4450 2875 50  0001 C CNN
F 3 "" H 4450 2875 50  0001 C CNN
	1    4450 2875
	-1   0    0    1   
$EndComp
$Sheet
S 3475 800  1100 1450
U 5F785555
F0 "power" 50
F1 "power.sch" 50
F2 "BAT_LVL" O L 3475 2125 50 
F3 "U_PWR" O L 3475 1900 50 
F4 "VDD" O L 3475 1750 50 
F5 "USB_D-" I R 4575 2025 50 
F6 "USB_D+" I R 4575 2125 50 
F7 "BAT_CHK" O L 3475 2000 50 
$EndSheet
Wire Wire Line
	3475 2125 3325 2125
Text GLabel 2850 1750 0    50   UnSpc ~ 0
VDD
Wire Wire Line
	2850 1750 3125 1750
Text GLabel 2850 1900 0    50   UnSpc ~ 0
U_PWR
Wire Wire Line
	2850 1900 3475 1900
Connection ~ 3125 1750
$Sheet
S 9500 4225 1125 575 
U 5F613F5E
F0 "matrix" 50
F1 "matrix.sch" 50
F2 "ROW[1..16]" U L 9500 4450 50 
F3 "COL[0..23]" U L 9500 4650 50 
$EndSheet
NoConn ~ 5150 5775
NoConn ~ 5150 5875
NoConn ~ 3750 5775
$Comp
L dk_Rectangular-Connectors-Headers-Male-Pins:61300311121 J2
U 1 1 5F933175
P 2975 3975
F 0 "J2" V 2850 3975 50  0000 R CNN
F 1 "61300311121" H 3200 3775 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Horizontal" H 3175 4175 60  0001 L CNN
F 3 "https://katalog.we-online.de/em/datasheet/6130xx11121.pdf" H 3175 4275 60  0001 L CNN
F 4 "732-5316-ND" H 3175 4375 60  0001 L CNN "Digi-Key_PN"
F 5 "61300311121" H 3175 4475 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 3175 4575 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 3175 4675 60  0001 L CNN "Family"
F 8 "https://katalog.we-online.de/em/datasheet/6130xx11121.pdf" H 3175 4775 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/wurth-electronics-inc/61300311121/732-5316-ND/4846825" H 3175 4875 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER VERT 3POS 2.54MM" H 3175 4975 60  0001 L CNN "Description"
F 11 "Wurth Electronics Inc." H 3175 5075 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3175 5175 60  0001 L CNN "Status"
	1    2975 3975
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 4175 3125 4175
$Comp
L power:GND #PWR08
U 1 1 5F9AF30E
P 3125 3975
F 0 "#PWR08" H 3125 3725 50  0001 C CNN
F 1 "GND" V 3130 3847 50  0000 R CNN
F 2 "" H 3125 3975 50  0001 C CNN
F 3 "" H 3125 3975 50  0001 C CNN
	1    3125 3975
	-1   0    0    1   
$EndComp
Text Notes 2900 4200 1    50   ~ 0
UART
Wire Wire Line
	3125 1750 3475 1750
Text GLabel 4400 7525 3    50   Input ~ 0
VDD
Text GLabel 6625 5775 1    50   UnSpc ~ 0
VDD
$Sheet
S 7550 3850 1175 1100
U 6011206E
F0 "Matrix Driver" 50
F1 "matrix_driver.sch" 50
F2 "COL[0..23]" I R 8725 4650 50 
F3 "ROW[1..16]" I R 8725 4450 50 
F4 "D[0..7]" I L 7550 4875 50 
F5 "ROWSDI" I L 7550 4275 50 
F6 "LE" I L 7550 4175 50 
F7 "ROWCLK" I L 7550 4375 50 
F8 "SEGCLK0" I L 7550 4775 50 
F9 "SEGCLK1" I L 7550 4675 50 
F10 "SEGCLK2" I L 7550 4575 50 
F11 "~OE" I L 7550 4075 50 
$EndSheet
Wire Bus Line
	8725 4650 9500 4650
Wire Bus Line
	8725 4450 9500 4450
$Comp
L MCU_Microchip_ATmega:ATxmega64C3-AU U2
U 1 1 60F7F62B
P 4450 4675
F 0 "U2" H 4950 2900 50  0000 C CNN
F 1 "ATxmega64C3-AU" H 4450 4675 50  0000 C CNN
F 2 "Package_QFP:TQFP-64_14x14mm_P0.8mm" H 4450 4675 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8492-8-and-16-bit-AVR-microcontroller-ATxmega32C3_64C3_128C3_192C3_256C3_datasheet.pdf" H 4450 4675 50  0001 C CNN
	1    4450 4675
	-1   0    0    1   
$EndComp
Wire Bus Line
	7550 4875 5775 4875
Entry Wire Line
	5675 4575 5775 4475
Wire Wire Line
	5675 4575 5150 4575
Entry Wire Line
	5675 4675 5775 4575
Wire Wire Line
	5675 4675 5150 4675
Entry Wire Line
	5675 4775 5775 4675
Wire Wire Line
	5675 4775 5150 4775
Entry Wire Line
	5675 4875 5775 4775
Wire Wire Line
	5675 4875 5150 4875
Entry Wire Line
	5675 4975 5775 4875
Wire Wire Line
	5675 4975 5150 4975
Entry Wire Line
	5675 5075 5775 4975
Wire Wire Line
	5675 5075 5150 5075
Entry Wire Line
	5675 5175 5775 5075
Wire Wire Line
	5675 5175 5150 5175
Entry Wire Line
	5675 5275 5775 5175
Wire Wire Line
	5675 5275 5150 5275
Text Label 5500 5275 0    50   ~ 0
D0
Text Label 5500 5175 0    50   ~ 0
D1
Text Label 5500 5075 0    50   ~ 0
D2
Text Label 5500 4975 0    50   ~ 0
D3
Text Label 5500 4875 0    50   ~ 0
D4
Text Label 5500 4775 0    50   ~ 0
D5
Text Label 5500 4675 0    50   ~ 0
D6
Text Label 5500 4575 0    50   ~ 0
D7
Text Label 5200 3275 0    50   ~ 0
D-
Text Label 5200 3175 0    50   ~ 0
D+
Wire Wire Line
	5150 3175 5350 3175
Wire Wire Line
	4575 2125 5350 2125
Wire Wire Line
	5350 2125 5350 3175
Wire Wire Line
	4575 2025 5450 2025
Wire Wire Line
	5450 2025 5450 3275
Wire Wire Line
	5150 3275 5450 3275
Text Label 5900 4875 0    50   ~ 0
D[0..7]
Connection ~ 5775 4875
Wire Wire Line
	3125 4075 3750 4075
Text Label 3150 4175 0    50   ~ 0
RX
Text Label 3150 4075 0    50   ~ 0
TX
Wire Wire Line
	7550 4775 6250 4775
Wire Wire Line
	7550 4675 6350 4675
Wire Wire Line
	7550 4575 6450 4575
$Comp
L local:TFBS4711 U1
U 1 1 610B6C7F
P 1100 2325
F 0 "U1" H 1067 2850 50  0000 C CNN
F 1 "TFBS4711" H 1067 2759 50  0000 C CNN
F 2 "local:TFBS4711-IrDA" H 1150 2425 50  0001 C CNN
F 3 "https://www.vishay.com/docs/82633/tfbs4711.pdf" H 1150 2425 50  0001 C CNN
	1    1100 2325
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 610B848D
P 1600 2825
F 0 "#PWR03" H 1600 2575 50  0001 C CNN
F 1 "GND" V 1605 2697 50  0000 R CNN
F 2 "" H 1600 2825 50  0001 C CNN
F 3 "" H 1600 2825 50  0001 C CNN
	1    1600 2825
	1    0    0    -1  
$EndComp
Text GLabel 2075 2525 2    50   Input ~ 0
VDD
$Comp
L Device:R R2
U 1 1 610D52DA
P 1825 2525
F 0 "R2" V 1750 2525 50  0000 C CNN
F 1 "47R" V 1825 2525 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1755 2525 50  0001 C CNN
F 3 "~" H 1825 2525 50  0001 C CNN
	1    1825 2525
	0    1    1    0   
$EndComp
$Comp
L Device:C C1
U 1 1 610DC121
P 1600 2675
F 0 "C1" V 1375 2700 50  0000 C CNN
F 1 "100nF" V 1450 2725 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1638 2525 50  0001 C CNN
F 3 "~" H 1600 2675 50  0001 C CNN
	1    1600 2675
	-1   0    0    1   
$EndComp
Wire Wire Line
	1400 2825 1600 2825
Wire Wire Line
	1400 2625 1400 2825
Connection ~ 1600 2825
Wire Wire Line
	1400 2525 1600 2525
Connection ~ 1600 2525
Wire Wire Line
	1600 2525 1675 2525
Wire Wire Line
	1400 2225 2700 2225
Wire Wire Line
	1400 2125 2775 2125
Wire Wire Line
	1975 2525 2075 2525
$Comp
L dk_Alarms-Buzzers-and-Sirens:PS1240P02BT BZ1
U 1 1 5F87649F
P 1275 6450
F 0 "BZ1" H 1373 6203 60  0000 C CNN
F 1 "PS1240P02BT" H 1373 6309 60  0000 C CNN
F 2 "digikey-footprints:Piezo_Transducer_THT_PS1240P02BT" H 1475 6650 60  0001 L CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/piezoelectronic_buzzer_ps_en.pdf" H 1475 6750 60  0001 L CNN
F 4 "445-2525-1-ND" H 1475 6850 60  0001 L CNN "Digi-Key_PN"
F 5 "PS1240P02BT" H 1475 6950 60  0001 L CNN "MPN"
F 6 "Audio Products" H 1475 7050 60  0001 L CNN "Category"
F 7 "Alarms, Buzzers, and Sirens" H 1475 7150 60  0001 L CNN "Family"
F 8 "https://product.tdk.com/info/en/catalog/datasheets/piezoelectronic_buzzer_ps_en.pdf" H 1475 7250 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/tdk-corporation/PS1240P02BT/445-2525-1-ND/935930" H 1475 7350 60  0001 L CNN "DK_Detail_Page"
F 10 "AUDIO PIEZO TRANSDUCER 30V TH" H 1475 7450 60  0001 L CNN "Description"
F 11 "TDK Corporation" H 1475 7550 60  0001 L CNN "Manufacturer"
F 12 "Active" H 1475 7650 60  0001 L CNN "Status"
	1    1275 6450
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT RV2
U 1 1 5F890273
P 2250 6450
F 0 "RV2" H 2180 6496 50  0000 R CNN
F 1 "2K" H 2180 6405 50  0000 R CNN
F 2 "Potentiometer_SMD:Potentiometer_Bourns_TC33X_Vertical" H 2250 6450 50  0001 C CNN
F 3 "~" H 2250 6450 50  0001 C CNN
	1    2250 6450
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5F89CA0B
P 2250 6300
F 0 "#PWR05" H 2250 6050 50  0001 C CNN
F 1 "GND" V 2255 6172 50  0000 R CNN
F 2 "" H 2250 6300 50  0001 C CNN
F 3 "" H 2250 6300 50  0001 C CNN
	1    2250 6300
	-1   0    0    1   
$EndComp
Wire Wire Line
	1375 6450 2100 6450
$Comp
L power:GND #PWR02
U 1 1 5F8A383B
P 1375 6550
F 0 "#PWR02" H 1375 6300 50  0001 C CNN
F 1 "GND" V 1380 6422 50  0000 R CNN
F 2 "" H 1375 6550 50  0001 C CNN
F 3 "" H 1375 6550 50  0001 C CNN
	1    1375 6550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_PHOTO R1
U 1 1 5F8A50CF
P 1500 5825
F 0 "R1" V 1707 5825 50  0000 C CNN
F 1 "R_PHOTO" V 1616 5825 50  0000 C CNN
F 2 "OptoDevice:R_LDR_5.1x4.3mm_P3.4mm_Vertical" V 1550 5575 50  0001 L CNN
F 3 "https://cdn-learn.adafruit.com/downloads/pdf/photocells.pdf" H 1500 5775 50  0001 C CNN
	1    1500 5825
	0    1    -1   0   
$EndComp
Text GLabel 1275 5825 0    50   Input ~ 0
VDD
Wire Wire Line
	1275 5825 1350 5825
$Comp
L Device:R R3
U 1 1 5F8AB810
P 1975 5825
F 0 "R3" V 1768 5825 50  0000 C CNN
F 1 "10K" V 1859 5825 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1905 5825 50  0001 C CNN
F 3 "~" H 1975 5825 50  0001 C CNN
	1    1975 5825
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5F8AC3B2
P 2200 5825
F 0 "#PWR06" H 2200 5575 50  0001 C CNN
F 1 "GND" V 2205 5697 50  0000 R CNN
F 2 "" H 2200 5825 50  0001 C CNN
F 3 "" H 2200 5825 50  0001 C CNN
	1    2200 5825
	0    -1   1    0   
$EndComp
Wire Wire Line
	2125 5825 2200 5825
Wire Wire Line
	1650 5825 1750 5825
Wire Wire Line
	1750 5675 1750 5825
Connection ~ 1750 5825
Wire Wire Line
	1750 5825 1825 5825
$Comp
L Device:R_POT RV1
U 1 1 5F8C41C9
P 1550 1500
F 0 "RV1" V 1343 1500 50  0000 C CNN
F 1 "100R" V 1434 1500 50  0000 C CNN
F 2 "Potentiometer_SMD:Potentiometer_Bourns_TC33X_Vertical" H 1550 1500 50  0001 C CNN
F 3 "~" H 1550 1500 50  0001 C CNN
	1    1550 1500
	0    -1   1    0   
$EndComp
Text GLabel 2100 1500 2    50   UnSpc ~ 0
U_PWR
Wire Wire Line
	1400 2025 1550 2025
Wire Wire Line
	1550 2025 1550 1700
Wire Wire Line
	1700 1500 1925 1500
Wire Wire Line
	1400 1500 1325 1500
Wire Wire Line
	1325 1500 1325 1700
Wire Wire Line
	1325 1700 1550 1700
Connection ~ 1550 1700
Wire Wire Line
	1550 1700 1550 1650
$Comp
L Device:C C2
U 1 1 5F8D11CB
P 1925 1350
F 0 "C2" V 2075 1350 50  0000 C CNN
F 1 "4.7uF" V 2000 1175 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1963 1200 50  0001 C CNN
F 3 "~" H 1925 1350 50  0001 C CNN
	1    1925 1350
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5F8D2408
P 1925 1050
F 0 "#PWR04" H 1925 800 50  0001 C CNN
F 1 "GND" V 1930 922 50  0000 R CNN
F 2 "" H 1925 1050 50  0001 C CNN
F 3 "" H 1925 1050 50  0001 C CNN
	1    1925 1050
	-1   0    0    1   
$EndComp
Wire Wire Line
	1925 1200 1925 1050
Connection ~ 1925 1500
Wire Wire Line
	1925 1500 2100 1500
Wire Wire Line
	3700 3550 3700 5175
Wire Wire Line
	3325 2125 3325 3550
Wire Wire Line
	3325 3550 3700 3550
Text Notes 2750 7075 0    50   ~ 0
GPIO Expansion
$Comp
L power:GND #PWR01
U 1 1 5F9C511C
P 625 4350
F 0 "#PWR01" H 625 4100 50  0001 C CNN
F 1 "GND" H 630 4177 50  0000 C CNN
F 2 "" H 625 4350 50  0001 C CNN
F 3 "" H 625 4350 50  0001 C CNN
	1    625  4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3275 3975 3750 3975
Wire Wire Line
	3275 3875 3750 3875
Wire Wire Line
	3275 4275 3750 4275
Wire Wire Line
	3275 3775 3750 3775
$Comp
L Switch:SW_Push SW4
U 1 1 5FBDC4D1
P 925 3375
F 0 "SW4" H 750 3575 50  0000 C CNN
F 1 "HDROP" H 1025 3575 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 925 3575 50  0001 C CNN
F 3 "~" H 925 3575 50  0001 C CNN
	1    925  3375
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5FBEC059
P 7425 1025
F 0 "SW3" H 7250 1225 50  0000 C CNN
F 1 "SDROP" H 7525 1225 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7425 1225 50  0001 C CNN
F 3 "~" H 7425 1225 50  0001 C CNN
	1    7425 1025
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5FBEC899
P 925 4350
F 0 "SW2" H 750 4550 50  0000 C CNN
F 1 "PAUSE" H 1025 4550 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 925 4550 50  0001 C CNN
F 3 "~" H 925 4550 50  0001 C CNN
	1    925  4350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5FBECB5D
P 925 3900
F 0 "SW1" H 750 4075 50  0000 C CNN
F 1 "HOLD" H 1000 4075 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 925 4100 50  0001 C CNN
F 3 "~" H 925 4100 50  0001 C CNN
	1    925  3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1125 3900 2475 3900
Wire Wire Line
	625  3900 725  3900
Wire Wire Line
	625  3900 625  4350
$Comp
L Switch:SW_Push SW8
U 1 1 5FC41930
P 7425 3450
F 0 "SW8" H 7250 3650 50  0000 C CNN
F 1 "RIGHT" H 7525 3650 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7425 3650 50  0001 C CNN
F 3 "~" H 7425 3650 50  0001 C CNN
	1    7425 3450
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW7
U 1 1 5FC4193A
P 7425 3000
F 0 "SW7" H 7250 3200 50  0000 C CNN
F 1 "ROTL" H 7525 3200 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7425 3200 50  0001 C CNN
F 3 "~" H 7425 3200 50  0001 C CNN
	1    7425 3000
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW6
U 1 1 5FC41944
P 7425 2550
F 0 "SW6" H 7250 2750 50  0000 C CNN
F 1 "RIGHT" H 7525 2750 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7425 2750 50  0001 C CNN
F 3 "~" H 7425 2750 50  0001 C CNN
	1    7425 2550
	-1   0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW5
U 1 1 5FC4194E
P 7425 2100
F 0 "SW5" H 7250 2275 50  0000 C CNN
F 1 "ROTR" H 7500 2275 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 7425 2300 50  0001 C CNN
F 3 "~" H 7425 2300 50  0001 C CNN
	1    7425 2100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	725  4350 625  4350
Wire Wire Line
	6250 4775 6250 4375
Wire Wire Line
	6250 4375 5150 4375
Wire Wire Line
	6350 4675 6350 4275
Wire Wire Line
	6350 4275 5150 4275
Wire Wire Line
	7225 2100 6775 2100
Wire Wire Line
	7225 2550 6875 2550
Wire Wire Line
	7225 3450 7075 3450
Wire Wire Line
	7225 3000 6975 3000
Wire Wire Line
	7625 3450 7800 3450
Wire Wire Line
	7800 3450 7800 3000
Wire Wire Line
	7800 2100 7625 2100
Wire Wire Line
	7625 2550 7800 2550
Connection ~ 7800 2550
Wire Wire Line
	7800 2550 7800 2100
Wire Wire Line
	7625 3000 7800 3000
Connection ~ 7800 3000
Wire Wire Line
	7800 3000 7800 2550
$Comp
L power:GND #PWR0101
U 1 1 5FC72BB8
P 7800 3450
F 0 "#PWR0101" H 7800 3200 50  0001 C CNN
F 1 "GND" H 7805 3277 50  0000 C CNN
F 2 "" H 7800 3450 50  0001 C CNN
F 3 "" H 7800 3450 50  0001 C CNN
	1    7800 3450
	1    0    0    -1  
$EndComp
Connection ~ 7800 3450
Text Label 3275 3975 0    50   ~ 0
ROWSDI
Wire Wire Line
	7550 4275 7200 4275
Text Label 7200 4275 0    50   ~ 0
ROWSDI
Wire Wire Line
	7550 4375 7200 4375
Text Label 7200 4375 0    50   ~ 0
ROWCLK
Text Label 7200 4175 0    50   ~ 0
LE
Wire Wire Line
	7200 4175 7550 4175
Text Label 7200 4075 0    50   ~ 0
~OE
Wire Wire Line
	7200 4075 7550 4075
Text Label 3275 3875 0    50   ~ 0
~OE
Text Label 3275 3775 0    50   ~ 0
LE
Text Label 3275 4275 0    50   ~ 0
ROWCLK
Text Label 1625 2125 0    50   ~ 0
IrTX
Text Label 1625 2225 0    50   ~ 0
IrRX
Wire Wire Line
	6575 1025 7225 1025
Wire Wire Line
	7625 1025 7800 1025
Connection ~ 7800 2100
Wire Wire Line
	1125 3375 3750 3375
Wire Wire Line
	1125 4350 2550 4350
Connection ~ 625  4350
Wire Wire Line
	1750 5675 3325 5675
Wire Wire Line
	3325 5675 3325 6075
Wire Wire Line
	3325 6075 3750 6075
Wire Wire Line
	2250 6600 2600 6600
Wire Wire Line
	2600 6600 2600 6175
Wire Wire Line
	2600 6175 3750 6175
Wire Wire Line
	2700 2225 2700 3275
Wire Wire Line
	2700 3275 3750 3275
Wire Wire Line
	2775 2125 2775 3175
Wire Wire Line
	2775 3175 3750 3175
Text Label 1625 2325 0    50   ~ 0
IrSD
NoConn ~ 3750 4375
NoConn ~ 3750 5475
NoConn ~ 3750 5575
NoConn ~ 3750 5675
Wire Wire Line
	3300 6400 3300 6725
Wire Wire Line
	3500 6400 3300 6400
$Comp
L power:GND #PWR09
U 1 1 5F922BBE
P 3500 6400
F 0 "#PWR09" H 3500 6150 50  0001 C CNN
F 1 "GND" V 3505 6272 50  0000 R CNN
F 2 "" H 3500 6400 50  0001 C CNN
F 3 "" H 3500 6400 50  0001 C CNN
	1    3500 6400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3400 6600 3500 6600
Wire Wire Line
	3400 6725 3400 6600
Text GLabel 3500 6600 2    50   Input ~ 0
VDD
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 5F91B7A4
P 3100 6925
F 0 "J1" V 2972 7305 50  0000 L CNN
F 1 "Conn_01x08" V 3063 7305 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Horizontal" H 3100 6925 50  0001 C CNN
F 3 "~" H 3100 6925 50  0001 C CNN
	1    3100 6925
	0    1    1    0   
$EndComp
Wire Wire Line
	2700 4575 3750 4575
Wire Wire Line
	2700 4575 2700 6725
Wire Wire Line
	2800 4675 3750 4675
Wire Wire Line
	2800 4675 2800 6725
Wire Wire Line
	2900 4775 3750 4775
Wire Wire Line
	2900 4775 2900 6725
Wire Wire Line
	3000 4875 3750 4875
Wire Wire Line
	3000 4875 3000 6725
Wire Wire Line
	3100 4975 3750 4975
Wire Wire Line
	3100 4975 3100 6725
Wire Wire Line
	3200 5075 3750 5075
Wire Wire Line
	3200 5075 3200 6725
Wire Wire Line
	4350 6675 4350 7075
Connection ~ 4350 6675
Connection ~ 4450 6675
$Comp
L Device:C C12
U 1 1 5FD69EC0
P 4200 7075
F 0 "C12" V 3948 7075 50  0000 C CNN
F 1 "100nF" V 4039 7075 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 6925 50  0001 C CNN
F 3 "~" H 4200 7075 50  0001 C CNN
	1    4200 7075
	0    1    1    0   
$EndComp
Connection ~ 4350 7075
Wire Wire Line
	4350 7075 4350 7475
$Comp
L Device:C C14
U 1 1 5FD6AC2B
P 4600 7075
F 0 "C14" V 4348 7075 50  0000 C CNN
F 1 "100nF" V 4439 7075 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4638 6925 50  0001 C CNN
F 3 "~" H 4600 7075 50  0001 C CNN
	1    4600 7075
	0    -1   -1   0   
$EndComp
Connection ~ 4450 7075
Wire Wire Line
	4450 7075 4450 6675
$Comp
L Device:C C13
U 1 1 5FD6B34C
P 4200 7475
F 0 "C13" V 3948 7475 50  0000 C CNN
F 1 "100nF" V 4039 7475 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4238 7325 50  0001 C CNN
F 3 "~" H 4200 7475 50  0001 C CNN
	1    4200 7475
	0    1    1    0   
$EndComp
Connection ~ 4350 7475
Wire Wire Line
	4350 7475 4350 7525
Wire Wire Line
	4050 7475 4050 7075
Connection ~ 4050 6675
Connection ~ 4050 7075
Wire Wire Line
	4050 7075 4050 6675
Wire Wire Line
	4750 7075 4750 6675
Connection ~ 4750 6675
$Comp
L Device:R R5
U 1 1 5FD78AC8
P 5525 6325
F 0 "R5" V 5318 6325 50  0000 C CNN
F 1 "10K" V 5409 6325 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5455 6325 50  0001 C CNN
F 3 "~" H 5525 6325 50  0001 C CNN
	1    5525 6325
	1    0    0    1   
$EndComp
Connection ~ 5525 6175
Wire Wire Line
	5525 6175 5150 6175
Text GLabel 5525 6475 3    50   Input ~ 0
VDD
Wire Wire Line
	4350 7525 4450 7525
$Comp
L Device:C C15
U 1 1 5FDA21B7
P 4600 7475
F 0 "C15" V 4348 7475 50  0000 C CNN
F 1 "100nF" V 4439 7475 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4638 7325 50  0001 C CNN
F 3 "~" H 4600 7475 50  0001 C CNN
	1    4600 7475
	0    -1   -1   0   
$EndComp
Connection ~ 4450 7475
Wire Wire Line
	4450 7475 4450 7075
Wire Wire Line
	4750 7075 4750 7475
Connection ~ 4750 7075
Wire Wire Line
	2625 2325 2625 5875
Wire Wire Line
	2625 5875 3750 5875
Wire Wire Line
	1400 2325 2625 2325
Wire Wire Line
	6975 4175 5150 4175
Wire Wire Line
	6975 3000 6975 4175
Wire Wire Line
	7075 4075 5150 4075
Wire Wire Line
	7075 3450 7075 4075
Wire Wire Line
	6875 3975 5150 3975
Wire Wire Line
	6875 2550 6875 3975
Wire Wire Line
	6775 3875 5150 3875
Wire Wire Line
	6775 2100 6775 3875
Wire Wire Line
	6450 3675 5150 3675
Wire Wire Line
	6450 3675 6450 4575
$Comp
L Switch:SW_Push SW9
U 1 1 5FC778DC
P 6000 3050
F 0 "SW9" H 6000 3335 50  0000 C CNN
F 1 "START" H 6000 3244 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6000 3250 50  0001 C CNN
F 3 "~" H 6000 3250 50  0001 C CNN
	1    6000 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR027
U 1 1 5FC9EE66
P 6200 3050
F 0 "#PWR027" H 6200 2800 50  0001 C CNN
F 1 "GND" H 6205 2877 50  0000 C CNN
F 2 "" H 6200 3050 50  0001 C CNN
F 3 "" H 6200 3050 50  0001 C CNN
	1    6200 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 3050 5650 3050
Wire Wire Line
	5650 3050 5650 3775
Wire Wire Line
	5650 3775 5150 3775
Wire Wire Line
	2550 3675 3750 3675
Wire Wire Line
	2550 3675 2550 4350
Wire Wire Line
	2475 3475 3750 3475
Wire Wire Line
	2475 3475 2475 3900
Wire Wire Line
	7800 1025 7800 2100
Wire Wire Line
	725  3375 625  3375
Wire Wire Line
	625  3375 625  3900
Connection ~ 625  3900
Wire Wire Line
	6575 1025 6575 3475
Wire Wire Line
	5150 3475 6575 3475
$Comp
L Switch:SW_Push SW10
U 1 1 5FD1BDC4
P 6000 2550
F 0 "SW10" H 6000 2835 50  0000 C CNN
F 1 "SELECT" H 6000 2744 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6000 2750 50  0001 C CNN
F 3 "~" H 6000 2750 50  0001 C CNN
	1    6000 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2550 6200 3050
Connection ~ 6200 3050
Wire Wire Line
	5800 2550 5550 2550
Wire Wire Line
	5550 2550 5550 3375
Wire Wire Line
	5550 3375 5150 3375
Wire Wire Line
	3700 5175 3750 5175
NoConn ~ 3750 5975
Wire Wire Line
	3475 2000 3250 2000
Wire Wire Line
	3250 2000 3250 3625
Wire Wire Line
	3250 3625 3625 3625
Wire Wire Line
	3625 3625 3625 5275
Wire Wire Line
	3625 5275 3750 5275
Wire Bus Line
	5775 4875 5775 5175
Wire Bus Line
	5775 4475 5775 4875
$EndSCHEMATC
