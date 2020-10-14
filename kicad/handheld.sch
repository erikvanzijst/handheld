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
P 1150 7275
F 0 "#LOGO1" H 1150 7775 50  0001 C CNN
F 1 "Logo_Open_Hardware_Large" H 1150 6875 50  0001 C CNN
F 2 "" H 1150 7275 50  0001 C CNN
F 3 "~" H 1150 7275 50  0001 C CNN
	1    1150 7275
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
	4350 6675 4350 6800
Wire Wire Line
	4450 6800 4450 6675
Connection ~ 4350 6675
Connection ~ 4450 6675
$Comp
L dk_Pushbutton-Switches:GPTS203211B S8
U 1 1 5F99E26D
P 1900 5525
F 0 "S8" H 1575 5675 50  0000 C CNN
F 1 "LEFT" H 1500 5575 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 5725 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5825 60  0001 L CNN
F 4 "CW181-ND" H 2100 5925 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 6025 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 6125 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 6225 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 6325 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 6425 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 6525 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 6625 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 6725 60  0001 L CNN "Status"
	1    1900 5525
	1    0    0    -1  
$EndComp
$Comp
L dk_Pushbutton-Switches:GPTS203211B S7
U 1 1 5F9C5456
P 1900 5300
F 0 "S7" H 1575 5450 50  0000 C CNN
F 1 "RIGHT" H 1500 5350 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 5500 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5600 60  0001 L CNN
F 4 "CW181-ND" H 2100 5700 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 5800 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 5900 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 6000 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 6100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 6200 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 6300 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 6400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 6500 60  0001 L CNN "Status"
	1    1900 5300
	1    0    0    -1  
$EndComp
$Comp
L dk_Pushbutton-Switches:GPTS203211B S6
U 1 1 5F9C5FB7
P 1900 5075
F 0 "S6" H 1575 5225 50  0000 C CNN
F 1 "SOFTDROP" H 1500 5125 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 5275 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5375 60  0001 L CNN
F 4 "CW181-ND" H 2100 5475 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 5575 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 5675 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 5775 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5875 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 5975 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 6075 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 6175 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 6275 60  0001 L CNN "Status"
	1    1900 5075
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 5525 1250 5525
Wire Wire Line
	2225 5275 3750 5275
Wire Wire Line
	2150 5175 3750 5175
$Comp
L dk_Pushbutton-Switches:GPTS203211B S5
U 1 1 5FA8729A
P 1900 4850
F 0 "S5" H 1575 5000 50  0000 C CNN
F 1 "HARDDROP" H 1500 4900 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 5050 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5150 60  0001 L CNN
F 4 "CW181-ND" H 2100 5250 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 5350 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 5450 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 5550 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5650 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 5750 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 5850 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 5950 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 6050 60  0001 L CNN "Status"
	1    1900 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4850 1250 4850
Connection ~ 1250 4850
Wire Wire Line
	1250 4850 1250 5075
Wire Wire Line
	1700 5075 1250 5075
Connection ~ 1250 5075
Wire Wire Line
	1250 5075 1250 5300
Wire Wire Line
	1700 5300 1250 5300
Connection ~ 1250 5300
Wire Wire Line
	1250 5300 1250 5525
Wire Wire Line
	2100 4850 2150 4850
$Comp
L dk_Pushbutton-Switches:GPTS203211B S4
U 1 1 5FB2C393
P 1900 4625
F 0 "S4" H 1575 4775 50  0000 C CNN
F 1 "ROTL" H 1500 4675 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 4825 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 4925 60  0001 L CNN
F 4 "CW181-ND" H 2100 5025 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 5125 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 5225 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 5325 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5425 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 5525 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 5625 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 5725 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 5825 60  0001 L CNN "Status"
	1    1900 4625
	1    0    0    -1  
