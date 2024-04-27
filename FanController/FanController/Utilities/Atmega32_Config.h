/*
 * Atmega32_Config.h
 *
 * Created: 07/11/2023 11:14:59 PM
 *  Author: MAI
 */ 


#ifndef ATMEGA32_CONFIG_H_
#define ATMEGA32_CONFIG_H_

/*    clock    */
#ifndef F_CFG
#define F_CFG  8000000UL
#endif
/*    CPU   */
#ifndef F_CPU
#define F_CPU 8000000UL
#endif 


/*		AVR header		*/
#include "Register.h"
#include "types.h"
#include "bitwise.h"
#include "avr/interrupt.h"
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/io.h>


#endif /* ATMEGA32_CONFIG_H_ */