/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _VARIANT_ARDUINO_ZERO_
#define _VARIANT_ARDUINO_ZERO_

// The definitions here needs a SAMD core >=1.6.6
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10606

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (26u)
#define NUM_DIGITAL_PINS     (14u)
#define NUM_ANALOG_INPUTS    (6u)
#define NUM_ANALOG_OUTPUTS   (1u)
#define analogInputToDigitalPin(p)  ((p < 6u) ? (p) + 14u : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
//#define analogInPinToBit(P)        ( )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
// #define digitalPinToTimer(P)

// LEDs
#define PIN_LED_9			 (9u) //orig 13 instead of 9
#define PIN_LED_RXL          (25u)
#define PIN_LED_TXL          (26u)
#define PIN_LED              PIN_LED_9 //orig 13
#define PIN_LED2             PIN_LED_RXL
#define PIN_LED3             PIN_LED_TXL
#define LED_BUILTIN          PIN_LED_9 //orig 13

/*
 * Analog pins
 */
#define PIN_A0               (14ul)
#define PIN_A1               (15ul)
#define PIN_A2               (16ul)
#define PIN_A3               (17ul)
#define PIN_A4               (18ul)
#define PIN_A5               (19ul)
#define PIN_DAC0             (14ul)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t DAC0 = PIN_DAC0;
#define ADC_RESOLUTION		12

// Other pins
//#define PIN_ATN              (38ul)
//static const uint8_t ATN = PIN_ATN;
#define PIN_SPI_CS_SD		(31ul) //added instead of ATN above
#define PIN_SPI_CS_RFM		(27ul) //new
#define PIN_SPI_CS_XTB1		(26ul) //new
#define PIN_SPI_CS_XTB2		(16ul) //new
#define PIN_XTB_START		(19ul) //new
#define PIN_XTB_RESET		(30ul) //new
#define PIN_RF_NIRQ			(14ul) //new
#define PIN_RF_SDN			(42ul) //new
#define PIN_I_BATT			(18ul) //new
#define PIN_ENAB_GPS		(8ul)  //new
#define PIN_ENAB_BURN1		(25ul) //new
#define PIN_ENAB_BURN2		(2ul)  //new
#define PIN_ENAB_BURN3		(3ul)  //new
#define PIN_ENAB_BURN4		(4ul)  //new
#define PIN_GPS_1PPS		(15ul) //new
#define PIN_BURN_RELAY_A	(5ul)  //new
#define PIN_BURN_RELAY_B	(1ul)  //new
#define PIN_UART1_TX		(13ul) //new
#define PIN_UART1_RX		(10ul) //new
#define PIN_WDT_WDI			(12ul) //new
static const uint8_t SPI_CS_SD = PIN_SPI_CS_SD; //new
static const uint8_t SPI_CS_RFM = PIN_SPI_CS_RFM; //new
static const uint8_t SPI_CS_XTB1 = PIN_SPI_CS_XTB1; //new
static const uint8_t SPI_CS_XTB2 = PIN_SPI_CS_XTB2; //new
static const uint8_t XTB_START = PIN_XTB_START; //new
static const uint8_t XTB_RESET = PIN_XTB_RESET; //new
static const uint8_t RF_NIRQ = PIN_RF_NIRQ; //new
static const uint8_t RF_SDN = PIN_RF_SDN;  //new
static const uint8_t I_BATT = PIN_I_BATT;  //new
static const uint8_t ENAB_GPS = PIN_ENAB_GPS; //new
static const uint8_t ENAB_BURN1 = PIN_ENAB_BURN1; //new
static const uint8_t ENAB_BURN2 = PIN_ENAB_BURN2; //new
static const uint8_t ENAB_BURN3 = PIN_ENAB_BURN3; //new
static const uint8_t ENAB_BURN4 = PIN_ENAB_BURN4; //new
static const uint8_t GPS_1PPS = PIN_GPS_1PPS; //new
static const uint8_t BURN_RELAY_A = PIN_BURN_RELAY_A; //new
static const uint8_t BURN_RELAY_B = PIN_BURN_RELAY_B; //new
static const uint8_t UART1_TX = PIN_UART1_TX; //new
static const uint8_t UART1_RX = PIN_UART1_RX; //new
static const uint8_t WDT_WDI = PIN_WDT_WDI; //new

/*
 * Serial interfaces
 */
// Serial (EDBG)
#define PIN_SERIAL_RX       (31ul)
#define PIN_SERIAL_TX       (30ul)
#define PAD_SERIAL_TX       (UART_TX_PAD_2)
#define PAD_SERIAL_RX       (SERCOM_RX_PAD_3)

// Serial1
#define PIN_SERIAL1_RX       (0ul)
#define PIN_SERIAL1_TX       (1ul)
#define PAD_SERIAL1_TX       (UART_TX_PAD_2)
#define PAD_SERIAL1_RX       (SERCOM_RX_PAD_3)

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1
// Instead of using SERCOM4, and the SPI-header pins, the Mini Breakout
// uses pins 10-13 for SPI, on the unused sercom1
#define PIN_SPI_MISO         (20u) //orig 12
#define PIN_SPI_MOSI         (7u) //orig 11
#define PIN_SPI_SCK          (21u) //orig 13
#define PIN_SPI_SS           (19u) //orig 10
#define PERIPH_SPI           sercom3 //original sercom 1
// Pad Map:     0       1   2     3
//          MOSI (TX)  SCK  SS  MOSI (RX)
#define PAD_SPI_TX           SPI_PAD_3_SCK_1 //original pad 0, clk 1
#define PAD_SPI_RX           SERCOM_RX_PAD_0 //original pad 3

static const uint8_t SS	  = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (22u) //orig 20u
#define PIN_WIRE_SCL         (38u) //orig 21u
#define PERIPH_WIRE          sercom2 //orig sercom3
#define WIRE_IT_HANDLER      SERCOM2_Handler //orig sercom3_handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
//#define PIN_USB_HOST_ENABLE (27ul) //originally commented in
#define PIN_USB_DM          (28ul) //USB_D-
#define PIN_USB_DP          (29ul) //USB_D+

/*
 * I2S Interfaces
 */
#define I2S_INTERFACES_COUNT 1

#define I2S_DEVICE          0
#define I2S_CLOCK_GENERATOR 3
#define PIN_I2S_SD          (9u)
#define PIN_I2S_SCK         (1u)
#define PIN_I2S_FS          (0u)

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial;
extern Uart Serial1;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
#define SERIAL_PORT_MONITOR         Serial
// Serial has no physical pins broken out, so it's not listed as HARDWARE port
#define SERIAL_PORT_HARDWARE        Serial1
#define SERIAL_PORT_HARDWARE_OPEN   Serial1

#endif /* _VARIANT_ARDUINO_ZERO_ */