$EndComp
$Comp
L dk_Pushbutton-Switches:GPTS203211B S3
U 1 1 5FB2CD6E
P 1900 4400
F 0 "S3" H 1575 4550 50  0000 C CNN
F 1 "ROTR" H 1500 4450 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 4600 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 4700 60  0001 L CNN
F 4 "CW181-ND" H 2100 4800 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 4900 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 5000 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 5100 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 5200 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 5300 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 5400 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 5500 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 5600 60  0001 L CNN "Status"
	1    1900 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4625 1250 4625
Connection ~ 1250 4625
Wire Wire Line
	1250 4625 1250 4850
Wire Wire Line
	1700 4400 1250 4400
Connection ~ 1250 4400
Wire Wire Line
	1250 4400 1250 4625
Wire Wire Line
	2100 4625 2225 4625
Wire Wire Line
	2100 4400 2300 4400
$Comp
L dk_Pushbutton-Switches:GPTS203211B S2
U 1 1 5FD11B86
P 1900 4175
F 0 "S2" H 1575 4325 50  0000 C CNN
F 1 "PAUSE" H 1500 4225 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 4375 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 4475 60  0001 L CNN
F 4 "CW181-ND" H 2100 4575 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 4675 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 4775 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 4875 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 4975 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 5075 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 5175 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 5275 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 5375 60  0001 L CNN "Status"
	1    1900 4175
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4175 1250 4175
Connection ~ 1250 4175
Wire Wire Line
	1250 4175 1250 4400
Wire Wire Line
	2100 4175 2375 4175
$Comp
L power:GND #PWR01
U 1 1 5FD6E0B9
P 1250 5525
F 0 "#PWR01" H 1250 5275 50  0001 C CNN
F 1 "GND" H 1255 5352 50  0000 C CNN
F 2 "" H 1250 5525 50  0001 C CNN
F 3 "" H 1250 5525 50  0001 C CNN
	1    1250 5525
	1    0    0    -1  
$EndComp
Connection ~ 1250 5525
$Comp
L dk_Pushbutton-Switches:GPTS203211B S1
U 1 1 5FD6EBE1
P 1900 3950
F 0 "S1" H 1575 4100 50  0000 C CNN
F 1 "HOLD" H 1500 4000 50  0000 C CNN
F 2 "digikey-footprints:PushButton_12x12mm_THT_GPTS203211B" H 2100 4150 50  0001 L CNN
F 3 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 4250 60  0001 L CNN
F 4 "CW181-ND" H 2100 4350 60  0001 L CNN "Digi-Key_PN"
F 5 "GPTS203211B" H 2100 4450 60  0001 L CNN "MPN"
F 6 "Switches" H 2100 4550 60  0001 L CNN "Category"
F 7 "Pushbutton Switches" H 2100 4650 60  0001 L CNN "Family"
F 8 "http://switches-connectors-custom.cwind.com/Asset/GPTS203211BR2.pdf" H 2100 4750 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cw-industries/GPTS203211B/CW181-ND/3190590" H 2100 4850 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH PUSHBUTTON SPST 1A 30V" H 2100 4950 60  0001 L CNN "Description"
F 11 "CW Industries" H 2100 5050 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 5150 60  0001 L CNN "Status"
	1    1900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 3950 1250 3950
Wire Wire Line
	1250 3950 1250 4175
Wire Wire Line
	2100 3950 2450 3950
$Comp
L Connector:AVR-PDI-6 J3
U 1 1 5FDFDAE0
P 6525 6175
F 0 "J3" H 6195 6221 50  0000 R CNN
F 1 "AVR-PDI-6" H 6195 6130 50  0000 R CNN
F 2 "" V 6275 6125 50  0001 C CNN
F 3 " ~" H 5250 5625 50  0001 C CNN
	1    6525 6175
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6125 6175 5150 6175
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
$EndSheet
Wire Wire Line
	3475 2125 2950 2125
