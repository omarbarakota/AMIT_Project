/*
 * EEPROM_Program.c
 *
 *  Created on: Oct 10, 2021
 *      Author: Lenovo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "Internal_EEPROM_Private.h"

///*Internal EEPROM*/
void(*Internal_EEPROM_CallbackFunction)(void);

void InternalEEPROM_voidWrite_Data(u16 Copy_u16LocationAddress, u8 Copy_u8Data)
{
	//wait until EEWE=0 POOL
	while(GET_BIT(EECR,1)!=0);
	//wait spmen in spmcr =0
	while(GET_BIT(SPMCR,0)!=0);
	//write new address EEAR
	EEAR=Copy_u16LocationAddress;
	//write new data EEDR
	EEDR=Copy_u8Data;
	//write one to EEMWE
	SET_BIT(EECR,2);
	//after setting EEMWE SET EEWE within four clock cycles
	SET_BIT(EECR,1);
}
u8 InternalEEPROM_u8ReadData(u16 Copy_u16LocationAddress)
{
	////wait until EEWE=0 POOL
	while(GET_BIT(EECR,1)!=0);
	//SET ADDRESS
	EEAR=Copy_u16LocationAddress;
	//START EEPROM READ SET EERE
	SET_BIT(EECR,0);
	//EECR|=(1<<0);
	//RETURN DATA
	return EEDR;
}
void Internal_EEPROM_SET_CallbackFunction(void(*Copy_P_Fun_CallbackFunction)(void))
{
	Internal_EEPROM_CallbackFunction=Copy_P_Fun_CallbackFunction;
}
void __vector_18 (void) __attribute__((signal));
void __vector_18 (void)
{
	Internal_EEPROM_CallbackFunction();
}

