/*
 * led_program.c
 *
 * Created: 06/10/2023 3:51:43 PM
 *  Author: Morad
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "led_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void led0_on (void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
}

void led1_on (void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
}
void led2_on (void)
{
DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);	
}

void led0_off (void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
}
void led1_off (void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
}
void led2_off (void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_setPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
}
void led0_toggle (void)
{
DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
DIO_togglePinValue(DIO_PORTC,DIO_PIN2);	
}
void led1_toggle (void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_togglePinValue(DIO_PORTC,DIO_PIN7);
}
void led2_toggle (void)
{
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_togglePinValue(DIO_PORTD,DIO_PIN3);
}