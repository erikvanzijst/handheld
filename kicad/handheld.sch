EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 3
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
Entry Wire Line
	11875 4625 11975 4725
Entry Wire Line
	11875 3425 11975 3525
Entry Wire Line
	11875 3825 11975 3925
Entry Wire Line
	11875 1425 11975 1525
Entry Wire Line
	11875 5425 11975 5525
Entry Wire Line
	11875 6225 11975 6325
Entry Wire Line
	11875 5025 11975 5125
Entry Wire Line
	11875 4225 11975 4325
Entry Wire Line
	11875 2225 11975 2325
Entry Wire Line
	11875 2625 11975 2725
Text Label 11325 5025 0    50   ~ 0
ROW10
Entry Wire Line
	11875 5825 11975 5925
Entry Wire Line
	11875 3025 11975 3125
Text Label 11325 5825 0    50   ~ 0
ROW12
Entry Wire Line
	11875 7425 11975 7525
Text Label 11325 6225 0    50   ~ 0
ROW13
Entry Wire Line
	11875 7025 11975 7125
Text Label 11325 6625 0    50   ~ 0
ROW14
Entry Wire Line
	11875 6625 11975 6725
Text Label 11325 7025 0    50   ~ 0
ROW15
Entry Wire Line
	11875 1825 11975 1925
Text Label 11325 7425 0    50   ~ 0
ROW16
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
L local:P-FET U37
U 2 1 5F09B5FB
P 10950 1775
F 0 "U37" H 10700 1975 50  0000 C CNN
F 1 "P-FET" V 10950 1775 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 2175 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 2175 50  0001 C CNN
	2    10950 1775
	1    0    0    -1  
$EndComp
Text Label 11325 5425 0    50   ~ 0
ROW11
Text Label 11325 3825 0    50   ~ 0
ROW7
Text Label 11325 3425 0    50   ~ 0
ROW6
Text Label 11325 3025 0    50   ~ 0
ROW5
Text Label 11325 2225 0    50   ~ 0
ROW3
Text Label 11325 2625 0    50   ~ 0
ROW4
Text Label 11325 1825 0    50   ~ 0
ROW2
Text Label 11325 1425 0    50   ~ 0
ROW1
$Comp
L local:P-FET U37
U 1 1 5F127DC7
P 10950 1375
F 0 "U37" H 10700 1575 50  0000 C CNN
F 1 "P-FET" V 10950 1375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 1775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 1775 50  0001 C CNN
	1    10950 1375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U38
U 2 1 5F137EE0
P 10950 2575
F 0 "U38" H 10700 2775 50  0000 C CNN
F 1 "P-FET" V 10950 2575 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 2975 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 2975 50  0001 C CNN
	2    10950 2575
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U39
U 2 1 5F15A3EE
P 10950 3375
F 0 "U39" H 10700 3575 50  0000 C CNN
F 1 "P-FET" V 10950 3375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 3775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 3775 50  0001 C CNN
	2    10950 3375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U39
U 1 1 5F15A3F8
P 10950 2975
F 0 "U39" H 10700 3175 50  0000 C CNN
F 1 "P-FET" V 10950 2975 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 3375 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 3375 50  0001 C CNN
	1    10950 2975
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U40
U 2 1 5F15A402
P 10950 4175
F 0 "U40" H 10700 4375 50  0000 C CNN
F 1 "P-FET" V 10950 4175 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 4575 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 4575 50  0001 C CNN
	2    10950 4175
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U40
U 1 1 5F15A40C
P 10950 3775
F 0 "U40" H 10700 3975 50  0000 C CNN
F 1 "P-FET" V 10950 3775 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 4175 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 4175 50  0001 C CNN
	1    10950 3775
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U41
U 1 1 5F17DC71
P 10950 4575
F 0 "U41" H 10700 4775 50  0000 C CNN
F 1 "P-FET" V 10950 4575 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 4975 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 4975 50  0001 C CNN
	1    10950 4575
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U41
U 2 1 5F17DC7B
P 10950 4975
F 0 "U41" H 10700 5175 50  0000 C CNN
F 1 "P-FET" V 10950 4975 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 5375 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 5375 50  0001 C CNN
	2    10950 4975
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U42
U 1 1 5F17DC85
P 10950 5375
F 0 "U42" H 10700 5575 50  0000 C CNN
F 1 "P-FET" V 10950 5375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 5775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 5775 50  0001 C CNN
	1    10950 5375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U42
U 2 1 5F17DC8F
P 10950 5775
F 0 "U42" H 10700 5975 50  0000 C CNN
F 1 "P-FET" V 10950 5775 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 6175 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 6175 50  0001 C CNN
	2    10950 5775
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U43
U 2 1 5F17DC99
P 10950 6575
F 0 "U43" H 10700 6775 50  0000 C CNN
F 1 "P-FET" V 10950 6575 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 6975 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 6975 50  0001 C CNN
	2    10950 6575
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U43
U 1 1 5F17DCA3
P 10950 6175
F 0 "U43" H 10700 6375 50  0000 C CNN
F 1 "P-FET" V 10950 6175 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 6575 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 6575 50  0001 C CNN
	1    10950 6175
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U44
U 2 1 5F17DCAD
P 10950 7375
F 0 "U44" H 10700 7575 50  0000 C CNN
F 1 "P-FET" V 10950 7375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 7775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 7775 50  0001 C CNN
	2    10950 7375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U44
U 1 1 5F17DCB7
P 10950 6975
F 0 "U44" H 10700 7175 50  0000 C CNN
F 1 "P-FET" V 10950 6975 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 7375 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 7375 50  0001 C CNN
	1    10950 6975
	1    0    0    -1  
$EndComp
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
Wire Wire Line
	10650 1325 10600 1325
