# TeensyRA8876-8080
## A RA8876 8080 parallel driver library for Teensy boards and variants.

This library is designed to be used with the TeensyRa8876-GFX-Common library and can be found here:
- https://github.com/wwatson4506/TeensyRA8876-GFX-Common

This driver also uses a new FlexIO library found here:
- https://github.com/KurtE/FlexIO_t4/tree/master

Communication with the Teensy is accomplished using the 8080 parallel mode of FlexIO. To install unzip the zip file in the Arduino/libraries folder.

![https://github.com/wwatson4506/TeensyRA8876-8080/blob/main/extras/MEM_Transfer.jpg](https://github.com/wwatson4506/TeensyRA8876-8080/blob/main/extras/MEM_Transfer.jpg)

# PINOUTS

### CONNECTING THE TEENSY TO THE ER-TFTM101-1 in FlexIO 8080 mode

40 pin dual inline connector pinouts can be found here.

https://www.buydisplay.com/download/interfacing/ER-TFTM101-1_CTP_Interfacing.pdf

## WIRED
### Dev Board 5                 RA8876

   PIN                                                         PIN
```
Use These 8 data lines for 8-bit data bus.
- D0  40 <-------------------> 15 
- D1  41 <-------------------> 16
- D2  42 <-------------------> 17 
- D3  43 <-------------------> 18 
- D4  44 <-------------------> 19
- D5  45 <-------------------> 20
- D6  06 <-------------------> 21
- D7  09 <-------------------> 22
*********************************
Add These 8 data lines for 16-bit data bus.
- D8  32 <-------------------> 23  
- D9  47 <-------------------> 24
- D10 48 <-------------------> 25 
- D11 49 <-------------------> 26 
- D12 08 <-------------------> 27
- D13 07 <-------------------> 28
- D14 50 <-------------------> 29
- D15 51 <-------------------> 30
*********************************
Control Signals.
- RD  52 --------------------> 05
- WR  56 --------------------> 06
- CS  11 --------------------> 07
- RS  13 --------------------> 08
- RST 12 --------------------> 11
*********************************
Power and Grounds
- BL  3.3V (BACKLITE) -------> 14
- TFT 5V --------------------> 3,4,37,38
- GND -----------------------> 1,2,13,31,39,40
```


### Teensy 4.1 <--------------> RA8876

   PIN                                                         PIN
```
Use These 8 data lines for 8-bit data bus.
- D0  19 --------------------> 15
- D1  18 --------------------> 16
- D2  14 --------------------> 17
- D3  15 --------------------> 18
- D4  40 --------------------> 19
- D5  41 --------------------> 20
- D6  17 --------------------> 21
- D7  16 --------------------> 22
*********************************
Add The 8 data lines fores6-bit data bus.
- D8  22 --------------------> 23 
- D9  23 --------------------> 24
- D10 20 --------------------> 25
- D11 21 --------------------> 26
- D12 38 --------------------> 27
- D13 39 --------------------> 28
- D14 26 --------------------> 29
- D15 27 --------------------> 30
*********************************
Control Signals.
- RD  37 --------------------> 05
- WR  36 --------------------> 06
- CS  11 --------------------> 07
- RS  13 --------------------> 08
- RST 12 --------------------> 11
- BL  3.3V (BACKLITE) -------> 14 or  I/O pin.
*********************************
Power and Grounds
- TFT 5V --------------------> 3,4,37,38
- GND -----------------------> 1,2,13,31,39,40
NOTE: All power and ground pins should be connected.
```
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

- ### There is still an issue with DMA being used with a buss speed greater than 12MHz.



## Examples Folder Listings:
Example sketches can be found in the TeensyRA8876-8080 and TeensyRA8876-SPI examples folders.

- gauges  ---------------------->  A Sumotoy example originally created for the RA8875.
- graphicCursor ------------->  A demonstration of defining and using a graphical mouse pointer. A USB mouse is required. Also demonstrates single and double mouse button clicks.
- graphics --------------------->  Demonstrates common graphics usage, lines, circles, rectangles and more.
- ILI_ADA_FontTest4 -------> Demonstrates usage of ILI9341 and Adafruit fonts on the RA8876.
- MemoryTransfer -------- -> Shows usage of many BTE (Block Transfer Engine) functions.
- pipTest ------------------------> Example of PIP (Picture In Picture) usage.
- RA8876_pictureEmbed --> Displays 16Bit color images. Also demonstrates rotation.
- RA8876Rotate --------------> Also demontrates use of rotation.
- scroll ---------------------------> Simple demonstration of scrolliing screen up and down.
- TestCases -----------------------------> Folder containing various sketches used for testing.
  - DMA_ASYNC_testing ---------> Tests usage of DMA and ASYNC together.
  - DMA_Testing_2 ----------------> More DMA tests using SDRAM on the Dev Board 5. Not compatible with  Teensy 4.0, 4.0 or MicroMod.
  - Kurts_RA8876_p_FB_and_clip_tests --> Frame buffer and clip tests.
  - RA8876p_readPixels ---------> Tests color bar write and read accuracy with rotation.
  - TestDMA -------------------------> Another DMA test for displaying images.
  - TestDMA_FB --------------------> More ASYNC and DMA testing using frame buffer callbacks.
  - writeRotatedRect_ra8876 --> Displays images and color bars with rotation.
- treedee -------------------------------> Demonstrates a spinning 3D wire cube.
- UserDefinedFonts ----------------> Demonstrates loading  user define fonts into pattern ram.   Fonts can also be loaded from an SD card or USB drive.



# This is WIP.   USE AT YOUR OWN RISK.  There are no guarantees when using this library. More to come.
