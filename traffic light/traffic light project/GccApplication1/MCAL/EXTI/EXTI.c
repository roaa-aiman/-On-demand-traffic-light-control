/*
 * EXTI.c
 *
 * Created: 1/31/2023 9:28:46 AM
 *  Author: lenovo
 */ 
#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"

/* EXTI files */
#include "EXTI.h"

u8  M_EXTI_voidInt0Init(void)
{
	/*Check sense control*/
	
	u8 Local_u8ErorrState=OK; 
	
	#if INT0_SENS == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
	
	#elif  INT0_SENS == ON_CHANGE 
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
	
	#elif  INT0_SENS == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
	
	#elif  INT0_SENS == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
	
	#else
	#error "wrong INT0_SENSE configuration option"
    Local_u8ErorrState= NOK;
	#endif
	

	/* CHECK Peripheral interrupt enable for INT0*/
	#if INTO_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
	#elif INTO_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
	#else
	#error  " wrong INTO_INITIAL_STATE configration "
    Local_u8ErorrState= NOK;
	#endif
	
	return Local_u8ErorrState;
	
}

