/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 12, 2021
 *      Author: gerges
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void EXTI_voidINT0_Init(void);
void EXTI_voidINT1_Init(void);
void EXTI_voidINT2_Init(void);

void EXTI_INT0_voidSetCallBackFunc (void(*Copy_voidP_CallBackFunc) (void));
void EXTI_INT1_voidSetCallBackFunc (void(*Copy_voidP_CallBackFunc) (void));
void EXTI_INT2_voidSetCallBackFunc (void(*Copy_voidP_CallBackFunc) (void));

#endif /* EXTI_INTERFACE_H_ */
