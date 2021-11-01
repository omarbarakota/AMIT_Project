/*
 * SEG_interface.h
 *
 *  Created on: Sep 24, 2021
 *      Author: Lenovo
 */

#ifndef SEG_INTERFACE_H_
#define SEG_INTERFACE_H_

#define LEFT_SEG	0
#define RIGHT_SEG	1
#define BOTH_SEG	2

#define SEG_ON		0
#define SEG_OFF		1

void SEG_voidInit(void);

u8 SEG_voidSegDisplay(u8 Copy_u8SegPosition,u8 Copy_u8SegValue);
void SEG_voidSEGViewer(u8* P_u8Counter,u8 Copy_u8Value);
void SEG_voidDisableSeg(void);
void SEG_voidSEGBlinker(u8 Flag ,u8* P_u8Counter,u8 Copy_u8Value);


#endif /* SEG_INTERFACE_H_ */
