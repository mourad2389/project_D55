/*
 * GI_program.c
 *
 * Created: 10/10/2023 10:50:13 PM
 *  Author: Kareem Hussein
 */ 


/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GI_interface.h"
#include "GI_private.h"


void GI_enable(void)
{
	SET_BIT(SREG,I);
}


void GI_disable(void)
{
	CLR_BIT(SREG,I);
}