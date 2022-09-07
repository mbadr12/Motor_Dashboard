/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_config.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_register.h"

static void (*TIMER0_pvCallBackFunc) (void)=NULL;

void TIMER0_voidInit(void)
{
	/*choose CTC Mode*/
	SET_BIT(TCCR0,TCCR0_WGM01);
	CLR_BIT(TCCR0,TCCR0_WGM00);
	/*Output Compare Match Interrupt Enable*/
	SET_BIT(TIMSK,TIMSK_OCIE0);
	/*Set Compare Match Value to 125*/
	OCR0=125;
	/*Clear on Compare Match ,Set on top*/
	//SET_BIT(TCCR0,5);
	//CLR_BIT(TCCR0,4);
	/*Prescaler: Division By 8*/
	SET_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);
}

void TIMER1_voidInit(void)
{
	/*Choose Fast PWM Mode*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	/*Compare Output Mode*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	/*Prescaler*/
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	CLR_BIT(TCCR1B,TCCR1B_CS12);
}

void TIMER1_voidSetChannelACompMatchValue(u16 Copy_u16Value)
{
	OCR1A=Copy_u16Value;
}

void TIMER1_voidSetICR1Value(u16 Copy_u16Value)
{
	ICR1=Copy_u16Value;
}

void TIMER0_voidSetCompMatchValue(u8 Copy_u8Value)
{
	OCR0 = Copy_u8Value;
}
u8 TIMER0_u8SetCallBack(void (* Copy_pvCallBackFunc) (void))
{
	u8 Local_u8ErrorStatus=OK;
	if(Copy_pvCallBackFunc!=NULL)
	{
		/*pass The pointer to local function to global pointer to function to be called in ISR*/
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
