
﻿# Chip Interface (0.96 Inch OLED Module 12864 128x64SSD1306)


A bare metal C interface implementation for the Arduino and an OLED display.


## Usage


1. Start in the Makefile. If needed, change `AVRDUDE_MMCU` to the device that is being used. 
2. Change the `AVRDUDE_PORT` to the port that is being used.
3. In some cases, the bandwidth might need to change according to what chip is being used. This can be changed at `AVRDUDE_BAND`.


4. Now in the terminal, run `make` and the Makefile will compile the program. Next, run `make flash` to upload the code to the Arduino.


## Application


This code will use a button to tally up a score. The score increments by 100 each time the button is pressed.


The driver for this display is credited to Marian Hrinko.


## Youtube Video Link


https://youtube.com/shorts/Ieaa2U-VgN0?feature=share
