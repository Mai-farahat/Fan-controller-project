/*
 * Timmer.c
 *
 * Created: 19/10/2023 1:59:32 PM
 *  Author: MAI
 */ 
/*******************************************
			 Section :INCLUDES			
*******************************************/
#include "Timmer.h"

/**************************************************
			 Section :Global Variables			
**************************************************/
TIMER0_Config_t G_timer_cfg;
void (*GP_IRQ_CallBack)(void);
uint8_t numOfOverFlow = 0;


/**************************************************************************
				Section :APIs Supported by MCAL Timer0 Driver			
**************************************************************************/


/*
 * @FN			:Timer0_Init
 * @brief		:initialization timer 
 * @param(in)	:timer0_cfg-> a pointer to TIMER0_Config_t struchure that contains the configration information for timer
 * @retval		:none
 * @Note		:none
 */

void Timer0_Init(TIMER0_Config_t* timer0_cfg){
	G_timer_cfg = *timer0_cfg;
	
	//1: which mode
	TCCR0 |= timer0_cfg->Timer_Mode;
	if(timer0_cfg->Timer_Mode==Timer_Mode_FastPWM_noninterval ||timer0_cfg->Timer_Mode==Timer_Mode_FastPWM_interval){
		SET_func(DDRB , 3);
	}
	
	// 2: PreScaler 
	TCCR0 |= timer0_cfg->Timer_clock_source;
	if(timer0_cfg->Timer_clock_source==Timer_clock_source_EXTERNAL_CLOCK_SOURCE_FALLING ||
	 timer0_cfg->Timer_clock_source==Timer_clock_source_EXTERNAL_CLOCK_SOURCE_RISING)
	 {
		 /* CONFIGURE T0 (PB0) as Input*/
		 CLEAR_func(DDRB , 0);
	 }
	 
	 // 3: IRQ Enable
	 TIMSK |= timer0_cfg->IRQ_Enable;
	 if(timer0_cfg->IRQ_Enable |= IRQ_Enable_NON)
	 {
		   sei();
	 }
	
	GP_IRQ_CallBack = timer0_cfg->P_IRQ_CallBack;
	
	
	 
}
ISR(TIMER0_OVF_vect)
{
	GP_IRQ_CallBack();
}
ISR(TIMER0_COMP_vect)
{
	GP_IRQ_CallBack();
}
/*
 * @FN			:Timer0_Deinit
 * @brief		:Deinitialization timer 
 * @retval		:none
 * @Note		:none
 */
void Timer0_Deinit(void){
	TCCR0 &= ~((1<<CS00) | (1<<CS01) | (1<<CS02));
}
/*
 * @FN			:Timer0_GetCounterValue
 * @brief		:Get counter value 
 * @param(in)	:TicksNum: value to set in OCR(compare value must not exceed 255.
 * @retval		:none
 * @Note		:none
 */

void Timer0_GetCounterValue(uint8_t* TicksNum){
	*TicksNum = TCNT0;
}
/*
 * @FN			:Timer0_SetCompareValue
 * @brief		:Set compare value 
 * @param(in)	:TicksNum: value to set in OCR(compare value must not exceed 255.
 * @retval		:none
 * @Note		:none
 */
void Timer0_SetCompareValue(uint8_t  TicksNum){
	OCR0 = TicksNum;
}
/*
 * @FN			:Timer0_PWM_DutyCycle
 * @brief		:PWM DutyCycle
 * @param(in)	:DutyCycle .
 * @retval		:none
 * @Note		:none
 */
void Timer0_PWM_DutyCycle(uint8_t DutyCycle){
	if(G_timer_cfg.Timer_Mode == Timer_Mode_FastPWM_noninterval){
		OCR0 = (0xFF*DutyCycle)/100;
	}
	else if(G_timer_cfg.Timer_Mode == Timer_Mode_FastPWM_interval){
		OCR0 = (255-DutyCycle);
	}
}