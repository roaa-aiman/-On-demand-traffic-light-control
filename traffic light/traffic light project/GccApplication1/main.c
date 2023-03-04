/*
 * GccApplication1.c
 *
 * Created: 1/31/2023 6:08:36 AM
 * Author : ROAA AIMAN 
 */ 
#include "Utilities/register.h"
#include "Utilities/BIT_MATH.h"
#include "Utilities/STD_TYPES.h"


#include "MCAL/DIO/DIO.h"
#include "MCAL/EXTI/EXTI.h"
#include "MCAL/Timer/Timer.h"

#include "HAL/LED/LED.h"
#include "HAL/Button/Button.h"

#include "APP/APP.h"

#include <math.h>
#include "avr/interrupt.h"
int main(void)
{
	
	MDIO_u8SetPinDirection(  DIO_u8PORTD,  DIO_u8PIN2, DIO_u8PIN_INPUT);
	MDIO_u8SetPinValue(DIO_u8PORTD,  DIO_u8PIN2, DIO_u8PIN_HIGH);
	
	MDIO_u8SetPinDirection(  DIO_u8PORTA,  DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	
	

	APP_INT ();
	
    /* Replace with your application code */
    while (1) 
    {
	
APP_start() ;
	 
	
    }
}
