EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 4
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
L Regulator_Switching:LM3670MF U4
U 1 1 5F788F1B
P 5500 3550
F 0 "U4" H 5500 3875 50  0000 C CNN
F 1 "LM3671MF-3.3" H 5500 3784 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-5" H 5550 3300 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm3670.pdf" H 5250 3200 50  0001 C CNN
	1    5500 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 3450 5075 3450
$Comp
L Device:C C6
U 1 1 5F78C119
P 6725 3750
F 0 "C6" H 6840 3796 50  0000 L CNN
F 1 "10uF" H 6840 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6763 3600 50  0001 C CNN
F 3 "~" H 6725 3750 50  0001 C CNN
	1    6725 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:L L1
U 1 1 5F78D3BA
P 6225 3450
F 0 "L1" V 6044 3450 50  0000 C CNN
F 1 "10uH" V 6135 3450 50  0000 C CNN
F 2 "local:CDRH5D18NP" H 6225 3450 50  0001 C CNN
F 3 "http://products.sumida.com/products/pdf/CDRH5D18,5D18BHP.pdf" H 6225 3450 50  0001 C CNN
	1    6225 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	5800 3450 6075 3450
Wire Wire Line
	6375 3450 6475 3450
Wire Wire Line
	5800 3650 6475 3650
Wire Wire Line
	6475 3650 6475 3450
Connection ~ 6475 3450
Wire Wire Line
	6475 3450 6725 3450
$Comp
L power:GND #PWR015
U 1 1 5F78F1EA
P 5500 3975
F 0 "#PWR015" H 5500 3725 50  0001 C CNN
F 1 "GND" H 5505 3802 50  0000 C CNN
F 2 "" H 5500 3975 50  0001 C CNN
F 3 "" H 5500 3975 50  0001 C CNN
	1    5500 3975
	1    0    0    -1  
$EndComp
Wire Wire Line
	6725 3450 6725 3600
Wire Wire Line
	6725 3975 6725 3900
Connection ~ 5500 3975
Wire Wire Line
	5500 3975 6275 3975
Wire Wire Line
	5500 3850 5500 3975
Connection ~ 6725 3450
$Comp
L Device:Battery BT1
U 1 1 5F7915DC
P 2075 3350
F 0 "BT1" V 1925 3275 50  0000 L CNN
F 1 "2 x 1.5V AA" V 2225 3125 50  0000 L CNN
F 2 "Battery:BatteryHolder_MPD_BC12AAPC_2xAA" V 2075 3410 50  0001 C CNN
F 3 "~" V 2075 3410 50  0001 C CNN
	1    2075 3350
	0    1    -1   0   
$EndComp
Wire Wire Line
	4225 3450 4300 3450
Connection ~ 4300 3450
Text Label 2450 3350 2    50   ~ 0
6V
$Comp
L power:PWR_FLAG #FLG01
U 1 1 5F794155
P 6275 3975
F 0 "#FLG01" H 6275 4050 50  0001 C CNN
F 1 "PWR_FLAG" H 6275 4148 50  0000 C CNN
F 2 "" H 6275 3975 50  0001 C CNN
F 3 "~" H 6275 3975 50  0001 C CNN
	1    6275 3975
	1    0    0    -1  
$EndComp
Connection ~ 6275 3975
Wire Wire Line
	6275 3975 6725 3975
$Comp
L dk_USB-DVI-HDMI-Connectors:UE27AC54100 J4
U 1 1 5F8B701D
P 3625 1900
F 0 "J4" V 3692 2253 60  0000 L CNN
F 1 "UE27AC54100" V 3798 2253 60  0000 L CNN
F 2 "digikey-footprints:USB_A_Female_UE27AC54100" H 3825 2100 60  0001 L CNN
F 3 "https://www.amphenolcanada.com/ProductSearch/drawings/AC/UE27ACX4X0X.pdf" H 3825 2200 60  0001 L CNN
F 4 "UE27AC54100-ND" H 3825 2300 60  0001 L CNN "Digi-Key_PN"
F 5 "UE27AC54100" H 3825 2400 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 3825 2500 60  0001 L CNN "Category"
F 7 "USB, DVI, HDMI Connectors" H 3825 2600 60  0001 L CNN "Family"
F 8 "https://www.amphenolcanada.com/ProductSearch/drawings/AC/UE27ACX4X0X.pdf" H 3825 2700 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/amphenol-icc-commercial-products/UE27AC54100/UE27AC54100-ND/1972253" H 3825 2800 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN RCPT USB2.0 TYPEA 4POS R/A" H 3825 2900 60  0001 L CNN "Description"
F 11 "Amphenol ICC (Commercial Products)" H 3825 3000 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3825 3100 60  0001 L CNN "Status"
	1    3625 1900
	0    1    1    0   
