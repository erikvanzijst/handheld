/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set BUZZER output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void BUZZER_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set BUZZER data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BUZZER_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(0, dir);
}

/**
 * \brief Set BUZZER input/sense configuration
 *
 * Enable/disable BUZZER digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BUZZER_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(0, isc);
}

/**
 * \brief Set BUZZER inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BUZZER is inverted
 *                     false = I/O on BUZZER is not inverted
 */
static inline void BUZZER_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(0, inverted);
}

/**
 * \brief Set BUZZER level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BUZZER_set_level(const bool level)
{
	PORTA_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on BUZZER
 *
 * Toggle the pin level
 */
static inline void BUZZER_toggle_level()
{
	PORTA_toggle_pin_level(0);
}

/**
 * \brief Get level on BUZZER
 *
 * Reads the level on a pin
 */
static inline bool BUZZER_get_level()
{
	return PORTA_get_pin_level(0);
}

/**
 * \brief Set BUZZER interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void BUZZER_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set BUZZER interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void BUZZER_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set BUZZER interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void BUZZER_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set LDR output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void LDR_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set LDR data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LDR_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(1, dir);
}

/**
 * \brief Set LDR input/sense configuration
 *
 * Enable/disable LDR digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void LDR_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(1, isc);
}

/**
 * \brief Set LDR inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on LDR is inverted
 *                     false = I/O on LDR is not inverted
 */
static inline void LDR_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(1, inverted);
}

/**
 * \brief Set LDR level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LDR_set_level(const bool level)
{
	PORTA_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on LDR
 *
 * Toggle the pin level
 */
static inline void LDR_toggle_level()
{
	PORTA_toggle_pin_level(1);
}

/**
 * \brief Get level on LDR
 *
 * Reads the level on a pin
 */
static inline bool LDR_get_level()
{
	return PORTA_get_pin_level(1);
}

/**
 * \brief Set LDR interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void LDR_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set LDR interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void LDR_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set LDR interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void LDR_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set IRSD output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void IRSD_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set IRSD data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void IRSD_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(3, dir);
}

/**
 * \brief Set IRSD input/sense configuration
 *
 * Enable/disable IRSD digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void IRSD_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(3, isc);
}

/**
 * \brief Set IRSD inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on IRSD is inverted
 *                     false = I/O on IRSD is not inverted
 */
static inline void IRSD_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(3, inverted);
}

/**
 * \brief Set IRSD level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void IRSD_set_level(const bool level)
{
	PORTA_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on IRSD
 *
 * Toggle the pin level
 */
static inline void IRSD_toggle_level()
{
	PORTA_toggle_pin_level(3);
}

/**
 * \brief Get level on IRSD
 *
 * Reads the level on a pin
 */
static inline bool IRSD_get_level()
{
	return PORTA_get_pin_level(3);
}

/**
 * \brief Set IRSD interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void IRSD_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set IRSD interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void IRSD_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set IRSD interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void IRSD_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set BATT output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void BATT_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTA_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set BATT data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BATT_set_dir(const enum port_dir dir)
{
	PORTA_set_pin_dir(7, dir);
}

/**
 * \brief Set BATT input/sense configuration
 *
 * Enable/disable BATT digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BATT_set_isc(const PORT_ISC_t isc)
{
	PORTA_pin_set_isc(7, isc);
}

/**
 * \brief Set BATT inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BATT is inverted
 *                     false = I/O on BATT is not inverted
 */
static inline void BATT_set_inverted(const bool inverted)
{
	PORTA_pin_set_inverted(7, inverted);
}

/**
 * \brief Set BATT level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BATT_set_level(const bool level)
{
	PORTA_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on BATT
 *
 * Toggle the pin level
 */
static inline void BATT_toggle_level()
{
	PORTA_toggle_pin_level(7);
}

/**
 * \brief Get level on BATT
 *
 * Reads the level on a pin
 */
static inline bool BATT_get_level()
{
	return PORTA_get_pin_level(7);
}

