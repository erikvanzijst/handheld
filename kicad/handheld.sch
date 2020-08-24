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
$Comp
L local:TLC59025 U2
U 1 1 5EE0C466
P 7650 8675
F 0 "U2" V 8150 7800 50  0000 R CNN
F 1 "TLC59025" V 7650 8875 50  0000 R CNN
F 2 "local:SSOP-24_3.9x8.7mm_P0.635mm_widepads" H 7650 8675 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tlc59025.pdf" H 7650 8675 50  0001 C CNN
	1    7650 8675
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6900 8125 6900 7900
Wire Wire Line
	7000 7900 7000 8125
Wire Wire Line
	7100 8125 7100 7900
Wire Wire Line
	7200 7900 7200 8125
Wire Wire Line
	7300 8125 7300 7900
Wire Wire Line
	7400 7900 7400 8125
Wire Wire Line
	7500 8125 7500 7900
Wire Wire Line
	7600 7900 7600 8125
Text Label 6900 8125 1    50   ~ 0
COL0
Text Label 7000 8125 1    50   ~ 0
COL1
Text Label 7100 8125 1    50   ~ 0
COL2
Text Label 7200 8125 1    50   ~ 0
COL3
Text Label 7300 8125 1    50   ~ 0
COL4
Text Label 7400 8125 1    50   ~ 0
COL5
Text Label 7500 8125 1    50   ~ 0
COL6
Text Label 7600 8125 1    50   ~ 0
COL7
Entry Wire Line
	7600 7900 7700 7800
Entry Wire Line
	7500 7900 7600 7800
Entry Wire Line
	7400 7900 7500 7800
Entry Wire Line
	7300 7900 7400 7800
Entry Wire Line
	7200 7900 7300 7800
Entry Wire Line
	7100 7900 7200 7800
Entry Wire Line
	7000 7900 7100 7800
Entry Wire Line
	6900 7900 7000 7800
Wire Wire Line
	8400 7900 8400 8125
Wire Wire Line
	8300 8125 8300 7900
Wire Wire Line
	8200 7900 8200 8125
Wire Wire Line
	8100 8125 8100 7900
Wire Wire Line
	8000 7900 8000 8125
Wire Wire Line
	7900 8125 7900 7900
Wire Wire Line
	7800 7900 7800 8125
Wire Wire Line
	7700 8125 7700 7900
Text Label 8400 7900 3    50   ~ 0
COL15
Text Label 8200 7900 3    50   ~ 0
COL13
Text Label 8100 7900 3    50   ~ 0
COL12
Text Label 8000 7900 3    50   ~ 0
COL11
Text Label 7900 7900 3    50   ~ 0
COL10
Text Label 7800 7925 3    50   ~ 0
COL9
Text Label 7700 7925 3    50   ~ 0
COL8
Entry Wire Line
	8400 7900 8500 7800
Entry Wire Line
	8300 7900 8400 7800
Text Label 8300 7900 3    50   ~ 0
COL14
Entry Wire Line
	8200 7900 8300 7800
Entry Wire Line
	8100 7900 8200 7800
Entry Wire Line
	8000 7900 8100 7800
Entry Wire Line
	7900 7900 8000 7800
Entry Wire Line
	7800 7900 7900 7800
Entry Wire Line
	7700 7900 7800 7800
Wire Wire Line
	8600 8675 8700 8675
Wire Wire Line
	8700 8675 8700 8975
$Comp
L power:VDD #PWR07
U 1 1 5EE2B883
P 6425 8550
F 0 "#PWR07" H 6425 8400 50  0001 C CNN
F 1 "VDD" H 6442 8723 50  0000 C CNN
F 2 "" H 6425 8550 50  0001 C CNN
F 3 "" H 6425 8550 50  0001 C CNN
	1    6425 8550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6425 8675 6650 8675
Text Label 5575 6150 2    50   ~ 0
~OE
$Comp
L Device:R R1
U 1 1 5EF48347
P 8300 9275
F 0 "R1" V 8225 9100 50  0000 C CNN
F 1 "1K" V 8184 9275 50  0000 C CNN
F 2 "local:R_1206_3216Metric_Pad1.42x1.75mm_widepads" V 8230 9275 50  0001 C CNN
F 3 "~" H 8300 9275 50  0001 C CNN
	1    8300 9275
	0    1    1    0   
$EndComp
Wire Wire Line
	7300 9175 7300 9275
Wire Wire Line
	7300 9275 8150 9275