$EndComp
$Comp
L local:P-FET U3
U 1 1 5F8BAAF4
P 3925 3500
F 0 "U3" H 3925 3815 50  0000 C CNN
F 1 "P-FET" H 3925 3724 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4125 3900 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 4125 3900 50  0001 C CNN
	1    3925 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3625 3450 3400 3450
$Comp
L Device:R R4
U 1 1 5F8BFEFE
P 3525 3825
F 0 "R4" H 3595 3871 50  0000 L CNN
F 1 "10K" H 3595 3780 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3455 3825 50  0001 C CNN
F 3 "~" H 3525 3825 50  0001 C CNN
	1    3525 3825
	1    0    0    -1  
$EndComp
Wire Wire Line
	3525 3675 3525 3550
Wire Wire Line
	3525 3550 3625 3550
Wire Wire Line
	1825 3350 1875 3350
Wire Wire Line
	4925 3600 4925 3450
Wire Wire Line
	4925 3900 4925 3975
$Comp
L Device:C C5
U 1 1 5F789842
P 4925 3750
F 0 "C5" H 4725 3750 50  0000 L CNN
F 1 "4.7uF" H 4700 3650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4963 3600 50  0001 C CNN
F 3 "~" H 4925 3750 50  0001 C CNN
	1    4925 3750
	1    0    0    -1  
$EndComp
Connection ~ 4925 3450
Connection ~ 4925 3975
Wire Wire Line
	3825 2200 3825 2225
Wire Wire Line
	3825 2225 4500 2225
Wire Wire Line
	4500 2225 4500 3975
Wire Wire Line
	6725 3450 7325 3450
Text Label 7000 3450 0    50   ~ 0
3.3V
Text Label 3525 2200 3    50   ~ 0
5V
Wire Wire Line
	3525 3975 4500 3975
Connection ~ 4500 3975
Wire Wire Line
	4500 3975 4925 3975
Connection ~ 3525 3550
Wire Wire Line
	3750 2825 3525 2825
Wire Wire Line
	3525 2825 3525 3050
Wire Wire Line
	4050 2825 4300 2825
Wire Wire Line
	4300 2825 4300 3450
Wire Wire Line
	5075 3550 5075 3450
Connection ~ 5075 3450
Wire Wire Line
	5075 3450 4925 3450
$Comp
L power:GND #PWR014
U 1 1 5F8DC955
P 3300 2025
F 0 "#PWR014" H 3300 1775 50  0001 C CNN
F 1 "GND" H 3305 1852 50  0000 C CNN
F 2 "" H 3300 2025 50  0001 C CNN
F 3 "" H 3300 2025 50  0001 C CNN
	1    3300 2025
	1    0    0    -1  
$EndComp
Wire Wire Line
	4575 3450 4575 3025
Wire Wire Line
	4575 3025 7325 3025
Connection ~ 4575 3450
Wire Wire Line
	4575 3450 4300 3450
Text Label 7000 3025 0    50   ~ 0
3.5-5V
Text Notes 5275 3025 0    50   ~ 0
Unregulated power directly from USB or\nbatteries. Ranges between 3.5 and 5V.\nDriving LEDs with constant current drivers.
$Comp
L Device:Battery BT2
U 1 1 5F45FF3D
P 2075 3975
F 0 "BT2" V 1925 3925 50  0000 L CNN
F 1 "2 x 1.5V AA" V 2225 3750 50  0000 L CNN
F 2 "Battery:BatteryHolder_MPD_BC12AAPC_2xAA" V 2075 4035 50  0001 C CNN
F 3 "~" V 2075 4035 50  0001 C CNN
	1    2075 3975
	0    -1   1    0   
$EndComp
Wire Wire Line
	2275 3975 3525 3975
Wire Wire Line
	1875 3975 1825 3975
Text HLabel 1825 2825 2    50   Output ~ 0
BAT_LVL
Wire Wire Line
	1825 3975 1825 3350
Connection ~ 3525 3975
Wire Wire Line
	1825 3350 1825 2825
Connection ~ 1825 3350
Text HLabel 7325 3025 2    50   UnSpc ~ 0
U_PWR
Text HLabel 7325 3450 2    50   Output ~ 0
VDD
Wire Wire Line
	4575 3450 4925 3450
