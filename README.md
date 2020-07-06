# STM32_HAL_74hc595
Simple led 4x7 panel controll using 74hc595 module.
Liblary contains few simply functions and structure to control this module.
Communication with 74hc595 is carried out by manual pin selection, simpler method is using SPI.

Pintouts:
Digit0 -> PC0
Digit1 -> PC1
Digit2 -> PC2
Digit3 -> PC3
Data -> PA1
Clk -> PA2
Latch -> PA3
