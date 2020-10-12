EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
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
Text Label 5575 6150 2    50   ~ 0
~OE
$Comp
L Device:C C2
U 1 1 5EFA155D
P 4825 7550
F 0 "C2" V 4573 7550 50  0000 C CNN
F 1 "100nF" V 4664 7550 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 4863 7400 50  0001 C CNN
F 3 "~" H 4825 7550 50  0001 C CNN
	1    4825 7550
	0    -1   -1   0   
$EndComp
$Comp
L power:VDD #PWR02
U 1 1 5EE456DF
P 3350 2125
F 0 "#PWR02" H 3350 1975 50  0001 C CNN
F 1 "VDD" H 3367 2298 50  0000 C CNN
F 2 "" H 3350 2125 50  0001 C CNN
F 3 "" H 3350 2125 50  0001 C CNN
	1    3350 2125
	1    0    0    -1  
$EndComp
Text Label 5800 5250 2    50   ~ 0
COLSDI0
Text Label 5775 5450 2    50   ~ 0
COLCLK
$Comp
L power:GND #PWR05
U 1 1 5F1E6F61
P 4975 7550
F 0 "#PWR05" H 4975 7300 50  0001 C CNN
F 1 "GND" V 4980 7422 50  0000 R CNN
F 2 "" H 4975 7550 50  0001 C CNN
F 3 "" H 4975 7550 50  0001 C CNN
	1    4975 7550
	0    -1   -1   0   
$EndComp
$Comp
L Graphic:Logo_Open_Hardware_Large #LOGO1
U 1 1 5EE98802
P 1125 10700
F 0 "#LOGO1" H 1125 11200 50  0001 C CNN
F 1 "Logo_Open_Hardware_Large" H 1125 10300 50  0001 C CNN
F 2 "" H 1125 10700 50  0001 C CNN
F 3 "~" H 1125 10700 50  0001 C CNN
	1    1125 10700
	1    0    0    -1  
$EndComp
Text Label 5850 5350 2    50   ~ 0
COLSDI16
$Comp
L MCU_Microchip_ATmega:ATxmega64D4-AU U1
U 1 1 5F7BA44B
P 4675 5950
F 0 "U1" H 4225 7325 50  0000 C CNN
F 1 "ATxmega64D4-AU" H 4675 6375 50  0000 C CNN
F 2 "Package_QFP:TQFP-44_10x10mm_P0.8mm" H 4675 5950 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8135-8-and-16-bit-AVR-microcontroller-ATxmega16D4-32D4-64D4-128D4_datasheet.pdf" H 4675 5950 50  0001 C CNN
	1    4675 5950
	-1   0    0    1   
$EndComp
Text Label 5800 5050 2    50   ~ 0
ROWCLK
Text Label 5775 4950 2    50   ~ 0
ROWSDI
Text Label 5575 5150 2    50   ~ 0
LE
Wire Wire Line
	6050 5250 5375 5250
Wire Wire Line
	5925 5350 5375 5350
Wire Wire Line
	5800 5450 5375 5450
Wire Wire Line
	5600 6150 5375 6150
NoConn ~ 5375 6750
NoConn ~ 5375 6650
$Comp
L Device:C C1
U 1 1 5F8DFF39
P 4425 7550
F 0 "C1" V 4173 7550 50  0000 C CNN
F 1 "100nF" V 4264 7550 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 4463 7400 50  0001 C CNN
F 3 "~" H 4425 7550 50  0001 C CNN
	1    4425 7550
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5F8DFF43
P 4275 7550
F 0 "#PWR03" H 4275 7300 50  0001 C CNN
F 1 "GND" V 4280 7422 50  0000 R CNN
F 2 "" H 4275 7550 50  0001 C CNN
F 3 "" H 4275 7550 50  0001 C CNN
	1    4275 7550
	0    1    1    0   
$EndComp
Wire Wire Line
	4675 7350 4675 7550
Wire Wire Line
	4575 7350 4575 7550
Wire Wire Line
	4575 7550 4575 7675
Wire Wire Line
	4675 7675 4675 7550
