/*
 * EXTI_Program.c
 *
 *  Created on: Sep 12, 2021
 *      Author: gerges
 */


#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_Private.h"



void (*EXTI_INT0_CallBackFun)(void);
void (*EXTI_INT1_CallBackFun)(void);
void (*EXTI_INT2_CallBackFun)(void);


void EXTI_voidINT0_Init(void)
{
	/*select Sense Control (Falling edge)*/
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
	/*Enable PIE INT0*/
	SET_BIT(GICR,6);
}
void EXTI_voidINT1_Init(void)
{
	/*select Sense Control (Falling edge)*/
	CLR_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	/*Enable PIE INT1*/
	SET_BIT(GICR,7);

}
void EXTI_voidINT2_Init(void)
{
	/*select Sense Control (Falling edge)*/
	CLR_BIT(MCUCSR,6);
	/*Enable PIE INT2*/
	SET_BIT(GICR,5);
}


void EXTI_INT0_voidSetCallBackFunc(void(*Copy_voidP_CallBackFunc) (void))
{
	EXTI_INT0_CallBackFun=Copy_voidP_CallBackFunc;
}
void EXTI_INT1_voidSetCallBackFunc (void(*Copy_voidP_CallBackFunc) (void))
{
	EXTI_INT1_CallBackFun=Copy_voidP_CallBackFunc;
}
void EXTI_INT2_voidSetCallBackFunc (void(*Copy_voidP_CallBackFunc) (void))
{
	EXTI_INT2_CallBackFun=Copy_voidP_CallBackFunc;
}

void __vector_1(void)	__attribute__((signal));
void __vector_1(void)
{
	EXTI_INT0_CallBackFun();
}
void __vector_2(void)	__attribute__((signal));
void __vector_2(void)
{
	EXTI_INT1_CallBackFun();
}
void __vector_3(void)	__attribute__((signal));
void __vector_3(void)
{
	EXTI_INT2_CallBackFun();
}