Wire Wire Line
	10600 7325 10650 7325
Wire Wire Line
	10650 6925 10600 6925
Connection ~ 10600 6925
Wire Wire Line
	10600 6925 10600 7325
Wire Wire Line
	10650 6525 10600 6525
Connection ~ 10600 6525
Wire Wire Line
	10600 6525 10600 6925
Wire Wire Line
	10650 6125 10600 6125
Connection ~ 10600 6125
Wire Wire Line
	10600 6125 10600 6525
Wire Wire Line
	10650 5725 10600 5725
Connection ~ 10600 5725
Wire Wire Line
	10600 5725 10600 6125
Wire Wire Line
	10650 5325 10600 5325
Connection ~ 10600 5325
Wire Wire Line
	10600 5325 10600 5725
Wire Wire Line
	10650 4925 10600 4925
Connection ~ 10600 4925
Wire Wire Line
	10600 4925 10600 5325
Wire Wire Line
	10650 4525 10600 4525
Wire Wire Line
	10600 1325 10600 1725
Connection ~ 10600 4525
Wire Wire Line
	10600 4525 10600 4925
Wire Wire Line
	10650 4125 10600 4125
Connection ~ 10600 4125
Wire Wire Line
	10600 4125 10600 4525
Wire Wire Line
	10650 3725 10600 3725
Connection ~ 10600 3725
Wire Wire Line
	10600 3725 10600 4125
Wire Wire Line
	10650 3325 10600 3325
Connection ~ 10600 3325
Wire Wire Line
	10600 3325 10600 3725
Wire Wire Line
	10650 2925 10600 2925
Connection ~ 10600 2925
Wire Wire Line
	10600 2925 10600 3325
Wire Wire Line
	10650 2525 10600 2525
Connection ~ 10600 2525
Wire Wire Line
	10600 2525 10600 2925
Wire Wire Line
	10650 2125 10600 2125
Connection ~ 10600 2125
Wire Wire Line
	10600 2125 10600 2525
Wire Wire Line
	10650 1725 10600 1725
Connection ~ 10600 1725
Wire Wire Line
	10600 1725 10600 2125
Wire Wire Line
	11875 1425 11250 1425
Wire Wire Line
	11250 1825 11875 1825
Wire Wire Line
	11250 2225 11875 2225
Wire Wire Line
	11250 2625 11875 2625
Wire Wire Line
	11250 3025 11875 3025
Wire Wire Line
	11250 3425 11875 3425
Wire Wire Line
	11250 3825 11875 3825
Wire Wire Line
	11250 4225 11875 4225
Wire Wire Line
	11250 4625 11875 4625
Wire Wire Line
	11250 5025 11875 5025
Wire Wire Line
	11250 5425 11875 5425
Wire Wire Line
	11250 5825 11875 5825
Wire Wire Line
	11250 6225 11875 6225
Wire Wire Line
	11250 6625 11875 6625
Wire Wire Line
	11250 7025 11875 7025
Wire Wire Line
	11250 7425 11875 7425
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
Text Label 11325 4225 0    50   ~ 0
ROW8
Text Label 11325 4625 0    50   ~ 0
ROW9
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
$Comp
L power:GND #PWR012
U 1 1 600982F8
P 8950 3300
F 0 "#PWR012" H 8950 3050 50  0001 C CNN
F 1 "GND" V 8955 3172 50  0000 R CNN
F 2 "" H 8950 3300 50  0001 C CNN
F 3 "" H 8950 3300 50  0001 C CNN
	1    8950 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 6032EDF9
P 8950 6150
F 0 "#PWR014" H 8950 5900 50  0001 C CNN
F 1 "GND" V 8955 6022 50  0000 R CNN
F 2 "" H 8950 6150 50  0001 C CNN
F 3 "" H 8950 6150 50  0001 C CNN
	1    8950 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 2200 9425 2200
Wire Wire Line
	9425 2200 9425 1425
Wire Wire Line
	9425 1425 10650 1425
Wire Wire Line
	9350 2300 9525 2300
Wire Wire Line
	9525 2300 9525 1825
Wire Wire Line
	9525 1825 10650 1825
Wire Wire Line
	9350 2400 9625 2400
Wire Wire Line
	9625 2400 9625 2225
Wire Wire Line
	9625 2225 10650 2225
Wire Wire Line
	9350 2900 9425 2900
Wire Wire Line
	9425 2900 9425 4225
Wire Wire Line
	9425 4225 10650 4225
Wire Wire Line
	9350 2800 9525 2800
Wire Wire Line
	9525 2800 9525 3825
Wire Wire Line
	9525 3825 10650 3825
Wire Wire Line
	9350 2700 9625 2700
Wire Wire Line
	9625 2700 9625 3425
Wire Wire Line
	9625 3425 10650 3425
Wire Wire Line
	9350 2600 9725 2600
Wire Wire Line
	9725 2600 9725 3025
Wire Wire Line
	9725 3025 10650 3025
Wire Wire Line
	9350 2500 9825 2500
Wire Wire Line
	9825 2500 9825 2625
Wire Wire Line
	9825 2625 10650 2625
Wire Wire Line
	9350 5050 9425 5050
Wire Wire Line
	9425 5050 9425 4625
Wire Wire Line
	9425 4625 10650 4625
Wire Wire Line
	9350 5150 9525 5150
Wire Wire Line
	9525 5150 9525 5025
Wire Wire Line
	9525 5025 10650 5025
Wire Wire Line
	9350 5250 9925 5250
Wire Wire Line
	9925 5250 9925 5425
Wire Wire Line
	9925 5425 10650 5425
Wire Wire Line
	9350 5750 9425 5750
Wire Wire Line
	9425 5750 9425 7425
Wire Wire Line
	9425 7425 10650 7425
