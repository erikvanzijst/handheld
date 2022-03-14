/**
 * \file
 *
 * \brief TC related functionality implementation.
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
 */

/**
 * \addtogroup doc_driver_tc
 *
 * \section doc_driver_tc_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <tc.h>
#include "wallclock.h"

/**
 * \brief Initialize tc interface
 * \return Initialization status.
 */
int8_t TIMER_0_init()
{

	TCC0.CTRLA = TC_CLKSEL_DIV64_gc; /* System Clock / 64 */

	TCC0.CTRLB = 0 << TC0_CCDEN_bp      /* Compare or Capture D Enable: disabled */
	             | 0 << TC0_CCCEN_bp    /* Compare or Capture C Enable: disabled */
	             | 0 << TC0_CCBEN_bp    /* Compare or Capture B Enable: disabled */
	             | 0 << TC0_CCAEN_bp    /* Compare or Capture A Enable: enabled */
	             | TC_WGMODE_NORMAL_gc; /* Normal Mode */

	// TCC0.CTRLC = 0 << TC0_CMPD_bp /* Compare D Output Value: disabled */
	//		 | 0 << TC0_CMPC_bp /* Compare C Output Value: disabled */
	//		 | 0 << TC0_CMPB_bp /* Compare B Output Value: disabled */
	//		 | 0 << TC0_CMPA_bp /* Compare A Output Value: disabled */;

	// TCC0.CTRLD = TC_EVACT_OFF_gc /* No Event Action */
	//		 | 0 << TC0_EVDLY_bp /* Event Delay: disabled */
	//		 | TC_EVSEL_OFF_gc; /* No Event Source */

	// TCC0.CTRLE = 0; /* Byte Mode: 0 */

	TCC0.INTCTRLB = TC_CCDINTLVL_OFF_gc   /* Interrupt Disabled */
	                | TC_CCCINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCBINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCAINTLVL_OFF_gc /* Medium Level */;

	TCC0.INTCTRLA = TC_ERRINTLVL_OFF_gc /* Interrupt Disabled */
			 | TC_OVFINTLVL_MED_gc; /* Interrupt Enabled */

	// TCC0.CCA = 0x7c /* Compare or Capture A: 0x7c */;

	// TCC0.CCB = 0x0 /* Compare or Capture B: 0x0 */;

	// TCC0.CCC = 0x0; /* Compare or Capture C: 0x0 */

	// TCC0.CCD = 0x0; /* Compare or Capture D: 0x0 */

	// TCC0.CNT = 0x0; /* Count: 0x0 */

	TCC0.PER = 250; /* Period: 2kHz */


	// Timer used for RTC and millis()
	TCD0.CTRLA = TC_CLKSEL_DIV64_gc; /* System Clock / 64 */
	TCD0.CTRLB = 0 << TC0_CCDEN_bp      /* Compare or Capture D Enable: disabled */
	             | 0 << TC0_CCCEN_bp    /* Compare or Capture C Enable: disabled */
	             | 0 << TC0_CCBEN_bp    /* Compare or Capture B Enable: disabled */
	             | 1 << TC0_CCAEN_bp    /* Compare or Capture A Enable: enabled */
	             | TC_WGMODE_NORMAL_gc; /* Normal Mode */
	TCD0.INTCTRLA = TC_ERRINTLVL_OFF_gc /* Interrupt Disabled */
			 		| TC_OVFINTLVL_OFF_gc; /* Interrupt Enabled */
	TCD0.INTCTRLB = TC_CCDINTLVL_OFF_gc   /* Interrupt Disabled */
	                | TC_CCCINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCBINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCAINTLVL_MED_gc /* Medium Level */;
	TCD0.CCA = TC_INTERVAL;					/* Compare or Capture A: 50000; trigger every 100ms */


	// Timer for sound driver
	TCE0.CTRLA = TC_CLKSEL_OFF_gc; 		/* Initially off */
	TCE0.CTRLB = 0 << TC0_CCDEN_bp      /* Compare or Capture D Enable: disabled */
	             | 0 << TC0_CCCEN_bp    /* Compare or Capture C Enable: disabled */
	             | 0 << TC0_CCBEN_bp    /* Compare or Capture B Enable: disabled */
	             | 0 << TC0_CCAEN_bp    /* Compare or Capture A Enable: enabled */
	             | TC_WGMODE_NORMAL_gc; /* Normal Mode */
	TCE0.INTCTRLA = TC_ERRINTLVL_OFF_gc /* Interrupt Disabled */
			 		| TC_OVFINTLVL_HI_gc; /* high-priority interrupt to keep tones clear */
	TCE0.INTCTRLB = TC_CCDINTLVL_OFF_gc   /* Interrupt Disabled */
	                | TC_CCCINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCBINTLVL_OFF_gc /* Interrupt Disabled */
	                | TC_CCAINTLVL_OFF_gc /* Medium Level */;

    // Timer used for alarm()
    TCF0.CTRLA = TC_CLKSEL_OFF_gc;      // Start in disabled mode
    TCF0.CTRLB = 0 << TC0_CCDEN_bp      /* Compare or Capture D Enable: disabled */
                 | 0 << TC0_CCCEN_bp    /* Compare or Capture C Enable: disabled */
                 | 0 << TC0_CCBEN_bp    /* Compare or Capture B Enable: disabled */
                 | 0 << TC0_CCAEN_bp    /* Compare or Capture A Enable: disabled */
                 | TC_WGMODE_NORMAL_gc; /* Normal Mode */
    TCF0.INTCTRLA = TC_ERRINTLVL_OFF_gc /* Interrupt Disabled */
                    | TC_OVFINTLVL_OFF_gc; /* Interrupt Disabled */
    TCF0.INTCTRLB = TC_CCDINTLVL_OFF_gc   /* Interrupt Disabled */
                    | TC_CCCINTLVL_OFF_gc /* Interrupt Disabled */
                    | TC_CCBINTLVL_OFF_gc /* Interrupt Disabled */
                    | TC_CCAINTLVL_MED_gc /* Medium Level */;

    return 0;
}