/**
 * \brief Set BATT interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void BATT_int_level(const uint8_t level)
{
	PORTA_set_int_level(level);
}

/**
 * \brief Set BATT interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void BATT_int0_mask(const uint8_t value)
{
	PORTA_write_int0_mask(value);
}

/**
 * \brief Set BATT interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void BATT_int1_mask(const uint8_t value)
{
	PORTA_write_int1_mask(value);
}

/**
 * \brief Set BATTCHK output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void BATTCHK_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set BATTCHK data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BATTCHK_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(0, dir);
}

/**
 * \brief Set BATTCHK input/sense configuration
 *
 * Enable/disable BATTCHK digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BATTCHK_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(0, isc);
}

/**
 * \brief Set BATTCHK inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BATTCHK is inverted
 *                     false = I/O on BATTCHK is not inverted
 */
static inline void BATTCHK_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(0, inverted);
}

/**
 * \brief Set BATTCHK level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BATTCHK_set_level(const bool level)
{
	PORTB_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on BATTCHK
 *
 * Toggle the pin level
 */
static inline void BATTCHK_toggle_level()
{
	PORTB_toggle_pin_level(0);
}

/**
 * \brief Get level on BATTCHK
 *
 * Reads the level on a pin
 */
static inline bool BATTCHK_get_level()
{
	return PORTB_get_pin_level(0);
}

/**
 * \brief Set BATTCHK interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void BATTCHK_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set BATTCHK interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void BATTCHK_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set BATTCHK interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void BATTCHK_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set BATTLVL output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void BATTLVL_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTB_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set BATTLVL data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void BATTLVL_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(1, dir);
}

/**
 * \brief Set BATTLVL input/sense configuration
 *
 * Enable/disable BATTLVL digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void BATTLVL_set_isc(const PORT_ISC_t isc)
{
	PORTB_pin_set_isc(1, isc);
}

/**
 * \brief Set BATTLVL inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on BATTLVL is inverted
 *                     false = I/O on BATTLVL is not inverted
 */
static inline void BATTLVL_set_inverted(const bool inverted)
{
	PORTB_pin_set_inverted(1, inverted);
}

/**
 * \brief Set BATTLVL level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void BATTLVL_set_level(const bool level)
{
	PORTB_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on BATTLVL
 *
 * Toggle the pin level
 */
static inline void BATTLVL_toggle_level()
{
	PORTB_toggle_pin_level(1);
}

/**
 * \brief Get level on BATTLVL
 *
 * Reads the level on a pin
 */
static inline bool BATTLVL_get_level()
{
	return PORTB_get_pin_level(1);
}

/**
 * \brief Set BATTLVL interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void BATTLVL_int_level(const uint8_t level)
{
	PORTB_set_int_level(level);
}

/**
 * \brief Set BATTLVL interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void BATTLVL_int0_mask(const uint8_t value)
{
	PORTB_write_int0_mask(value);
}

/**
 * \brief Set BATTLVL interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void BATTLVL_int1_mask(const uint8_t value)
{
	PORTB_write_int1_mask(value);
}

/**
 * \brief Set ROWCLK output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROWCLK_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set ROWCLK data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROWCLK_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(1, dir);
}

/**
 * \brief Set ROWCLK input/sense configuration
 *
 * Enable/disable ROWCLK digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROWCLK_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(1, isc);
}

/**
 * \brief Set ROWCLK inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROWCLK is inverted
 *                     false = I/O on ROWCLK is not inverted
 */
static inline void ROWCLK_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(1, inverted);
}

/**
 * \brief Set ROWCLK level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROWCLK_set_level(const bool level)
{
	PORTC_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on ROWCLK
 *
 * Toggle the pin level
 */
static inline void ROWCLK_toggle_level()
{
	PORTC_toggle_pin_level(1);
}

/**
 * \brief Get level on ROWCLK
 *
 * Reads the level on a pin
 */
static inline bool ROWCLK_get_level()
{
	return PORTC_get_pin_level(1);
}

/**
 * \brief Set ROWCLK interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROWCLK_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set ROWCLK interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROWCLK_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set ROWCLK interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROWCLK_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set ROWSDI output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void ROWSDI_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set ROWSDI data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void ROWSDI_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(4, dir);
}

/**
 * \brief Set ROWSDI input/sense configuration
 *
 * Enable/disable ROWSDI digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void ROWSDI_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(4, isc);
}

/**
 * \brief Set ROWSDI inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on ROWSDI is inverted
 *                     false = I/O on ROWSDI is not inverted
 */
static inline void ROWSDI_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(4, inverted);
}

/**
 * \brief Set ROWSDI level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void ROWSDI_set_level(const bool level)
{
	PORTC_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on ROWSDI
 *
 * Toggle the pin level
 */
