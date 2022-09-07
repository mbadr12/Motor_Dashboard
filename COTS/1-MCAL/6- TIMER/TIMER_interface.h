/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#ifndef COTS_1_MCAL_6__TIMER_TIMER_INTERFACE_H_
#define COTS_1_MCAL_6__TIMER_TIMER_INTERFACE_H_

void TIMER0_voidInit(void);

void TIMER1_voidInit(void);

void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value);

void TIMER1_voidSetICR1Value(u16 Copy_u16Value);

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value);

u8 TIMER0_u8SetCallBack(void (* Copy_pvCallBackFunc) (void));

#endif /* COTS_1_MCAL_6__TIMER_TIMER_INTERFACE_H_ */
