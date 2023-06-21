/*
 * main.c
 *
 *  Created on: Jun 21, 2023
 *      Author: Khaled
 */

#include "lcd_interfacing.h"
#include "adc_interfacing.h"
#include "led_interface.h"
void main()
{

	leds_configuration();
	lcd_intilization();
	adc_init();
	send_command(LCD_CLEAR);
	lcd_display('k');

	while(1)
{


		u16 adc_read1=adc_convert(channel0);

			send_command(LCD_CLEAR);
			go_to_xy(row1, column2);

			Lcd_DisplayNum(adc_read1);
			if(adc_read1>120)
			{

				led_on(led1);

			}
			else
			{
				led_off(led1);
			}

	u16 adc_read2=adc_convert(channel2);

	send_command(LCD_CLEAR);
	go_to_xy(row2, column2);

	Lcd_DisplayNum(adc_read2);
	if(adc_read2>120)
	{

		led_on(led2);

	}
	else
	{
		led_off(led2);
	}



}

}