static inline void ROWSDI_toggle_level()
{
	PORTC_toggle_pin_level(4);
}

/**
 * \brief Get level on ROWSDI
 *
 * Reads the level on a pin
 */
static inline bool ROWSDI_get_level()
{
	return PORTC_get_pin_level(4);
}

/**
 * \brief Set ROWSDI interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void ROWSDI_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set ROWSDI interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROWSDI_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set ROWSDI interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void ROWSDI_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set OEB output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void OEB_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set OEB data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void OEB_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(5, dir);
}

/**
 * \brief Set OEB input/sense configuration
 *
 * Enable/disable OEB digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void OEB_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(5, isc);
}

/**
 * \brief Set OEB inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on OEB is inverted
 *                     false = I/O on OEB is not inverted
 */
static inline void OEB_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(5, inverted);
}

/**
 * \brief Set OEB level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void OEB_set_level(const bool level)
{
	PORTC_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on OEB
 *
 * Toggle the pin level
 */
static inline void OEB_toggle_level()
{
	PORTC_toggle_pin_level(5);
}

/**
 * \brief Get level on OEB
 *
 * Reads the level on a pin
 */
static inline bool OEB_get_level()
{
	return PORTC_get_pin_level(5);
}

/**
 * \brief Set OEB interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void OEB_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set OEB interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void OEB_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set OEB interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void OEB_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set LE output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void LE_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(6, output_pull_mode);
}

/**
 * \brief Set LE data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LE_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(6, dir);
}

/**
 * \brief Set LE input/sense configuration
 *
 * Enable/disable LE digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void LE_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(6, isc);
}

/**
 * \brief Set LE inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on LE is inverted
 *                     false = I/O on LE is not inverted
 */
static inline void LE_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(6, inverted);
}

/**
 * \brief Set LE level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LE_set_level(const bool level)
{
	PORTC_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on LE
 *
 * Toggle the pin level
 */
static inline void LE_toggle_level()
{
	PORTC_toggle_pin_level(6);
}

/**
 * \brief Get level on LE
 *
 * Reads the level on a pin
 */
static inline bool LE_get_level()
{
	return PORTC_get_pin_level(6);
}

/**
 * \brief Set LE interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void LE_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set LE interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void LE_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set LE interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void LE_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set SW_UP output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_UP_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTC_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set SW_UP data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_UP_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(7, dir);
}

/**
 * \brief Set SW_UP input/sense configuration
 *
 * Enable/disable SW_UP digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_UP_set_isc(const PORT_ISC_t isc)
{
	PORTC_pin_set_isc(7, isc);
}

/**
 * \brief Set SW_UP inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_UP is inverted
 *                     false = I/O on SW_UP is not inverted
 */
static inline void SW_UP_set_inverted(const bool inverted)
{
	PORTC_pin_set_inverted(7, inverted);
}

/**
 * \brief Set SW_UP level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_UP_set_level(const bool level)
{
	PORTC_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on SW_UP
 *
 * Toggle the pin level
 */
static inline void SW_UP_toggle_level()
{
	PORTC_toggle_pin_level(7);
}

/**
 * \brief Get level on SW_UP
 *
 * Reads the level on a pin
 */
static inline bool SW_UP_get_level()
{
	return PORTC_get_pin_level(7);
}

/**
 * \brief Set SW_UP interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_UP_int_level(const uint8_t level)
{
	PORTC_set_int_level(level);
}

/**
 * \brief Set SW_UP interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_UP_int0_mask(const uint8_t value)
{
	PORTC_write_int0_mask(value);
}

/**
 * \brief Set SW_UP interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_UP_int1_mask(const uint8_t value)
{
	PORTC_write_int1_mask(value);
}

/**
 * \brief Set SW_LEFT output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_LEFT_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set SW_LEFT data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_LEFT_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(0, dir);
}

/**
 * \brief Set SW_LEFT input/sense configuration
 *
 * Enable/disable SW_LEFT digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_LEFT_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(0, isc);
}

/**
 * \brief Set SW_LEFT inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_LEFT is inverted
 *                     false = I/O on SW_LEFT is not inverted
 */
static inline void SW_LEFT_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(0, inverted);
}

