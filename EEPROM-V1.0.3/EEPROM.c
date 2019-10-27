/**
******************************************************************************
* @file    EEPROM.c
* @author  Majid Derhambakhsh
* @version V1.0.3
* @date    02-04-2018
* @brief
******************************************************************************
* @description  Set up and use the Internal AVR EEPROM
*   
* @attention    This file is for Codevision AVR
******************************************************************************
*/

/******************** Librarys Include ********************/
#include <io.h>
#include <stdint.h>
#include <delay.h>
/*-----------------------------------------------*/
#include "EEPROM.h"
/********************* Functions **********************/
void EEPROM_write(uint16_t uiaddress,uint8_t ucdata) /* Function For Write To EEPROM */
{
 EEAR = uiaddress;       /* Set up address register */
 while(EECR & (1<<EEWE)) /* Wait for completion of previous write */
 EEAR = uiaddress;       /* Set up address register */
 EEDR = ucdata;          /* Set up data registers */
 EECR |= (1<<EEMWE);     /* Write logical one to EEMWE */
 EECR |= (1<<EEWE);      /* Start eeprom write by setting EEWE */   
 delay_ms(9);
}
/*-----------------------------------------------*/
void EEPROM_erase(uint16_t start_byte,uint16_t end_byte) /* Function For Erase EEPROM */
{
 for(;start_byte<end_byte;start_byte++) /* Loop For Counts And Copy */
 {
  EEPROM_write(start_byte,ERASE); /* Write Erase Byte To EEPROM */
 }
}
/*-----------------------------------------------*/
void EEPROM_write_nbyte(uint8_t *str,uint16_t start_byte,uint16_t nbyte) /* Function For Write String To EEPROM */
{
/*************** Create Variable ***************/ 
 uint16_t end_byte=0; /* Variable For Count */                             
/************* End Create Variable *************/
 end_byte=(start_byte+nbyte);           /* Set Value For Counter */
 for(;start_byte<end_byte;start_byte++) /* Loop For Counts And Copy */
 {
  EEPROM_write(start_byte,*str);        /* Write String To EEPROM */
  str++;                                /* Select Next Byte */
 }
}
/*-----------------------------------------------*/
uint8_t EEPROM_read(uint8_t uiaddress) /* Function For Raed EEPROM Data */
{
 EEAR = uiaddress;       /* Set up address register */
 while(EECR & (1<<EEWE)) /* Wait for completion of previous write */
 EEAR = uiaddress;       /* Set up address register */
 EECR |= (1<<EERE);      /* Start eeprom read by writing EERE */
 return EEDR;            /* Return data from data register */    
 delay_ms(9);
}
/*-----------------------------------------------*/
void EEPROM_read_nbyte(uint8_t *str,uint16_t start_byte,uint16_t nbyte)
{
/*************** Create Variable ***************/ 
 uint16_t end_byte=0; /* Variable For Count */                             
/************* End Create Variable *************/
 end_byte=(start_byte+nbyte);           /* Set Value For Counter */
 for(;start_byte<end_byte;start_byte++) /* Loop For Counts And Copy */
 {
  *str=EEPROM_read(start_byte);         /* Write String To EEPROM */
  str++;                                /* Select Next Byte */
 }
}
/* End Program */