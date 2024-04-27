/*
 * Register.h
 *
 * Created: 18/09/2023 3:32:34 PM
 *  Author: MAI
 */ 

#ifndef REGISTER_H_
#define REGISTER_H_
#include "types.h"

//PORT A
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA  *((volatile uint8_t*)0x3A)
#define PINA  *((volatile uint8_t*)0x39)

//PORT B
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB  *((volatile uint8_t*)0x37)
#define PINB  *((volatile uint8_t*)0x36)

//PORT C
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC  *((volatile uint8_t*)0x34)
#define PINC  *((volatile uint8_t*)0x33)

//PORT D
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD  *((volatile uint8_t*)0x31)
#define PIND  *((volatile uint8_t*)0x30)

// Registers EX Interrupt
#define SREG   *((volatile uint8_t*)0x5F)
#define MCUCSR *((volatile uint8_t*)0x54)
#define MCUCR  *((volatile uint8_t*)0x55)
#define GICR   *((volatile uint8_t*)0x5B)
#define GIFR   *((volatile uint8_t*)0x5A)

// Registers of timer0 
#define TIMSK      *((volatile uint8_t*)0x59) //timer interrupt mask

#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1

#define TIFR       *((volatile uint8_t*)0x58) //timer interrupt flag register

#define TIFR_TOV0		0
#define TIFR_OCF0		1

#define TCCR0      *((volatile uint8_t*)0x53) //timer control register

#define TCCR0_FOC0      7
#define TCCR0_WGM00		6
#define TCCR0_COM01		5
#define TCCR0_COM00		4
#define TCCR0_WGM01		3
#define TCCR0_CS02      2
#define TCCR0_CS01		1
#define TCCR0_CS00		0

#define TCNT0      *((volatile uint8_t*)0x52) //timer/counter register
#define OCR0       *((volatile uint8_t*)0x5C) //output compare register

// Registers for ADC

#define ADMUX      *((volatile uint8_t*)0x27)
#define MUX0       0
#define MUX1       1
#define MUX2       2
#define MUX3       3
#define MUX4       4
#define ADLAR      5
#define REFS0      6
#define REFS1      7

#define ADCSRA     *((volatile uint8_t*)0x26) 
#define ADPS0      0
#define ADPS1      1
#define ADPS2      2
#define ADIE       3
#define ADIF       4
#define ADATE      5
#define ADSC       6
#define ADEN       7  

#define ADCH       *((volatile uint8_t*)0x25)
#define ADCL       *((volatile uint8_t*)0x24)
#define SFIOR      *((volatile uint8_t*)0x50)





#endif /* REGISTER_H_ */