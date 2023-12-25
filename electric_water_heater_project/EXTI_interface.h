/*
 * EXTI_interface.h
 *
 * Created: 10/10/2023 9:48:52 PM
 *  Author: Kareem Hussein
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


/* Macros For Interrupt Source */
#define EXTI_INT0                     0     //PD2
#define EXTI_INT1                     1     //PD3
#define EXTI_INT2                     2     //PB2
	
/* Macros For Interrupt Trigger Edge */	
#define EXTI_RISING_EDGE              0
#define EXTI_FALLING_EDGE             1
#define EXTI_LOW_LEVEL                2
#define EXTI_ANY_LOGICAL_CHANGE       3


void EXTI_enable (u8 interruptSource, u8 interruptTriggerEdge);
void EXTI_disable(u8 interruptSource);
void INT0_setcallback(void(*ptrtofun0)(void));
void INT1_setcallback(void(*ptrtofun1)(void));
void INT2_setcallback(void(*ptrtofun2)(void));
void INT3_setcallback(void(*ptrtofun3)(void));


#endif /* EXTI_INTERFACE_H_ */