/**
 * \brief Set SW_LEFT level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_LEFT_set_level(const bool level)
{
	PORTD_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on SW_LEFT
 *
 * Toggle the pin level
 */
static inline void SW_LEFT_toggle_level()
{
	PORTD_toggle_pin_level(0);
}

/**
 * \brief Get level on SW_LEFT
 *
 * Reads the level on a pin
 */
static inline bool SW_LEFT_get_level()
{
	return PORTD_get_pin_level(0);
}

/**
 * \brief Set SW_LEFT interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_LEFT_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set SW_LEFT interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_LEFT_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set SW_LEFT interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_LEFT_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set SW_RIGHT output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_RIGHT_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set SW_RIGHT data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_RIGHT_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(1, dir);
}

/**
 * \brief Set SW_RIGHT input/sense configuration
 *
 * Enable/disable SW_RIGHT digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_RIGHT_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(1, isc);
}

/**
 * \brief Set SW_RIGHT inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_RIGHT is inverted
 *                     false = I/O on SW_RIGHT is not inverted
 */
static inline void SW_RIGHT_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(1, inverted);
}

/**
 * \brief Set SW_RIGHT level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_RIGHT_set_level(const bool level)
{
	PORTD_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on SW_RIGHT
 *
 * Toggle the pin level
 */
static inline void SW_RIGHT_toggle_level()
{
	PORTD_toggle_pin_level(1);
}

/**
 * \brief Get level on SW_RIGHT
 *
 * Reads the level on a pin
 */
static inline bool SW_RIGHT_get_level()
{
	return PORTD_get_pin_level(1);
}

/**
 * \brief Set SW_RIGHT interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_RIGHT_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set SW_RIGHT interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_RIGHT_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set SW_RIGHT interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_RIGHT_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set SW_DOWN output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_DOWN_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set SW_DOWN data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_DOWN_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(4, dir);
}

/**
 * \brief Set SW_DOWN input/sense configuration
 *
 * Enable/disable SW_DOWN digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_DOWN_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(4, isc);
}

/**
 * \brief Set SW_DOWN inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_DOWN is inverted
 *                     false = I/O on SW_DOWN is not inverted
 */
static inline void SW_DOWN_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(4, inverted);
}

/**
 * \brief Set SW_DOWN level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_DOWN_set_level(const bool level)
{
	PORTD_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on SW_DOWN
 *
 * Toggle the pin level
 */
static inline void SW_DOWN_toggle_level()
{
	PORTD_toggle_pin_level(4);
}

/**
 * \brief Get level on SW_DOWN
 *
 * Reads the level on a pin
 */
static inline bool SW_DOWN_get_level()
{
	return PORTD_get_pin_level(4);
}

/**
 * \brief Set SW_DOWN interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_DOWN_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set SW_DOWN interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_DOWN_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set SW_DOWN interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_DOWN_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set SELECT output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SELECT_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTD_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set SELECT data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SELECT_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(5, dir);
}

/**
 * \brief Set SELECT input/sense configuration
 *
 * Enable/disable SELECT digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SELECT_set_isc(const PORT_ISC_t isc)
{
	PORTD_pin_set_isc(5, isc);
}

/**
 * \brief Set SELECT inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SELECT is inverted
 *                     false = I/O on SELECT is not inverted
 */
static inline void SELECT_set_inverted(const bool inverted)
{
	PORTD_pin_set_inverted(5, inverted);
}

/**
 * \brief Set SELECT level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SELECT_set_level(const bool level)
{
	PORTD_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on SELECT
 *
 * Toggle the pin level
 */
static inline void SELECT_toggle_level()
{
	PORTD_toggle_pin_level(5);
}

/**
 * \brief Get level on SELECT
 *
 * Reads the level on a pin
 */
static inline bool SELECT_get_level()
{
	return PORTD_get_pin_level(5);
}

/**
 * \brief Set SELECT interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SELECT_int_level(const uint8_t level)
{
	PORTD_set_int_level(level);
}

/**
 * \brief Set SELECT interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SELECT_int0_mask(const uint8_t value)
{
	PORTD_write_int0_mask(value);
}

/**
 * \brief Set SELECT interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SELECT_int1_mask(const uint8_t value)
{
	PORTD_write_int1_mask(value);
}

/**
 * \brief Set SEGCLK0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SEGCLK0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set SEGCLK0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEGCLK0_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(0, dir);
}

/**
 * \brief Set SEGCLK0 input/sense configuration
 *
 * Enable/disable SEGCLK0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEGCLK0_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(0, isc);
}

/**
 * \brief Set SEGCLK0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEGCLK0 is inverted
 *                     false = I/O on SEGCLK0 is not inverted
 */