$Comp
L Device:C C3
U 1 1 5EF743CF
P 6425 8825
F 0 "C3" H 6540 8871 50  0000 L CNN
F 1 "100nF" H 6540 8780 50  0000 L CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 6463 8675 50  0001 C CNN
F 3 "~" H 6425 8825 50  0001 C CNN
	1    6425 8825
	1    0    0    -1  
$EndComp
Connection ~ 6425 8675
Wire Wire Line
	6425 8550 6425 8675
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
L power:GND #PWR08
U 1 1 5F217EB1
P 6425 8975
F 0 "#PWR08" H 6425 8725 50  0001 C CNN
F 1 "GND" H 6430 8802 50  0000 C CNN
F 2 "" H 6425 8975 50  0001 C CNN
F 3 "" H 6425 8975 50  0001 C CNN
	1    6425 8975
	1    0    0    -1  
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
Wire Wire Line
	7100 9175 7100 9475
Wire Wire Line
	7200 9175 7200 9575
Wire Wire Line
	7500 9175 7500 9675
Text Label 5800 5250 2    50   ~ 0
COLSDI0
Text Label 5775 5450 2    50   ~ 0
COLCLK
$Comp
L local:P-FET U6
U 1 1 5F09B5FB
P 10950 1775
F 0 "U6" H 10700 1975 50  0000 C CNN
F 1 "P-FET" V 10950 1775 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 2175 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 2175 50  0001 C CNN
	1    10950 1775
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
L local:P-FET U6
U 2 1 5F127DC7
P 10950 1375
F 0 "U6" H 10700 1575 50  0000 C CNN
F 1 "P-FET" V 10950 1375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 1775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 1775 50  0001 C CNN
	2    10950 1375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U7
U 1 1 5F137EE0
P 10950 2575
F 0 "U7" H 10700 2775 50  0000 C CNN
F 1 "P-FET" V 10950 2575 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 2975 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 2975 50  0001 C CNN
	1    10950 2575
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U8
U 1 1 5F15A3EE
P 10950 3375
F 0 "U8" H 10700 3575 50  0000 C CNN
F 1 "P-FET" V 10950 3375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 3775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 3775 50  0001 C CNN
	1    10950 3375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U8
U 2 1 5F15A3F8
P 10950 2975
F 0 "U8" H 10700 3175 50  0000 C CNN
F 1 "P-FET" V 10950 2975 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 3375 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 3375 50  0001 C CNN
	2    10950 2975
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U9
U 1 1 5F15A402
P 10950 4175
F 0 "U9" H 10700 4375 50  0000 C CNN
F 1 "P-FET" V 10950 4175 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 4575 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 4575 50  0001 C CNN
	1    10950 4175
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U9
U 2 1 5F15A40C
P 10950 3775
F 0 "U9" H 10700 3975 50  0000 C CNN
F 1 "P-FET" V 10950 3775 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 4175 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 4175 50  0001 C CNN
	2    10950 3775
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U10
U 1 1 5F17DC71
P 10950 4575
F 0 "U10" H 10700 4775 50  0000 C CNN
F 1 "P-FET" V 10950 4575 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 4975 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 4975 50  0001 C CNN
	1    10950 4575
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U10
U 2 1 5F17DC7B
P 10950 4975
F 0 "U10" H 10700 5175 50  0000 C CNN
F 1 "P-FET" V 10950 4975 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 5375 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 5375 50  0001 C CNN
	2    10950 4975
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U11
U 1 1 5F17DC85
P 10950 5375
F 0 "U11" H 10700 5575 50  0000 C CNN
F 1 "P-FET" V 10950 5375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 5775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 5775 50  0001 C CNN
	1    10950 5375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U11
U 2 1 5F17DC8F
P 10950 5775
F 0 "U11" H 10700 5975 50  0000 C CNN
F 1 "P-FET" V 10950 5775 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 6175 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 6175 50  0001 C CNN
	2    10950 5775
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U12
U 1 1 5F17DC99
P 10950 6575
F 0 "U12" H 10700 6775 50  0000 C CNN
F 1 "P-FET" V 10950 6575 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 6975 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 6975 50  0001 C CNN
	1    10950 6575
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U12
U 2 1 5F17DCA3
P 10950 6175
F 0 "U12" H 10700 6375 50  0000 C CNN
F 1 "P-FET" V 10950 6175 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 6575 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 6575 50  0001 C CNN
	2    10950 6175
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U13
U 1 1 5F17DCAD
P 10950 7375
F 0 "U13" H 10700 7575 50  0000 C CNN
F 1 "P-FET" V 10950 7375 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 7775 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 7775 50  0001 C CNN
	1    10950 7375
	1    0    0    -1  
