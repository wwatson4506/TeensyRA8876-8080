/* RA8876_Config.h
 A file to place user defines and configs.
*/

#ifndef RA8876_CONFIG_H
#define RA8876_CONFIG_H

#define USE_8080_8_BIT_MODE 8
#define USE_8080_16_BIT_MODE 16
#define BUS_SPEED 20 //Available settings 2,4,8,12,20,24,30,40,60,120

//External backlight control connected to this Arduino pin
// Otherwise 3.3v
//#define BACKLITE 5 or change to your pin choice

#if defined(ARDUINO_TEENSY41)
// Hardware defines T4.1
#define RA8876_8080_CS 11
#define RA8876_8080_DC 13
#define RA8876_8080_RESET 12
#define RA8876_D0 19
#define RA8876_RD 37    // FlexIO3:19: RD
#define RA8876_WR 36    // FlexIO3:18: WR

#elif defined(ARDUINO_TEENSY_DEVBRD5)
// Hardware defines DB5 board and Kurt's shield
#define RA8876_8080_CS 53
#define RA8876_8080_RESET 54
#define RA8876_8080_DC 55
#define RA8876_D0 40
#define BACKLITE 29
#define RA8876_RD 52    // FlexIO3:10: RD
#define RA8876_WR 56    // FlexIO3:11 WR
#endif

// Uncomment to use FT5206 touch.
#define USE_FT5206_TOUCH

#endif // RA8876_CONFIG_H
