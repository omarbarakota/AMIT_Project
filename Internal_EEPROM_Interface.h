/*
 * EEPROM_Interface.h
 *
 *  Created on: Oct 10, 2021
 *      Author: Lenovo
 */

#ifndef INTERNAL_EEPROM_INTERFACE_H_
#define INTERNAL_EEPROM_INTERFACE_H_

void InternalEEPROM_voidWrite_Data(u16 Copy_u16LocationAddress, u8 Copy_u8Data);
u8 InternalEEPROM_u8ReadData(u16 Copy_u16LocationAddress);
void Internal_EEPROM_SET_CallbackFunction(void(*Copy_P_Fun_CallbackFunction)(void));

#endif /* INTERNAL_EEPROM_INTERFACE_H_ */
