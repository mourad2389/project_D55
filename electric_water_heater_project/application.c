/*
 * application.c
 *
 * Created: 15/12/2023 1:17:02 AM
 *  Author: Morad
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "ADC_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "GI_interface.h"
#include "LCD_interface.h"
#include "led_interface.h"
#include "EEPROM_interface.h"

void setting_mode_ON (void)
{
		u16 digital_value , analog_value ;
		u8 temp ,set_temp ,heatingmode_temp,coolingmode_temp ;

}
	