$EndComp
$Comp
L local:P-FET U13
U 2 1 5F17DCB7
P 10950 6975
F 0 "U13" H 10700 7175 50  0000 C CNN
F 1 "P-FET" V 10950 6975 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 7375 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 7375 50  0001 C CNN
	2    10950 6975
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5F1E6F61
P 4975 7550
F 0 "#PWR06" H 4975 7300 50  0001 C CNN
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
Wire Wire Line
	5800 9475 7100 9475
Wire Wire Line
	7200 9575 6175 9575
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
$Comp
L local:TLC59025 U5
U 1 1 5F370614
P 10250 8675
F 0 "U5" V 10750 7800 50  0000 R CNN
F 1 "TLC59025" V 10250 8875 50  0000 R CNN
F 2 "local:SSOP-24_3.9x8.7mm_P0.635mm_widepads" H 10250 8675 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tlc59025.pdf" H 10250 8675 50  0001 C CNN
	1    10250 8675
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9500 8125 9500 7900
Wire Wire Line
	9600 7900 9600 8125
Wire Wire Line
	9700 8125 9700 7900
Wire Wire Line
	9800 7900 9800 8125
Wire Wire Line
	9900 8125 9900 7900
Wire Wire Line
	10000 7900 10000 8125
Wire Wire Line
	10100 8125 10100 7900
Wire Wire Line
	10200 7900 10200 8125
Text Label 9500 8125 1    50   ~ 0
COL16
Text Label 9600 8125 1    50   ~ 0
COL17
Text Label 9700 8125 1    50   ~ 0
COL18
Text Label 9800 8125 1    50   ~ 0
COL19
Text Label 9900 8125 1    50   ~ 0
COL20
Text Label 10000 8125 1    50   ~ 0
COL21
Text Label 10100 8125 1    50   ~ 0
COL22
Text Label 10200 8125 1    50   ~ 0
COL23
Entry Wire Line
	10100 7900 10200 7800
Entry Wire Line
	10000 7900 10100 7800
Entry Wire Line
	9900 7900 10000 7800
Entry Wire Line
	9800 7900 9900 7800
Entry Wire Line
	9700 7900 9800 7800
Entry Wire Line
	9600 7900 9700 7800
Entry Wire Line
	9500 7900 9600 7800
$Comp
L power:GND #PWR020
U 1 1 5F37064E
P 11300 8675
F 0 "#PWR020" H 11300 8425 50  0001 C CNN
F 1 "GND" H 11305 8502 50  0000 C CNN
F 2 "" H 11300 8675 50  0001 C CNN
F 3 "" H 11300 8675 50  0001 C CNN
	1    11300 8675
	1    0    0    -1  
$EndComp
Wire Wire Line
	11200 8675 11300 8675
$Comp
L power:VDD #PWR019
U 1 1 5F37065A
P 9025 8550
F 0 "#PWR019" H 9025 8400 50  0001 C CNN
F 1 "VDD" H 9042 8723 50  0000 C CNN
F 2 "" H 9025 8550 50  0001 C CNN
F 3 "" H 9025 8550 50  0001 C CNN
	1    9025 8550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9025 8675 9250 8675
$Comp
L Device:R R2
U 1 1 5F370665
P 9150 9275
F 0 "R2" V 9050 9425 50  0000 C CNN
F 1 "1K" V 9034 9275 50  0000 C CNN
F 2 "local:R_1206_3216Metric_Pad1.42x1.75mm_widepads" V 9080 9275 50  0001 C CNN
F 3 "~" H 9150 9275 50  0001 C CNN
	1    9150 9275
	0    1    1    0   
$EndComp
Wire Wire Line
	9900 9175 9900 9275
$Comp
L Device:C C6
U 1 1 5F370674
P 9025 8825
F 0 "C6" H 9140 8871 50  0000 L CNN
F 1 "100nF" H 9140 8780 50  0000 L CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 9063 8675 50  0001 C CNN
F 3 "~" H 9025 8825 50  0001 C CNN
	1    9025 8825
	1    0    0    -1  
$EndComp
Connection ~ 9025 8675
Wire Wire Line
	9025 8550 9025 8675