Connection ~ 4575 7550
Connection ~ 4675 7550
$Comp
L dk_Pushbutton-Switches:GPTS203211B S8
U 1 1 5F99E26D
P 2875 5850
F 0 "S8" H 2550 6000 50  0000 C CNN
F 1 "LEFT" H 2475 5900 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 6050 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 6150 60  0001 L CNN
F 4 "CW181-ND" H 3075 6250 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 6350 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 6450 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 6550 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 6650 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 6750 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 6850 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 6950 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 7050 60  0001 L CNN "Status"
	1    2875 5850
	1    0    0    -1  
$EndComp
$Comp
L dk_Pushbutton-Switches:GPTS203211B S7
U 1 1 5F9C5456
P 2875 5625
F 0 "S7" H 2550 5775 50  0000 C CNN
F 1 "RIGHT" H 2475 5675 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 5825 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5925 60  0001 L CNN
F 4 "CW181-ND" H 3075 6025 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 6125 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 6225 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 6325 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 6425 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 6525 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 6625 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 6725 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 6825 60  0001 L CNN "Status"
	1    2875 5625
	1    0    0    -1  
$EndComp
$Comp
L dk_Pushbutton-Switches:GPTS203211B S6
U 1 1 5F9C5FB7
P 2875 5400
F 0 "S6" H 2550 5550 50  0000 C CNN
F 1 "SOFTDROP" H 2475 5450 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 5600 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5700 60  0001 L CNN
F 4 "CW181-ND" H 3075 5800 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 5900 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 6000 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 6100 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 6200 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 6300 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 6400 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 6500 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 6600 60  0001 L CNN "Status"
	1    2875 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2675 5850 2225 5850
Wire Wire Line
	3075 5850 3750 5850
Wire Wire Line
	3750 5850 3750 5650
Wire Wire Line
	3750 5650 3975 5650
Wire Wire Line
	3075 5625 3675 5625
Wire Wire Line
	3675 5625 3675 5550
Wire Wire Line
	3675 5550 3975 5550
Wire Wire Line
	3075 5400 3900 5400
Wire Wire Line
	3900 5400 3900 5450
Wire Wire Line
	3900 5450 3975 5450
$Comp
L dk_Pushbutton-Switches:GPTS203211B S5
U 1 1 5FA8729A
P 2875 5175
F 0 "S5" H 2550 5325 50  0000 C CNN
F 1 "HARDDROP" H 2475 5225 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 5375 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5475 60  0001 L CNN
F 4 "CW181-ND" H 3075 5575 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 5675 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 5775 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 5875 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5975 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 6075 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 6175 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 6275 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 6375 60  0001 L CNN "Status"
	1    2875 5175
	1    0    0    -1  
$EndComp
Wire Wire Line
	2675 5175 2225 5175
Connection ~ 2225 5175
Wire Wire Line
	2225 5175 2225 5400
Wire Wire Line
	2675 5400 2225 5400
Connection ~ 2225 5400
Wire Wire Line
	2225 5400 2225 5625
Wire Wire Line
	2675 5625 2225 5625
Connection ~ 2225 5625
Wire Wire Line
	2225 5625 2225 5850
Wire Wire Line
	3075 5175 3500 5175
$Comp
L dk_Pushbutton-Switches:GPTS203211B S4
U 1 1 5FB2C393
P 2875 4950
F 0 "S4" H 2550 5100 50  0000 C CNN
F 1 "ROTL" H 2475 5000 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 5150 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5250 60  0001 L CNN
F 4 "CW181-ND" H 3075 5350 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 5450 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 5550 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 5650 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5750 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 5850 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 5950 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 6050 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 6150 60  0001 L CNN "Status"
	1    2875 4950
	1    0    0    -1  
$EndComp
$Comp
L dk_Pushbutton-Switches:GPTS203211B S3
U 1 1 5FB2CD6E
P 2875 4725
F 0 "S3" H 2550 4875 50  0000 C CNN
F 1 "ROTR" H 2475 4775 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 4925 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5025 60  0001 L CNN
F 4 "CW181-ND" H 3075 5125 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 5225 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 5325 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 5425 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5525 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 5625 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 5725 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 5825 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 5925 60  0001 L CNN "Status"
	1    2875 4725
	1    0    0    -1  
$EndComp
Wire Wire Line
	2675 4950 2225 4950
Connection ~ 2225 4950
Wire Wire Line
	2225 4950 2225 5175
Wire Wire Line
	2675 4725 2225 4725
Connection ~ 2225 4725
Wire Wire Line
	2225 4725 2225 4950
Wire Wire Line
	3075 4950 3625 4950
