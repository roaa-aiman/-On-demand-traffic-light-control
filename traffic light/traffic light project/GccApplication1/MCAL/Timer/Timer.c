/*
 * Timer.c
 *
 * Created: 1/31/2023 8:07:53 AM
 *  Author: lenovo
 */ 
#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"

/* TIMER files */
#include "Timer.h"
#include <math.h>


u8 MTIMER0_voidInitialize(void)
{
	/*Select Timer0 Mode*/
	u8 Local_u8ErorrState=OK;

	#if TIMER0_MODE == TIMER0_NORMAL_MODE
	CLR_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);


	#elif TIMER0_MODE == TIMER0_PWM_MODE
	SET_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);

	#elif TIMER0_MODE == TIMER0_CTC_MODE
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	
	#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
	SET_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	#else
	//error
	#endif
	
	/*Enable Mode of Interrupt*/
	#if TIMER0_INTERRUPT_ENABLE == TIMER0_COMPAR_MATCH_INTERRUPT_ENABLE
	SET_BIT(TIMSK, TIMSK_OCIE0);
	#elif TIMER0_INTERRUPT_ENABLE == TIMER0_OVERFLOW_INTERRUPT_ENABLE
	SET_BIT(TIMSK, TIMSK_TOIE0);

	#else
	//error
	Local_u8ErorrState= NOK;
	#endif
	return Local_u8ErorrState;

}

u8 MTIMER0_START(void)
{
	u8 Local_u8ErorrState=OK;
	/*Select Clock Prescaler*/
	#if TIMER0_SELECT_CLK == TIMER0_NO_CLK
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_NO_PRESCALER
	SET_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_8
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_64
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);


	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_256
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_1024
	SET_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_ON_FALLING_EDGE
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_ON_RISING_EDGE
	SET_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);
	#else
	//error
	Local_u8ErorrState= NOK;
	#endif
	return Local_u8ErorrState;

}

u8 MTIMER0_STOP(void)
{
	u8 Local_u8ErorrState=OK;
	#if TIMER0_SELECT_CLK == TIMER0_NO_CLK
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_NO_PRESCALER
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_8
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_64
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);


	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_256
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_DIVIDED_BY_1024
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_ON_FALLING_EDGE
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	#elif TIMER0_SELECT_CLK == TIMER0_CLK_ON_RISING_EDGE
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
	#else
	//error
	Local_u8ErorrState= NOK;
	#endif
	return Local_u8ErorrState;

}
// ALL CALCULATION FOR 1M AND NO PRESCALER

u8 MTIMER0_delay(u32 desired_time)
{
	u8 Local_u8ErorrState=OK;
	f64 Tmax_delay = 0.000256; //Ttick  * 2^(8)
	f64 Ttick = ( 1/1000000);
	u32 NUMBER_OF_OVERFLOWS ;
	u32 intial_value ;
	u32  overflowcounter = 0 ;

	if (desired_time == Tmax_delay)
	{
		intial_value = 0 ;
		NUMBER_OF_OVERFLOWS = 1;
		
	}

	else if (desired_time < Tmax_delay)
	{
		intial_value = (Tmax_delay-desired_time) /Ttick  ;
		NUMBER_OF_OVERFLOWS = 1;
		
	}

	else if (desired_time > Tmax_delay)
	{
		NUMBER_OF_OVERFLOWS = ceil (desired_time / Tmax_delay);
		intial_value = 256 - ((desired_time/Ttick )/NUMBER_OF_OVERFLOWS) ;
		
	}

	else
	{
		Local_u8ErorrState= NOK;
	}
	TCNT0 = intial_value  ;
	MTIMER0_START();
	while (overflowcounter < NUMBER_OF_OVERFLOWS )
	{
		while(GET_BIT(TIFR, TIFR_TOV0) == 0);// wait till the timer overflow flag is SET
		
		SET_BIT(TIFR, TIFR_TOV0); //clear timer1 overflow flag
		overflowcounter ++ ;

	}

	overflowcounter = 0  ;
	TCNT0 = 0x00;
	MTIMER0_STOP();
	
	return Local_u8ErorrState;
}