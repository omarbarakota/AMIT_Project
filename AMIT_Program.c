/*
 * AMIT_Program.c
 *
 *  Created on: Oct 13, 2021
 *      Author: Lenovo
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SEG_interface.h"
#include "AMIT_Interface.h"
#include "util/delay.h"

u16 Counter5000=0;
u8 Counter10=0,Counter100=0;

u8 Button_State_On_Off=OFF_STATE;
u8 ModeFlag=DEFAULT_MODE;

u8 GLO_u8EEPROMValue;
//this function controls the onn and off states
void AMIT_Project_voidON_OFF(void)
	{
	 if(Button_State_On_Off==OFF_STATE)
	 {
		Button_State_On_Off=ON_STATE;
	 }
	 else if(Button_State_On_Off==ON_STATE)
	 {
		 Button_State_On_Off=OFF_STATE;
	 }
	 else
	 {
		 /* NOTHING */
	 }
}
//this functions is used to increment the set temperature
void AMIT_Project_voidUP(void)
{
	//enters the SET_TEMPERATURE_MODE
	if(ModeFlag==DEFAULT_MODE)
	{
		 ModeFlag=SET_TEMPERATURE_MODE;
	}
	else if(ModeFlag==SET_TEMPERATURE_MODE   &&   GLO_u8EEPROMValue<75)//Min TEMP
	{
		//increment the set temperature
		GLO_u8EEPROMValue+=5;
	}
	else
	{
		/* NOTHING */
	}
	Counter5000=0;
}
void AMIT_Project_voidDOWN(void)
{
	if(ModeFlag==DEFAULT_MODE)
	{
		//enters the SET_TEMPERATURE_MODE
		ModeFlag=SET_TEMPERATURE_MODE;
	}
	else if(ModeFlag==SET_TEMPERATURE_MODE   &&   GLO_u8EEPROMValue>35)//Min TEMP
	{
		//decrement the set temperature
		GLO_u8EEPROMValue-=5;
	}
	else
	{
		/* NOTHING */
	}
	Counter5000=0;
}
void AMIT_Project_Timers(void)
{
	//the timers starts counting
	Counter10++;
	Counter100++;
}
void AMIT_Projectvoid_Cooling_HeatingLeds(u8 Copy_u8Flag)
{
	//if we need to cool the water
	if (Copy_u8Flag == COOLING) //Cooling
	{
		//Set the LED
		DIO_u8SetPinValue(DIO_PIN7, DIO_PORTC, PIN_HIGH);
	}
	//if we need to heat the water
	else if (Copy_u8Flag == HEATING) //Heating
	{
		//toggle the LED
		DIO_u8TogglePinValue(DIO_PIN7, DIO_PORTC);
	}
	else
	{
		/*Nothing*/
	}
}
u8 AMIT_Projectu8_TempreatureCompare(u8 Copy_u8SensorTempreature,u8 Copy_u8SetTempreature)
{
	u8 flag;
	// if the water is hotter than the needed temperature
	if(Copy_u8SensorTempreature>=(Copy_u8SetTempreature+5))
	{
		flag=COOLING;//Cooling
	}
	// if the water is colder than the needed temperature
	else if (Copy_u8SensorTempreature<=(Copy_u8SetTempreature-5))
	{
		flag=HEATING;//Heating
	}
	else
	{
		flag=0;//the water temp is close to the set temp +-5
	}
	return flag;
}