Wire Wire Line
	3625 5975 3750 5975
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
P 3325 3075
F 0 "J2" V 3200 3075 50  0000 R CNN
F 1 "61300311121" H 3550 2875 50  0000 R CNN
F 2 "digikey-footprints:PinHeader_1x3_P2.54_Drill1.1mm" H 3525 3275 60  0001 L CNN
F 3 "https://katalog.we-online.de/em/datasheet/6130xx11121.pdf" H 3525 3375 60  0001 L CNN
F 4 "732-5316-ND" H 3525 3475 60  0001 L CNN "Digi-Key_PN"
F 5 "61300311121" H 3525 3575 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 3525 3675 60  0001 L CNN "Category"
F 7 "Rectangular Connectors - Headers, Male Pins" H 3525 3775 60  0001 L CNN "Family"
F 8 "https://katalog.we-online.de/em/datasheet/6130xx11121.pdf" H 3525 3875 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/wurth-electronics-inc/61300311121/732-5316-ND/4846825" H 3525 3975 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN HEADER VERT 3POS 2.54MM" H 3525 4075 60  0001 L CNN "Description"
F 11 "Wurth Electronics Inc." H 3525 4175 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3525 4275 60  0001 L CNN "Status"
	1    3325 3075
	0    1    1    0   
$EndComp
Wire Wire Line
	3750 3275 3475 3275
$Comp
L power:GND #PWR08
U 1 1 5F9AF30E
P 3475 3075
F 0 "#PWR08" H 3475 2825 50  0001 C CNN
F 1 "GND" V 3480 2947 50  0000 R CNN
F 2 "" H 3475 3075 50  0001 C CNN
F 3 "" H 3475 3075 50  0001 C CNN
	1    3475 3075
	-1   0    0    1   
$EndComp
Text Notes 3250 3300 1    50   ~ 0
UART
Wire Wire Line
	3125 1750 3475 1750
Text GLabel 4400 6900 3    50   Input ~ 0
VDD
Wire Wire Line
	4350 6800 4400 6800
Wire Wire Line
	4400 6800 4400 6900
Connection ~ 4400 6800
Wire Wire Line
	4400 6800 4450 6800
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
F8 "~OE" I L 7550 4075 50 
F9 "SEGCLK0" I L 7550 4775 50 
F10 "SEGCLK1" I L 7550 4675 50 
F11 "SEGCLK2" I L 7550 4575 50 
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
	3475 3175 3750 3175
Text Label 3500 3275 0    50   ~ 0
RX
Text Label 3500 3175 0    50   ~ 0
TX
Wire Wire Line
	7550 4375 5150 4375
Wire Wire Line
	5150 4275 7550 4275
Wire Wire Line
	7550 4175 5150 4175
Wire Wire Line
	5150 4075 7550 4075
Wire Wire Line
	7550 4775 6250 4775
Wire Wire Line
	6250 4775 6250 3975
Wire Wire Line
	6250 3975 5150 3975
Wire Wire Line
	7550 4675 6350 4675
Wire Wire Line
	6350 4675 6350 3875
Wire Wire Line
	6350 3875 5150 3875
Wire Wire Line
	7550 4575 6450 4575
Wire Wire Line
	6450 4575 6450 3775
Wire Wire Line
	6450 3775 5150 3775
Wire Wire Line
	2100 5075 3750 5075
Wire Wire Line
	2150 4975 2150 4850
Wire Wire Line
	2150 4975 3750 4975
Wire Wire Line
	2225 4875 2225 4625
Wire Wire Line
	2225 4875 3750 4875
Wire Wire Line
	2300 4775 2300 4400
Wire Wire Line
	2300 4775 3750 4775
Wire Wire Line
	2375 4675 2375 4175
Wire Wire Line
	2375 4675 3750 4675
Wire Wire Line
	2450 4575 2450 3950
Wire Wire Line
	2450 4575 3750 4575
Wire Wire Line
	2100 5300 2150 5300
Wire Wire Line
	2150 5175 2150 5300
Wire Wire Line
	2100 5525 2225 5525
Wire Wire Line
	2225 5275 2225 5525
