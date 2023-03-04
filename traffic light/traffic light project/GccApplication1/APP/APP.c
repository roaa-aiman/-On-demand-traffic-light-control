/*
 * APP.c
 *
 * Created: 1/31/2023 10:24:19 AM
 *  Author: lenovo
 */ 
#include "../Utilities/register.h"
#include "../Utilities/BIT_MATH.h"
#include "../Utilities/STD_TYPES.h"


#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/Timer/Timer.h"

#include "../HAL/LED/LED.h"
#include "../HAL/Button/Button.h"

#include "APP.h"
#include "avr/interrupt.h"
#include <avr/wdt.h>
u8 car_red_flag = 0 ;
u8 car_green_flag = 0 ;
u8 car_yellow_flag = 0 ;

void APP_INT (void)
{
	// car leds initialization
	H_LED_void_Init( LED_CAR_PORT , H_LED_LEDID_LED0);
	H_LED_void_Init( LED_CAR_PORT , H_LED_LEDID_LED1);
	H_LED_void_Init( LED_CAR_PORT, H_LED_LEDID_LED2);
	// pedestrian leds initialization
	H_LED_void_Init( LED_PED_PORT , H_LED_LEDID_LED0);
	H_LED_void_Init( LED_PED_PORT , H_LED_LEDID_LED1);
	H_LED_void_Init( LED_PED_PORT , H_LED_LEDID_LED2);
	
	//INTRUPT INTIALIZATION
	M_EXTI_voidInt0Init();
	GIE_voidEnable();
	
	//BUTTON LED INTIALIZATION
	H_BTN_void_Init( H_BTN_BTNID_BTN2) ;
	H_BTN_u8_SetBtnVal( H_BTN_BTNID_BTN2);
	
	//TIMER INTIALIZATION
	MTIMER0_voidInitialize();
}

void APP_start(void)
{

	car_green_flag = 1;
	H_LED_void_TurnOn(LED_CAR_PORT , H_LED_LEDID_LED0);
	MTIMER0_delay(5);
	H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED0);
	car_green_flag = 0;

	car_yellow_flag = 1 ;
	for (u8 i=0 ; i <= 4 ; i++)
	{
		H_LED_void_Toggle (LED_CAR_PORT , H_LED_LEDID_LED1);
		MTIMER0_delay(1);
	
	}
	H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED1);
	car_yellow_flag = 0 ;

	car_red_flag = 1 ;
	H_LED_void_TurnOn(LED_CAR_PORT , H_LED_LEDID_LED2);
	MTIMER0_delay(5);
	H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED2);
	car_red_flag = 0 ;
	
	car_yellow_flag = 1 ;
	for (u8 i=0 ; i <= 4; i++)
	{
		H_LED_void_Toggle (LED_CAR_PORT , H_LED_LEDID_LED1);
		MTIMER0_delay(1);
	}
	H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED1);
	car_yellow_flag = 0 ;
}


ISR (INT0_vect)
{
	
	if (car_red_flag == 1)
	{


		H_LED_void_TurnOn(LED_PED_PORT , H_LED_LEDID_LED0);
		H_LED_void_TurnOn(LED_CAR_PORT , H_LED_LEDID_LED2);
		MTIMER0_delay(5);
		
		
	}
	
	else if (car_green_flag == 1 || car_yellow_flag == 1 )
	{
		H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED0);
		H_LED_void_TurnOn(LED_PED_PORT , H_LED_LEDID_LED2);
		
		H_LED_void_TurnOff (LED_CAR_PORT , H_LED_LEDID_LED1);
		
		for (u8 i=0 ; i <= 4 ; i++)
	{
		H_LED_void_Toggle (LED_CAR_PORT , H_LED_LEDID_LED1);
		H_LED_void_Toggle (LED_PED_PORT , H_LED_LEDID_LED1);
		MTIMER0_delay(1);
	
	}
	H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED1);
	H_LED_void_TurnOff(LED_PED_PORT, H_LED_LEDID_LED1);
	
		H_LED_void_TurnOff(LED_PED_PORT , H_LED_LEDID_LED2);
		H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED0);
		
		H_LED_void_TurnOn(LED_PED_PORT , H_LED_LEDID_LED0);
		H_LED_void_TurnOn(LED_CAR_PORT , H_LED_LEDID_LED2);
		MTIMER0_delay(5);
		
	}
	
	H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED2);
	
	for (u8 i=0 ; i <= 4 ; i++)
	{
		H_LED_void_Toggle (LED_CAR_PORT , H_LED_LEDID_LED1);
		H_LED_void_Toggle (LED_PED_PORT , H_LED_LEDID_LED1);
		MTIMER0_delay(1);
		
	}
	H_LED_void_TurnOff(LED_CAR_PORT , H_LED_LEDID_LED1);
	H_LED_void_TurnOff(LED_PED_PORT, H_LED_LEDID_LED1);
	
	H_LED_void_TurnOff(LED_PED_PORT , H_LED_LEDID_LED0);
	
	
	H_LED_void_TurnOn(LED_PED_PORT , H_LED_LEDID_LED2);
	H_LED_void_TurnOn(LED_CAR_PORT , H_LED_LEDID_LED0);
	MTIMER0_delay(5);
	
	H_LED_void_TurnOff(LED_PED_PORT , H_LED_LEDID_LED0);
	H_LED_void_TurnOff(LED_PED_PORT , H_LED_LEDID_LED1);
	H_LED_void_TurnOff(LED_PED_PORT , H_LED_LEDID_LED2);
	wdt_enable(WDTO_15MS);

}