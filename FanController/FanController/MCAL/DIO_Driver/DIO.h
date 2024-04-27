/*
 * DIO.h
 *
 * Created: 18/09/2023 3:34:15 PM
 *  Author: MAI
 */ 


#ifndef DIO_H_
#define DIO_H_
// Section :INCLUDES
#include "../../Utilities/Register.h"
#include "DIO_CFG.h"

// Section :Macro Declarations
#define BIT_MASK      (uint8_t)0X01
#define pin_max       7

#define DIO_PIN_CFG    CFG_ENABLE
#define DIO_PORT_CFG   CFG_ENABLE

#define A    PORTA
#define B    PORTB
#define C    PORTC
#define D    PORTD

//Section :Macro Functions Declarations
#define SET_func(REG,BIT_NUM)        (REG |=(BIT_MASK <<  BIT_NUM))
#define CLEAR_func(REG,BIT_NUM)      (REG &= ~(BIT_MASK <<  BIT_NUM))
#define TOGGLE_func(REG,BIT_NUM)     (REG ^=(BIT_MASK <<  BIT_NUM))
#define READ_func(REG,BIT_NUM)       ((REG >> BIT_NUM)& BIT_MASK)

//Section :Data type Declarations
typedef enum{
	E_NOT_OK,
	E_OK
	}std_ReturnType_t;
typedef enum{
	DIO_INPUT,
	DIO_OUTPUT
	}direction_t;
typedef enum{
	DIO_LOW,
	DIO_HIGH
	}logic_t;
typedef enum{
	DIO_PIN0=0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
	}pin_t;

//Section : Functions Declarations
#if DIO_PIN_CFG
std_ReturnType_t DIO_DIRECTION_INIT(uint8_t pinNum,uint8_t port,direction_t direc);
std_ReturnType_t DIO_WRITE(uint8_t pinNum,uint8_t port,logic_t logic);
std_ReturnType_t DIO_READ(uint8_t pinNum,uint8_t port,logic_t*state);
std_ReturnType_t DIO_TOGGLE(uint8_t pinNum,uint8_t port);
#endif

#endif /* DIO_H_ */