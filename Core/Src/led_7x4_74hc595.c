#include "led_7x4_74hc595.h"

void set_cathode_high(void){
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);

}

void change_number(struct led_display *settings, short number_to_display){
	if(number_to_display < 0 || number_to_display > 9999)
		for (int i =0; i < 4; ++i)
			settings->digits[i] = 0;
	else
	{
		settings->digits[0] = number_to_display / 1000;
		settings->digits[1] = number_to_display % 1000 / 100;
		settings->digits[2] = number_to_display % 100 / 10;
		settings->digits[3] = number_to_display % 10;
	}
}


void display_number(struct led_display *settings){
	set_cathode_high();                                   	//clear led display
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);	//put the shift register to read
	shift_out_led_display(settings, LSBFIRST, numbers[settings->digits[settings->curret_digit_to_display]]); 	//send the data
    switch(settings->curret_digit_to_display){	//turn on the relevent digit
    	case 0 : 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET); break;
    	case 1 : 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET); break;
    	case 2 : 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET); break;
    	case 3 : 	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET); break;
    	default:
    		break;
    }
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	settings->curret_digit_to_display++;						//count up the digit
    if (settings->curret_digit_to_display > 3)
    	settings->curret_digit_to_display = 0;
}

void shift_out_led_display(struct led_display *settings, uint8_t bitOrder, uint8_t val)
{

	for (uint8_t i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST)
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, !!(val & (1 << i)));
		else
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, !!(val & (1 << (7 - i))));
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	}
}

struct led_display setup_led_display(void){
	struct led_display temp = {0, {0,0,0,0}};
	return temp;
}