Wire Wire Line
	9350 5650 9525 5650
Wire Wire Line
	9525 5650 9525 7025
Wire Wire Line
	9525 7025 10650 7025
Wire Wire Line
	9350 5550 9625 5550
Wire Wire Line
	9625 5550 9625 6625
Wire Wire Line
	9625 6625 10650 6625
Wire Wire Line
	9350 5450 9725 5450
Wire Wire Line
	9725 5450 9725 6225
Wire Wire Line
	9725 6225 10650 6225
Wire Wire Line
	9350 5350 9825 5350
Wire Wire Line
	9825 5350 9825 5825
Wire Wire Line
	9825 5825 10650 5825
$Comp
L 74xx:74HCT595 U22
U 1 1 5F2F5F11
P 8950 2600
F 0 "U22" H 8700 3150 50  0000 C CNN
F 1 "74HCT595" V 9025 2600 50  0000 C CNN
F 2 "" H 8950 2600 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT595.pdf" H 8950 2600 50  0001 C CNN
	1    8950 2600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HCT595 U23
U 1 1 5F2F7A3D
P 8950 5450
F 0 "U23" H 8700 6000 50  0000 C CNN
F 1 "74HCT595" V 9025 5375 50  0000 C CNN
F 2 "" H 8950 5450 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT595.pdf" H 8950 5450 50  0001 C CNN
	1    8950 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C6
U 1 1 5F2FACBD
P 8950 4575
F 0 "C6" V 8698 4575 50  0000 C CNN
F 1 "100nF" V 8789 4575 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 8988 4425 50  0001 C CNN
F 3 "~" H 8950 4575 50  0001 C CNN
	1    8950 4575
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5F2FACC7
P 8950 4425
F 0 "#PWR013" H 8950 4175 50  0001 C CNN
F 1 "GND" V 8955 4297 50  0000 R CNN
F 2 "" H 8950 4425 50  0001 C CNN
F 3 "" H 8950 4425 50  0001 C CNN
	1    8950 4425
	-1   0    0    1   
$EndComp
Wire Wire Line
	8950 4725 8950 4750
$Comp
L Device:C C5
U 1 1 5F34EBF1
P 8950 1725
F 0 "C5" V 8698 1725 50  0000 C CNN
F 1 "100nF" V 8789 1725 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 8988 1575 50  0001 C CNN
F 3 "~" H 8950 1725 50  0001 C CNN
	1    8950 1725
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5F34EBFB
P 8950 1575
F 0 "#PWR011" H 8950 1325 50  0001 C CNN
F 1 "GND" V 8955 1447 50  0000 R CNN
F 2 "" H 8950 1575 50  0001 C CNN
F 3 "" H 8950 1575 50  0001 C CNN
	1    8950 1575
	-1   0    0    1   
$EndComp
Wire Wire Line
	8950 1875 8950 2000
Connection ~ 8950 1875
Wire Wire Line
	5375 4950 8025 4950
Wire Wire Line
	8025 4950 8025 2200
Wire Wire Line
	8025 2200 8550 2200
Wire Wire Line
	9350 3100 9350 3825
Wire Wire Line
	9350 3825 8550 3825
Wire Wire Line
	8550 3825 8550 5050
Wire Wire Line
	8400 5050 8400 2400
Wire Wire Line
	5375 5050 8400 5050
Wire Wire Line
	8400 2400 8550 2400
Wire Wire Line
	8400 5050 8400 5250
Wire Wire Line
	8400 5250 8550 5250
Connection ~ 8400 5050
Wire Wire Line
	8200 5150 8200 5550
Wire Wire Line
	8200 5550 8550 5550
Wire Wire Line
	8200 5150 8200 2700
Wire Wire Line
	8200 2700 8550 2700
Connection ~ 8200 5150
Wire Wire Line
	8475 1875 8475 2500
Wire Wire Line
	8475 2500 8550 2500
Wire Wire Line
	8475 2500 8475 4750
Wire Wire Line
	8475 5350 8550 5350
Connection ~ 8475 2500
Wire Wire Line
	8950 4750 8475 4750
Connection ~ 8950 4750
Wire Wire Line
	8950 4750 8950 4850
Connection ~ 8475 4750
Wire Wire Line
	8475 4750 8475 5350
Wire Wire Line
	8550 2800 8300 2800
Wire Wire Line
	8300 2800 8300 5650
Wire Wire Line
	8300 5650 8550 5650
Wire Wire Line
	8300 5650 8300 5850
Wire Wire Line
	5600 5850 5600 6150
Connection ~ 8300 5650
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
Wire Wire Line
	10375 1325 10600 1325
Connection ~ 10600 1325
$Sheet
S 12800 7375 1125 575 
U 5F613F5E
F0 "matrix" 50
F1 "matrix.sch" 50
F2 "ROW[1..16]" U L 12800 7600 50 
F3 "COL[0..23]" U L 12800 7800 50 
$EndSheet
Wire Bus Line
	12800 7600 11975 7600
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
	8300 5850 5600 5850
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
NoConn ~ 9350 5950
NoConn ~ 11250 1325
Text Label 12150 7800 0    50   ~ 0
COL[0..23]
Text Label 12150 7600 0    50   ~ 0
ROW[1..16]
$Comp
L local:P-FET U38
U 1 1 5F137EEA
P 10950 2175
F 0 "U38" H 10700 2375 50  0000 C CNN
F 1 "P-FET" V 10950 2175 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 2575 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 2575 50  0001 C CNN
	1    10950 2175
	1    0    0    -1  
