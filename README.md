# TeensyRA8876-8080
## A RA8876 8080 parallel driver library for Teensy boards and variants.

This library is designed to be used with the TeensyRa8876-GFX-Common library and can be found here:
- https://github.com/wwatson4506/TeensyRA8876-GFX-Common

This driver also uses a new FlexIO library found here:
- https://github.com/KurtE/FlexIO_t4/tree/master

Communication with the Teensy is accomplished using the 8080 parallel mode of FlexIO. To install unzip the zip file in the Arduino/libraries folder.

Example sketches can be found in the TeensyRA8876-8080 and TeensyRA8876-SPI examples folders.

![https://github.com/wwatson4506/TeensyRA8876-8080/blob/main/extras/MEM_Transfer.jpg](https://github.com/wwatson4506/TeensyRA8876-8080/blob/main/extras/MEM_Transfer.jpg)

# PINOUTS

### CONNECTING THE TEENSY TO THE ER-TFTM101-1 in FlexIO 8080 mode

40 pin dual inline connector pinouts can be found here:

https://www.buydisplay.com/download/interfacing/ER-TFTM101-1_RTP_Interfacing.pdf

## WIRED
### Dev Board 5 <_______> RA8876

      PIN                     PIN
*********************************
Use These 8 data lines for 8-bit data bus.
- D0  40 _______________> 15 
- D1  41 _______________> 16
- D2  42 _______________> 17 
- D3  43 _______________> 18 
- D4  44 _______________> 19
- D5  45 _______________> 20
- D6  06 _______________> 21
- D7  09 _______________> 22
*********************************
Add These 8 data lines for 16-bit data bus.
- D8  32 _______________> 23  
- D9  47 _______________> 24
- D10 48 _______________> 25 
- D11 49 _______________> 26 
- D12 08 _______________> 27
- D13 07 _______________> 28
- D14 50 _______________> 29
- D15 51 _______________> 30
*********************************
Control Signals.
- RD  52 _______________> 05
- WR  56 _______________> 06
- CS  11 _______________> 07
- RS  13 _______________> 08
- RST 12 _______________> 11
*********************************
Power and Grounds
- BL  3.3V (BACKLITE) ____> 14
- TFT 5V ________________> 3,4,37,38
- GND    ________________> 1,2,13,31,39,40



### Teensy 4.1 <________> RA8876

      PIN                     PIN
*********************************
Use These 8 data lines for 8-bit data bus.
- D0  19 _______________> 15
- D1  18 _______________> 16
- D2  14 _______________> 17
- D3  15 _______________> 18
- D4  40 _______________> 19
- D5  41 _______________> 20
- D6  17 _______________> 21
- D7  16 _______________> 22
*********************************
Add The 8 data lines fores6-bit data bus.
- D8  22 _______________> 23 
- D9  23 _______________> 24
- D10 20 _______________> 25
- D11 21 _______________> 26
- D12 38 _______________> 27
- D13 39 _______________> 28
- D14 26 _______________> 29
- D15 27 _______________> 30
*********************************
Control Signals.
- RD  37 _______________> 05
- WR  36 _______________> 06
- CS  11 _______________> 07
- RS  13 _______________> 08
- RST 12 _______________> 11
- BL  3.3V (BACKLITE) ____> 14 or  I/O pin.
*********************************
Power and Grounds
- TFT 5V ________________> 3,4,37,38
- GND    ________________> 1,2,13,31,39,40

NOTE: All power and ground pins should be connected.
*********************************
### MINIMAL SKETCH EXAMPLE

```
// sketch.ino

#include "Arduino.h"
#include "RA8876_Config_8080.h" // Global config file.
#include <RA8876_t41_p.h>

// RA8876_8080_DC, RA8876_8080_CS and RA8876_8080_RESET are defined in
// src/RA8876_Config_8080.h.
RA8876_t41_p tft = RA8876_t41_p(RA8876_8080_DC,RA8876_8080_CS,RA8876_8080_RESET);

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 3000) {} //wait for Serial Monitor (3 seconds).

  // Set 8/16bit bus mode. Default is 8bit bus mode.
  tft.setBusWidth(RA8876_8080_BUS_WIDTH); // RA8876_8080_BUS_WIDTH is defined in
                                          // src/RA8876_Config_8080.h. 
  tft.begin(BUS_SPEED); // RA8876_8080_BUS_WIDTH is defined in
                        // src/RA8876_Config_8080.h. Default is 20MHz. 
  ... // Rest of user setup code.
}


void loop() {
 ... // Users loop code.
}

```



## NOTES:

- ###  setBusWidth() if used must be called before begin().

- ### The T4.1 uses FlexIO2 which does not support DMA. Non-blocking async mode is     supported.


# This is WIP.   USE AT YOUR OWN RISK.  There are no guarantees when using this library. More to come.
