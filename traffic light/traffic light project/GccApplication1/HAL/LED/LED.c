/*
 * LED.c
 *
 * Created: 1/31/2023 8:02:38 AM
 *  Author: lenovo
 */ 
#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
 
	/* DIO file */
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/EXTI/EXTI.h"
#include "../../MCAL/GIE/GIE.h"
#include "../../MCAL/Timer/Timer.h"


	/* LED files */
#include "LED.h"


/* 
 * Public Function Prototype 
 */

u8 H_LED_void_Init( u8 copy_u8PortId  , u8 copy_u8_LedID){
	u8 local_u8_BtnVal = OK;
	switch(copy_u8_LedID){
		case H_LED_LEDID_LED0:
		MDIO_u8SetPinDirection( copy_u8PortId , LED0 , DIO_u8PORT_OUTPUT) ;
		break;
		case H_LED_LEDID_LED1:
		MDIO_u8SetPinDirection( copy_u8PortId , LED1 , DIO_u8PORT_OUTPUT) ;
		break;
		case H_LED_LEDID_LED2:
		MDIO_u8SetPinDirection( copy_u8PortId , LED2 , DIO_u8PORT_OUTPUT) ;
		break;
		case H_LED_LEDID_LED3:
		MDIO_u8SetPinDirection( copy_u8PortId , LED3 , DIO_u8PORT_OUTPUT) ;
		break;
		case H_LED_LEDID_LED4:
		MDIO_u8SetPinDirection( copy_u8PortId , LED4 , DIO_u8PORT_OUTPUT) ;
		break;
		case H_LED_LEDID_LED5:
		MDIO_u8SetPinDirection( copy_u8PortId , LED5 , DIO_u8PORT_OUTPUT) ;
		break;
		case H_LED_LEDID_LED6:
		MDIO_u8SetPinDirection( copy_u8PortId , LED6 , DIO_u8PORT_OUTPUT) ;
		break;
		case H_LED_LEDID_LED7:
		MDIO_u8SetPinDirection( copy_u8PortId , LED7 , DIO_u8PORT_OUTPUT) ;
		break;
		default:local_u8_BtnVal = NOK;/* Wrong LED ID */
		break;
	}
	return local_u8_BtnVal;
}

u8 H_LED_void_TurnOn(u8 copy_u8PortId  ,u8 copy_u8_LedID){
	u8 local_u8_BtnVal = OK;
	switch(copy_u8_LedID){
		case H_LED_LEDID_LED0:
		MDIO_u8SetPinValue( copy_u8PortId, LED0 , DIO_u8PIN_HIGH) ;
		break;
		case H_LED_LEDID_LED1:
		MDIO_u8SetPinValue( copy_u8PortId, LED1 , DIO_u8PIN_HIGH) ;
		break;
		case H_LED_LEDID_LED2:
		MDIO_u8SetPinValue( copy_u8PortId, LED2 , DIO_u8PIN_HIGH) ;
		break;
		case H_LED_LEDID_LED3:
		MDIO_u8SetPinValue( copy_u8PortId, LED3 , DIO_u8PIN_HIGH) ;
		break;
		case H_LED_LEDID_LED4:
		MDIO_u8SetPinValue( copy_u8PortId, LED4 , DIO_u8PIN_HIGH) ;
		break;
		case H_LED_LEDID_LED5:
		MDIO_u8SetPinValue( copy_u8PortId, LED5 , DIO_u8PIN_HIGH) ;
		break;
		case H_LED_LEDID_LED6:
		MDIO_u8SetPinValue( copy_u8PortId, LED6 , DIO_u8PIN_HIGH) ;
		break;
		case H_LED_LEDID_LED7:
		MDIO_u8SetPinValue( copy_u8PortId, LED7 , DIO_u8PIN_HIGH) ;
		break;
		default: local_u8_BtnVal = NOK;/* Wrong LED ID */
		break;
	}
	return local_u8_BtnVal;
}

u8 H_LED_void_TurnOff(u8 copy_u8PortId , u8 copy_u8_LedID){
	u8 local_u8_BtnVal = OK;
	switch(copy_u8_LedID){
		case H_LED_LEDID_LED0:
		MDIO_u8SetPinValue( copy_u8PortId, LED0 , DIO_u8PIN_LOW);
		break;
		case H_LED_LEDID_LED1:
		MDIO_u8SetPinValue( copy_u8PortId, LED1 , DIO_u8PIN_LOW);
		break;
		case H_LED_LEDID_LED2:
		MDIO_u8SetPinValue( copy_u8PortId, LED2 , DIO_u8PIN_LOW);
		break;
		case H_LED_LEDID_LED3:
		MDIO_u8SetPinValue( copy_u8PortId, LED3 , DIO_u8PIN_LOW);
		break;
		case H_LED_LEDID_LED4:
		MDIO_u8SetPinValue( copy_u8PortId, LED4 , DIO_u8PIN_LOW);
		break;
		case H_LED_LEDID_LED5:
		MDIO_u8SetPinValue( copy_u8PortId, LED5 , DIO_u8PIN_LOW);
		break;
		case H_LED_LEDID_LED6:
		MDIO_u8SetPinValue( copy_u8PortId, LED6 , DIO_u8PIN_LOW);
		break;
		case H_LED_LEDID_LED7:
		MDIO_u8SetPinValue( copy_u8PortId, LED7 , DIO_u8PIN_LOW);
		break;
		default: local_u8_BtnVal = NOK;/* Wrong LED ID */
		break;
	}
	return local_u8_BtnVal;
}

u8 H_LED_void_Toggle (u8 copy_u8PortId , u8 copy_u8_LedID){
	u8 local_u8_BtnVal = OK;
	switch(copy_u8_LedID){
		case H_LED_LEDID_LED0:
		MDIO_u8TogPinValue( copy_u8PortId, LED0); break;
		case H_LED_LEDID_LED1:
		MDIO_u8TogPinValue( copy_u8PortId, LED1); break;
		case H_LED_LEDID_LED2:
		MDIO_u8TogPinValue( copy_u8PortId, LED2); break;
		case H_LED_LEDID_LED3:
		MDIO_u8TogPinValue( copy_u8PortId, LED3); break;
		case H_LED_LEDID_LED4:
		MDIO_u8TogPinValue( copy_u8PortId, LED4); break;
		case H_LED_LEDID_LED5:
		MDIO_u8TogPinValue( copy_u8PortId, LED5); break;
		case H_LED_LEDID_LED6:
		MDIO_u8TogPinValue( copy_u8PortId, LED6); break;
		case H_LED_LEDID_LED7:
		MDIO_u8TogPinValue( copy_u8PortId, LED7); break;
		default:local_u8_BtnVal = NOK;/* Wrong LED ID */
		break;
	}
	return local_u8_BtnVal;
}

