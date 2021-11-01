/*
 * EEPROM_Private.h
 *
 *  Created on: Oct 10, 2021
 *      Author: Lenovo
 */

#ifndef INTERNAL_EEPROM_PRIVATE_H_
#define INTERNAL_EEPROM_PRIVATE_H_

			/*internal eeprom*/
#define SPMCR	*((volatile u8*)0x57)
#define EECR	*((volatile u8*)0x3C)
#define EEDR	*((volatile u8*)0x3D)
#define EEAR	*((volatile u16*)0x3E)

#define INTERNAL_EEPROM_INTERRUPT_ENABLE	1
#define INTERNAL_EEPROM_INTERRUPT_DISABLE	0

#endif /* INTERNAL_EEPROM_PRIVATE_H_ */
