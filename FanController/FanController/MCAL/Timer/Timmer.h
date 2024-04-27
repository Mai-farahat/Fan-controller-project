/*
 * Timmer.h
 *
 * Created: 19/10/2023 2:00:05 PM
 *  Author: MAI
 */ 


#ifndef TIMMER_H_
#define TIMMER_H_

/*******************************************
			 Section :INCLUDES			
*******************************************/

#include "../../Utilities/Atmega32_Config.h"


/**********************************************************************
			 Section :User Type Definition(Structures)				
**********************************************************************/

typedef struct  
{
	/*		Timer_Mode		
	*Timer Mode (Normal , CTC , Fast PWM , Phase Correct PWM)
	* this parameter must be set base on @ref Timer_Mode_Define
	*/
	uint8_t Timer_Mode;
	
	/*		Timer_clock_source		
	*Timer clock source (PreScaler with Internal clock/ External)
	* this parameter must be set base on @ref Timer_clock_source_Define
	*/
	uint8_t Timer_clock_source;
	
	/*		IRQ_Enable		
	*Enable or Disable IRQ
	* this parameter must be set base on @ref IRQ_Enable_Define
	*/
	uint8_t IRQ_Enable;
	
	/*		(*P_IRQ_CallBack)(void)
	*Set the C Function which will be called once IRQ Happens
	*/
	void (*P_IRQ_CallBack)(void);
	
}TIMER0_Config_t;

/******************************************************************
				Section :Macro Configuration References			
******************************************************************/

//				@ref Timer_Mode_Define

#define    Timer_Mode_Normal									(uint8_t)(0b10000<<WGM01)
#define    Timer_Mode_CTC										(uint8_t)(0b10001<<WGM01)
#define    Timer_Mode_FastPWM_noninterval						(uint8_t)(0b01101<<WGM01)
#define    Timer_Mode_FastPWM_interval							(uint8_t)(0b01111<<WGM01)
#define    Timer_Mode_PhaseCorrectPWM_noninterval				(uint8_t)(0b01100<<WGM01)
#define    Timer_Mode_PhaseCorrectPWM_interval					(uint8_t)(0b01110<<WGM01)

//				@ref Timer_clock_source_Define

#define    Timer_clock_source_NO_CLOCK							(uint8_t)(0b000<<CS00)
#define    Timer_clock_source_NO_PRESCALER_FACTOR 				(uint8_t)(0b001<<CS00)
#define    Timer_clock_source_DIVISION_FACTOR_8					(uint8_t)(0b010<<CS00)
#define    Timer_clock_source_DIVISION_FACTOR_64				(uint8_t)(0b011<<CS00)
#define    Timer_clock_source_DIVISION_FACTOR_256				(uint8_t)(0b100<<CS00)
#define    Timer_clock_source_DIVISION_FACTOR_1024				(uint8_t)(0b101<<CS00)
#define    Timer_clock_source_EXTERNAL_CLOCK_SOURCE_FALLING		(uint8_t)(0b110<<CS00)
#define    Timer_clock_source_EXTERNAL_CLOCK_SOURCE_RISING		(uint8_t)(0b111<<CS00)

//				@ref IRQ_Enable_Define

#define		IRQ_Enable_NON										((uint8_t)(0))
#define		IRQ_Enable_OCIE0									((uint8_t)(1<<OCIE0))
#define		IRQ_Enable_TOIE0									((uint8_t)(1<<TOIE0))

/**************************************************************************
				Section :APIs Supported by MCAL Timer0 Driver			
**************************************************************************/


void Timer0_Init(TIMER0_Config_t* timer0_cfg);
void Timer0_Deinit(void);
void Timer0_GetCounterValue(uint8_t* TicksNum);
void Timer0_SetCompareValue(uint8_t  TicksNum);
void Timer0_PWM_DutyCycle(uint8_t DutyCycle);

#endif TIMMER_H_ 