$EndComp
NoConn ~ 11250 1725
NoConn ~ 11250 2125
NoConn ~ 11250 2525
NoConn ~ 11250 2925
NoConn ~ 11250 3325
NoConn ~ 11250 3725
NoConn ~ 11250 4125
NoConn ~ 11250 4525
NoConn ~ 11250 4925
NoConn ~ 11250 5325
NoConn ~ 11250 5725
NoConn ~ 11250 6125
NoConn ~ 11250 6525
NoConn ~ 11250 6925
NoConn ~ 11250 7325
Wire Wire Line
	3350 2125 3700 2125
Wire Wire Line
	8475 1875 8950 1875
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
Wire Wire Line
	5375 5150 8200 5150
$Comp
L local:SN54LV574 U36
U 1 1 5F882467
P 10800 9925
F 0 "U36" V 11000 9125 50  0000 R CNN
F 1 "SN54LV574" V 11100 9400 50  0000 R CNN
F 2 "Package_SO:SO-20_5.3x12.6mm_P1.27mm" H 10850 9125 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/sn74lv574a.pdf" H 10800 9925 50  0001 C CNN
	1    10800 9925
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U49
U 1 1 5F8845AA
P 11650 8950
F 0 "U49" V 11900 9200 50  0000 R CNN
F 1 "DMN601" V 11650 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 11650 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 11650 8950 50  0001 C CNN
	1    11650 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U46
U 1 1 5F885684
P 11150 8950
F 0 "U46" V 11400 9200 50  0000 R CNN
F 1 "DMN601" V 11150 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 11150 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 11150 8950 50  0001 C CNN
	1    11150 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U34
U 1 1 5F886130
P 10650 8950
F 0 "U34" V 10900 9200 50  0000 R CNN
F 1 "DMN601" V 10650 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 10650 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 10650 8950 50  0001 C CNN
	1    10650 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U31
U 1 1 5F886A46
P 10150 8950
F 0 "U31" V 10400 9200 50  0000 R CNN
F 1 "DMN601" V 10150 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 10150 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 10150 8950 50  0001 C CNN
	1    10150 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U28
U 1 1 5F887530
P 9650 8950
F 0 "U28" V 9900 9200 50  0000 R CNN
F 1 "DMN601" V 9650 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 9650 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 9650 8950 50  0001 C CNN
	1    9650 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U25
U 1 1 5F88753A
P 9150 8950
F 0 "U25" V 9400 9200 50  0000 R CNN
F 1 "DMN601" V 9150 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 9150 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 9150 8950 50  0001 C CNN
	1    9150 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U19
U 1 1 5F887544
P 8650 8950
F 0 "U19" V 8900 9200 50  0000 R CNN
F 1 "DMN601" V 8650 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 8650 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 8650 8950 50  0001 C CNN
	1    8650 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U16
U 1 1 5F88754E
P 8150 8950
F 0 "U16" V 8400 9200 50  0000 R CNN
F 1 "DMN601" V 8150 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 8150 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 8150 8950 50  0001 C CNN
	1    8150 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U13
U 1 1 5F8983CB
P 7650 8950
F 0 "U13" V 7900 9200 50  0000 R CNN
F 1 "DMN601" V 7650 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 7650 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 7650 8950 50  0001 C CNN
	1    7650 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U10
U 1 1 5F8983D5
P 7150 8950
F 0 "U10" V 7400 9200 50  0000 R CNN
F 1 "DMN601" V 7150 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 7150 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 7150 8950 50  0001 C CNN
	1    7150 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U6
U 1 1 5F8983DF
P 6650 8950
F 0 "U6" V 6900 9200 50  0000 R CNN
F 1 "DMN601" V 6650 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 6650 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 6650 8950 50  0001 C CNN
	1    6650 8950
	0    -1   -1   0   
$EndComp
$Comp
L local:DMN601 U3
U 1 1 5F8983E9
P 6150 8950
F 0 "U3" V 6400 9225 50  0000 R CNN
F 1 "DMN601" V 6150 9050 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 6150 8650 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds30657.pdf" H 6150 8950 50  0001 C CNN
	1    6150 8950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6050 9250 6050 9300
Wire Wire Line
	6050 9300 6250 9300
Wire Wire Line
	11750 9250 11750 9300
Connection ~ 11750 9300
Wire Wire Line
	11750 9300 12175 9300
Wire Wire Line
	11550 9250 11550 9300
Connection ~ 11550 9300
Wire Wire Line
	11550 9300 11750 9300
Wire Wire Line
	11250 9250 11250 9300
Connection ~ 11250 9300
Wire Wire Line
	11250 9300 11550 9300
Wire Wire Line
	11050 9250 11050 9300
Connection ~ 11050 9300
Wire Wire Line
	11050 9300 11250 9300
Wire Wire Line
	10750 9250 10750 9300
Connection ~ 10750 9300
Wire Wire Line
	10750 9300 11050 9300
Wire Wire Line
	10550 9250 10550 9300
Connection ~ 10550 9300
Wire Wire Line
	10550 9300 10750 9300
Wire Wire Line
	10250 9250 10250 9300
Connection ~ 10250 9300
Wire Wire Line
	10250 9300 10550 9300
Wire Wire Line
	10050 9250 10050 9300
Connection ~ 10050 9300
Wire Wire Line
	9750 9250 9750 9300
Connection ~ 9750 9300
Wire Wire Line
	9750 9300 10050 9300
Wire Wire Line
	9550 9250 9550 9300
Connection ~ 9550 9300
Wire Wire Line
	9550 9300 9750 9300
Wire Wire Line
	9250 9250 9250 9300
Connection ~ 9250 9300
Wire Wire Line
	9250 9300 9550 9300
Wire Wire Line
	9050 9250 9050 9300
Connection ~ 9050 9300
Wire Wire Line
	9050 9300 9250 9300
Wire Wire Line
	8750 9250 8750 9300
Connection ~ 8750 9300
Wire Wire Line
	8750 9300 9050 9300
