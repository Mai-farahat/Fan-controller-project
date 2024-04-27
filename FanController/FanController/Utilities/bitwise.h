/*
 * bitwise.h
 *
 * Created: 07/11/2023 11:30:51 PM
 *  Author: MAI
 */ 


#ifndef BITWISE_H_
#define BITWISE_H_

#define BIT_MASK      (uint8_t)0X01

#define SET_func(REG,BIT_NUM)        (REG |=(BIT_MASK << BIT_NUM))
#define CLEAR_func(REG,BIT_NUM)      (REG &= ~(BIT_MASK << BIT_NUM))
#define TOGGLE_func(REG,BIT_NUM)     (REG ^=(BIT_MASK << BIT_NUM))
#define READ_func(REG,BIT_NUM)       ((REG >> BIT_NUM)& BIT_MASK)



#endif /* BITWISE_H_ */