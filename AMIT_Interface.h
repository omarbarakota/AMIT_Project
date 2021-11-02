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
/* to use this function you will need these variable
 * extern u8 Button_State_On_Off;
 */
void AMIT_Project_voidUP(void);
/* to use this function you will need these variable
 * extern u8 ModeFlag;
 * extern u8 GLO_u8EEPROMValue;
 */
void AMIT_Project_voidDOWN(void);
/* to use this function you will need these variable
 * extern u8 ModeFlag;
 * extern u8 GLO_u8EEPROMValue;
 */
void AMIT_Project_Timers(void);
/* to use this function you will need these variables
 * extern u16 Counter5000;
 * extern u8 Counter10,Counter100;
 */
void AMIT_Projectvoid_Cooling_HeatingLeds(u8 Copy_u8Flag);
u8 AMIT_Projectu8_TempreatureCompare(u8 Copy_u8SensorTempreature,u8 Copy_u8SetTempreature);


#endif /* AMIT_INTERFACE_H_ */