Wire Wire Line
	8550 9250 8550 9300
Connection ~ 8550 9300
Wire Wire Line
	8550 9300 8750 9300
Wire Wire Line
	8250 9250 8250 9300
Connection ~ 8250 9300
Wire Wire Line
	8250 9300 8550 9300
Wire Wire Line
	8050 9250 8050 9300
Connection ~ 8050 9300
Wire Wire Line
	8050 9300 8250 9300
Wire Wire Line
	7750 9250 7750 9300
Connection ~ 7750 9300
Wire Wire Line
	7750 9300 8050 9300
Wire Wire Line
	7550 9250 7550 9300
Connection ~ 7550 9300
Wire Wire Line
	7550 9300 7750 9300
Wire Wire Line
	7250 9250 7250 9300
Connection ~ 7250 9300
Wire Wire Line
	7250 9300 7550 9300
Wire Wire Line
	7050 9250 7050 9300
Connection ~ 7050 9300
Wire Wire Line
	7050 9300 7250 9300
Wire Wire Line
	6750 9250 6750 9300
Connection ~ 6750 9300
Wire Wire Line
	6750 9300 7050 9300
Wire Wire Line
	6550 9250 6550 9300
Connection ~ 6550 9300
Wire Wire Line
	6550 9300 6750 9300
Wire Wire Line
	6250 9250 6250 9300
Connection ~ 6250 9300
Wire Wire Line
	6250 9300 6550 9300
$Comp
L power:GND #PWR018
U 1 1 5FA01FCB
P 12175 9300
F 0 "#PWR018" H 12175 9050 50  0001 C CNN
F 1 "GND" V 12180 9172 50  0000 R CNN
F 2 "" H 12175 9300 50  0001 C CNN
F 3 "" H 12175 9300 50  0001 C CNN
	1    12175 9300
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5FA030DD
P 11650 9875
F 0 "#PWR017" H 11650 9625 50  0001 C CNN
F 1 "GND" V 11655 9747 50  0000 R CNN
F 2 "" H 11650 9875 50  0001 C CNN
F 3 "" H 11650 9875 50  0001 C CNN
	1    11650 9875
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 9250 10150 9525
Wire Wire Line
	10150 9525 10550 9525
Wire Wire Line
	10550 9525 10550 9575
Wire Wire Line
	10350 9250 10350 9475
Wire Wire Line
	10350 9475 10650 9475
Wire Wire Line
	10650 9475 10650 9575
Wire Wire Line
	10650 9250 10650 9425
Wire Wire Line
	10650 9425 10750 9425
Wire Wire Line
	10750 9425 10750 9575
Wire Wire Line
	10850 9250 10850 9575
Wire Wire Line
	11850 9250 11850 9525
Wire Wire Line
	11850 9525 11250 9525
Wire Wire Line
	11250 9525 11250 9575
Wire Wire Line
	11650 9250 11650 9475
Wire Wire Line
	11650 9475 11150 9475
Wire Wire Line
	11150 9475 11150 9575
Wire Wire Line
	11350 9250 11350 9425
Wire Wire Line
	11350 9425 11050 9425
Wire Wire Line
	11050 9425 11050 9575
Wire Wire Line
	11150 9250 11150 9375
Wire Wire Line
	11150 9375 10950 9375
Wire Wire Line
	10950 9375 10950 9575
$Comp
L Device:C C7
U 1 1 5FA96AAE
P 10400 9775
F 0 "C7" H 10200 9775 50  0000 C CNN
F 1 "100nF" V 10200 9600 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 10438 9625 50  0001 C CNN
F 3 "~" H 10400 9775 50  0001 C CNN
	1    10400 9775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5FA9A6DC
P 10400 9625
F 0 "#PWR016" H 10400 9375 50  0001 C CNN
F 1 "GND" V 10405 9497 50  0000 R CNN
F 2 "" H 10400 9625 50  0001 C CNN
F 3 "" H 10400 9625 50  0001 C CNN
	1    10400 9625
	0    1    1    0   
$EndComp
Wire Wire Line
	10400 9925 10400 9975
Connection ~ 10400 9925
$Comp
L local:SN54LV574 U21
U 1 1 5FAAF889
P 8800 9925
F 0 "U21" V 9000 9125 50  0000 R CNN
F 1 "SN54LV574" V 9100 9400 50  0000 R CNN
F 2 "Package_SO:SO-20_5.3x12.6mm_P1.27mm" H 8850 9125 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/sn74lv574a.pdf" H 8800 9925 50  0001 C CNN
	1    8800 9925
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5FAAF89D
P 9650 9875
F 0 "#PWR015" H 9650 9625 50  0001 C CNN
F 1 "GND" V 9655 9747 50  0000 R CNN
F 2 "" H 9650 9875 50  0001 C CNN
F 3 "" H 9650 9875 50  0001 C CNN
	1    9650 9875
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8150 9250 8150 9525
Wire Wire Line
	8150 9525 8550 9525
Wire Wire Line
	8550 9525 8550 9575
Wire Wire Line
	8350 9250 8350 9475
Wire Wire Line
	8350 9475 8650 9475
Wire Wire Line
	8650 9475 8650 9575
Wire Wire Line
	8650 9250 8650 9425
Wire Wire Line
	8650 9425 8750 9425
Wire Wire Line
	8750 9425 8750 9575
Wire Wire Line
	8850 9250 8850 9575
Wire Wire Line
	9850 9250 9850 9525
Wire Wire Line
	9850 9525 9250 9525
Wire Wire Line
	9250 9525 9250 9575
Wire Wire Line
	9650 9250 9650 9475
Wire Wire Line
	9650 9475 9150 9475
Wire Wire Line
	9150 9475 9150 9575
Wire Wire Line
	9350 9250 9350 9425
