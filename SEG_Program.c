/*
 * SEG_Program.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Lenovo
 */
#include"STD_TYPES.h"
#include"DIO_Interface.h"
#include"SEG_Interface.h"
#include "SEG_Config.h"
void SEG_voidInit(void) {
	//EN1
	DIO_u8SetPinDirection(ENABLE_1_PIN, ENABLE_PORT, PIN_OUTPUT);
	//EN2
	DIO_u8SetPinDirection(ENABLE_2_PIN, ENABLE_PORT, PIN_OUTPUT);
	//OUT
	DIO_u8SetPinDirection(DATA_A_PIN, DATA_PORT, PIN_OUTPUT);
	DIO_u8SetPinDirection(DATA_B_PIN, DATA_PORT, PIN_OUTPUT);
	DIO_u8SetPinDirection(DATA_C_PIN, DATA_PORT, PIN_OUTPUT);
	DIO_u8SetPinDirection(DATA_D_PIN, DATA_PORT, PIN_OUTPUT);
}

u8 SEG_voidSegDisplay(u8 Copy_u8SegPosition,u8 Copy_u8SegValue)
{
	u8 Error_state=0;
	if(Copy_u8SegPosition==RIGHT_SEG)
	{
		//EN1
		DIO_u8SetPinValue(ENABLE_1_PIN, ENABLE_PORT, PIN_HIGH);
		//DISABLE2
		DIO_u8SetPinValue(ENABLE_2_PIN, ENABLE_PORT, PIN_LOW);
	}
	else if(Copy_u8SegPosition==LEFT_SEG)
	{
		//Disable Right
		DIO_u8SetPinValue(ENABLE_1_PIN, ENABLE_PORT, PIN_LOW);
		//Enable Left
		DIO_u8SetPinValue(ENABLE_2_PIN, ENABLE_PORT, PIN_HIGH);
	}
	else if(Copy_u8SegPosition==BOTH_SEG)
	{
		//Enable Right
		DIO_u8SetPinValue(ENABLE_1_PIN, ENABLE_PORT, PIN_LOW);
		//Enable Left
		DIO_u8SetPinValue(ENABLE_2_PIN, ENABLE_PORT, PIN_HIGH);
	}
	else
	{
		Error_state=1;
	}
	switch (Copy_u8SegValue) {
	case 0:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 1:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 2:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 3:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 4:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 5:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 6:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 7:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_LOW);
		break;
	case 8:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_HIGH);
		break;
	case 9:
		DIO_u8SetPinValue(DATA_A_PIN, DATA_PORT, PIN_HIGH);
		DIO_u8SetPinValue(DATA_B_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_C_PIN, DATA_PORT, PIN_LOW);
		DIO_u8SetPinValue(DATA_D_PIN, DATA_PORT, PIN_HIGH);
		break;
	default:
		Error_state=1;
		break;
	}
	return Error_state;
}
void SEG_voidSEGViewer(u8* P_u8Counter,u8 Copy_u8Value)
{
	u8 LOC_u8RightSegValue,LOC_u8LeftSegValue;
	LOC_u8RightSegValue=Copy_u8Value%10;// initial value ll 7 seg
	LOC_u8LeftSegValue = Copy_u8Value / 10;
	switch(*P_u8Counter)
	{
		case 0:
			SEG_voidSegDisplay(RIGHT_SEG, LOC_u8RightSegValue);
			break;
		case 10:
			SEG_voidSegDisplay(LEFT_SEG, LOC_u8LeftSegValue);
			break;
		case 19:
			*P_u8Counter = 0;
			break;
		default:
			/*Nothing*/
			break;
	}
}
void SEG_voidDisableSeg(void)
{
	//DISABLE1
	DIO_u8SetPinValue(ENABLE_1_PIN, ENABLE_PORT, PIN_LOW);
	//DISABLE2
	DIO_u8SetPinValue(ENABLE_2_PIN, ENABLE_PORT, PIN_LOW);
}

void SEG_voidSEGBlinker(u8 Flag ,u8* P_u8Counter,u8 Copy_u8Value)
{
	if(Flag==SEG_ON)
	{
		SEG_voidSEGViewer(P_u8Counter,Copy_u8Value);
	}
	else if(Flag==SEG_OFF)
	{
		SEG_voidDisableSeg();
	}
	else
	{
		/*Nothing*/
	}
}



//		abcd
//0		0000
//1 	0001
//2 	0010
//3 	0011
//4 	0100
//5 	0101
//6 	0110
//7 	0111
//8 	1000
//9 	1001
