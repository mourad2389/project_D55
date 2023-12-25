/*
 * SSD_program.c
 *
 * Created: 11/19/2023 11:28:52 PM
 *  Author: Kareem Hussein
 */ 


#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SSD_interface.h"


void SSD_init(void)
{
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);	
}


void SSD_displayNumber(u8 ssdId,u8 desiredNumber)
{
	if(desiredNumber<=9)
	{
		switch(ssdId)
		{
			case SSD_ONE:
			DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
			private_writeHalfPort(desiredNumber);
			break;
			
			case SSD_TWO:
			DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
			private_writeHalfPort(desiredNumber);
			break;
		}
	}
}


void SSD_displayMultiNumber(u8 desiredNumber)
{
	if(desiredNumber<=99)
	{
		DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
		private_writeHalfPort(desiredNumber/10);
		DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_setPinValue(DIO_PORTB,DIO_PIN2,DIO_PIN_LOW);
		private_writeHalfPort(desiredNumber%10);
		DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_HIGH);
		_delay_ms(10);
		DIO_setPinValue(DIO_PORTB,DIO_PIN1,DIO_PIN_LOW);
	}
}


static void private_writeHalfPort(u8 value)
{
	DIO_setPinValue(DIO_PORTA,DIO_PIN4,GET_BIT(value,0));
	DIO_setPinValue(DIO_PORTA,DIO_PIN5,GET_BIT(value,1));
	DIO_setPinValue(DIO_PORTA,DIO_PIN6,GET_BIT(value,2));
	DIO_setPinValue(DIO_PORTA,DIO_PIN7,GET_BIT(value,3));
}