Text Label 3625 2300 1    50   ~ 0
D-
Text Label 3725 2300 1    50   ~ 0
D+
Wire Wire Line
	3625 2375 2125 2375
Wire Wire Line
	3625 2200 3625 2375
Wire Wire Line
	3725 2475 2125 2475
Wire Wire Line
	3725 2200 3725 2475
Text HLabel 2125 2375 0    50   Input ~ 0
USB_D-
Text HLabel 2125 2475 0    50   Input ~ 0
USB_D+
$Comp
L dk_Slide-Switches:JS202011SCQN S1
U 1 1 5F865FA4
P 2725 3150
F 0 "S1" H 2700 2875 50  0000 C CNN
F 1 "JS202011SCQN" H 2700 3550 50  0000 C CNN
F 2 "local:JS202011AQN_THT_DPDT" H 2925 3350 50  0001 L CNN
F 3 "https://www.ckswitches.com/media/1422/js.pdf" H 2925 3450 60  0001 L CNN
F 4 "401-2002-1-ND" H 2925 3550 60  0001 L CNN "Digi-Key_PN"
F 5 "JS202011SCQN" H 2925 3650 60  0001 L CNN "MPN"
F 6 "Switches" H 2925 3750 60  0001 L CNN "Category"
F 7 "Slide Switches" H 2925 3850 60  0001 L CNN "Family"
F 8 "https://www.ckswitches.com/media/1422/js.pdf" H 2925 3950 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/c-k/JS202011SCQN/401-2002-1-ND/1640098" H 2925 4050 60  0001 L CNN "DK_Detail_Page"
F 10 "SWITCH SLIDE DPDT 300MA 6V" H 2925 4150 60  0001 L CNN "Description"
F 11 "C&K" H 2925 4250 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2925 4350 60  0001 L CNN "Status"
	1    2725 3150
	1    0    0    1   
$EndComp
Wire Wire Line
	2925 3450 3100 3450
Wire Wire Line
	2275 3350 2525 3350
Wire Wire Line
	2925 3050 3525 3050
Connection ~ 3525 3050
Wire Wire Line
	3525 3050 3525 3550
Wire Wire Line
	3525 2200 3525 2575
Wire Wire Line
	3525 2575 2525 2575
Wire Wire Line
	2525 2575 2525 2950
NoConn ~ 2925 2850
NoConn ~ 2925 3250
Wire Wire Line
	4925 3975 5500 3975
Wire Wire Line
	5075 3550 5200 3550
Wire Wire Line
	4225 3550 4300 3550
Wire Wire Line
	4300 3550 4300 3450
$Comp
L local:P-FET U?
U 2 1 5F952E8F
P 3925 4300
AR Path="/6011206E/5F952E8F" Ref="U?"  Part="2" 
AR Path="/5F785555/5F952E8F" Ref="U3"  Part="2" 
F 0 "U3" H 3675 4500 50  0000 C CNN
F 1 "P-FET" V 3925 4300 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 4125 4700 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/DMP3085LSD.pdf" H 4125 4700 50  0001 C CNN
	2    3925 4300
	1    0    0    -1  
$EndComp
NoConn ~ 4225 4350
NoConn ~ 4225 4250
Wire Wire Line
	3625 4350 3625 4300
Wire Wire Line
	3625 4300 3525 4300
Connection ~ 3625 4300
Wire Wire Line
	3625 4300 3625 4250
Wire Wire Line
	3525 4300 3525 3975
$Comp
L Diode:MRA4003T3G D1
U 1 1 5FBA69DF
P 3250 3450
F 0 "D1" H 3250 3233 50  0000 C CNN
F 1 "MRA4003T3G" H 3250 3324 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 3250 3275 50  0001 C CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/MRA4003T3-D.PDF" H 3250 3450 50  0001 C CNN
	1    3250 3450
	-1   0    0    1   
$EndComp
$Comp
L Diode:MRA4003T3G D2
U 1 1 5FBAF34B
P 3900 2825
F 0 "D2" H 3900 2608 50  0000 C CNN
F 1 "MRA4003T3G" H 3900 2699 50  0000 C CNN
F 2 "Diode_SMD:D_SMA" H 3900 2650 50  0001 C CNN
F 3 "http://www.onsemi.com/pub_link/Collateral/MRA4003T3-D.PDF" H 3900 2825 50  0001 C CNN
	1    3900 2825
	-1   0    0    1   
$EndComp
$EndSCHEMATC
