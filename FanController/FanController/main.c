/*
 * FanController.c
 *
 * Created: 12/02/2024 9:35:29 PM
 * Author : MAI
 */ 

#include <avr/io.h>
#include "ECUAL/LCD/LCD.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/Timer/Timmer.h"


int main(void)
{
	//INIT Timer
	TIMER0_Config_t timercfg;
	timercfg.Timer_Mode = Timer_Mode_FastPWM_noninterval;
	timercfg.Timer_clock_source = Timer_clock_source_DIVISION_FACTOR_8;
	timercfg.IRQ_Enable = IRQ_Enable_NON;
	Timer0_Init(&timercfg);
	
	//INIT ADC
	ADC_Config_t ADCcfg;
	ADCcfg.ADC_Mode = ADC_Mode_single_conversion;
	ADCcfg.ADC_Prescaler = ADC_Prescaler_2;
	ADCcfg.ADC_Result_Presentation = ADC_Result_Presentation_Right;
	ADCcfg.ADC_Voltage_Reference = ADC_Voltage_Reference_AVCC;
	ADCcfg.ADC_IRQ = ADC_IRQ_Disable;
	ADC_INIT(&ADCcfg);
	
	//INIT LCD
	LCD_8_bit_init();
	
	
	//INIT motor
	DIO_DIRECTION_INIT(DIO_PIN0,PORTB,DIO_OUTPUT);
	DIO_DIRECTION_INIT(DIO_PIN1,PORTB,DIO_OUTPUT);
	
	DIO_WRITE(DIO_PIN0,PORTB,DIO_HIGH);
	DIO_WRITE(DIO_PIN1,PORTB,DIO_LOW);
	
	
	LCD_8_bit_sendString("Temp: ");
	LCD_GotoXY(2,0);
	LCD_8_bit_sendString("Fan Speed: ");
	
	uint32_t ADCresult=0;
	uint8_t temp=0;
	uint8_t speed=0;
    /* Replace with your application code */
    while (1) 
    {
		LCD_GotoXY(1,6);
		ADC_Read_Channel(ADC0, &ADCresult, polling_enable);
		temp = (((ADCresult * 5000) / 1024) / 10);
		LCD_display_number(temp);
		LCD_8_bit_sendChar('C');
		
		if(temp < 25)
		{
			speed =0;
		}
		else if(temp>=25 && temp <35)
		{
			speed = 25;
		}
		else if(temp>=35 && temp <45)
		{
			speed = 50;
		}
		else if(temp>=45 && temp <55)
		{
			speed = 75;
		}
		else if(temp>=55 && temp <65)
		{
			speed = 98;
		}
		Timer0_PWM_DutyCycle(speed);
		
    }
}

