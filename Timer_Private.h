/*
 * Timer_Private.h
 *
 *  Created on: Sep 19, 2021
 *      Author: Lenovo
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TIMSK		 *((volatile u8*)0x59)
#define MCUCSR       *((volatile u8*)0x54)
#define WDTRC        *((volatile u8*)0x41)


#define WATCHDOG_PRESCALER_16K			0
#define WATCHDOG_PRESCALER_32K			1
#define WATCHDOG_PRESCALER_64K			2
#define WATCHDOG_PRESCALER_128K			3
#define WATCHDOG_PRESCALER_256K			4
#define WATCHDOG_PRESCALER_512K			5
#define WATCHDOG_PRESCALER_1024K		6
#define WATCHDOG_PRESCALER_2048K		7




/*****************	TIMER 0		*****************/

#define	TCCR0		*((volatile u8*)0x53)
#define	TCNT0		*((volatile u8*)0x52)
#define	OCR0		*((volatile u8*)0x5C)

#define TIMER0_NORMAL_MODE				0
#define TIMER0_CTC_MODE					1
#define TIMER0_PWM_PHASECORRECT_MODE	2
#define TIMER0_PWM_FAST_MODE			3

/*
 * 3l4an bt3ml BITMASK l awl 3 BITS (0b11111000)
 */
#define TIMER0_BITMASK_PRESCALER 		0xf8
#define TIMER0_NO_PRESCALER 			1
#define TIMER0_8_PRESCALER 				2
#define TIMER0_64_PRESCALER				3
#define TIMER0_256_PRESCALER			4
#define TIMER0_1024_PRESCALER			5

#define TIMER0_EXTERNAL_SOURCE_FALLING	6
#define TIMER0_EXTERNAL_SOURCE_RISING	7

#define OC0_PIN_DISCONNECTED			0
#define OC0_PIN_TOGGLE					1
#define OC0_PIN_CLEAR					2
#define OC0_PIN_SET						3



/*****************	TIMER 1		*****************/

#define TCCR1A    *((volatile u8*)0x4F)
#define TCCR1B    *((volatile u8*)0x4E)
#define TCNT1     *((volatile u16*)0x4C)
#define OCR1A     *((volatile u16*)0x4A)
#define OCR1B     *((volatile u16*)0x48)
#define ICR1     *((volatile u16*)0x46)
//A LOT OF OTHER OPTIONS IN DATASHEET P.109
#define TIMER1_NORMAL_MODE				0
#define TIMER1_CTC_MODE					1
#define TIMER1_PWM_PHASECORRECT_MODE	2
#define TIMER1_PWM_FAST_MODE			3

#define TIMER1_BITMASK_PRESCALER 		0xf8
#define TIMER1_NO_PRESCALER 			1
#define TIMER1_8_PRESCALER 				2
#define TIMER1_64_PRESCALER				3
#define TIMER1_256_PRESCALER			4
#define TIMER1_1024_PRESCALER			5

#define TIMER1_EXTERNAL_SOURCE_FALLING	6
#define TIMER1_EXTERNAL_SOURCE_RISING	7

#define OC1_PIN_DISCONNECTED			0
#define OC1_PIN_TOGGLE					1
#define OC1_PIN_CLEAR					2
#define OC1_PIN_SET						3



/*****************	TIMER 2		*****************/

#define	TCCR2		*((volatile u8*)0x45)
#define	TCNT2		*((volatile u8*)0x44)
#define	OCR2		*((volatile u8*)0x43)

#define TIMER2_NORMAL_MODE				0
#define TIMER2_CTC_MODE					1
#define TIMER2_PWM_PHASECORRECT_MODE	2
#define TIMER2_PWM_FAST_MODE			3

/*
 * 3l4an bt3ml BITMASK l awl 3 BITS (0b11111000)
 */
#define TIMER2_BITMASK_PRESCALER 		0xf8
#define TIMER2_NO_PRESCALER 			1
#define TIMER2_8_PRESCALER 				2
#define TIMER2_32_PRESCALER				3
#define TIMER2_64_PRESCALER				4
#define TIMER2_128_PRESCALER			5

#define TIMER2_256_PRESCALER			6
#define TIMER2_1024_PRESCALER			7

#define OC2_PIN_DISCONNECTED			0
#define OC2_PIN_TOGGLE					1
#define OC2_PIN_CLEAR					2
#define OC2_PIN_SET						3


#endif /* TIMER_PRIVATE_H_ */
