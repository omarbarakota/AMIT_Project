/*
 * Timer_Interface.h
 *
 *  Created on: Sep 19, 2021
 *      Author: Lenovo
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


void Wu8DT_voidEnable(void);
void Wu8DT_voidSleep(void);
void Wu8DT_voidDisable(void);


void TIMER0_voidInit(void);
void TIMER0_voidSetPreloadValue(u8 Copy_u8Preload);
void TIMER0_voidSetCTCValue(u8 Copy_u8CTCValue);

void TIMER1_voidInit(void);


void TIMER2_voidInit(void);
void TIMER2_voidSetPreloadValue(u8 Copy_u8Preload);
void TIMER2_voidSetCTCValue(u8 Copy_u8CTCValue);

#endif /* TIMER_INTERFACE_H_ */