$Comp
L power:GND #PWR013
U 1 1 5F370681
P 8875 8975
F 0 "#PWR013" H 8875 8725 50  0001 C CNN
F 1 "GND" H 8880 8802 50  0000 C CNN
F 2 "" H 8875 8975 50  0001 C CNN
F 3 "" H 8875 8975 50  0001 C CNN
	1    8875 8975
	1    0    0    -1  
$EndComp
NoConn ~ 10000 9175
Wire Wire Line
	9600 9175 9600 9375
Wire Wire Line
	9700 9175 9700 9475
Wire Wire Line
	9800 9175 9800 9575
Wire Wire Line
	10100 9675 7500 9675
Wire Wire Line
	10100 9175 10100 9675
Wire Wire Line
	7100 9475 9700 9475
Wire Wire Line
	9800 9575 7200 9575
Entry Wire Line
	10200 7900 10300 7800
NoConn ~ 10300 8125
NoConn ~ 10400 8125
NoConn ~ 10500 8125
NoConn ~ 10600 8125
NoConn ~ 10700 8125
NoConn ~ 10800 8125
NoConn ~ 10900 8125
NoConn ~ 11000 8125
Connection ~ 7500 9675
Wire Wire Line
	9025 8975 8875 8975
Connection ~ 8875 8975
Wire Wire Line
	8875 8975 8700 8975
Wire Wire Line
	9900 9275 9300 9275
Connection ~ 7200 9575
Connection ~ 7100 9475
NoConn ~ 7400 9175
Wire Wire Line
	7000 9175 7000 9275
Wire Wire Line
	6050 9275 7000 9275
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
Wire Wire Line
	5375 5150 6175 5150
Text Label 5575 5150 2    50   ~ 0
LE
Wire Wire Line
	6175 9575 6175 5150
Wire Wire Line
	6050 9275 6050 5250
Wire Wire Line
	6050 5250 5375 5250
Wire Wire Line
	5925 9375 5925 5350
Wire Wire Line
	5925 5350 5375 5350
Wire Wire Line
	5925 9375 9600 9375
Wire Wire Line
	5800 9475 5800 5450
Wire Wire Line
	5800 5450 5375 5450
Wire Wire Line
	5600 9675 5600 6150
Wire Wire Line
	5600 9675 7500 9675
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
L power:GND #PWR011
U 1 1 5FE8EC1D
P 6850 7450
F 0 "#PWR011" H 6850 7200 50  0001 C CNN
F 1 "GND" V 6855 7322 50  0000 R CNN
F 2 "" H 6850 7450 50  0001 C CNN
F 3 "" H 6850 7450 50  0001 C CNN
	1    6850 7450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 600982F8
P 8950 3300
F 0 "#PWR016" H 8950 3050 50  0001 C CNN
F 1 "GND" V 8955 3172 50  0000 R CNN
F 2 "" H 8950 3300 50  0001 C CNN
F 3 "" H 8950 3300 50  0001 C CNN
	1    8950 3300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 6032EDF9
P 8950 6150
F 0 "#PWR018" H 8950 5900 50  0001 C CNN
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
L 74xx:74HCT595 U3
U 1 1 5F2F5F11
P 8950 2600
F 0 "U3" H 8700 3150 50  0000 C CNN
F 1 "74HCT595" V 9025 2600 50  0000 C CNN
F 2 "" H 8950 2600 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT595.pdf" H 8950 2600 50  0001 C CNN
	1    8950 2600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74HCT595 U4
U 1 1 5F2F7A3D
P 8950 5450
F 0 "U4" H 8700 6000 50  0000 C CNN
F 1 "74HCT595" V 9025 5375 50  0000 C CNN
F 2 "" H 8950 5450 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74HC_HCT595.pdf" H 8950 5450 50  0001 C CNN
	1    8950 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5F2FACBD
P 8950 4575
F 0 "C5" V 8698 4575 50  0000 C CNN
F 1 "100nF" V 8789 4575 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 8988 4425 50  0001 C CNN
F 3 "~" H 8950 4575 50  0001 C CNN
	1    8950 4575
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR017
U 1 1 5F2FACC7
P 8950 4425
F 0 "#PWR017" H 8950 4175 50  0001 C CNN
F 1 "GND" V 8955 4297 50  0000 R CNN
F 2 "" H 8950 4425 50  0001 C CNN
F 3 "" H 8950 4425 50  0001 C CNN
	1    8950 4425
	-1   0    0    1   
$EndComp
Wire Wire Line
	8950 4725 8950 4750