Wire Wire Line
	9350 9425 9050 9425
Wire Wire Line
	9050 9425 9050 9575
Wire Wire Line
	9150 9250 9150 9375
Wire Wire Line
	9150 9375 8950 9375
Wire Wire Line
	8950 9375 8950 9575
$Comp
L Device:C C4
U 1 1 5FAAF8BD
P 8400 9775
F 0 "C4" H 8200 9775 50  0000 C CNN
F 1 "100nF" V 8200 9600 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 8438 9625 50  0001 C CNN
F 3 "~" H 8400 9775 50  0001 C CNN
	1    8400 9775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5FAAF8C8
P 8400 9625
F 0 "#PWR010" H 8400 9375 50  0001 C CNN
F 1 "GND" V 8405 9497 50  0000 R CNN
F 2 "" H 8400 9625 50  0001 C CNN
F 3 "" H 8400 9625 50  0001 C CNN
	1    8400 9625
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 9925 8400 9975
Connection ~ 8400 9925
Wire Wire Line
	10050 9300 10250 9300
$Comp
L local:SN54LV574 U8
U 1 1 5FACCAD9
P 6800 9925
F 0 "U8" V 7000 9125 50  0000 R CNN
F 1 "SN54LV574" V 7100 9400 50  0000 R CNN
F 2 "Package_SO:SO-20_5.3x12.6mm_P1.27mm" H 6850 9125 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/sn74lv574a.pdf" H 6800 9925 50  0001 C CNN
	1    6800 9925
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5FACCAE3
P 7650 9875
F 0 "#PWR09" H 7650 9625 50  0001 C CNN
F 1 "GND" V 7655 9747 50  0000 R CNN
F 2 "" H 7650 9875 50  0001 C CNN
F 3 "" H 7650 9875 50  0001 C CNN
	1    7650 9875
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 9250 6150 9525
Wire Wire Line
	6150 9525 6550 9525
Wire Wire Line
	6550 9525 6550 9575
Wire Wire Line
	6350 9250 6350 9475
Wire Wire Line
	6350 9475 6650 9475
Wire Wire Line
	6650 9475 6650 9575
Wire Wire Line
	6650 9250 6650 9425
Wire Wire Line
	6650 9425 6750 9425
Wire Wire Line
	6750 9425 6750 9575
Wire Wire Line
	6850 9250 6850 9575
Wire Wire Line
	7850 9250 7850 9525
Wire Wire Line
	7850 9525 7250 9525
Wire Wire Line
	7250 9525 7250 9575
Wire Wire Line
	7650 9250 7650 9475
Wire Wire Line
	7650 9475 7150 9475
Wire Wire Line
	7150 9475 7150 9575
Wire Wire Line
	7350 9250 7350 9425
Wire Wire Line
	7350 9425 7050 9425
Wire Wire Line
	7050 9425 7050 9575
Wire Wire Line
	7150 9250 7150 9375
Wire Wire Line
	7150 9375 6950 9375
Wire Wire Line
	6950 9375 6950 9575
$Comp
L Device:C C3
U 1 1 5FACCB03
P 6400 9775
F 0 "C3" H 6200 9775 50  0000 C CNN
F 1 "100nF" V 6200 9600 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 6438 9625 50  0001 C CNN
F 3 "~" H 6400 9775 50  0001 C CNN
	1    6400 9775
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5FACCB0E
P 6400 9625
F 0 "#PWR06" H 6400 9375 50  0001 C CNN
F 1 "GND" V 6405 9497 50  0000 R CNN
F 2 "" H 6400 9625 50  0001 C CNN
F 3 "" H 6400 9625 50  0001 C CNN
	1    6400 9625
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 9925 6400 9975
Connection ~ 6400 9925
Wire Wire Line
	6550 10225 6550 10275
Wire Wire Line
	6550 10275 8550 10275
Wire Wire Line
	10550 10275 10550 10225
Wire Wire Line
	8550 10225 8550 10275
Connection ~ 8550 10275
Wire Wire Line
	8550 10275 10550 10275
Wire Wire Line
	6650 10225 6650 10325
Wire Wire Line
	6650 10325 8650 10325
Wire Wire Line
	10650 10325 10650 10225
Wire Wire Line
	8650 10225 8650 10325
Connection ~ 8650 10325
Wire Wire Line
	8650 10325 10650 10325
Wire Wire Line
	6750 10225 6750 10375
Wire Wire Line
	6750 10375 8750 10375
Wire Wire Line
	10750 10375 10750 10225
Wire Wire Line
	8750 10225 8750 10375
Connection ~ 8750 10375
Wire Wire Line
	8750 10375 10750 10375
Wire Wire Line
	6850 10225 6850 10425
Wire Wire Line
	6850 10425 8850 10425
Wire Wire Line
	10850 10425 10850 10225
Wire Wire Line
	8850 10225 8850 10425
Connection ~ 8850 10425
Wire Wire Line
	8850 10425 10850 10425
Wire Wire Line
	6950 10225 6950 10475
Wire Wire Line
	6950 10475 8950 10475
Wire Wire Line
	10950 10475 10950 10225
Wire Wire Line
	8950 10225 8950 10475
Connection ~ 8950 10475
Wire Wire Line
	8950 10475 10950 10475
Wire Wire Line
	7050 10225 7050 10525
Wire Wire Line
	7050 10525 9050 10525
Wire Wire Line
	11050 10525 11050 10225
Wire Wire Line
	9050 10225 9050 10525
Connection ~ 9050 10525
Wire Wire Line
	9050 10525 11050 10525
Wire Wire Line
	7150 10225 7150 10575
Wire Wire Line
	7150 10575 9150 10575
Wire Wire Line
	11150 10575 11150 10225
Wire Wire Line
	9150 10225 9150 10575
