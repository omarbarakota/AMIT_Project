/*
 * Timer_Program.c
 *
 *  Created on: Sep 19, 2021
 *      Author: Lenovo
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include "DIO_Interface.h"
#include"Timer_Private.h"
#include"Timer_Config.h"

void (*TIMER0_CTC_CallBackFun)(void);

void Wu8DT_voidEnable(void)
{
	SET_BIT(WDTRC,3);
}
void Wu8DT_voidSleep(void)
{
	SET_BIT(WDTRC,4);//to be cleared
	CLR_BIT(WDTRC,3);
}
void Wu8DT_voidDisable(void)
{
//	SET_BIT(WDTRC,4);
//	SET_BIT(WDTRC,3);
//	CLR_BIT(WDTRC,4);
	//WDTRC &= (~(1<<3));
	//WDTRC &= (~(1<<4));
	WDTRC =0x18;//0b 0001 1000  WDTOE & WDE are Set
	WDTRC =0x00;//0b 0001 0000	WDE is Cleared

}



/*****************	TIMER 0		*****************/

void TIMER0_voidInit(void)
{

	/* Set Normal Mode */
#if TIMER0_MODE==TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,0);
#elif TIMER0_MODE==TIMER0_CTC_MODE
	/* Set CTC Mode */
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,1);

#elif TIMER0_MODE==TIMER0_PWM_PHASECORRECT_MODE
	/* Set PWM_PHASECORRECT Mode */
	CLR_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);
	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,1);
#elif TIMER0_MODE==TIMER0_PWM_FAST_MODE
	/* Set PWM_FAST Mode */
	SET_BIT(TCCR0,3);
	SET_BIT(TCCR0,6);

#else
	#error"You have error in set TIMER0 MODE"
#endif
/* Set Prescaler */
	TCCR0&=TIMER0_BITMASK_PRESCALER;
	TCCR0|=TIMER0_PRESCALER;
	/* OC0 PINMODE */
#if OC0_PIN_MODE==OC0_PIN_DISCONNECTED
	CLR_BIT(TCCR0,5);
	CLR_BIT(TCCR0,4);
#elif OC0_PIN_MODE==OC0_PIN_TOGGLE
	CLR_BIT(TCCR0,5);
	SET_BIT(TCCR0,4);

#elif OC0_PIN_MODE==OC0_PIN_CLEAR
	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif OC0_PIN_MODE==OC0_PIN_SET
	CLR_BIT(TCCR0,5);
	SET_BIT(TCCR0,4);
#else
	#error"You have error in set TIMER0 MODE"
#endif
}

void TIMER0_voidSetPreloadValue(u8 Copy_u8Preload)
{
	TCNT0=Copy_u8Preload;
}

void TIMER0_voidSetCTCValue(u8 Copy_u8CTCValue)
{
	OCR0=Copy_u8CTCValue;
}
			/************* TIMER0 INT	****************/
void Timer0_voidSetCallBack_Function(void (*Copy_voidP_CallBackFun) (void))
{
	TIMER0_CTC_CallBackFun=Copy_voidP_CallBackFun;
}
//11 ovf  10 ctc
void __vector_10(void)	__attribute__((signal));
void __vector_10(void)
{
	TIMER0_CTC_CallBackFun();
}



/*****************	TIMER 1		*****************/

/*	 F 7AGAT N2SA FL MOODS	W L PRESCALING*/
void TIMER1_voidInit(void)
{

	/*set modes*/

	/* Set Normal Mode */
#if	TIMER1_MODE==TIMER1_NORMAL_MODE
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);

//	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,2);
#elif TIMER1_MODE==TIMER1_CTC_MODE
	/* Set CTC Mode */
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);
	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,2);

#elif TIMER1_MODE==TIMER1_PWM_PHASECORRECT_MODE
//	/* Set PWM_PHASECORRECT Mode */
//	CLR_BIT(TCCR2,3);
//	SET_BIT(TCCR2,6);
//	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,2);
#elif TIMER1_MODE==TIMER1_PWM_FAST_MODE
//	/* Set PWM_FAST Mode */
//	SET_BIT(TCCR2,3);
//	SET_BIT(TCCR2,6);

#else
	#error"You have error in set TIMER2 MODE"
#endif


}




/*****************	TIMER 2		*****************/


void TIMER2_voidInit(void)
{

	/* Set Normal Mode */
#if TIMER2_MODE==TIMER2_NORMAL_MODE
	CLR_BIT(TCCR2,3);
	CLR_BIT(TCCR2,6);
	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,6);
#elif TIMER2_MODE==TIMER2_CTC_MODE
	/* Set CTC Mode */
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);
	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,7);

#elif TIMER2_MODE==TIMER2_PWM_PHASECORRECT_MODE
	/* Set PWM_PHASECORRECT Mode */
	CLR_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);
	/* OVERFLOW INTERRUPT ENABLE */
	SET_BIT(TIMSK,7);
#elif TIMER2_MODE==TIMER2_PWM_FAST_MODE
	/* Set PWM_FAST Mode */
	SET_BIT(TCCR2,3);
	SET_BIT(TCCR2,6);

#else
	#error"You have error in set TIMER2 MODE"
#endif
/* Set Prescaler */
	TCCR2&=TIMER2_BITMASK_PRESCALER;
	TCCR2|=TIMER2_PRESCALER;
	/* OC2 PINMODE */
#if OC2_PIN_MODE==OC2_PIN_DISCONNECTED
	CLR_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);
#elif OC2_PIN_MODE==OC2_PIN_TOGGLE
	SET_BIT(TCCR2,4);
	CLR_BIT(TCCR2,5);

#elif OC2_PIN_MODE==OC2_PIN_CLEAR
	CLR_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
#elif OC2_PIN_MODE==OC2_PIN_SET
	SET_BIT(TCCR2,4);
	SET_BIT(TCCR2,5);
#else
	#error"You have error in set TIMER2 MODE"
#endif
}

void TIMER2_voidSetPreloadValue(u8 Copy_u8Preload)
{
	TCNT2=Copy_u8Preload;
}

void TIMER2_voidSetCTCValue(u8 Copy_u8CTCValue)
{
	OCR2=Copy_u8CTCValue;
}