$Comp
L local:TFBS4711 U1
U 1 1 610B6C7F
P 1100 2325
F 0 "U1" H 1067 2850 50  0000 C CNN
F 1 "TFBS4711" H 1067 2759 50  0000 C CNN
F 2 "local:FPC_6" H 1150 2425 50  0001 C CNN
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
Wire Wire Line
	2700 4175 3750 4175
Wire Wire Line
	2775 4075 3750 4075
Wire Wire Line
	2625 4375 3750 4375
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
	1400 2325 2625 2325
Wire Wire Line
	2625 2325 2625 4375
Wire Wire Line
	1400 2225 2700 2225
Wire Wire Line
	2700 2225 2700 4175
Wire Wire Line
	1400 2125 2775 2125
Wire Wire Line
	2775 2125 2775 4075
Wire Wire Line
	1975 2525 2075 2525
$Comp
L dk_Alarms-Buzzers-and-Sirens:PS1240P02BT BZ1
U 1 1 5F87649F
P 1225 3325
F 0 "BZ1" H 1323 3078 60  0000 C CNN
F 1 "PS1240P02BT" H 1323 3184 60  0000 C CNN
F 2 "digikey-footprints:Piezo_Transducer_THT_PS1240P02BT" H 1425 3525 60  0001 L CNN
F 3 "https://product.tdk.com/info/en/catalog/datasheets/piezoelectronic_buzzer_ps_en.pdf" H 1425 3625 60  0001 L CNN
F 4 "445-2525-1-ND" H 1425 3725 60  0001 L CNN "Digi-Key_PN"
F 5 "PS1240P02BT" H 1425 3825 60  0001 L CNN "MPN"
F 6 "Audio Products" H 1425 3925 60  0001 L CNN "Category"
F 7 "Alarms, Buzzers, and Sirens" H 1425 4025 60  0001 L CNN "Family"
F 8 "https://product.tdk.com/info/en/catalog/datasheets/piezoelectronic_buzzer_ps_en.pdf" H 1425 4125 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/tdk-corporation/PS1240P02BT/445-2525-1-ND/935930" H 1425 4225 60  0001 L CNN "DK_Detail_Page"
F 10 "AUDIO PIEZO TRANSDUCER 30V TH" H 1425 4325 60  0001 L CNN "Description"
F 11 "TDK Corporation" H 1425 4425 60  0001 L CNN "Manufacturer"
F 12 "Active" H 1425 4525 60  0001 L CNN "Status"
	1    1225 3325
	-1   0    0    1   
$EndComp
Wire Wire Line
	2200 3475 3750 3475
$Comp
L Device:R_POT RV2
U 1 1 5F890273
P 2200 3325
F 0 "RV2" H 2130 3371 50  0000 R CNN
F 1 "2K" H 2130 3280 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2200 3325 50  0001 C CNN
F 3 "~" H 2200 3325 50  0001 C CNN
	1    2200 3325
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5F89CA0B
P 2200 3175
F 0 "#PWR05" H 2200 2925 50  0001 C CNN
F 1 "GND" V 2205 3047 50  0000 R CNN
F 2 "" H 2200 3175 50  0001 C CNN
F 3 "" H 2200 3175 50  0001 C CNN
	1    2200 3175
	-1   0    0    1   
$EndComp
Wire Wire Line
	1325 3325 2050 3325
$Comp
L power:GND #PWR02
U 1 1 5F8A383B
P 1325 3425
F 0 "#PWR02" H 1325 3175 50  0001 C CNN
F 1 "GND" V 1330 3297 50  0000 R CNN
F 2 "" H 1325 3425 50  0001 C CNN
F 3 "" H 1325 3425 50  0001 C CNN
	1    1325 3425
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_PHOTO R1
U 1 1 5F8A50CF
P 1575 6225
F 0 "R1" V 1782 6225 50  0000 C CNN
F 1 "R_PHOTO" V 1691 6225 50  0000 C CNN
F 2 "" V 1625 5975 50  0001 L CNN
F 3 "https://cdn-learn.adafruit.com/downloads/pdf/photocells.pdf" H 1575 6175 50  0001 C CNN
	1    1575 6225
	0    1    -1   0   
