/**
******************************************************************************
* @file    EEPROM.h
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

#ifndef _EEPROM_H
#define _EEPROM_H
/************************* Defines ************************/ 
#define ERASE 0xFF
/******************** Create Functions ********************/
void EEPROM_write(uint16_t uiaddress,uint8_t ucdata);
void EEPROM_erase(uint16_t start_byte,uint16_t end_byte);
void EEPROM_write_nbyte(uint8_t *str,uint16_t start_byte,uint16_t nbyte);
uint8_t EEPROM_read(uint8_t uiaddress);
void EEPROM_read_nbyte(uint8_t *str,uint16_t start_byte,uint16_t nbyte);
/******************* End Of The Program *******************/
#endif 