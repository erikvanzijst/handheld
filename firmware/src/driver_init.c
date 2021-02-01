/**
 * \file
 *
 * \brief Driver initialization.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/*
 * Code generated by START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <system.h>

void TIMER_0_initialization(void)
{

	TIMER_0_init();
}

void RTC_0_initialization(void)
{
	RTC_0_init();
}

/* configure pins and initialize registers */
void SLEEP_initialization(void)
{
	SLEEP_init();
}

/* Configure pins and initialize registers */
void USART_0_initialization(void)
{

	// Set pin direction to input
	PC2_set_dir(PORT_DIR_IN);

	PC2_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_TOTEM);

	// Set pin direction to output
	PC3_set_dir(PORT_DIR_OUT);

	PC3_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	USART_0_init();
}

/**
 * \brief System initialization
 */
void system_init()
{
	mcu_init();

	/* PORT setting on PA0 */

	// Set pin direction to output
	BUZZER_set_dir(PORT_DIR_OUT);

	BUZZER_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PA1 */

	// Disable pull-up resistor
	LDR_set_output_pull_mode(PORT_CONFIGURATION_TOTEM);
	// Disable digital         // Disable digital input buffer
	LDR_set_isc(PORT_ISC_INPUT_DISABLE_gc);

	/* PORT setting on PA3 */

	// Set pin direction to output
	IRSD_set_dir(PORT_DIR_OUT);

	IRSD_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    true);

	/* PORT setting on PA7 */

	// Set pin direction to output
	BATT_set_dir(PORT_DIR_OUT);

	BATT_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PB0 */

	// Set pin direction to output
	BATTCHK_set_dir(PORT_DIR_OUT);

	BATTCHK_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PB1 */

	// Disable pull-up resistor
	BATTLVL_set_output_pull_mode(PORT_CONFIGURATION_TOTEM);
	// Disable digital         // Disable digital input buffer
	BATTLVL_set_isc(PORT_ISC_INPUT_DISABLE_gc);

	/* PORT setting on PC1 */

	// Set pin direction to output
	ROWCLK_set_dir(PORT_DIR_OUT);

	ROWCLK_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PC4 */

	// Set pin direction to output
	ROWSDI_set_dir(PORT_DIR_OUT);

	ROWSDI_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PC5 */

	// Set pin direction to output
	OEB_set_dir(PORT_DIR_OUT);

	OEB_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PC6 */

	// Set pin direction to output
	LE_set_dir(PORT_DIR_OUT);

	LE_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PC7 */

	// Set pin direction to input
	SW_UP_set_dir(PORT_DIR_IN);

	SW_UP_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SW_UP_set_inverted(true);

	/* PORT setting on PD0 */

	// Set pin direction to input
	SW_LEFT_set_dir(PORT_DIR_IN);

	SW_LEFT_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SW_LEFT_set_inverted(true);

	/* PORT setting on PD1 */

	// Set pin direction to input
	SW_RIGHT_set_dir(PORT_DIR_IN);

	SW_RIGHT_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SW_RIGHT_set_inverted(true);

	/* PORT setting on PD4 */

	// Set pin direction to input
	SW_DOWN_set_dir(PORT_DIR_IN);

	SW_DOWN_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SW_DOWN_set_inverted(true);

	/* PORT setting on PD5 */

	SELECT_set_dir(
	    // <y> Pin direction
	    // <id> pad_dir
	    // <PORT_DIR_OFF"> Off
	    // <PORT_DIR_IN"> In
	    // <PORT_DIR_OUT"> Out
	    PORT_DIR_IN);

	SELECT_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SELECT_set_inverted(true);

	/* PORT setting on PE0 */

	// Set pin direction to output
	SEGCLK0_set_dir(PORT_DIR_OUT);

	SEGCLK0_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PE1 */

	// Set pin direction to output
	SEGCLK1_set_dir(PORT_DIR_OUT);

	SEGCLK1_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PE2 */

	// Set pin direction to input
	SW_A_set_dir(PORT_DIR_IN);

	SW_A_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SW_A_set_inverted(true);

	/* PORT setting on PE3 */

	// Set pin direction to input
	SW_X_set_dir(PORT_DIR_IN);

	SW_X_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);
	
	SW_X_set_inverted(true);

	/* PORT setting on PE4 */

	// Set pin direction to input
	SW_B_set_dir(PORT_DIR_IN);

	SW_B_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SW_B_set_inverted(true);

	/* PORT setting on PE5 */

	// Set pin direction to input
	SW_Y_set_dir(PORT_DIR_IN);

	SW_Y_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	SW_Y_set_inverted(true);

	/* PORT setting on PE6 */

	// Set pin direction to input
	START_set_dir(PORT_DIR_IN);

	START_set_output_pull_mode(
	    // <y> Output and Pull Configuration
	    // <id> pad_output_pull_config
	    // <PORT_CONFIGURATION_TOTEM"> Totem-pole
	    // <PORT_CONFIGURATION_BUSKEEPER"> Totem-pole with bus-keeper
	    // <PORT_CONFIGURATION_PULLDOWN"> Pull-down
	    // <PORT_CONFIGURATION_PULLUP"> Pull-up
	    // <PORT_CONFIGURATION_WIREDOR"> Wired-OR
	    // <PORT_CONFIGURATION_WIREDAND"> Wired-AND
	    // <PORT_CONFIGURATION_WIREDORPULL"> Wired-OR with pull-down
	    // <PORT_CONFIGURATION_WIREDANDPULL"> Wired-AND with pull-up
	    PORT_CONFIGURATION_PULLUP);

	START_set_inverted(true);

	/* PORT setting on PE7 */

	// Set pin direction to output
	SEGCLK2_set_dir(PORT_DIR_OUT);

	SEGCLK2_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF0 */

	// Set pin direction to output
	D0_set_dir(PORT_DIR_OUT);

	D0_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF1 */

	// Set pin direction to output
	D1_set_dir(PORT_DIR_OUT);

	D1_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF2 */

	// Set pin direction to output
	D2_set_dir(PORT_DIR_OUT);

	D2_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF3 */

	// Set pin direction to output
	D3_set_dir(PORT_DIR_OUT);

	D3_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF4 */

	// Set pin direction to output
	D4_set_dir(PORT_DIR_OUT);

	D4_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF5 */

	// Set pin direction to output
	D5_set_dir(PORT_DIR_OUT);

	D5_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF6 */

	// Set pin direction to output
	D6_set_dir(PORT_DIR_OUT);

	D6_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PF7 */

	// Set pin direction to output
	D7_set_dir(PORT_DIR_OUT);

	D7_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	PORTB_set_pin_dir(2, PORT_DIR_OUT);
	PORTB_set_pin_dir(3, PORT_DIR_OUT);

	PORTCFG.VPCTRLA = PORTCFG_VP0MAP_PORTC_gc | PORTCFG_VP1MAP_PORTD_gc;	// assign the virtual ports C==>VP0, D==>VP1
	PORTCFG.VPCTRLB = PORTCFG_VP2MAP_PORTE_gc | PORTCFG_VP3MAP_PORTF_gc;	// assign the virtual ports E==>VP2, F==>VP3

	TIMER_0_initialization();

	OSC_init();

	CLK_init();

	RTC_0_initialization();

	PMIC_init();

	SLEEP_initialization();

	USART_0_initialization();
}
