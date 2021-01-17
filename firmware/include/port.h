/**
 * \file
 *
 * \brief Xmega Port related support
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

#ifndef PORT_INCLUDED
#define PORT_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <compiler.h>

enum port_output_pull_mode {
	PORT_CONFIGURATION_TOTEM,
	PORT_CONFIGURATION_BUSKEEPER,
	PORT_CONFIGURATION_PULLDOWN,
	PORT_CONFIGURATION_PULLUP,
	PORT_CONFIGURATION_WIREDOR,
	PORT_CONFIGURATION_WIREDAND,
	PORT_CONFIGURATION_WIREDORPULL,
	PORT_CONFIGURATION_WIREDANDPULL
};

enum port_dir { PORT_DIR_IN, PORT_DIR_OUT, PORT_DIR_OFF };

/**
 * \brief Set port pin Output & Pull configuration
 *
 * Configure pin output mode and pull configuration
 *
 * \param[in] pin       		The pin number for device
 * \param[in] output_pull_mode	Pin output and pull mode
 */
static inline void PORTA_set_pin_output_pull_mode(const uint8_t pin, const enum port_output_pull_mode output_pull_mode)
{
	volatile uint8_t *port_pin_ctrl = (volatile uint8_t *)(&PORTA.PIN0CTRL) + pin;

	*port_pin_ctrl &= PORT_OPC_TOTEM_gc;
	if (output_pull_mode == PORT_CONFIGURATION_BUSKEEPER) {
		*port_pin_ctrl |= PORT_OPC_BUSKEEPER_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLDOWN) {
		*port_pin_ctrl |= PORT_OPC_PULLDOWN_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLUP) {
		*port_pin_ctrl |= PORT_OPC_PULLUP_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDOR) {
		*port_pin_ctrl |= PORT_OPC_WIREDOR_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDAND) {
		*port_pin_ctrl |= PORT_OPC_WIREDAND_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDORPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDORPULL_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDANDPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDANDPULL_gc;
	}
}

/**
 * \brief Set port pin inverted mode
 *
 * Configure pin invert I/O or not
 *
 * \param[in] pin       The pin number within port
 * \param[in] inverted  Pin inverted mode
 */
static inline void PORTA_pin_set_inverted(const uint8_t pin, const bool inverted)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTA + 0x10 + pin);

	if (inverted) {
		*port_pin_ctrl |= PORT_INVEN_bm;
	} else {
		*port_pin_ctrl &= ~PORT_INVEN_bm;
	}
}

/**
 * \brief Set port pin input/sense configuration
 *
 * Enable/disable digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] pin pin number within port
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 *
 */
