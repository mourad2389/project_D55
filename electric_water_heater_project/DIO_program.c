/*
 * DIO_program.c
 *
 * Created: 9/24/2023 10:08:21 PM
 *  Author: Kareem Hussein
 */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_setPinDirection(u8 PortId, u8 PinId, u8 PinDirection)
{
	if((PortId<=3)&&(PinId<=7)&&((PinDirection==DIO_PIN_OUTPUT)||(PinDirection==DIO_PIN_INPUT)))
	{
	switch(PortId)
	{
		case DIO_PORTA:
		switch(PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRA,PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRA,PinId);
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRB,PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRB,PinId);
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRC,PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRC,PinId);
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRD,PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRD,PinId);
			break;
		}
		break;
	} 
	}
	else
	{
		//Do Nothing
	}
}


void DIO_setPinValue(u8 PortId, u8 PinId, u8 PinValue)
{
	if((PortId<=3)&&(PinId<=7)&&((PinValue==DIO_PIN_HIGH)||(PinValue==DIO_PIN_LOW)))
	{
		switch(PortId)
	{
		case DIO_PORTA:
		switch(PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTA,PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTA,PinId);
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTB,PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTB,PinId);
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTC,PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTC,PinId);
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTD,PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTD,PinId);
			break;
		}
		break;
	}
	}
	else
	{
		//Do Nothing
	}
}


void DIO_getPinValue(u8 PortId, u8 PinId, u8* PinValue)
{
	if((PortId<=3)&&(PinId<=7)&&(PinValue!=NULL))
	{
		switch(PortId)
	{
		case DIO_PORTA:
		*PinValue = GET_BIT(PINA,PinId);
		break;
		
		case DIO_PORTB:
		*PinValue = GET_BIT(PINB,PinId);
		break;
		
		case DIO_PORTC:
		*PinValue = GET_BIT(PINC,PinId);
		break;
		
		case DIO_PORTD:
		*PinValue = GET_BIT(PIND,PinId);
		break;
	}
	}
	else
	{
		//Do Nothing
	}
}


void DIO_togglePinValue(u8 PortId, u8 PinId)
{
	if((PortId<=3) && (PinId<=7))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			TOG_BIT(PORTA,PinId);
			break;
			
			case DIO_PORTB:
			TOG_BIT(PORTB,PinId);
			break;
			
			case DIO_PORTC:
			TOG_BIT(PORTC,PinId);
			break;
			
			case DIO_PORTD:
			TOG_BIT(PORTD,PinId);
			break;
		}
	}
	else
	{
		//Do Nothing 
	}
}


void DIO_activePinInPullUpResistance(u8 PortId, u8 PinId)
{
	if((PortId<=3) && (PinId<=7))
	{
		switch(PortId)
		{
			case DIO_PORTA:
			SET_BIT(PORTA,PinId);
			break;
			
			case DIO_PORTB:
			SET_BIT(PORTB,PinId);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC,PinId);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD,PinId);
			break;
		}
	}
	else
	{
		//Do Nothing
	}
}