static inline void SEGCLK0_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(0, inverted);
}

/**
 * \brief Set SEGCLK0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEGCLK0_set_level(const bool level)
{
	PORTE_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on SEGCLK0
 *
 * Toggle the pin level
 */
static inline void SEGCLK0_toggle_level()
{
	PORTE_toggle_pin_level(0);
}

/**
 * \brief Get level on SEGCLK0
 *
 * Reads the level on a pin
 */
static inline bool SEGCLK0_get_level()
{
	return PORTE_get_pin_level(0);
}

/**
 * \brief Set SEGCLK0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SEGCLK0_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set SEGCLK0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SEGCLK0_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set SEGCLK0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SEGCLK0_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set SEGCLK1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SEGCLK1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set SEGCLK1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEGCLK1_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(1, dir);
}

/**
 * \brief Set SEGCLK1 input/sense configuration
 *
 * Enable/disable SEGCLK1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEGCLK1_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(1, isc);
}

/**
 * \brief Set SEGCLK1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEGCLK1 is inverted
 *                     false = I/O on SEGCLK1 is not inverted
 */
static inline void SEGCLK1_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(1, inverted);
}

/**
 * \brief Set SEGCLK1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEGCLK1_set_level(const bool level)
{
	PORTE_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on SEGCLK1
 *
 * Toggle the pin level
 */
static inline void SEGCLK1_toggle_level()
{
	PORTE_toggle_pin_level(1);
}

/**
 * \brief Get level on SEGCLK1
 *
 * Reads the level on a pin
 */
static inline bool SEGCLK1_get_level()
{
	return PORTE_get_pin_level(1);
}

/**
 * \brief Set SEGCLK1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SEGCLK1_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set SEGCLK1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SEGCLK1_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set SEGCLK1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SEGCLK1_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set SW_A output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_A_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set SW_A data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_A_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(2, dir);
}

/**
 * \brief Set SW_A input/sense configuration
 *
 * Enable/disable SW_A digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_A_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(2, isc);
}

/**
 * \brief Set SW_A inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_A is inverted
 *                     false = I/O on SW_A is not inverted
 */
static inline void SW_A_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(2, inverted);
}

/**
 * \brief Set SW_A level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_A_set_level(const bool level)
{
	PORTE_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on SW_A
 *
 * Toggle the pin level
 */
static inline void SW_A_toggle_level()
{
	PORTE_toggle_pin_level(2);
}

/**
 * \brief Get level on SW_A
 *
 * Reads the level on a pin
 */
static inline bool SW_A_get_level()
{
	return PORTE_get_pin_level(2);
}

/**
 * \brief Set SW_A interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_A_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set SW_A interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_A_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set SW_A interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_A_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set SW_X output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_X_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set SW_X data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_X_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(3, dir);
}

/**
 * \brief Set SW_X input/sense configuration
 *
 * Enable/disable SW_X digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_X_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(3, isc);
}

/**
 * \brief Set SW_X inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_X is inverted
 *                     false = I/O on SW_X is not inverted
 */
static inline void SW_X_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(3, inverted);
}

/**
 * \brief Set SW_X level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_X_set_level(const bool level)
{
	PORTE_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on SW_X
 *
 * Toggle the pin level
 */
static inline void SW_X_toggle_level()
{
	PORTE_toggle_pin_level(3);
}

/**
 * \brief Get level on SW_X
 *
 * Reads the level on a pin
 */
static inline bool SW_X_get_level()
{
	return PORTE_get_pin_level(3);
}

/**
 * \brief Set SW_X interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_X_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set SW_X interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_X_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set SW_X interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_X_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set SW_B output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_B_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set SW_B data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_B_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(4, dir);
}

/**
 * \brief Set SW_B input/sense configuration
 *
 * Enable/disable SW_B digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_B_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(4, isc);
}

/**
 * \brief Set SW_B inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_B is inverted
 *                     false = I/O on SW_B is not inverted
 */
static inline void SW_B_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(4, inverted);
}

/**
 * \brief Set SW_B level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_B_set_level(const bool level)
{
	PORTE_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on SW_B
 *
 * Toggle the pin level
 */
