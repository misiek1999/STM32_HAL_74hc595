// File to conrtoll LED 7x4 display using 74hc595
#ifndef LED_CONTROLL
#define LED_CONTROLL
	#include <stm32f1xx_hal.h>
	#define LSBFIRST 0
	#define MSBFIRST 1
	//array of decoded numbers
	static const uint8_t numbers[10] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110};

	struct led_display{
		uint8_t curret_digit_to_display ;
		uint8_t digits[4];
	};
	void set_cathode_high(void);
	void change_number(struct led_display *settings, short number_to_display);
	void shift_out_led_display(struct led_display *settings, uint8_t bitOrder, uint8_t val);
	void display_number(struct led_display *settings);
	struct led_display setup_led_display(void);
#endif