Connection ~ 9150 10575
Wire Wire Line
	9150 10575 11150 10575
Wire Wire Line
	7250 10225 7250 10625
Wire Wire Line
	7250 10625 9250 10625
Wire Wire Line
	11250 10625 11250 10225
Wire Wire Line
	9250 10225 9250 10625
Connection ~ 9250 10625
Wire Wire Line
	9250 10625 11250 10625
Wire Wire Line
	7500 10225 7500 10675
Wire Wire Line
	7500 10675 9500 10675
Wire Wire Line
	11500 10675 11500 10225
Wire Wire Line
	9500 10225 9500 10675
Connection ~ 9500 10675
Wire Wire Line
	9500 10675 11500 10675
Text GLabel 6400 9975 3    50   UnSpc ~ 0
U_PWR
Text GLabel 8400 9975 3    50   UnSpc ~ 0
U_PWR
Text GLabel 10400 9975 3    50   UnSpc ~ 0
U_PWR
$Comp
L local:NSI45015 U50
U 1 1 5FD6DFCE
P 11800 8400
F 0 "U50" V 11600 8400 50  0000 L CNN
F 1 "NSI45015" H 11650 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 11800 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 11800 8400 50  0001 C CNN
	1    11800 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U48
U 1 1 5FD6EBD4
P 11600 8400
F 0 "U48" V 11400 8400 50  0000 L CNN
F 1 "NSI45015" H 11450 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 11600 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 11600 8400 50  0001 C CNN
	1    11600 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U47
U 1 1 5FD92681
P 11300 8400
F 0 "U47" V 11100 8400 50  0000 L CNN
F 1 "NSI45015" H 11150 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 11300 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 11300 8400 50  0001 C CNN
	1    11300 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U45
U 1 1 5FD9268B
P 11100 8400
F 0 "U45" V 10900 8400 50  0000 L CNN
F 1 "NSI45015" H 10950 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 11100 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 11100 8400 50  0001 C CNN
	1    11100 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U35
U 1 1 5FDB6573
P 10800 8400
F 0 "U35" V 10600 8400 50  0000 L CNN
F 1 "NSI45015" H 10650 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 10800 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 10800 8400 50  0001 C CNN
	1    10800 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U33
U 1 1 5FDB657D
P 10600 8400
F 0 "U33" V 10400 8400 50  0000 L CNN
F 1 "NSI45015" H 10450 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 10600 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 10600 8400 50  0001 C CNN
	1    10600 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U32
U 1 1 5FDB6587
P 10300 8400
F 0 "U32" V 10100 8400 50  0000 L CNN
F 1 "NSI45015" H 10150 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 10300 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 10300 8400 50  0001 C CNN
	1    10300 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U30
U 1 1 5FDB6591
P 10100 8400
F 0 "U30" V 9900 8400 50  0000 L CNN
F 1 "NSI45015" H 9950 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 10100 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 10100 8400 50  0001 C CNN
	1    10100 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U29
U 1 1 5FDDB1ED
P 9800 8400
F 0 "U29" V 9600 8400 50  0000 L CNN
F 1 "NSI45015" H 9650 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 9800 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 9800 8400 50  0001 C CNN
	1    9800 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U27
U 1 1 5FDDB1F7
P 9600 8400
F 0 "U27" V 9400 8400 50  0000 L CNN
F 1 "NSI45015" H 9450 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 9600 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 9600 8400 50  0001 C CNN
	1    9600 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U26
U 1 1 5FDDB201
P 9300 8400
F 0 "U26" V 9100 8400 50  0000 L CNN
F 1 "NSI45015" H 9150 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 9300 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 9300 8400 50  0001 C CNN
	1    9300 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U24
U 1 1 5FDDB20B
P 9100 8400
F 0 "U24" V 8900 8400 50  0000 L CNN
F 1 "NSI45015" H 8950 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 9100 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 9100 8400 50  0001 C CNN
	1    9100 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U20
U 1 1 5FDDB215
P 8800 8400
F 0 "U20" V 8600 8400 50  0000 L CNN
F 1 "NSI45015" H 8650 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 8800 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 8800 8400 50  0001 C CNN
	1    8800 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U18
U 1 1 5FDDB21F
P 8600 8400
F 0 "U18" V 8400 8400 50  0000 L CNN
F 1 "NSI45015" H 8450 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 8600 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 8600 8400 50  0001 C CNN
	1    8600 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U17
U 1 1 5FDDB229
P 8300 8400
F 0 "U17" V 8100 8400 50  0000 L CNN
F 1 "NSI45015" H 8150 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 8300 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 8300 8400 50  0001 C CNN
	1    8300 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U15
U 1 1 5FDDB233
P 8100 8400
F 0 "U15" V 7900 8400 50  0000 L CNN
F 1 "NSI45015" H 7950 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 8100 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 8100 8400 50  0001 C CNN
	1    8100 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U14
U 1 1 5FE02F61
P 7800 8400
F 0 "U14" V 7600 8400 50  0000 L CNN
F 1 "NSI45015" H 7650 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 7800 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 7800 8400 50  0001 C CNN
	1    7800 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U12
U 1 1 5FE02F6B
P 7600 8400
F 0 "U12" V 7400 8400 50  0000 L CNN
F 1 "NSI45015" H 7450 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 7600 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 7600 8400 50  0001 C CNN
	1    7600 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U11
U 1 1 5FE02F75
P 7300 8400
F 0 "U11" V 7100 8400 50  0000 L CNN
F 1 "NSI45015" H 7150 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 7300 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 7300 8400 50  0001 C CNN
	1    7300 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U9
U 1 1 5FE02F7F
P 7100 8400
F 0 "U9" V 6900 8400 50  0000 L CNN
F 1 "NSI45015" H 6950 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 7100 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 7100 8400 50  0001 C CNN
	1    7100 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U7