static inline void SW_B_toggle_level()
{
	PORTE_toggle_pin_level(4);
}

/**
 * \brief Get level on SW_B
 *
 * Reads the level on a pin
 */
static inline bool SW_B_get_level()
{
	return PORTE_get_pin_level(4);
}

/**
 * \brief Set SW_B interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_B_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set SW_B interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_B_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set SW_B interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_B_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set SW_Y output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SW_Y_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set SW_Y data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SW_Y_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(5, dir);
}

/**
 * \brief Set SW_Y input/sense configuration
 *
 * Enable/disable SW_Y digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SW_Y_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(5, isc);
}

/**
 * \brief Set SW_Y inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SW_Y is inverted
 *                     false = I/O on SW_Y is not inverted
 */
static inline void SW_Y_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(5, inverted);
}

/**
 * \brief Set SW_Y level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SW_Y_set_level(const bool level)
{
	PORTE_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on SW_Y
 *
 * Toggle the pin level
 */
static inline void SW_Y_toggle_level()
{
	PORTE_toggle_pin_level(5);
}

/**
 * \brief Get level on SW_Y
 *
 * Reads the level on a pin
 */
static inline bool SW_Y_get_level()
{
	return PORTE_get_pin_level(5);
}

/**
 * \brief Set SW_Y interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SW_Y_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set SW_Y interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_Y_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set SW_Y interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SW_Y_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set START output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void START_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(6, output_pull_mode);
}

/**
 * \brief Set START data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void START_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(6, dir);
}

/**
 * \brief Set START input/sense configuration
 *
 * Enable/disable START digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void START_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(6, isc);
}

/**
 * \brief Set START inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on START is inverted
 *                     false = I/O on START is not inverted
 */
static inline void START_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(6, inverted);
}

/**
 * \brief Set START level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void START_set_level(const bool level)
{
	PORTE_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on START
 *
 * Toggle the pin level
 */
static inline void START_toggle_level()
{
	PORTE_toggle_pin_level(6);
}

/**
 * \brief Get level on START
 *
 * Reads the level on a pin
 */
static inline bool START_get_level()
{
	return PORTE_get_pin_level(6);
}

/**
 * \brief Set START interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void START_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set START interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void START_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set START interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void START_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set SEGCLK2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void SEGCLK2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTE_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set SEGCLK2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void SEGCLK2_set_dir(const enum port_dir dir)
{
	PORTE_set_pin_dir(7, dir);
}

/**
 * \brief Set SEGCLK2 input/sense configuration
 *
 * Enable/disable SEGCLK2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void SEGCLK2_set_isc(const PORT_ISC_t isc)
{
	PORTE_pin_set_isc(7, isc);
}

/**
 * \brief Set SEGCLK2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on SEGCLK2 is inverted
 *                     false = I/O on SEGCLK2 is not inverted
 */
static inline void SEGCLK2_set_inverted(const bool inverted)
{
	PORTE_pin_set_inverted(7, inverted);
}

/**
 * \brief Set SEGCLK2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void SEGCLK2_set_level(const bool level)
{
	PORTE_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on SEGCLK2
 *
 * Toggle the pin level
 */
static inline void SEGCLK2_toggle_level()
{
	PORTE_toggle_pin_level(7);
}

/**
 * \brief Get level on SEGCLK2
 *
 * Reads the level on a pin
 */
static inline bool SEGCLK2_get_level()
{
	return PORTE_get_pin_level(7);
}

/**
 * \brief Set SEGCLK2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void SEGCLK2_int_level(const uint8_t level)
{
	PORTE_set_int_level(level);
}

/**
 * \brief Set SEGCLK2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void SEGCLK2_int0_mask(const uint8_t value)
{
	PORTE_write_int0_mask(value);
}

/**
 * \brief Set SEGCLK2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void SEGCLK2_int1_mask(const uint8_t value)
{
	PORTE_write_int1_mask(value);
}

/**
 * \brief Set D0 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D0_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(0, output_pull_mode);
}

/**
 * \brief Set D0 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D0_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(0, dir);
}

/**
 * \brief Set D0 input/sense configuration
 *
 * Enable/disable D0 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D0_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(0, isc);
}

/**
 * \brief Set D0 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D0 is inverted
 *                     false = I/O on D0 is not inverted
 */
