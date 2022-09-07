/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	EXTI				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define GICR			*((volatile u8*) 0x5b)
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5
	
#define GIFR			*((volatile u8*) 0x5a)

#define MCUCR			*((volatile u8*) 0x55)
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

#define MCUCSR 			*((volatile u8*) 0x54)
#define MCUCSR_ISC2	 	6

#endif