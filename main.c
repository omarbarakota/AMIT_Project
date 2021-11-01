/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Lenovo
 */

#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SEG_interface.h"
#include "AMIT_Interface.h"
#include "ADC_Interface.h"
#include "Timer_Interface.h"
#include "Timer_Config.h"
#include "EXTI_Interface.h"
#include "GIE_Interface.h"
#include "util/delay.h"
#include "Internal_EEPROM_Interface.h"

int main (void)
{
	extern u16 Counter5000;
	extern u8 Counter10,Counter100;
	extern u8 Button_State_On_Off;
	extern u8 ModeFlag;
	extern u8 GLO_u8EEPROMValue;
	u32 LOC_u32SensorSumValue=0;
	u16 LOC_u16DigitalData=0, LOC_u16AnalogData=0,LOC_16Temperature=0;
	u16 Counter1000=0;
	u8 SEGFlag=SEG_ON,LEDflag=0;;
	//Cooling Heating LED
	DIO_u8SetPinDirection(DIO_PIN7,DIO_PORTC,PIN_OUTPUT);
	//EXT INT0 BUTTON2 ON/OFF BUTTON
	DIO_u8SetPinDirection(DIO_PIN2,DIO_PORTD,PIN_INPUT);
	//EXT INT1 BUTTON1 UP
	DIO_u8SetPinDirection(DIO_PIN6,DIO_PORTD,PIN_INPUT);
	//EXT INT2 BUTTON0 DOWN
	DIO_u8SetPinDirection(DIO_PIN0,DIO_PORTB,PIN_INPUT);

	InternalEEPROM_voidWrite_Data(20,60);
	_delay_ms(10);
	GLO_u8EEPROMValue=InternalEEPROM_u8ReadData(20);

	SEG_voidInit();
	TIMER0_voidInit();
	ADC_voidInit();

	EXTI_INT0_voidSetCallBackFunc(&AMIT_Project_voidON_OFF);
	EXTI_INT1_voidSetCallBackFunc(&AMIT_Project_voidUP);
	EXTI_INT2_voidSetCallBackFunc(&AMIT_Project_voidDOWN);

	TIMER0_voidSetCTCValue(TIMER0_CTC);
	Timer0_voidSetCallBack_Function(&AMIT_Project_Timers);

	EXTI_voidINT0_Init();
	EXTI_voidINT1_Init();
	EXTI_voidINT2_Init();
	GIE_voidEnable();

	while(1)
	{
		if(Button_State_On_Off==ON_STATE)
		{
			if(ModeFlag==SET_TEMPERATURE_MODE)
			{
				SEG_voidSEGBlinker(SEGFlag,&Counter10,GLO_u8EEPROMValue);
				if (Counter100 == 100)// 0.1 SEC
				{
					Counter1000+=Counter100;
					Counter100=0;
				}
				else
				{
					/*Nothing*/
				}
				if (Counter1000 == 1000)//1 SEC
				{
					if (SEGFlag == SEG_ON)
					{
						SEGFlag = SEG_OFF;
					}
					else if (SEGFlag == SEG_OFF)
					{
						SEGFlag = SEG_ON;
					}
					else
					{
						/*Nothing*/
					}
					Counter5000 += Counter1000;
					Counter1000 = 0;
				}
				else
				{
					/*Nothing*/
				}
				if (Counter5000 == 5000)// 5 SECS
				{
					InternalEEPROM_voidWrite_Data(20,GLO_u8EEPROMValue);
					ModeFlag=SENSING_TEMPERATURE_MODE;
					Counter5000 = 0;
				}
				else
				{
					/*Nothing*/
				}
			}
			else if (ModeFlag==SENSING_TEMPERATURE_MODE)
			{
				SEG_voidSEGViewer(&Counter10, LOC_16Temperature);
				if (Counter100 == 100)
				{
					LOC_u16DigitalData=ADC_u16StartConversion(0);
					LOC_u16AnalogData = (LOC_u16DigitalData * 5000UL) / 1024;
					LOC_u32SensorSumValue += LOC_u16AnalogData;
					Counter1000 += Counter100;
					Counter100 = 0;
				}
				else
				{
					/*Nothing*/
				}
				if (Counter1000 == 1000)//1 SEC
				{
					LOC_u32SensorSumValue /= 10;
					LOC_16Temperature = LOC_u32SensorSumValue / 10;
					LEDflag = AMIT_Projectu8_TempreatureCompare(LOC_16Temperature, GLO_u8EEPROMValue);
					AMIT_Projectvoid_Cooling_HeatingLeds(LEDflag);
					Counter5000 += Counter1000;
					Counter1000 = 0;
				}
				else
				{
					/*Nothing*/
				}
			}
			else if(ModeFlag==DEFAULT_MODE)
			{//Show the set temp
				SEG_voidSEGViewer(&Counter10,GLO_u8EEPROMValue);
			}
		}
		else //OFF_State
		{
			ModeFlag=DEFAULT_MODE;
			SEG_voidDisableSeg();
			DIO_u8SetPinValue(DIO_PIN7,DIO_PORTC,PIN_LOW);
			GLO_u8EEPROMValue=InternalEEPROM_u8ReadData(20);
			Counter10=0;
			Counter100=0;
			Counter1000=0;
			Counter5000=0;
		}
	}
	return 0;
}
