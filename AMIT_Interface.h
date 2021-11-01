/*
 * AMIT_Interface.h
 *
 *  Created on: Oct 14, 2021
 *      Author: Lenovo
 */

#ifndef AMIT_INTERFACE_H_
#define AMIT_INTERFACE_H_

#define COOLING		1
#define HEATING		2

#define SET_TEMPERATURE_MODE		0
#define SENSING_TEMPERATURE_MODE	1
#define DEFAULT_MODE				2

#define OFF_STATE	0
#define ON_STATE	1

#define UP_STATE	0
#define DOWN_STATE	1

void AMIT_Project_voidON_OFF(void);
void AMIT_Project_voidUP(void);
void AMIT_Project_voidDOWN(void);
void AMIT_Project_Timers(void);
void AMIT_Projectvoid_Cooling_HeatingLeds(u8 Copy_u8Flag);
u8 AMIT_Projectu8_TempreatureCompare(u8 Copy_u8SensorTempreature,u8 Copy_u8SetTempreature);


#endif /* AMIT_INTERFACE_H_ */
