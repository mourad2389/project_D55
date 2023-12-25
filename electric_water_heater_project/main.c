/*
 * electric_water_heater_project.c
 *
 * Created: 09/12/2023 8:53:10 PM
 * Author : Mourad
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

void button_OFF(void);
void button_ON (void);
void rise_set_temp (void);
void lower_set_temp (void);
	 


int main(void)
{
    // set DIO directions
	DIO_setPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_INPUT);   //ADC
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);  // red led
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);  // cooling
	DIO_setPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);  // heating  
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);   //INT0
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);   //INT1
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);   //INT2
   
	
	// initialize peripherals
	ADC_init(ADC_REFERENCE_INTERNAL);
	 LCD_init();
	 EEPROM_init();
	 
	 GI_enable();
	 INT0_setcallback(&button_OFF);
	 INT1_setcallback(&button_ON);
	 INT2_setcallback(&rise_set_temp);
	 INT3_setcallback(&lower_set_temp);
	 EXTI_enable(EXTI_INT0,EXTI_RISING_EDGE);
	 EXTI_enable(EXTI_INT1,EXTI_RISING_EDGE);
	 EXTI_enable(EXTI_INT2,EXTI_RISING_EDGE);
	 
	 u8 heatingmode_temp,coolingmode_temp;
	 u16 digital_value;
	 u16 analog_value;
	 	 u8  set_temp ;
	     u16 temp;
		EEPROM_writeByte(100,40);
		EEPROM_readByte(100,&set_temp);
		heatingmode_temp=set_temp - 5;
		coolingmode_temp=set_temp + 5 ;
	 
    while (1) 
{

        ADC_getDigitalValue(ADC_CHANNEL0,&digital_value);
			
	                    analog_value= ((u32)digital_value*2560)/1024 ;
	                    temp= analog_value/10 ;

     LCD_writeNumber(temp);
        _delay_ms(1000);
        LCD_clear();

if(temp < heatingmode_temp)
{
	DIO_setPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH); // run heater
	DIO_togglePinValue(DIO_PORTC,DIO_PIN2);  // red light blinking ( heating mode is active )
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW); // cooling off
}
else if(temp>coolingmode_temp)
{
	DIO_setPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH); // cooling ON
	DIO_setPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW); // red light off ( heating mode is not active )
	DIO_setPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW); // heater motor off
}
}
}

void button_OFF (void)
{
		// deactivate peripherals

}

void button_ON (void)
{
		// activate peripherals

}
void rise_set_temp (void)
{

	// set_temp =set_temp+5;
	// while ( set_temp <75 ) run program
}
void lower_set_temp (void)
{
		// set_temp =set_temp-5;
			// while ( set_temp > 35 ) run program


}