Wire Wire Line
	3075 4725 3675 4725
Wire Wire Line
	3500 5350 3975 5350
Wire Wire Line
	3500 5175 3500 5350
Wire Wire Line
	3625 5250 3975 5250
Wire Wire Line
	3625 4950 3625 5250
Wire Wire Line
	3675 5150 3975 5150
Wire Wire Line
	3675 4725 3675 5150
$Comp
L dk_Pushbutton-Switches:GPTS203211B S2
U 1 1 5FD11B86
P 2875 4500
F 0 "S2" H 2550 4650 50  0000 C CNN
F 1 "PAUSE" H 2475 4550 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 4700 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 4800 60  0001 L CNN
F 4 "CW181-ND" H 3075 4900 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 5000 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 5100 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 5200 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 5400 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 5500 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 5600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 5700 60  0001 L CNN "Status"
	1    2875 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2675 4500 2225 4500
Connection ~ 2225 4500
Wire Wire Line
	2225 4500 2225 4725
Wire Wire Line
	3075 4500 3750 4500
Wire Wire Line
	3750 4500 3750 5050
Wire Wire Line
	3750 5050 3975 5050
$Comp
L power:GND #PWR01
U 1 1 5FD6E0B9
P 2225 5850
F 0 "#PWR01" H 2225 5600 50  0001 C CNN
F 1 "GND" H 2230 5677 50  0000 C CNN
F 2 "" H 2225 5850 50  0001 C CNN
F 3 "" H 2225 5850 50  0001 C CNN
	1    2225 5850
	1    0    0    -1  
$EndComp
Connection ~ 2225 5850
$Comp
L dk_Pushbutton-Switches:GPTS203211B S1
U 1 1 5FD6EBE1
P 2875 4275
F 0 "S1" H 2550 4425 50  0000 C CNN
F 1 "HOLD" H 2475 4325 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 3075 4475 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 4575 60  0001 L CNN
F 4 "CW181-ND" H 3075 4675 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 3075 4775 60  0001 L CNN "MPN"
F 6 "Switches" H 3075 4875 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 3075 4975 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 3075 5075 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 3075 5175 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 3075 5275 60  0001 L CNN "Description"
F 11 "CW Industries" H 3075 5375 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3075 5475 60  0001 L CNN "Status"
	1    2875 4275
	1    0    0    -1  
$EndComp
Wire Wire Line
	2675 4275 2225 4275
Wire Wire Line
	2225 4275 2225 4500
Wire Wire Line
	3075 4275 3875 4275
Wire Wire Line
	3875 4275 3875 4950
Wire Wire Line
	3875 4950 3975 4950
$Comp
L Connector:AVR-PDI-6 J2
U 1 1 5FDFDAE0
P 6750 7050
F 0 "J2" H 6420 7096 50  0000 R CNN
F 1 "AVR-PDI-6" H 6420 7005 50  0000 R CNN
F 2 "" V 6500 7000 50  0001 C CNN
F 3 " ~" H 5475 6500 50  0001 C CNN
	1    6750 7050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6350 7050 5375 7050
Wire Wire Line
	5375 6950 6350 6950
$Comp
L power:GND #PWR08
U 1 1 5FE8EC1D
P 6850 7450
F 0 "#PWR08" H 6850 7200 50  0001 C CNN
F 1 "GND" V 6855 7322 50  0000 R CNN
F 2 "" H 6850 7450 50  0001 C CNN
F 3 "" H 6850 7450 50  0001 C CNN
	1    6850 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 5850 5600 6150
$Comp
L power:GND #PWR04
U 1 1 5F690054
P 4675 4550
F 0 "#PWR04" H 4675 4300 50  0001 C CNN
F 1 "GND" V 4680 4422 50  0000 R CNN
F 2 "" H 4675 4550 50  0001 C CNN
F 3 "" H 4675 4550 50  0001 C CNN
	1    4675 4550
	-1   0    0    1   
$EndComp
$Sheet
S 3700 1175 2325 1550
U 5F785555
F0 "power" 50
F1 "power.sch" 50
F2 "BAT_LVL" O L 3700 2500 50 
F3 "U_PWR" O L 3700 2275 50 
F4 "VDD" O L 3700 2125 50 
$EndSheet
Wire Wire Line
	3700 2500 3350 2500
Wire Wire Line
	3350 2500 3350 6350
Wire Wire Line
	3350 6350 3975 6350
