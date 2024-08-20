/* RA8876_Config.h
 A file to place user defines and configs.
*/

#ifndef RA8876_CONFIG_H
#define RA8876_CONFIG_H

// Hardware defines
#define USE_8080_8_BIT_MODE 8
#define USE_8080_16_BIT_MODE 16

// 8080 control signal defines for T4/MicroMod/DB5 (W/O shield)
#define RA8876_8080_CS 11
#define RA8876_8080_DC 13
#define RA8876_8080_RESET 12

#define RA8876_WR 53
#define RA8876_RD 52
#define RA8876_D0 40

/*
// Hardware defines DB5 board and Kurt's shield
#define RA8876_8080_CS 53
#define RA8876_8080_RESET 54
#define RA8876_8080_DC 55
#define RA8876_D0 40
#define BACKLITE 29
#define RA8876_RD 52    // FlexIO3:10: RD
#define RA8876_WR 56    // FlexIO3:11 WR
*/
#define BUS_SPEED 20 //Available settings 2,4,8,12,20,24,30,40,60,120

//External backlight control connected to this Arduino pin
//#define BACKLITE 5 
// #define BACKLITE 29 

// Uncomment to use FT5206 touch.
#define USE_FT5206_TOUCH

#endif // RA8876_CONFIG_H