static inline void D0_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(0, inverted);
}

/**
 * \brief Set D0 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D0_set_level(const bool level)
{
	PORTF_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on D0
 *
 * Toggle the pin level
 */
static inline void D0_toggle_level()
{
	PORTF_toggle_pin_level(0);
}

/**
 * \brief Get level on D0
 *
 * Reads the level on a pin
 */
static inline bool D0_get_level()
{
	return PORTF_get_pin_level(0);
}

/**
 * \brief Set D0 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D0_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D0 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D0_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D0 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D0_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

/**
 * \brief Set D1 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D1_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(1, output_pull_mode);
}

/**
 * \brief Set D1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D1_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(1, dir);
}

/**
 * \brief Set D1 input/sense configuration
 *
 * Enable/disable D1 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D1_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(1, isc);
}

/**
 * \brief Set D1 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D1 is inverted
 *                     false = I/O on D1 is not inverted
 */
static inline void D1_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(1, inverted);
}

/**
 * \brief Set D1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D1_set_level(const bool level)
{
	PORTF_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on D1
 *
 * Toggle the pin level
 */
static inline void D1_toggle_level()
{
	PORTF_toggle_pin_level(1);
}

/**
 * \brief Get level on D1
 *
 * Reads the level on a pin
 */
static inline bool D1_get_level()
{
	return PORTF_get_pin_level(1);
}

/**
 * \brief Set D1 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D1_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D1 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D1_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D1 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D1_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

/**
 * \brief Set D2 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D2_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(2, output_pull_mode);
}

/**
 * \brief Set D2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D2_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(2, dir);
}

/**
 * \brief Set D2 input/sense configuration
 *
 * Enable/disable D2 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D2_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(2, isc);
}

/**
 * \brief Set D2 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D2 is inverted
 *                     false = I/O on D2 is not inverted
 */
static inline void D2_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(2, inverted);
}

/**
 * \brief Set D2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D2_set_level(const bool level)
{
	PORTF_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on D2
 *
 * Toggle the pin level
 */
static inline void D2_toggle_level()
{
	PORTF_toggle_pin_level(2);
}

/**
 * \brief Get level on D2
 *
 * Reads the level on a pin
 */
static inline bool D2_get_level()
{
	return PORTF_get_pin_level(2);
}

/**
 * \brief Set D2 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D2_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D2 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D2_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D2 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D2_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

/**
 * \brief Set D3 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D3_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(3, output_pull_mode);
}

/**
 * \brief Set D3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D3_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(3, dir);
}

/**
 * \brief Set D3 input/sense configuration
 *
 * Enable/disable D3 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D3_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(3, isc);
}

/**
 * \brief Set D3 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D3 is inverted
 *                     false = I/O on D3 is not inverted
 */
static inline void D3_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(3, inverted);
}

/**
 * \brief Set D3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D3_set_level(const bool level)
{
	PORTF_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on D3
 *
 * Toggle the pin level
 */
static inline void D3_toggle_level()
{
	PORTF_toggle_pin_level(3);
}

/**
 * \brief Get level on D3
 *
 * Reads the level on a pin
 */
static inline bool D3_get_level()
{
	return PORTF_get_pin_level(3);
}

/**
 * \brief Set D3 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D3_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D3 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D3_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D3 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D3_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

/**
 * \brief Set D4 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D4_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(4, output_pull_mode);
}

/**
 * \brief Set D4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D4_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(4, dir);
}

/**
 * \brief Set D4 input/sense configuration
 *
 * Enable/disable D4 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D4_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(4, isc);
}

/**
 * \brief Set D4 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D4 is inverted
 *                     false = I/O on D4 is not inverted
 */
static inline void D4_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(4, inverted);
}

/**
 * \brief Set D4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D4_set_level(const bool level)
{
	PORTF_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on D4
 *
 * Toggle the pin level
 */
static inline void D4_toggle_level()
{
	PORTF_toggle_pin_level(4);
}

/**
 * \brief Get level on D4
 *
 * Reads the level on a pin
 */
static inline bool D4_get_level()
{
	return PORTF_get_pin_level(4);
}

/**
 * \brief Set D4 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D4_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D4 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D4_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D4 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D4_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

/**
 * \brief Set D5 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D5_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(5, output_pull_mode);
}

/**
 * \brief Set D5 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D5_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(5, dir);
}

/**
 * \brief Set D5 input/sense configuration
 *
 * Enable/disable D5 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D5_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(5, isc);
}

/**
 * \brief Set D5 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D5 is inverted
 *                     false = I/O on D5 is not inverted
 */