$Comp
L Device:C C4
U 1 1 5F34EBF1
P 8950 1725
F 0 "C4" V 8698 1725 50  0000 C CNN
F 1 "100nF" V 8789 1725 50  0000 C CNN
F 2 "local:C_0805_2012Metric_Pad1.15x1.40mm_widepads" H 8988 1575 50  0001 C CNN
F 3 "~" H 8950 1725 50  0001 C CNN
	1    8950 1725
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5F34EBFB
P 8950 1575
F 0 "#PWR015" H 8950 1325 50  0001 C CNN
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
	6175 5150 8200 5150
Wire Wire Line
	8200 5150 8200 5550
Wire Wire Line
	8200 5550 8550 5550
Connection ~ 6175 5150
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
Connection ~ 5600 6150
$Comp
L power:GND #PWR05
U 1 1 5F690054
P 4675 4550
F 0 "#PWR05" H 4675 4300 50  0001 C CNN
F 1 "GND" V 4680 4422 50  0000 R CNN
F 2 "" H 4675 4550 50  0001 C CNN
F 3 "" H 4675 4550 50  0001 C CNN
	1    4675 4550
	-1   0    0    1   
$EndComp
$Comp
L dk_Trimmer-Potentiometers:TC33X-2-103E POT1
U 1 1 5F692A6C
P 8700 10075
F 0 "POT1" V 8647 9988 60  0000 R CNN
F 1 "2K TC33X-2-202E" V 8753 9988 60  0000 R CNN
F 2 "digikey-footprints:Trimpot_3.8mmx3.6mm_TC33X-2-103E" H 8900 10275 60  0001 L CNN
F 3 "https://www.bourns.com/docs/Product-Datasheets/TC33.pdf" H 8900 10375 60  0001 L CNN
F 4 "TC33X-103ETR-ND" H 8900 10475 60  0001 L CNN "Digi-Key_PN"
F 5 "TC33X-2-103E" H 8900 10575 60  0001 L CNN "MPN"
F 6 "Potentiometers, Variable Resistors" H 8900 10675 60  0001 L CNN "Category"
F 7 "Trimmer Potentiometers" H 8900 10775 60  0001 L CNN "Family"
F 8 "https://www.bourns.com/docs/Product-Datasheets/TC33.pdf" H 8900 10875 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/bourns-inc/TC33X-2-103E/TC33X-103ETR-ND/612858" H 8900 10975 60  0001 L CNN "DK_Detail_Page"
F 10 "TRIMMER 10K OHM 0.1W J LEAD TOP" H 8900 11075 60  0001 L CNN "Description"
F 11 "Bourns Inc." H 8900 11175 60  0001 L CNN "Manufacturer"
F 12 "Active" H 8900 11275 60  0001 L CNN "Status"
	1    8700 10075
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 9275 8700 9275
Wire Wire Line
	8700 9275 8700 9875
Connection ~ 8700 9275
Wire Wire Line
	8700 9275 9000 9275
$Comp
L power:GND #PWR014
U 1 1 5F720E7C
P 8875 10400
F 0 "#PWR014" H 8875 10150 50  0001 C CNN
F 1 "GND" H 8880 10227 50  0000 C CNN
F 2 "" H 8875 10400 50  0001 C CNN
F 3 "" H 8875 10400 50  0001 C CNN
	1    8875 10400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 10275 8700 10400
Wire Wire Line
	8700 10400 8875 10400
Wire Wire Line
	9075 10400 9075 10075
Wire Wire Line
	9075 10075 9000 10075
Connection ~ 8875 10400
Wire Wire Line
	8875 10400 9075 10400
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
Text GLabel 10375 1325 0    50   UnSpc ~ 0
VDD
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
L power:GND #PWR09
U 1 1 5F9AF30E
P 6675 4550
F 0 "#PWR09" H 6675 4300 50  0001 C CNN
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
L local:P-FET U7
U 2 1 5F137EEA
P 10950 2175
F 0 "U7" H 10700 2375 50  0000 C CNN
F 1 "P-FET" V 10950 2175 50  0000 C CNN
F 2 "local:SOIC-8_3.9x4.9mm_P1.27mm_widepads" H 11150 2575 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 11150 2575 50  0001 C CNN
	2    10950 2175
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
Text GLabel 8475 1875 0    50   UnSpc ~ 0
VDD
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
Wire Bus Line
	11975 1525 11975 7600
Wire Bus Line
	7000 7800 12800 7800
$EndSCHEMATC
