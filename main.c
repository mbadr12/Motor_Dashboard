/************************************************************************************/
/************************************************************************************/
/*************************		Author: Mahmoud Badr		*************************/
/*************************		Layer:  APP				    *************************/
/*************************		Project: Motor Dash Board	*************************/
/*************************		Version:1.00				*************************/
/************************************************************************************/
/************************************************************************************/
#include "COTS/4-LIB/STD_TYPES.h"
#include <util/delay.h>

#include "COTS/1-MCAL/1-DIO/DIO_interface.h"
#include "COTS/1-MCAL/2-PORT/PORT_interface.h"
#include "COTS/1-MCAL/4-GIE/GIE_interface.h"
#include "COTS/1-MCAL/5-ADC/ADC_interface.h"
#include "COTS/1-MCAL/6- TIMER/TIMER_interface.h"
#include "COTS/2-HAL/6-MOTORS/MOTORS_interface.h"
#include "COTS/2-HAL/4-CLCD/CLCD_interface.h"
#include "COTS/2-HAL/5-KEYPAD/KEYPAD_interface.h"
/*Function To Get Password From User*/
u16 App_u16InvertNumber(u16 Copy_u8Number);
Map LM35Reading={0,255,0,10};
Map PotenReading={0,255,0,10};
Map Angle={0,180,600,2600};
static s16 APP_PotenMappedValue=0;
static s16 APP_LM35MappedValue=0;
static u8 APP_u8Direction=0;
DC_MOTOR DC={DIO_u8PORTA,DIO_u8PIN6,DIO_u8PIN7};
void APP_DCSpeed(void);
void APP_DCSpeed(void);
int main(void)
{
	STEPPER_MOTOR MOTOR1={DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN1,DIO_u8PIN2,DIO_u8PIN3};
	s8 Local_ps8Buffer[10];
	u16 Local_u16Angle=0;
	u16 Local_u16MappedAngle=0;
	u16 Local_ADCReading=0;
	u8 Local_u8Counter=0;
	u8 Local_u8TrailesCounter=0;
	u8 Local_u8PressedKey=0;
	u16 Local_u16UserName=0;
	u16 Local_u16EnteredPassword=0;
	u16 Local_u16CorrectPassword=0;
	/*Initialization of Port direction*/
	PORT_voidInit();
	CLCD_void_Init();
	GIE_voidEnable();
	ADC_voidInit();
	TIMER0_voidInit();
	TIMER1_voidInit();
	CLCD_voidSendString("Welcome");
	_delay_ms(3000);
	CLCD_voidCLR();
	CLCD_voidSendString("Enter ID: ");
	while(1)
	{
		/*Loop to take the user ID from Keypad*/
		for(u8 Local_u8Counter=0;Local_u8Counter<4;Local_u8Counter++)
		{
			Local_u8PressedKey=KPD_u8GetPressedKey();
			CLCD_voidSendData(Local_u8PressedKey);
			/*make the ID as a Number*/
			switch(Local_u8Counter)
			{
			case 0: Local_u16UserName=(Local_u8PressedKey-'0')*1000; break;
			case 1: Local_u16UserName+=(Local_u8PressedKey-'0')*100; break;
			case 2: Local_u16UserName+=(Local_u8PressedKey-'0')*10; break;
			case 3: Local_u16UserName+=(Local_u8PressedKey-'0'); break;
			}
		}
		_delay_ms(250);
		CLCD_voidCLR();
		CLCD_voidSendString("Password: ");
		/*Loop to take the user Password from Keypad*/
		for(Local_u8TrailesCounter=0;Local_u8TrailesCounter<3;Local_u8TrailesCounter++)
		{
			for(Local_u8Counter=0;Local_u8Counter<4;Local_u8Counter++)
			{
				Local_u8PressedKey=KPD_u8GetPressedKey();
				CLCD_voidSendData(Local_u8PressedKey);
				switch(Local_u8Counter)
				{
				case 0: Local_u16EnteredPassword=(Local_u8PressedKey-'0')*1000; break;
				case 1: Local_u16EnteredPassword+=(Local_u8PressedKey-'0')*100; break;
				case 2: Local_u16EnteredPassword+=(Local_u8PressedKey-'0')*10; break;
				case 3: Local_u16EnteredPassword+=(Local_u8PressedKey-'0'); break;
				}
			}
			/*The Password is the ID inverted*/
			Local_u16CorrectPassword=App_u16InvertNumber(Local_u16UserName);
			if(Local_u16EnteredPassword==Local_u16CorrectPassword)
			{
				_delay_ms(250);
				CLCD_voidCLR();
				CLCD_voidSendString("welcome to Motor");
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendString("Dash Board ");
				CLCD_void_SendNumber(Local_ps8Buffer,Local_u16UserName);
				_delay_ms(1000);
				break;
			}
			else
			{
				_delay_ms(250);
				CLCD_voidCLR();
				CLCD_voidSendString("Try Again: ");
			}
		}
		/*If the password entered 3 times wrong close the system*/
		if(Local_u8TrailesCounter==3)
		{
			_delay_ms(250);
			CLCD_voidCLR();
			CLCD_voidSendString("ByeBye");
		}
		else
		{
			while(1)
			{
				CLCD_voidCLR();
				CLCD_voidSendString("Choose One Motor");
				_delay_ms(500);
				CLCD_voidCLR();
				CLCD_voidSendString("1-DC   2-Stepper");
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendString("3-Servo");
				Local_u8PressedKey=KPD_u8GetPressedKey();
				switch(Local_u8PressedKey)
				{
				case'1': CLCD_voidCLR();
				CLCD_voidSendString("1-CW   2-CCW");
				APP_u8Direction=KPD_u8GetPressedKey();
				if(APP_u8Direction=='1' || APP_u8Direction=='2')
				{
					CLCD_voidCLR();
					CLCD_voidSendString("Speed Control");
					_delay_ms(500);
					CLCD_voidCLR();
					CLCD_voidSendString("1-FSpeed  2-LM35");
					CLCD_voidGoToXY(1,0);
					CLCD_voidSendString("3-Potentiometer");
					Local_u8PressedKey=KPD_u8GetPressedKey();
					CLCD_voidCLR();
					CLCD_voidSendString("DC is Running");
					CLCD_voidGoToXY(1,0);
					switch(Local_u8PressedKey)
					{
					case '1': CLCD_voidSendString("Full Speed");
					switch(APP_u8Direction)
					{
					case '1': DC_u8Rotate(&DC,CW); break;
					case '2': DC_u8Rotate(&DC,CCW); break;
					}
					while(KPD_u8GetPressedKey()!='*');
					DC_u8Stop(&DC); break;
					case '2': CLCD_voidSendString("LM35 Control");
					while(Local_u8PressedKey!='*')
					{
						APP_PotenMappedValue=0;
						ADC_u16StartConversionSynch(4,&Local_ADCReading);
						APP_LM35MappedValue=ADC_S16ReadingMap(&LM35Reading,Local_ADCReading);
						CLCD_voidCLR();
						CLCD_void_SendNumber(Local_ps8Buffer,APP_LM35MappedValue);
						_delay_ms(2500);
						TIMER0_u8SetCallBack(&APP_DCSpeed);
						Local_u8PressedKey=KPD_u8GetPressedKey();
					}DC_u8Stop(&DC); APP_LM35MappedValue=0; break;
					case '3': CLCD_voidSendString("Potentiometer");
					while(Local_u8PressedKey!='*')
					{
						APP_LM35MappedValue=0;
						ADC_u16StartConversionSynch(5,&Local_ADCReading);
						APP_PotenMappedValue=ADC_S16ReadingMap(&PotenReading,Local_ADCReading);
						CLCD_voidCLR();
						CLCD_void_SendNumber(Local_ps8Buffer,APP_LM35MappedValue);
						_delay_ms(2500);
						TIMER0_u8SetCallBack(&APP_DCSpeed);
						Local_u8PressedKey=KPD_u8GetPressedKey();
					}
					DC_u8Stop(&DC); APP_PotenMappedValue=0; break;
					}
				}break;
				case '2': CLCD_voidCLR();
				CLCD_voidSendString("1-CW   2-CCW");
				APP_u8Direction=KPD_u8GetPressedKey();
				if(APP_u8Direction=='1' || APP_u8Direction=='2')
				{
					CLCD_voidCLR();
					CLCD_voidSendString("Angle: ");
					CLCD_voidGoToXY(1,0);
					CLCD_voidSendString("Press # Last");
					Local_u8PressedKey=KPD_u8GetPressedKey();
					CLCD_voidGoToXY(0,7);
					Local_u16Angle=0;
					Local_u8Counter=0;
					while(Local_u8PressedKey!='#')
					{
						if(Local_u8Counter==0)
						{
							Local_u16Angle+=(Local_u8PressedKey-'0');
							Local_u8Counter++;
						}
						else
						{
							Local_u16Angle=(Local_u16Angle*10)+(Local_u8PressedKey-'0');
						}
						CLCD_voidSendData(Local_u8PressedKey);
						Local_u8PressedKey=KPD_u8GetPressedKey();
					}
					CLCD_voidCLR();
					CLCD_voidSendString("StepperMotor Run");
					CLCD_voidGoToXY(1,0);
					switch(APP_u8Direction)
					{
					case '1': STEPPER_u8Rotate(&MOTOR1,Local_u16Angle,CW); break;
					case '2': STEPPER_u8Rotate(&MOTOR1,Local_u16Angle,CCW); break;
					}
				}break;
				case '3': CLCD_voidCLR();
				CLCD_voidSendString("Angle: ");
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendString("Press # Last");
				CLCD_voidGoToXY(0,7);
				Local_u8PressedKey=KPD_u8GetPressedKey();
				Local_u16Angle=0;
				Local_u8Counter=0;
				while(Local_u8PressedKey!='#')
				{
					if(Local_u8Counter==0)
					{
						Local_u16Angle+=(Local_u8PressedKey-'0');
						Local_u8Counter++;
					}
					else
					{
						Local_u16Angle=(Local_u16Angle*10)+(Local_u8PressedKey-'0');
					}
					CLCD_voidSendData(Local_u8PressedKey);
					Local_u8PressedKey=KPD_u8GetPressedKey();
				}
				CLCD_voidCLR();
				CLCD_voidSendString("Servo Run");
				Local_u16MappedAngle=ADC_S16ReadingMap(&Angle,Local_u16Angle);
				TIMER1_voidSetICR1Value(20000);
				TIMER1_voidSetChannelACompMatchValue(Local_u16MappedAngle);
				Local_u16MappedAngle=0; break;
				default: DC_u8Stop(&DC); STEPPER_u8Stop(&MOTOR1); break;
				}
			}
		}
	}
}
/*Function to invert Number EX: 1234 -> 4321*/
u16 App_u16InvertNumber(u16 Copy_u8Number)
{
	u16 Local_u16InvertedNum=0;
	u8 Local_u8Rem=0;
	for(u8 Local_u8Counter=0;Local_u8Counter<4;Local_u8Counter++)
	{
		Local_u8Rem=Copy_u8Number%10;
		Copy_u8Number/=10;
		switch(Local_u8Counter)
		{
		case 0: Local_u16InvertedNum=Local_u8Rem*1000; break;
		case 1: Local_u16InvertedNum+=Local_u8Rem*100; break;
		case 2: Local_u16InvertedNum+=Local_u8Rem*10; break;
		case 3: Local_u16InvertedNum+=Local_u8Rem; break;
		}
	}
	return Local_u16InvertedNum;
}
void APP_DCSpeed(void)
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if(APP_PotenMappedValue==0)
	{
		if(Local_u8Counter==APP_LM35MappedValue)
		{
			DC_u8Stop(&DC);
		}
	}
	if(APP_LM35MappedValue==0)
	{
		if(Local_u8Counter==APP_PotenMappedValue)
		{
			DC_u8Stop(&DC);
		}
	}
	if(Local_u8Counter==10)
	{
		switch(APP_u8Direction)
		{
		case '1': DC_u8Rotate(&DC,CW); break;
		case '2': DC_u8Rotate(&DC,CCW); break;
		Local_u8Counter=0;
		}
	}
}