Text GLabel 3075 2125 0    50   UnSpc ~ 0
VDD
Wire Wire Line
	3075 2125 3350 2125
Text GLabel 3075 2275 0    50   UnSpc ~ 0
U_PWR
Wire Wire Line
	3075 2275 3700 2275
Connection ~ 3350 2125
$Sheet
S 12625 5975 1125 575 
U 5F613F5E
F0 "matrix" 50
F1 "matrix.sch" 50
F2 "ROW[1..16]" U L 12625 6200 50 
F3 "COL[0..23]" U L 12625 6400 50 
$EndSheet
NoConn ~ 5375 5850
NoConn ~ 5375 5950
NoConn ~ 5375 6050
NoConn ~ 3975 5850
NoConn ~ 3975 5950
NoConn ~ 3975 6050
NoConn ~ 3975 6150
NoConn ~ 3975 6450
NoConn ~ 3975 6550
NoConn ~ 3975 6650
NoConn ~ 3975 6750
NoConn ~ 3975 6850
NoConn ~ 3975 6950
NoConn ~ 3975 7050
$Comp
L dk_Rectangular-Connectors-Headers-Male-Pins:61300311121 J1
U 1 1 5F933175
P 6675 4400
F 0 "J1" H 6587 4412 50  0000 R CNN
F 1 "61300311121" H 6587 4503 50  0000 R CNN
F 2 "digikey-footprints:PinHeader_1x3_P2.54_Drill1.1mm" H 6875 4600 60  0001 L CNN
F 3 "https://katalog.we-online.de/em/datasheet/6130xx11121.pdf" H 6875 4700 60  0001 L CNN
F 4 "732-5316-ND" H 6875 4800 60  0001 L CNN "Digi-Key_PN"
F 5 "61300311121" H 6875 4900 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 6875 5000 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 6875 5100 60  0001 L CNN "Family"
F 8 "https://katalog.we-online.de/em/datasheet/6130xx11121.pdf" H 6875 5200 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/wurth-electronics-inc/61300311121/732-5316-ND/4846825" H 6875 5300 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER VERT 3POS 2.54MM" H 6875 5400 60  0001 L CNN "Description"
F 11 "Wurth Electronics Inc." H 6875 5500 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6875 5600 60  0001 L CNN "Status"
	1    6675 4400
	-1   0    0    1   
$EndComp
Wire Wire Line
	5375 5550 6475 5550
Wire Wire Line
	6475 5550 6475 4550
Wire Wire Line
	5375 5650 6575 5650
Wire Wire Line
	6575 5650 6575 4550
$Comp
L power:GND #PWR07
U 1 1 5F9AF30E
P 6675 4550
F 0 "#PWR07" H 6675 4300 50  0001 C CNN
F 1 "GND" V 6680 4422 50  0000 R CNN
F 2 "" H 6675 4550 50  0001 C CNN
F 3 "" H 6675 4550 50  0001 C CNN
	1    6675 4550
	1    0    0    -1  
$EndComp
Text Notes 6450 4325 0    50   ~ 0
UART
Wire Wire Line
	3350 2125 3700 2125
Text GLabel 4625 7775 3    50   Input ~ 0
VDD
Wire Wire Line
	4575 7675 4625 7675
Wire Wire Line
	4625 7675 4625 7775
Connection ~ 4625 7675
Wire Wire Line
	4625 7675 4675 7675
Text GLabel 6850 6650 1    50   UnSpc ~ 0
VDD
$Sheet
S 10500 5175 1350 1450
U 6011206E
F0 "Matrix Driver" 50
F1 "matrix_driver.sch" 50
F2 "COL[0..23]" I R 11850 6400 50 
F3 "ROW[1..16]" I R 11850 6200 50 
F4 "D[0..8]" I L 10500 6200 50 
F5 "ROWSDI" I L 10500 5450 50 
F6 "LE" I L 10500 5550 50 
F7 "ROWCLK" I L 10500 5350 50 
F8 "~OE" I L 10500 5750 50 
F9 "SEGCLK0" I L 10500 6300 50 
F10 "SEGCLK1" I L 10500 6400 50 
F11 "SEGCLK2" I L 10500 6500 50 
$EndSheet
Wire Bus Line
	11850 6400 12625 6400
Wire Bus Line
	11850 6200 12625 6200
$EndSCHEMATC
