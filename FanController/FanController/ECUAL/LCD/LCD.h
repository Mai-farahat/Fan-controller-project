/*
 * LCD.h
 *
 * Created: 07/02/2024 12:42:26 AM
 *  Author: MAI
 */ 


#ifndef LCD_H_
#define LCD_H_
// Section :INCLUDES
#include "./../../Utilities/Atmega32_Config.h"
// Section :Macro Declarations
// for 8_bit_mode
#define LCD_Command_Dir DDRD
#define LCD_Command_Port PORTD
#define LCD_Data_Dir DDRC
#define LCD_Data_Port PORTC
 
//for 4_bit_mode
#define LCD_Dir  DDRA
#define LCD_Port PORTA

#define RS  2
#define RW  1
#define E   0

#define LCD_CLEAR_SCREEN							                0x01
#define LCD_DISP_ON_Cursor_OFF   								    0x0C
#define LCD_DISP_ON_CURSOR_Cursor_Blinking   						0x0E
#define LCD_BEGIN_AT_FIRST_LINE						                0x80
#define LCD_BEGIN_AT_SECOND_LINE					                0xC0
#define LCD_MOVE_CURSOR_RIGHT   					                0x14
#define LCD_MOVE_CURSOR_LEFT 	  					                0x10
#define LCD_MOVE_DISP_RIGHT       					                0x1C
#define LCD_MOVE_DISP_LEFT   						                0x18
#define LCD_8BIT_MODE_2LINES   					                    0x38
#define LCD_4BIT_MODE_2LINES   					                    0x28
#define LCD_8BIT_MODE_1LINE   					                    0x30
#define LCD_4BIT_MODE_1LINE   					                    0x20
#define LCD_INC_CURSOR   							                0x06




//Section : Functions Declarations
void LCD_8_bit_init(void);
void LCD_8_bit_sendCommand(uint8_t cmnd);
void LCD_8_bit_sendChar(uint8_t char_data);
void LCD_8_bit_sendString(uint8_t *str);
void LCD_GotoXY(uint8_t line, uint8_t position );
void LCD_display_number (uint8_t Number );

void LCD_4_bit_init(void);
void LCD_4_bit_sendCommand(uint8_t cmnd);
void LCD_4_bit_sendChar(uint8_t data);


#endif /* LCD_H_ */