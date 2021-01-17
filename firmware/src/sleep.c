/**
 * \file
 *
 * \brief SLEEP related functionality implementation.
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

/**
 * \defgroup doc_driver_system_ Sleep Controller
 * \ingroup doc_driver_system
 *
 * \section doc_driver_sleep_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <sleep.h>

/**
 * \brief Initialize Sleep Controller
 *
 * \return Initialization status.
 */
int8_t SLEEP_init()
{

	/* Sleep Configuration*/

	// SLEEP.CTRL = SLEEP_SMODE_IDLE_gc /* Idle mode */
	//		 | 0 << SLEEP_SEN_bp; /* Sleep Enable: disabled */

	/* Power Reduction Configuration*/

	// PR.PRGEN = 0 << PR_USB_bp /* USB power down: disabled */
	//		 | 0 << PR_RTC_bp /* RTC power down: disabled */
	//		 | 0 << PR_EVSYS_bp /* EVSYS power down: disabled */;

	// PR.PRPA = 0 << PR_ADC_bp /* ADCA power down: disabled */
	//		 | 0 << PR_AC_bp; /* ACA power down: disabled */

	// PR.PRPC = 0 << PR_TWI_bp /* TWIC power down: disabled */
	//		 | 0 << PR_USART0_bp /* USART0C power down: disabled */
	//		 | 0 << PR_SPI_bp /* SPIC power down: disabled */
	//		 | 0 << PR_HIRES_bp /* HIRESC power down: disabled */
	//		 | 0 << PR_TC1_bp /* TC1C power down: disabled */
	//		 | 0 << PR_TC0_bp /* TC0C power down: disabled */;

	// PR.PRPD = 0 << PR_USART0_bp /* USART0D power down: disabled */
	//		 | 0 << PR_SPI_bp /* SPID power down: disabled */
	//		 | 0 << PR_TC0_bp /* TC0D power down: disabled */;

	// PR.PRPE = 0 << PR_TWI_bp /* TWIE power down: disabled */
	//		 | 0 << PR_USART0_bp /* USART0E power down: disabled */
	//		 | 0 << PR_TC0_bp /* TC0E power down: disabled */;

	// PR.PRPF = 0 << PR_TC0_bp /* TC0F power down: disabled */;

	return 0;
}
