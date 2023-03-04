/*
 * GIE.c
 *
 * Created: 2/3/2023 8:22:04 AM
 *  Author: lenovo
 */ 

#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"


#include "GIE.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,SREG_I);
}