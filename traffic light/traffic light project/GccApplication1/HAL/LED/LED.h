/*
 * LED.h
 *
 * Created: 1/31/2023 8:01:52 AM
 *  Author: lenovo
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../Utilities/register.h"
#include "../../MCAL/DIO/DIO.h"


#define H_LED_LEDID_LED0   0
#define H_LED_LEDID_LED1   1
#define H_LED_LEDID_LED2   2
#define H_LED_LEDID_LED3   3
#define H_LED_LEDID_LED4   4
#define H_LED_LEDID_LED5   5
#define H_LED_LEDID_LED6   6
#define H_LED_LEDID_LED7   7

#define LED0	 DIO_u8PIN0
#define LED1	 DIO_u8PIN1
#define LED2	 DIO_u8PIN2
#define LED3	 DIO_u8PIN3
#define LED4	 DIO_u8PIN4
#define LED5	 DIO_u8PIN5
#define LED6	 DIO_u8PIN6
#define LED7	 DIO_u8PIN7

#define LED_CAR_PORT    DIO_u8PORTA
#define LED_PED_PORT    DIO_u8PORTB

/* 
 * Public Function Prototype 
 */

u8 H_LED_void_Init   ( u8 copy_u8PortId  ,u8 copy_u8_LedID);

u8 H_LED_void_TurnOn ( u8 copy_u8PortId  ,u8 copy_u8_LedID);

u8 H_LED_void_TurnOff( u8 copy_u8PortId  ,u8 copy_u8_LedID);

u8 H_LED_void_Toggle ( u8 copy_u8PortId  ,u8 copy_u8_LedID);






#endif /* LED_H_ */