U 1 1 5FE02F89
P 6800 8400
F 0 "U7" V 6600 8400 50  0000 L CNN
F 1 "NSI45015" H 6650 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 6800 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 6800 8400 50  0001 C CNN
	1    6800 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U5
U 1 1 5FE02F93
P 6600 8400
F 0 "U5" V 6400 8400 50  0000 L CNN
F 1 "NSI45015" H 6450 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 6600 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 6600 8400 50  0001 C CNN
	1    6600 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U4
U 1 1 5FE02F9D
P 6300 8400
F 0 "U4" V 6100 8400 50  0000 L CNN
F 1 "NSI45015" H 6150 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 6300 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 6300 8400 50  0001 C CNN
	1    6300 8400
	0    1    -1   0   
$EndComp
$Comp
L local:NSI45015 U2
U 1 1 5FE02FA7
P 6100 8400
F 0 "U2" V 5900 8400 50  0000 L CNN
F 1 "NSI45015" H 5950 8500 50  0000 L CNN
F 2 "digikey-footprints:SOD-123" H 6100 8300 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NSI45015W-D.PDF" H 6100 8400 50  0001 C CNN
	1    6100 8400
	0    1    -1   0   
$EndComp
Entry Wire Line
	11800 7900 11900 7800
Entry Wire Line
	11600 7900 11700 7800
Entry Wire Line
	11300 7900 11400 7800
Entry Wire Line
	11100 7900 11200 7800
Entry Wire Line
	10800 7900 10900 7800
Entry Wire Line
	10600 7900 10700 7800
Entry Wire Line
	10300 7900 10400 7800
Entry Wire Line
	10100 7900 10200 7800
Entry Wire Line
	9800 7900 9900 7800
Entry Wire Line
	9600 7900 9700 7800
Entry Wire Line
	9300 7900 9400 7800
Entry Wire Line
	9100 7900 9200 7800
Entry Wire Line
	8800 7900 8900 7800
Entry Wire Line
	8600 7900 8700 7800
Entry Wire Line
	8300 7900 8400 7800
Entry Wire Line
	8100 7900 8200 7800
Entry Wire Line
	7800 7900 7900 7800
Entry Wire Line
	7600 7900 7700 7800
Entry Wire Line
	7300 7900 7400 7800
Entry Wire Line
	7100 7900 7200 7800
Entry Wire Line
	6800 7900 6900 7800
Entry Wire Line
	6600 7900 6700 7800
Entry Wire Line
	6300 7900 6400 7800
Entry Wire Line
	6100 7900 6200 7800
Wire Wire Line
	11800 8150 11800 7900
Text Label 11800 8150 1    50   ~ 0
COL23
Wire Wire Line
	11600 8150 11600 7900
Text Label 11600 8150 1    50   ~ 0
COL22
Wire Wire Line
	11300 8150 11300 7900
Text Label 11300 8150 1    50   ~ 0
COL21
Wire Wire Line
	11100 8150 11100 7900
Text Label 11100 8150 1    50   ~ 0
COL20
Wire Wire Line
	10800 8150 10800 7900
Text Label 10800 8150 1    50   ~ 0
COL19
Wire Wire Line
	10600 8150 10600 7900
Text Label 10600 8150 1    50   ~ 0
COL18
Wire Wire Line
	10300 8150 10300 7900
Text Label 10300 8150 1    50   ~ 0
COL17
Wire Wire Line
	10100 8150 10100 7900
Text Label 10100 8150 1    50   ~ 0
COL16
Wire Wire Line
	9800 8150 9800 7900
Text Label 9800 8150 1    50   ~ 0
COL15
Wire Wire Line
	9600 8150 9600 7900
Text Label 9600 8150 1    50   ~ 0
COL14
Wire Wire Line
	9300 8150 9300 7900
Text Label 9300 8150 1    50   ~ 0
COL13
Wire Wire Line
	9100 8150 9100 7900
Text Label 9100 8150 1    50   ~ 0
COL12
Wire Wire Line
	8800 8150 8800 7900
Text Label 8800 8150 1    50   ~ 0
COL11
Wire Wire Line
	8600 8150 8600 7900
Text Label 8600 8150 1    50   ~ 0
COL10
Wire Wire Line
	8300 8150 8300 7900
Text Label 8300 8150 1    50   ~ 0
COL9
Wire Wire Line
	8100 8150 8100 7900
Text Label 8100 8150 1    50   ~ 0
COL8
Wire Wire Line
	7800 8150 7800 7900
Text Label 7800 8150 1    50   ~ 0
COL7
Wire Wire Line
	7600 8150 7600 7900
Text Label 7600 8150 1    50   ~ 0
COL6
Wire Wire Line
	7300 8150 7300 7900
Text Label 7300 8150 1    50   ~ 0
COL5
Wire Wire Line
	7100 8150 7100 7900
Text Label 7100 8150 1    50   ~ 0
COL4
Wire Wire Line
	6800 8150 6800 7900
Text Label 6800 8150 1    50   ~ 0
COL3
Wire Wire Line
	6600 8150 6600 7900
Text Label 6600 8150 1    50   ~ 0
COL2
Wire Wire Line
	6300 8150 6300 7900
Text Label 6300 8150 1    50   ~ 0
COL1
Wire Wire Line
	6100 8150 6100 7900
Text Label 6100 8150 1    50   ~ 0
COL0
Text GLabel 8475 1875 0    50   UnSpc ~ 0
U_PWR
Text GLabel 10375 1325 0    50   UnSpc ~ 0
U_PWR
Wire Bus Line
	11975 1525 11975 7600
Wire Bus Line
	6150 7800 12800 7800
$EndSCHEMATC