static inline void D5_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(5, inverted);
}

/**
 * \brief Set D5 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D5_set_level(const bool level)
{
	PORTF_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on D5
 *
 * Toggle the pin level
 */
static inline void D5_toggle_level()
{
	PORTF_toggle_pin_level(5);
}

/**
 * \brief Get level on D5
 *
 * Reads the level on a pin
 */
static inline bool D5_get_level()
{
	return PORTF_get_pin_level(5);
}

/**
 * \brief Set D5 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D5_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D5 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D5_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D5 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D5_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

/**
 * \brief Set D6 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D6_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(6, output_pull_mode);
}

/**
 * \brief Set D6 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D6_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(6, dir);
}

/**
 * \brief Set D6 input/sense configuration
 *
 * Enable/disable D6 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D6_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(6, isc);
}

/**
 * \brief Set D6 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D6 is inverted
 *                     false = I/O on D6 is not inverted
 */
static inline void D6_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(6, inverted);
}

/**
 * \brief Set D6 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D6_set_level(const bool level)
{
	PORTF_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on D6
 *
 * Toggle the pin level
 */
static inline void D6_toggle_level()
{
	PORTF_toggle_pin_level(6);
}

/**
 * \brief Get level on D6
 *
 * Reads the level on a pin
 */
static inline bool D6_get_level()
{
	return PORTF_get_pin_level(6);
}

/**
 * \brief Set D6 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D6_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D6 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D6_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D6 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D6_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

/**
 * \brief Set D7 output & pull configuration
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] output_pull_mode Pin output & pull mode
 */
static inline void D7_set_output_pull_mode(const enum port_output_pull_mode output_pull_mode)
{
	PORTF_set_pin_output_pull_mode(7, output_pull_mode);
}

/**
 * \brief Set D7 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void D7_set_dir(const enum port_dir dir)
{
	PORTF_set_pin_dir(7, dir);
}

/**
 * \brief Set D7 input/sense configuration
 *
 * Enable/disable D7 digital input buffer and pin change interrupt,
 * select pin interrupt edge/level sensing mode
 *
 * \param[in] isc PORT_ISC_BOTHEDGES_gc     = Sense Both Edges
 *                PORT_ISC_RISING_gc        = Sense Rising Edge
 *                PORT_ISC_FALLING_gc       = Sense Falling Edge
 *                PORT_ISC_INPUT_DISABLE_gc = Digital Input Buffer disabled
 *                PORT_ISC_LEVEL_gc         = Sense low Level
 */
static inline void D7_set_isc(const PORT_ISC_t isc)
{
	PORTF_pin_set_isc(7, isc);
}

/**
 * \brief Set D7 inverted mode
 *
 * Enable or disable inverted I/O on a pin
 *
 * \param[in] inverted true  = I/O on D7 is inverted
 *                     false = I/O on D7 is not inverted
 */
static inline void D7_set_inverted(const bool inverted)
{
	PORTF_pin_set_inverted(7, inverted);
}

/**
 * \brief Set D7 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void D7_set_level(const bool level)
{
	PORTF_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on D7
 *
 * Toggle the pin level
 */
static inline void D7_toggle_level()
{
	PORTF_toggle_pin_level(7);
}

/**
 * \brief Get level on D7
 *
 * Reads the level on a pin
 */
static inline bool D7_get_level()
{
	return PORTF_get_pin_level(7);
}

/**
 * \brief Set D7 interrupt level
 *
 * Sets interrupt level for port
 *
 * \param[in] level Value to write to the port register
 */
static inline void D7_int_level(const uint8_t level)
{
	PORTF_set_int_level(level);
}

/**
 * \brief Set D7 interrupt vector 0 mask
 *
 * Sets interrupt mask for port vector 0
 *
 * \param[in] value Value to write to the port register
 */
static inline void D7_int0_mask(const uint8_t value)
{
	PORTF_write_int0_mask(value);
}

/**
 * \brief Set D7 interrupt vector 1 mask
 *
 * Sets interrupt mask for port vector 1
 *
 * \param[in] value Value to write to the port register
 */
static inline void D7_int1_mask(const uint8_t value)
{
	PORTF_write_int1_mask(value);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
