/*
 * LCD.c
 *
 * Created: 07/02/2024 12:42:09 AM
 *  Author: MAI
 */ 
// Section :INCLUDES
#include "LCD.h"

/*
 * @FN			:LCD_8_bit_init
 * @brief		:initialization  LCD_8_bit_mode 
 * @param(in)	:none
 * @retval		:none
 * @Note		:none
 */
void LCD_8_bit_init(void)
{
	LCD_Command_Dir = 0XFF; //Make LCD command port direction as o/p
	LCD_Data_Dir = 0XFF;    //Make LCD data port direction as o/p
	
	_delay_ms(20);
	LCD_8_bit_sendCommand(LCD_8BIT_MODE_2LINES);
	LCD_8_bit_sendCommand(LCD_DISP_ON_Cursor_OFF);
	LCD_8_bit_sendCommand(LCD_INC_CURSOR);
	LCD_8_bit_sendCommand(LCD_CLEAR_SCREEN);	
}
/*
 * @FN			:LCD_8_bit_sendCommand
 * @brief		:send the command value to the data port 
 * @param(in)	:cmnd
 * @retval		:none
 * @Note		:make RS pin low(command) , make RW pin low(write) , Generate high to low pulse (E)pin
 */
void LCD_8_bit_sendCommand(uint8_t cmnd)
{
	LCD_Data_Port = cmnd;
	CLEAR_func(LCD_Command_Port, RS);
	CLEAR_func(LCD_Command_Port,RW);
	SET_func(LCD_Command_Port, E);
	_delay_us(1);
	CLEAR_func(LCD_Command_Port,E);
	_delay_ms(3);	
}
/*
 * @FN			:LCD_8_bit_sendChar
 * @brief		:send character ASCII value to the data port
 * @param(in)	:char_data
 * @retval		:none
 * @Note		:make RS pin high(data register) , make RW pin low(write) , Generate high to low pulse (E)pin
 */
void LCD_8_bit_sendChar(uint8_t char_data)
{
	LCD_Data_Port = char_data;
	SET_func(LCD_Command_Port, RS);
	CLEAR_func(LCD_Command_Port, RW);
	SET_func(LCD_Command_Port, E);
	_delay_us(1);
	CLEAR_func(LCD_Command_Port, E);
	_delay_ms(1);
}
/*
 * @FN			:LCD_8_bit_sendString
 * @brief		:this function takes a string(array of char) and sends one char at a time to the LCD data
 function till the end of the string
 * @param(in)	:*str
 * @retval		:none
 * @Note		: for loop is used for sending  a char in each iteration , null char->end of the string
 */
void LCD_8_bit_sendString(uint8_t *str)
{
	uint16_t i;
	for(i=0; str[i]!=0; i++)
	{
		LCD_8_bit_sendChar(str[i]);
	}
}
void LCD_GotoXY(uint8_t line, uint8_t position )
{

	if(line==1)
	{
		if (position < 16 && position >=0)
		LCD_8_bit_sendCommand(LCD_BEGIN_AT_FIRST_LINE+position);
	}
	else if (line==2)
	{
		if (position < 16 && position >=0)
		LCD_8_bit_sendCommand(LCD_BEGIN_AT_SECOND_LINE+ position);
	}
}
void LCD_display_number (uint8_t Number )
{

	char  str[6];

	sprintf(str,"%d",Number);	// Adjust the formatting to your liking.

	LCD_8_bit_sendString (str) ;

}
/*
 * @FN			:LCD_4_bit_init
 * @brief		:initialization  LCD_4_bit_mode 
 * @param(in)	:none
 * @retval		:none
 * @Note		:none
 */
void LCD_4_bit_init(void)
{
	LCD_Dir = 0XFF;
	_delay_ms(20);
	
	LCD_4_bit_sendCommand(0X02); //send for 4 bit initialization of LCD
	LCD_4_bit_sendCommand(LCD_4BIT_MODE_2LINES);
	LCD_4_bit_sendCommand(LCD_DISP_ON_Cursor_OFF);
	LCD_4_bit_sendCommand(LCD_INC_CURSOR);
	LCD_4_bit_sendCommand(LCD_CLEAR_SCREEN);
}
/*
 * @FN			:LCD_4_bit_sendCommand
 * @brief		:send the HIGH nibble of command 
 * @param(in)	:cmnd
 * @retval		:none
 * @Note		:make RS pin low(command) , make RW pin low(write) , Generate high to low pulse (E)pin,
 send the lower nibble of command , Generate high to low pulse (E)pin
 */
void LCD_4_bit_sendCommand(uint8_t cmnd)
{
	LCD_Port = (LCD_Port & 0X0F) | (cmnd & 0xF0); // sending upper nibble
	CLEAR_func(LCD_Port, RS);
	CLEAR_func(LCD_Port, RW);
	SET_func(LCD_Port, E);
	_delay_us(1);
	CLEAR_func(LCD_Port, E);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0X0F) | (cmnd << 4); // sending lower nibble
	SET_func(LCD_Port, E);
	_delay_us(1);
	CLEAR_func(LCD_Port, E);
	_delay_ms(2);
}
/*
 * @FN			:LCD_4_bit_sendChar
 * @brief		:display character
 * @param(in)	:data
 * @retval		:none
 * @Note		:send the higher nibble of data,make RS pin high(data register) , make RW pin low(write) ,
  Generate high to low pulse (E)pin , send the lower nibble, Generate high to low pulse (E)pin 
 */
void LCD_4_bit_sendChar(uint8_t data)
{
	LCD_Port = (LCD_Port & 0X0F) | (data & 0xF0); // sending upper nibble
	SET_func(LCD_Port, RS);
	CLEAR_func(LCD_Port, RW);
	SET_func(LCD_Port, E);
	_delay_us(1);
	CLEAR_func(LCD_Port, E);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0X0F) | (data << 4); // sending lower nibble
	SET_func(LCD_Port, E);
	_delay_us(1);
	CLEAR_func(LCD_Port, E);
	_delay_ms(2);
}