$EndComp
Text GLabel 1350 6225 0    50   Input ~ 0
VDD
Wire Wire Line
	1350 6225 1425 6225
$Comp
L Device:R R3
U 1 1 5F8AB810
P 2050 6225
F 0 "R3" V 1843 6225 50  0000 C CNN
F 1 "10K" V 1934 6225 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 1980 6225 50  0001 C CNN
F 3 "~" H 2050 6225 50  0001 C CNN
	1    2050 6225
	0    1    -1   0   
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5F8AC3B2
P 2275 6225
F 0 "#PWR06" H 2275 5975 50  0001 C CNN
F 1 "GND" V 2280 6097 50  0000 R CNN
F 2 "" H 2275 6225 50  0001 C CNN
F 3 "" H 2275 6225 50  0001 C CNN
	1    2275 6225
	0    -1   1    0   
$EndComp
Wire Wire Line
	2200 6225 2275 6225
Wire Wire Line
	1725 6225 1825 6225
Wire Wire Line
	3750 6075 1825 6075
Wire Wire Line
	1825 6075 1825 6225
Connection ~ 1825 6225
Wire Wire Line
	1825 6225 1900 6225
$Comp
L Device:R_POT RV1
U 1 1 5F8C41C9
P 1550 1500
F 0 "RV1" V 1343 1500 50  0000 C CNN
F 1 "100R" V 1434 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1550 1500 50  0001 C CNN
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
NoConn ~ 3750 3375
NoConn ~ 5150 3375
NoConn ~ 5150 3475
NoConn ~ 5150 3675
NoConn ~ 3750 3975
NoConn ~ 3750 4275
NoConn ~ 3750 5875
NoConn ~ 3750 6175
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 5F91B7A4
P 3100 6925
F 0 "J1" V 2972 7305 50  0000 L CNN
F 1 "Conn_01x08" V 3063 7305 50  0000 L CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x08_P2.00mm_Horizontal" H 3100 6925 50  0001 C CNN
F 3 "~" H 3100 6925 50  0001 C CNN
	1    3100 6925
	0    1    1    0   
$EndComp
Text GLabel 3500 6600 2    50   Input ~ 0
VDD
Wire Wire Line
	3400 6725 3400 6600
Wire Wire Line
	3400 6600 3500 6600
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
	3500 6400 3300 6400
Wire Wire Line
	3300 6400 3300 6725
Wire Wire Line
	3000 6725 3000 5475
Wire Wire Line
	3000 5475 3750 5475
Wire Wire Line
	3100 6725 3100 5575
Wire Wire Line
	3100 5575 3750 5575
Wire Wire Line
	3200 6725 3200 5675
Wire Wire Line
	3200 5675 3750 5675
Wire Wire Line
	3625 3550 3625 5975
Wire Wire Line
	2950 2125 2950 3550
Wire Wire Line
	2950 3550 3625 3550
Wire Wire Line
	3750 3675 2850 3675
Wire Wire Line
	2850 3675 2850 4425
Wire Wire Line
	2850 4425 2700 4425
Wire Wire Line
	2700 4425 2700 6725
Wire Wire Line
	3750 3775 2950 3775
Wire Wire Line
	2950 3775 2950 4500
Wire Wire Line
	2950 4500 2800 4500
Wire Wire Line
	2800 4500 2800 6725
Wire Wire Line
	3750 3875 3050 3875
Wire Wire Line
	3050 3875 3050 5375
Wire Wire Line
	3050 5375 2900 5375
Wire Wire Line
	2900 5375 2900 6725
Wire Bus Line
	5775 4875 5775 5175
Wire Bus Line
	5775 4475 5775 4875
Text Notes 2750 7075 0    50   ~ 0
GPIO Expansion
$EndSCHEMATC
