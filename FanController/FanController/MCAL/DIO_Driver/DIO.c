/*
 * DIO.c
 *
 * Created: 18/09/2023 3:33:58 PM
 *  Author: MAI
 */ 
#include "DIO.h"
#if DIO_PIN_CFG
std_ReturnType_t DIO_DIRECTION_INIT(uint8_t pinNum, uint8_t port,direction_t direc){
	if(pinNum>pin_max){return E_NOT_OK;}
	else{
		switch(port){
				case 'a':
				if(direc==DIO_INPUT){CLEAR_func(DDRA,pinNum);}
				else if(direc==DIO_OUTPUT){SET_func(DDRA,pinNum);}
				else{return E_NOT_OK;}
				break;
				case 'b':
				if(direc==DIO_INPUT){CLEAR_func(DDRB,pinNum);}
				else if(direc==DIO_OUTPUT){SET_func(DDRB,pinNum);}
				else{return E_NOT_OK;}
				break;
				case 'c':
				if(direc==DIO_INPUT){CLEAR_func(DDRC,pinNum);}
				else if(direc==DIO_OUTPUT){SET_func(DDRC,pinNum);}
				else{return E_NOT_OK;}
				break;
				case 'd':
				if(direc==DIO_INPUT){CLEAR_func(DDRD,pinNum);}
				else if(direc==DIO_OUTPUT){SET_func(DDRD,pinNum);}
				else{return E_NOT_OK;}
				break;
				}
	}
	return E_OK;
}
std_ReturnType_t DIO_WRITE(uint8_t pinNum, uint8_t port,logic_t logic){ 
	if (pinNum>pin_max){return E_NOT_OK;}
	else{
		switch(port){
			case 'a':
			if(logic ==DIO_LOW){CLEAR_func(PORTA,pinNum);}
			else if(logic ==DIO_HIGH){SET_func(PORTA,pinNum);}
			else{return E_NOT_OK;}
			break;
			case 'b':
			if(logic ==DIO_LOW){CLEAR_func(PORTB,pinNum);}
			else if(logic ==DIO_HIGH){SET_func(PORTB,pinNum);}
			else{return E_NOT_OK;}
			break;
			case 'c':
			if(logic ==DIO_LOW){CLEAR_func(PORTC,pinNum);}
			else if(logic ==DIO_HIGH){SET_func(PORTC,pinNum);}
			else{return E_NOT_OK;}
			break;
			case 'd':
			if(logic ==DIO_LOW){CLEAR_func(PORTD,pinNum);}
			else if(logic ==DIO_HIGH){SET_func(PORTD,pinNum);}
			else{return E_NOT_OK;}
			break;
			}
	}
	return E_OK;
}
std_ReturnType_t DIO_READ(uint8_t pinNum,uint8_t port,logic_t*state){
	if (pinNum>pin_max && *state ==NULL){return E_NOT_OK;}
    else{
		switch(port){
	     case 'a' :
		 *state=READ_func(PINA,pinNum);
		 break;
		 case 'b' :
		 *state=READ_func(PINB,pinNum);
		 break;
		 case 'c' :
		 *state=READ_func(PINC,pinNum);
		 break;
		 case 'd':
		 *state=READ_func(PIND,pinNum);
		 break;
	}
	}
	return E_OK;
	}
std_ReturnType_t DIO_TOGGLE(uint8_t pinNum,uint8_t port){
	if (pinNum>pin_max){return E_NOT_OK;}
	else{
		switch(port){
			case 'a':
			TOGGLE_func(PORTA,pinNum);
			break;
			case 'b':
			TOGGLE_func(PORTB,pinNum);
			break;
			case 'c':
			TOGGLE_func(PORTC,pinNum);
			break;
			case 'd':
			TOGGLE_func(PORTD,pinNum);
			break;
		}
	}
	return E_OK;
}
#endif