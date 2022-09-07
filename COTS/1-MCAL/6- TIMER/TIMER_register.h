/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  MCAL			    *************************/
/*************************		SWC: 	TIMER 				*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/

#ifndef COTS_1_MCAL_6__TIMER_TIMER_REGISTER_H_
#define COTS_1_MCAL_6__TIMER_TIMER_REGISTER_H_

/*TIMER0 Registers*/
#define TCCR0 *((volatile u8*) 0x53) /*TIMER0 control Register*/
#define TCCR0_WGM00 6				 /*Waveform Generation bit0*/
#define TCCR0_WGM01 3				 /*Waveform Generation bit1*/
#define TCCR0_CS02  2				 /*Pre-Scaler bit2*/
#define TCCR0_CS01  1				 /*Pre-Scaler bit1*/
#define TCCR0_CS00  0				 /*Pre-Scaler bit0*/
#define OCR0  *((volatile u8*) 0x5c) /*OutPut Compare Register 0*/

#define TIMSK *((volatile u8*) 0x59) /*Timer Mask*/
#define TIMSK_OCIE0 1				 /*Out Compare 0 interrupt Enable*/
/*TIMER1 Registers*/
#define TCCR1A *((volatile u8*) 0x4f) /*TIMER1 Control Register A*/
#define TCCR1A_COM1A1	7
#define TCCR1A_COM1A0	6
#define TCCR1A_COM1B1	5
#define TCCR1A_COM1B0	4
#define TCCR1A_WGM11	1
#define TCCR1A_WGM10	0

#define TCCR1B *((volatile u8*) 0x4e) /*TIMER1 Control Register B*/
#define TCCR1B_WGM13	4
#define TCCR1B_WGM12	3
#define TCCR1B_CS12		2
#define TCCR1B_CS11		1
#define TCCR1B_CS10		0

#define TCNT1 *((volatile u16*) 0x4c)
#define OCR1A *((volatile u16*) 0x4a)
#define ICR1  *((volatile u16*) 0x46)




#endif /* COTS_1_MCAL_6__TIMER_TIMER_REGISTER_H_ */
