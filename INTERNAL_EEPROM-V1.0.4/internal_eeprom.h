/*
------------------------------------------------------------------------------
~ File   : internal_eeprom.h
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

#ifndef _INTERNAL_EEPROM_H
#define _INTERNAL_EEPROM_H

/* ------------------------------------------------ Includes ------------------------------------------------- */

#include <stdint.h> /* Import standard integer lib */

/* ------------------------------------------------------------------ */

#ifdef __CODEVISIONAVR__  /* Check compiler */

#pragma warn_unref_func- /* Disable 'unused function' warning */

#include <io.h>          /* Import io library */
#include <delay.h>       /* Import delay library */

/* ------------------------------------------------------------------ */

#elif defined(__GNUC__)  /* Check compiler */

#pragma GCC diagnostic ignored "-Wunused-function" /* Disable 'unused function' warning */

#include <avr/io.h>      /* Import io library */
#include <util/delay.h>  /* Import delay library */

/* ------------------------------------------------------------------ */

#else                     /* Compiler not found */

#error Chip or Compiler not supported  /* Send error */

#endif /* __CODEVISIONAVR__ */

/* ------------------------------------------------------------------ */

/* ------------------------------------------------- Defines ------------------------------------------------- */

#define _WAIT_TIME 9

#ifndef _NULL
	#define _NULL 0xFF
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ By compiler ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifdef __CODEVISIONAVR__  /* Check compiler */

#ifndef _DELAY_MS
	#define _DELAY_MS(t)                     delay_ms((t)) /* Change function */
#endif /* _DELAY_MS */

/* ------------------------------------------------------------------ */

#elif defined(__GNUC__)  /* Check compiler */

#ifndef _DELAY_MS
	#define _DELAY_MS(t)                     _delay_ms((t)) /* Change function */
#endif /* _DELAY_MS */

/* ------------------------------------------------------------------ */

#else
#endif /* __CODEVISIONAVR__ */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ------------------------------------------------ Prototype ------------------------------------------------ */

void EEPROM_SingleWrite(uint16_t mem_address, uint8_t udata);

void EEPROM_Erase(uint16_t start_address, uint16_t end_address);

void EEPROM_BurstWrite(uint8_t *str, uint16_t start_address, uint16_t quantity);

uint8_t EEPROM_SingleRead(uint8_t mem_address);

void EEPROM_BurstRead(uint8_t *str, uint16_t start_address, uint16_t quantity);

#endif 