static inline void PORTA_pin_set_isc(const uint8_t pin, const PORT_ISC_t isc)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTA + 0x10 + pin);

	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | isc;
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] mask      Bit mask where 1 means apply direction setting to the
 *                      corresponding pin
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTA_set_port_dir(const uint8_t mask, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTA.DIRCLR = mask;
		break;
	case PORT_DIR_OUT:
		PORTA.DIRSET = mask;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		PORTCFG.MPCMASK = mask;
		PORTA.PIN0CTRL  = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] pin       The pin number for device
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTA_set_pin_dir(const uint8_t pin, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTA.DIRCLR = 1 << pin;
		break;
	case PORT_DIR_OUT:
		PORTA.DIRSET = 1 << pin;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		*((uint8_t *)&PORTA + 0x10 + pin) = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on the pins defined by the bit mask
 *
 * \param[in] mask  Bit mask where 1 means apply port level to the corresponding
 *                  pin
 * \param[in] level true  = Pin levels set to "high" state
 *                  false = Pin levels set to "low" state
 */
static inline void PORTA_set_port_level(const uint8_t mask, const bool level)
{
	if (level == true) {
		PORTA.OUTSET = mask;
	} else {
		PORTA.OUTCLR = mask;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on a pin
 *
 * \param[in] pin       The pin number for device
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PORTA_set_pin_level(const uint8_t pin, const bool level)
{
	if (level == true) {
		PORTA.OUTSET = 1 << pin;
	} else {
		PORTA.OUTCLR = 1 << pin;
	}
}

/**
 * \brief Toggle out level on pins
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] mask  Bit mask where 1 means toggle pin level to the corresponding
 *                  pin
 */
static inline void PORTA_toggle_port_level(const uint8_t mask)
{
	PORTA.OUTTGL = mask;
}

/**
 * \brief Toggle output level on pin
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] pin       The pin number for device
 */
static inline void PORTA_toggle_pin_level(const uint8_t pin)
{
	PORTA.OUTTGL = 1 << pin;
}

/**
 * \brief Get input level on pins
 *
 * Read the input level on pins connected to a port
 *
 */
static inline uint8_t PORTA_get_port_level()
{
	return PORTA.IN;
}

/**
 * \brief Get level on pin
 *
 * Reads the level on pins connected to a port
 *
 * \param[in] pin       The pin number for device
 */
static inline bool PORTA_get_pin_level(const uint8_t pin)
{
	return PORTA.IN & (1 << pin);
}

/**
 * \brief Write value to Port
 *
 * Write directly to the port OUT register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTA_write_port(const uint8_t value)
{
	PORTA.OUT = value;
}

/**
 * \brief Write value to interrupt control register
 *
 * Read modify Write  to the interrupt control register
 *
 * \param[in] level Value to write to the port register
 */
static inline void PORTA_set_int_level(const uint8_t level)
{
	PORTA.INTCTRL |= level;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTA_write_int0_mask(const uint8_t value)
{
	PORTA.INT0MASK = value;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTA_write_int1_mask(const uint8_t value)
{
	PORTA.INT1MASK = value;
}

/**
 * \brief Set port pin Output & Pull configuration
 *
 * Configure pin output mode and pull configuration
 *
 * \param[in] pin       		The pin number for device
 * \param[in] output_pull_mode	Pin output and pull mode
 */
static inline void PORTB_set_pin_output_pull_mode(const uint8_t pin, const enum port_output_pull_mode output_pull_mode)
{
	volatile uint8_t *port_pin_ctrl = (volatile uint8_t *)(&PORTB.PIN0CTRL) + pin;

	*port_pin_ctrl &= PORT_OPC_TOTEM_gc;
	if (output_pull_mode == PORT_CONFIGURATION_BUSKEEPER) {
		*port_pin_ctrl |= PORT_OPC_BUSKEEPER_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLDOWN) {
		*port_pin_ctrl |= PORT_OPC_PULLDOWN_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLUP) {
		*port_pin_ctrl |= PORT_OPC_PULLUP_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDOR) {
		*port_pin_ctrl |= PORT_OPC_WIREDOR_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDAND) {
		*port_pin_ctrl |= PORT_OPC_WIREDAND_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDORPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDORPULL_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDANDPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDANDPULL_gc;
	}
}

/**
 * \brief Set port pin inverted mode
 *
 * Configure pin invert I/O or not
 *
 * \param[in] pin       The pin number within port
 * \param[in] inverted  Pin inverted mode
 */
static inline void PORTB_pin_set_inverted(const uint8_t pin, const bool inverted)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTB + 0x10 + pin);

	if (inverted) {
		*port_pin_ctrl |= PORT_INVEN_bm;
	} else {
		*port_pin_ctrl &= ~PORT_INVEN_bm;
	}
}

/**
 * \brief Set port pin input/sense configuration
 *
 * Enable/disable digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] pin pin number within port
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 *
 */
static inline void PORTB_pin_set_isc(const uint8_t pin, const PORT_ISC_t isc)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTB + 0x10 + pin);

	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | isc;
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] mask      Bit mask where 1 means apply direction setting to the
 *                      corresponding pin
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTB_set_port_dir(const uint8_t mask, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTB.DIRCLR = mask;
		break;
	case PORT_DIR_OUT:
		PORTB.DIRSET = mask;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		PORTCFG.MPCMASK = mask;
		PORTB.PIN0CTRL  = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] pin       The pin number for device
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTB_set_pin_dir(const uint8_t pin, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTB.DIRCLR = 1 << pin;
		break;
	case PORT_DIR_OUT:
		PORTB.DIRSET = 1 << pin;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		*((uint8_t *)&PORTB + 0x10 + pin) = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on the pins defined by the bit mask
 *
 * \param[in] mask  Bit mask where 1 means apply port level to the corresponding
 *                  pin
 * \param[in] level true  = Pin levels set to "high" state
 *                  false = Pin levels set to "low" state
 */
static inline void PORTB_set_port_level(const uint8_t mask, const bool level)
{
	if (level == true) {
		PORTB.OUTSET = mask;
	} else {
		PORTB.OUTCLR = mask;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on a pin
 *
 * \param[in] pin       The pin number for device
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PORTB_set_pin_level(const uint8_t pin, const bool level)
{
	if (level == true) {
		PORTB.OUTSET = 1 << pin;
	} else {
		PORTB.OUTCLR = 1 << pin;
	}
}

/**
 * \brief Toggle out level on pins
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] mask  Bit mask where 1 means toggle pin level to the corresponding
 *                  pin
 */
static inline void PORTB_toggle_port_level(const uint8_t mask)
{
	PORTB.OUTTGL = mask;
}

/**
 * \brief Toggle output level on pin
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] pin       The pin number for device
 */
static inline void PORTB_toggle_pin_level(const uint8_t pin)
{
	PORTB.OUTTGL = 1 << pin;
}

/**
 * \brief Get input level on pins
 *
 * Read the input level on pins connected to a port
 *
 */
static inline uint8_t PORTB_get_port_level()
{
	return PORTB.IN;
}

/**
 * \brief Get level on pin
 *
 * Reads the level on pins connected to a port
 *
 * \param[in] pin       The pin number for device
 */
static inline bool PORTB_get_pin_level(const uint8_t pin)
{
	return PORTB.IN & (1 << pin);
}

/**
 * \brief Write value to Port
 *
 * Write directly to the port OUT register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTB_write_port(const uint8_t value)
{
	PORTB.OUT = value;
}

/**
 * \brief Write value to interrupt control register
 *
 * Read modify Write  to the interrupt control register
 *
 * \param[in] level Value to write to the port register
 */
static inline void PORTB_set_int_level(const uint8_t level)
{
	PORTB.INTCTRL |= level;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTB_write_int0_mask(const uint8_t value)
{
	PORTB.INT0MASK = value;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTB_write_int1_mask(const uint8_t value)
{
	PORTB.INT1MASK = value;
}

/**
 * \brief Set port pin Output & Pull configuration
 *
 * Configure pin output mode and pull configuration
 *
 * \param[in] pin       		The pin number for device
 * \param[in] output_pull_mode	Pin output and pull mode
 */
static inline void PORTC_set_pin_output_pull_mode(const uint8_t pin, const enum port_output_pull_mode output_pull_mode)
{
	volatile uint8_t *port_pin_ctrl = (volatile uint8_t *)(&PORTC.PIN0CTRL) + pin;

	*port_pin_ctrl &= PORT_OPC_TOTEM_gc;
	if (output_pull_mode == PORT_CONFIGURATION_BUSKEEPER) {
		*port_pin_ctrl |= PORT_OPC_BUSKEEPER_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLDOWN) {
		*port_pin_ctrl |= PORT_OPC_PULLDOWN_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLUP) {
		*port_pin_ctrl |= PORT_OPC_PULLUP_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDOR) {
		*port_pin_ctrl |= PORT_OPC_WIREDOR_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDAND) {
		*port_pin_ctrl |= PORT_OPC_WIREDAND_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDORPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDORPULL_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDANDPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDANDPULL_gc;
	}
}

/**
 * \brief Set port pin inverted mode
 *
 * Configure pin invert I/O or not
 *
 * \param[in] pin       The pin number within port
 * \param[in] inverted  Pin inverted mode
 */
static inline void PORTC_pin_set_inverted(const uint8_t pin, const bool inverted)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTC + 0x10 + pin);

	if (inverted) {
		*port_pin_ctrl |= PORT_INVEN_bm;
	} else {
		*port_pin_ctrl &= ~PORT_INVEN_bm;
	}
}

/**
 * \brief Set port pin input/sense configuration
 *
 * Enable/disable digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] pin pin number within port
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 *
 */
static inline void PORTC_pin_set_isc(const uint8_t pin, const PORT_ISC_t isc)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTC + 0x10 + pin);

	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | isc;
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] mask      Bit mask where 1 means apply direction setting to the
 *                      corresponding pin
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTC_set_port_dir(const uint8_t mask, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTC.DIRCLR = mask;
		break;
	case PORT_DIR_OUT:
		PORTC.DIRSET = mask;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		PORTCFG.MPCMASK = mask;
		PORTC.PIN0CTRL  = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] pin       The pin number for device
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTC_set_pin_dir(const uint8_t pin, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTC.DIRCLR = 1 << pin;
		break;
	case PORT_DIR_OUT:
		PORTC.DIRSET = 1 << pin;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		*((uint8_t *)&PORTC + 0x10 + pin) = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on the pins defined by the bit mask
 *
 * \param[in] mask  Bit mask where 1 means apply port level to the corresponding
 *                  pin
 * \param[in] level true  = Pin levels set to "high" state
 *                  false = Pin levels set to "low" state
 */
static inline void PORTC_set_port_level(const uint8_t mask, const bool level)
{
	if (level == true) {
		PORTC.OUTSET = mask;
	} else {
		PORTC.OUTCLR = mask;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on a pin
 *
 * \param[in] pin       The pin number for device
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PORTC_set_pin_level(const uint8_t pin, const bool level)
{
	if (level == true) {
		PORTC.OUTSET = 1 << pin;
	} else {
		PORTC.OUTCLR = 1 << pin;
	}
}

/**
 * \brief Toggle out level on pins
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] mask  Bit mask where 1 means toggle pin level to the corresponding
 *                  pin
 */
static inline void PORTC_toggle_port_level(const uint8_t mask)
{
	PORTC.OUTTGL = mask;
}

/**
 * \brief Toggle output level on pin
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] pin       The pin number for device
 */
static inline void PORTC_toggle_pin_level(const uint8_t pin)
{
	PORTC.OUTTGL = 1 << pin;
}

/**
 * \brief Get input level on pins
 *
 * Read the input level on pins connected to a port
 *
 */
static inline uint8_t PORTC_get_port_level()
{
	return PORTC.IN;
}

/**
 * \brief Get level on pin
 *
 * Reads the level on pins connected to a port
 *
 * \param[in] pin       The pin number for device
 */
static inline bool PORTC_get_pin_level(const uint8_t pin)
{
	return PORTC.IN & (1 << pin);
}

/**
 * \brief Write value to Port
 *
 * Write directly to the port OUT register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTC_write_port(const uint8_t value)
{
	PORTC.OUT = value;
}

/**
 * \brief Write value to interrupt control register
 *
 * Read modify Write  to the interrupt control register
 *
 * \param[in] level Value to write to the port register
 */
static inline void PORTC_set_int_level(const uint8_t level)
{
	PORTC.INTCTRL |= level;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTC_write_int0_mask(const uint8_t value)
{
	PORTC.INT0MASK = value;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTC_write_int1_mask(const uint8_t value)
{
	PORTC.INT1MASK = value;
}

/**
 * \brief Set port pin Output & Pull configuration
 *
 * Configure pin output mode and pull configuration
 *
 * \param[in] pin       		The pin number for device
 * \param[in] output_pull_mode	Pin output and pull mode
 */
static inline void PORTD_set_pin_output_pull_mode(const uint8_t pin, const enum port_output_pull_mode output_pull_mode)
{
	volatile uint8_t *port_pin_ctrl = (volatile uint8_t *)(&PORTD.PIN0CTRL) + pin;

	*port_pin_ctrl &= PORT_OPC_TOTEM_gc;
	if (output_pull_mode == PORT_CONFIGURATION_BUSKEEPER) {
		*port_pin_ctrl |= PORT_OPC_BUSKEEPER_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLDOWN) {
		*port_pin_ctrl |= PORT_OPC_PULLDOWN_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLUP) {
		*port_pin_ctrl |= PORT_OPC_PULLUP_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDOR) {
		*port_pin_ctrl |= PORT_OPC_WIREDOR_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDAND) {
		*port_pin_ctrl |= PORT_OPC_WIREDAND_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDORPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDORPULL_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDANDPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDANDPULL_gc;
	}
}

/**
 * \brief Set port pin inverted mode
 *
 * Configure pin invert I/O or not
 *
 * \param[in] pin       The pin number within port
 * \param[in] inverted  Pin inverted mode
 */
static inline void PORTD_pin_set_inverted(const uint8_t pin, const bool inverted)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTD + 0x10 + pin);

	if (inverted) {
		*port_pin_ctrl |= PORT_INVEN_bm;
	} else {
		*port_pin_ctrl &= ~PORT_INVEN_bm;
	}
}

/**
 * \brief Set port pin input/sense configuration
 *
 * Enable/disable digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] pin pin number within port
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 *
 */
static inline void PORTD_pin_set_isc(const uint8_t pin, const PORT_ISC_t isc)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTD + 0x10 + pin);

	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | isc;
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] mask      Bit mask where 1 means apply direction setting to the
 *                      corresponding pin
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTD_set_port_dir(const uint8_t mask, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTD.DIRCLR = mask;
		break;
	case PORT_DIR_OUT:
		PORTD.DIRSET = mask;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		PORTCFG.MPCMASK = mask;
		PORTD.PIN0CTRL  = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] pin       The pin number for device
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTD_set_pin_dir(const uint8_t pin, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTD.DIRCLR = 1 << pin;
		break;
	case PORT_DIR_OUT:
		PORTD.DIRSET = 1 << pin;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		*((uint8_t *)&PORTD + 0x10 + pin) = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on the pins defined by the bit mask
 *
 * \param[in] mask  Bit mask where 1 means apply port level to the corresponding
 *                  pin
 * \param[in] level true  = Pin levels set to "high" state
 *                  false = Pin levels set to "low" state
 */
static inline void PORTD_set_port_level(const uint8_t mask, const bool level)
{
	if (level == true) {
		PORTD.OUTSET = mask;
	} else {
		PORTD.OUTCLR = mask;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on a pin
 *
 * \param[in] pin       The pin number for device
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PORTD_set_pin_level(const uint8_t pin, const bool level)
{
	if (level == true) {
		PORTD.OUTSET = 1 << pin;
	} else {
		PORTD.OUTCLR = 1 << pin;
	}
}

/**
 * \brief Toggle out level on pins
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] mask  Bit mask where 1 means toggle pin level to the corresponding
 *                  pin
 */
static inline void PORTD_toggle_port_level(const uint8_t mask)
{
	PORTD.OUTTGL = mask;
}

/**
 * \brief Toggle output level on pin
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] pin       The pin number for device
 */
static inline void PORTD_toggle_pin_level(const uint8_t pin)
{
	PORTD.OUTTGL = 1 << pin;
}

/**
 * \brief Get input level on pins
 *
 * Read the input level on pins connected to a port
 *
 */
static inline uint8_t PORTD_get_port_level()
{
	return PORTD.IN;
}

/**
 * \brief Get level on pin
 *
 * Reads the level on pins connected to a port
 *
 * \param[in] pin       The pin number for device
 */
static inline bool PORTD_get_pin_level(const uint8_t pin)
{
	return PORTD.IN & (1 << pin);
}

/**
 * \brief Write value to Port
 *
 * Write directly to the port OUT register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTD_write_port(const uint8_t value)
{
	PORTD.OUT = value;
}

/**
 * \brief Write value to interrupt control register
 *
 * Read modify Write  to the interrupt control register
 *
 * \param[in] level Value to write to the port register
 */
static inline void PORTD_set_int_level(const uint8_t level)
{
	PORTD.INTCTRL |= level;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTD_write_int0_mask(const uint8_t value)
{
	PORTD.INT0MASK = value;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTD_write_int1_mask(const uint8_t value)
{
	PORTD.INT1MASK = value;
}

/**
 * \brief Set port pin Output & Pull configuration
 *
 * Configure pin output mode and pull configuration
 *
 * \param[in] pin       		The pin number for device
 * \param[in] output_pull_mode	Pin output and pull mode
 */
static inline void PORTE_set_pin_output_pull_mode(const uint8_t pin, const enum port_output_pull_mode output_pull_mode)
{
	volatile uint8_t *port_pin_ctrl = (volatile uint8_t *)(&PORTE.PIN0CTRL) + pin;

	*port_pin_ctrl &= PORT_OPC_TOTEM_gc;
	if (output_pull_mode == PORT_CONFIGURATION_BUSKEEPER) {
		*port_pin_ctrl |= PORT_OPC_BUSKEEPER_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLDOWN) {
		*port_pin_ctrl |= PORT_OPC_PULLDOWN_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLUP) {
		*port_pin_ctrl |= PORT_OPC_PULLUP_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDOR) {
		*port_pin_ctrl |= PORT_OPC_WIREDOR_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDAND) {
		*port_pin_ctrl |= PORT_OPC_WIREDAND_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDORPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDORPULL_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDANDPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDANDPULL_gc;
	}
}

/**
 * \brief Set port pin inverted mode
 *
 * Configure pin invert I/O or not
 *
 * \param[in] pin       The pin number within port
 * \param[in] inverted  Pin inverted mode
 */
static inline void PORTE_pin_set_inverted(const uint8_t pin, const bool inverted)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTE + 0x10 + pin);

	if (inverted) {
		*port_pin_ctrl |= PORT_INVEN_bm;
	} else {
		*port_pin_ctrl &= ~PORT_INVEN_bm;
	}
}

/**
 * \brief Set port pin input/sense configuration
 *
 * Enable/disable digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] pin pin number within port
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 *
 */
static inline void PORTE_pin_set_isc(const uint8_t pin, const PORT_ISC_t isc)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTE + 0x10 + pin);

	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | isc;
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] mask      Bit mask where 1 means apply direction setting to the
 *                      corresponding pin
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTE_set_port_dir(const uint8_t mask, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTE.DIRCLR = mask;
		break;
	case PORT_DIR_OUT:
		PORTE.DIRSET = mask;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		PORTCFG.MPCMASK = mask;
		PORTE.PIN0CTRL  = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] pin       The pin number for device
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTE_set_pin_dir(const uint8_t pin, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTE.DIRCLR = 1 << pin;
		break;
	case PORT_DIR_OUT:
		PORTE.DIRSET = 1 << pin;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		*((uint8_t *)&PORTE + 0x10 + pin) = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on the pins defined by the bit mask
 *
 * \param[in] mask  Bit mask where 1 means apply port level to the corresponding
 *                  pin
 * \param[in] level true  = Pin levels set to "high" state
 *                  false = Pin levels set to "low" state
 */
static inline void PORTE_set_port_level(const uint8_t mask, const bool level)
{
	if (level == true) {
		PORTE.OUTSET = mask;
	} else {
		PORTE.OUTCLR = mask;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on a pin
 *
 * \param[in] pin       The pin number for device
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PORTE_set_pin_level(const uint8_t pin, const bool level)
{
	if (level == true) {
		PORTE.OUTSET = 1 << pin;
	} else {
		PORTE.OUTCLR = 1 << pin;
	}
}

/**
 * \brief Toggle out level on pins
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] mask  Bit mask where 1 means toggle pin level to the corresponding
 *                  pin
 */
static inline void PORTE_toggle_port_level(const uint8_t mask)
{
	PORTE.OUTTGL = mask;
}

/**
 * \brief Toggle output level on pin
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] pin       The pin number for device
 */
static inline void PORTE_toggle_pin_level(const uint8_t pin)
{
	PORTE.OUTTGL = 1 << pin;
}

/**
 * \brief Get input level on pins
 *
 * Read the input level on pins connected to a port
 *
 */
static inline uint8_t PORTE_get_port_level()
{
	return PORTE.IN;
}

/**
 * \brief Get level on pin
 *
 * Reads the level on pins connected to a port
 *
 * \param[in] pin       The pin number for device
 */
static inline bool PORTE_get_pin_level(const uint8_t pin)
{
	return PORTE.IN & (1 << pin);
}

/**
 * \brief Write value to Port
 *
 * Write directly to the port OUT register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTE_write_port(const uint8_t value)
{
	PORTE.OUT = value;
}

/**
 * \brief Write value to interrupt control register
 *
 * Read modify Write  to the interrupt control register
 *
 * \param[in] level Value to write to the port register
 */
static inline void PORTE_set_int_level(const uint8_t level)
{
	PORTE.INTCTRL |= level;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTE_write_int0_mask(const uint8_t value)
{
	PORTE.INT0MASK = value;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTE_write_int1_mask(const uint8_t value)
{
	PORTE.INT1MASK = value;
}

/**
 * \brief Set port pin Output & Pull configuration
 *
 * Configure pin output mode and pull configuration
 *
 * \param[in] pin       		The pin number for device
 * \param[in] output_pull_mode	Pin output and pull mode
 */
static inline void PORTF_set_pin_output_pull_mode(const uint8_t pin, const enum port_output_pull_mode output_pull_mode)
{
	volatile uint8_t *port_pin_ctrl = (volatile uint8_t *)(&PORTF.PIN0CTRL) + pin;

	*port_pin_ctrl &= PORT_OPC_TOTEM_gc;
	if (output_pull_mode == PORT_CONFIGURATION_BUSKEEPER) {
		*port_pin_ctrl |= PORT_OPC_BUSKEEPER_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLDOWN) {
		*port_pin_ctrl |= PORT_OPC_PULLDOWN_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLUP) {
		*port_pin_ctrl |= PORT_OPC_PULLUP_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDOR) {
		*port_pin_ctrl |= PORT_OPC_WIREDOR_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDAND) {
		*port_pin_ctrl |= PORT_OPC_WIREDAND_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDORPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDORPULL_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDANDPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDANDPULL_gc;
	}
}

/**
 * \brief Set port pin inverted mode
 *
 * Configure pin invert I/O or not
 *
 * \param[in] pin       The pin number within port
 * \param[in] inverted  Pin inverted mode
 */
static inline void PORTF_pin_set_inverted(const uint8_t pin, const bool inverted)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTF + 0x10 + pin);

	if (inverted) {
		*port_pin_ctrl |= PORT_INVEN_bm;
	} else {
		*port_pin_ctrl &= ~PORT_INVEN_bm;
	}
}

/**
 * \brief Set port pin input/sense configuration
 *
 * Enable/disable digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] pin pin number within port
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 *
 */
static inline void PORTF_pin_set_isc(const uint8_t pin, const PORT_ISC_t isc)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTF + 0x10 + pin);

	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | isc;
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] mask      Bit mask where 1 means apply direction setting to the
 *                      corresponding pin
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTF_set_port_dir(const uint8_t mask, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTF.DIRCLR = mask;
		break;
	case PORT_DIR_OUT:
		PORTF.DIRSET = mask;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		PORTCFG.MPCMASK = mask;
		PORTF.PIN0CTRL  = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] pin       The pin number for device
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTF_set_pin_dir(const uint8_t pin, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTF.DIRCLR = 1 << pin;
		break;
	case PORT_DIR_OUT:
		PORTF.DIRSET = 1 << pin;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		*((uint8_t *)&PORTF + 0x10 + pin) = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on the pins defined by the bit mask
 *
 * \param[in] mask  Bit mask where 1 means apply port level to the corresponding
 *                  pin
 * \param[in] level true  = Pin levels set to "high" state
 *                  false = Pin levels set to "low" state
 */
static inline void PORTF_set_port_level(const uint8_t mask, const bool level)
{
	if (level == true) {
		PORTF.OUTSET = mask;
	} else {
		PORTF.OUTCLR = mask;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on a pin
 *
 * \param[in] pin       The pin number for device
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PORTF_set_pin_level(const uint8_t pin, const bool level)
{
	if (level == true) {
		PORTF.OUTSET = 1 << pin;
	} else {
		PORTF.OUTCLR = 1 << pin;
	}
}

/**
 * \brief Toggle out level on pins
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] mask  Bit mask where 1 means toggle pin level to the corresponding
 *                  pin
 */
static inline void PORTF_toggle_port_level(const uint8_t mask)
{
	PORTF.OUTTGL = mask;
}

/**
 * \brief Toggle output level on pin
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] pin       The pin number for device
 */
static inline void PORTF_toggle_pin_level(const uint8_t pin)
{
	PORTF.OUTTGL = 1 << pin;
}

/**
 * \brief Get input level on pins
 *
 * Read the input level on pins connected to a port
 *
 */
static inline uint8_t PORTF_get_port_level()
{
	return PORTF.IN;
}

/**
 * \brief Get level on pin
 *
 * Reads the level on pins connected to a port
 *
 * \param[in] pin       The pin number for device
 */
static inline bool PORTF_get_pin_level(const uint8_t pin)
{
	return PORTF.IN & (1 << pin);
}

/**
 * \brief Write value to Port
 *
 * Write directly to the port OUT register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTF_write_port(const uint8_t value)
{
	PORTF.OUT = value;
}

/**
 * \brief Write value to interrupt control register
 *
 * Read modify Write  to the interrupt control register
 *
 * \param[in] level Value to write to the port register
 */
static inline void PORTF_set_int_level(const uint8_t level)
{
	PORTF.INTCTRL |= level;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTF_write_int0_mask(const uint8_t value)
{
	PORTF.INT0MASK = value;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTF_write_int1_mask(const uint8_t value)
{
	PORTF.INT1MASK = value;
}

/**
 * \brief Set port pin Output & Pull configuration
 *
 * Configure pin output mode and pull configuration
 *
 * \param[in] pin       		The pin number for device
 * \param[in] output_pull_mode	Pin output and pull mode
 */
static inline void PORTR_set_pin_output_pull_mode(const uint8_t pin, const enum port_output_pull_mode output_pull_mode)
{
	volatile uint8_t *port_pin_ctrl = (volatile uint8_t *)(&PORTR.PIN0CTRL) + pin;

	*port_pin_ctrl &= PORT_OPC_TOTEM_gc;
	if (output_pull_mode == PORT_CONFIGURATION_BUSKEEPER) {
		*port_pin_ctrl |= PORT_OPC_BUSKEEPER_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLDOWN) {
		*port_pin_ctrl |= PORT_OPC_PULLDOWN_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_PULLUP) {
		*port_pin_ctrl |= PORT_OPC_PULLUP_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDOR) {
		*port_pin_ctrl |= PORT_OPC_WIREDOR_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDAND) {
		*port_pin_ctrl |= PORT_OPC_WIREDAND_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDORPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDORPULL_gc;
	} else if (output_pull_mode == PORT_CONFIGURATION_WIREDANDPULL) {
		*port_pin_ctrl |= PORT_OPC_WIREDANDPULL_gc;
	}
}

/**
 * \brief Set port pin inverted mode
 *
 * Configure pin invert I/O or not
 *
 * \param[in] pin       The pin number within port
 * \param[in] inverted  Pin inverted mode
 */
static inline void PORTR_pin_set_inverted(const uint8_t pin, const bool inverted)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTR + 0x10 + pin);

	if (inverted) {
		*port_pin_ctrl |= PORT_INVEN_bm;
	} else {
		*port_pin_ctrl &= ~PORT_INVEN_bm;
	}
}

/**
 * \brief Set port pin input/sense configuration
 *
 * Enable/disable digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] pin pin number within port
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 *
 */
static inline void PORTR_pin_set_isc(const uint8_t pin, const PORT_ISC_t isc)
{
	volatile uint8_t *port_pin_ctrl = ((uint8_t *)&PORTR + 0x10 + pin);

	*port_pin_ctrl = (*port_pin_ctrl & ~PORT_ISC_gm) | isc;
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] mask      Bit mask where 1 means apply direction setting to the
 *                      corresponding pin
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTR_set_port_dir(const uint8_t mask, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTR.DIRCLR = mask;
		break;
	case PORT_DIR_OUT:
		PORTR.DIRSET = mask;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		PORTCFG.MPCMASK = mask;
		PORTR.PIN0CTRL  = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] pin       The pin number for device
 * \param[in] dir       PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void PORTR_set_pin_dir(const uint8_t pin, const enum port_dir dir)
{
	switch (dir) {
	case PORT_DIR_IN:
		PORTR.DIRCLR = 1 << pin;
		break;
	case PORT_DIR_OUT:
		PORTR.DIRSET = 1 << pin;
		break;
	case PORT_DIR_OFF:
		/* Activate pullup for power saving */
		*((uint8_t *)&PORTR + 0x10 + pin) = PORT_OPC_PULLUP_gc;
		break;
	default:
		break;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on the pins defined by the bit mask
 *
 * \param[in] mask  Bit mask where 1 means apply port level to the corresponding
 *                  pin
 * \param[in] level true  = Pin levels set to "high" state
 *                  false = Pin levels set to "low" state
 */
static inline void PORTR_set_port_level(const uint8_t mask, const bool level)
{
	if (level == true) {
		PORTR.OUTSET = mask;
	} else {
		PORTR.OUTCLR = mask;
	}
}

/**
 * \brief Set port level
 *
 * Sets output level on a pin
 *
 * \param[in] pin       The pin number for device
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void PORTR_set_pin_level(const uint8_t pin, const bool level)
{
	if (level == true) {
		PORTR.OUTSET = 1 << pin;
	} else {
		PORTR.OUTCLR = 1 << pin;
	}
}

/**
 * \brief Toggle out level on pins
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] mask  Bit mask where 1 means toggle pin level to the corresponding
 *                  pin
 */
static inline void PORTR_toggle_port_level(const uint8_t mask)
{
	PORTR.OUTTGL = mask;
}

/**
 * \brief Toggle output level on pin
 *
 * Toggle the pin levels on pins defined by bit mask
 *
 * \param[in] pin       The pin number for device
 */
static inline void PORTR_toggle_pin_level(const uint8_t pin)
{
	PORTR.OUTTGL = 1 << pin;
}

/**
 * \brief Get input level on pins
 *
 * Read the input level on pins connected to a port
 *
 */
static inline uint8_t PORTR_get_port_level()
{
	return PORTR.IN;
}

/**
 * \brief Get level on pin
 *
 * Reads the level on pins connected to a port
 *
 * \param[in] pin       The pin number for device
 */
static inline bool PORTR_get_pin_level(const uint8_t pin)
{
	return PORTR.IN & (1 << pin);
}

/**
 * \brief Write value to Port
 *
 * Write directly to the port OUT register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTR_write_port(const uint8_t value)
{
	PORTR.OUT = value;
}

/**
 * \brief Write value to interrupt control register
 *
 * Read modify Write  to the interrupt control register
 *
 * \param[in] level Value to write to the port register
 */
static inline void PORTR_set_int_level(const uint8_t level)
{
	PORTR.INTCTRL |= level;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTR_write_int0_mask(const uint8_t value)
{
	PORTR.INT0MASK = value;
}

/**
 * \brief Write value to interrupt mask
 *
 * Write directly to the interrupt mask register
 *
 * \param[in] value Value to write to the port register
 */
static inline void PORTR_write_int1_mask(const uint8_t value)
{
	PORTR.INT1MASK = value;
}

#ifdef __cplusplus
}
#endif

#endif /* PORT_INCLUDED */
