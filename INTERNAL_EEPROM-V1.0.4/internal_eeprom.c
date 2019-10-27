/*
------------------------------------------------------------------------------
~ File   : internal_eeprom.c
~ Author : Majid Derhambakhsh
~ Version: V1.0.4
~ Created: 10/28/2019 12:38:00 AM
~ Brief  :
~ Support: Majid.do16@gmail.com
------------------------------------------------------------------------------
~ Description:    Set up and use the Internal AVR EEPROM.

~ Attention  :    This library is for CVAVR/GNUC Compilers.
------------------------------------------------------------------------------
*/

/* -------------------- Library include -------------------- */

#include "internal_eeprom.h"

/* ----------------------- Functions ----------------------- */

void EEPROM_SingleWrite(uint16_t mem_address,uint8_t udata) /* Function For Write To EEPROM */
{
	
	EEAR = mem_address; /* Set up address register */
	while(EECR & (1 << EEWE)); /* Wait for completion of previous write */
	EEAR = mem_address; /* Set up address register */
	EEDR = udata; /* Set up data registers */
	EECR |= (1 << EEMWE); /* Write logical one to EEMWE */
	EECR |= (1 << EEWE); /* Start eeprom write by setting EEWE */
	
	_DELAY_MS(_WAIT_TIME);
	
}

/*-----------------------------------------------*/
void EEPROM_Erase(uint16_t start_address, uint16_t end_address) /* Function For Erase EEPROM */
{
	
	for(; start_address < end_address; start_address++) /* Loop For Counts And Copy */
	{
		EEPROM_SingleWrite(start_address, _NULL); /* Write Erase Byte To EEPROM */
	}
	
}

/*-----------------------------------------------*/
void EEPROM_BurstWrite(uint8_t *str,uint16_t start_address,uint16_t quantity) /* Function For Write String To EEPROM */
{
	
	quantity += start_address; /* Set Value For Counter */
	
	for(; start_address < quantity; start_address++) /* Loop For Counts And Copy */
	{
		
		EEPROM_SingleWrite(start_address, *str); /* Write String To EEPROM */
		str++; /* Select Next Byte */
		
	}
	
}

/* --------------------------------------------- */
uint8_t EEPROM_SingleRead(uint8_t mem_address) /* Function For Read EEPROM Data */
{
	
	EEAR = mem_address; /* Set up address register */
	while(EECR & (1 << EEWE)); /* Wait for completion of previous write */
	EEAR = mem_address; /* Set up address register */
	EECR |= (1 << EERE); /* Start eeprom read by writing EERE */
	
	return EEDR;  /* Return data from data register */
	
	//_DELAY_MS(_WAIT_TIME);
	
}

/* --------------------------------------------- */
void EEPROM_BurstRead(uint8_t *str, uint16_t start_address, uint16_t quantity)
{
	
	quantity += start_address; /* Set Value For Counter */
	
	for(; start_address < quantity; start_address++) /* Loop For Counts And Copy */
	{
		
		*str = EEPROM_SingleRead(start_address); /* Write String To EEPROM */
		str++; /* Select Next Byte */
		
	}
	
}

/* End Program */