/*
 * EXTI_program.c
 *
 * Created: 10/10/2023 9:48:41 PM
 *  Author: Kareem Hussein
 */ 

#define F_CPU 16000000UL
#include <util/delay.h> 
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "EXTI_interface.h"
#include "EXTI_private.h"



void EXTI_enable(u8 interruptSource, u8 interruptTriggerEdge)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
		}
		SET_BIT(GICR,INT0); //Enable INT0
		break;
		
		case EXTI_INT1:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case EXTI_ANY_LOGICAL_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
		}
		SET_BIT(GICR,INT1); //Enable INT1
		break;
		
		case EXTI_INT2:
		switch(interruptTriggerEdge)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR,ISC2);
			break;
		}
		SET_BIT(GICR,INT2); //Enable INT2
		break;
	}
}


void EXTI_disable(u8 interruptSource)
{
	switch(interruptSource)
	{
		case EXTI_INT0:
		CLR_BIT(GICR,INT0); //Disable INT0
		break;
		
		case EXTI_INT1:
		CLR_BIT(GICR,INT1); //Disable INT1
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR,INT2); //Disable INT2
		break;
	}
}

static void (*private_pcallback0)(void) = NULL ;
static void (*private_pcallback1)(void) = NULL ;
static void (*private_pcallback2)(void) = NULL ;
static void (*private_pcallback3)(void) = NULL ;


void INT0_setcallback (void(*ptrtofun0)(void))
{
	if(ptrtofun0!=NULL)
	{
		private_pcallback0 = ptrtofun0;
	}
}
void INT1_setcallback (void(*ptrtofun1)(void))
{
	if(ptrtofun1!=NULL)
	{
		private_pcallback1 = ptrtofun1;
	}
}
void INT2_setcallback (void(*ptrtofun2)(void))
{
	if(ptrtofun2!=NULL)
	{
		private_pcallback2 = ptrtofun2;
	}
}

void INT3_setcallback (void(*ptrtofun3)(void))
{
	if(ptrtofun3!=NULL)
	{
		private_pcallback3 = ptrtofun3;
	}
}
void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	static u8 counter = 0 ;
	counter ++ ;
	switch (counter)
	{
		case 1 :
	{
			private_pcallback0();
	}	
		break ;
		case 2 : 
	{
			private_pcallback1();
			counter = 0;
	}	
		break ;
	}
}
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	static u8 counter = 0 ;
	counter ++ ;
	if (private_pcallback2!=NULL)
	{
		private_pcallback2();
	}
}

void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	static u8 counter = 0 ;
	counter ++ ;
	
	if (private_pcallback3!=NULL)
	{
		private_pcallback3();
	}
}
