/*
 * Button.c
 *
 * Created: 1/31/2023 9:20:36 AM
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

/* Button files */
#include "Button.h"

u8 H_BTN_void_Init(u8 copy_u8_BtnID){
	u8 local_u8_BtnVal = OK;
	switch (copy_u8_BtnID)
	{
		case H_BTN_BTNID_BTN0:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN0 , DIO_u8PORT_INPUT);
		break;
		case H_BTN_BTNID_BTN1:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN1 , DIO_u8PORT_INPUT);
		break;
		case H_BTN_BTNID_BTN2:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN2 , DIO_u8PORT_INPUT);
		break;
		case H_BTN_BTNID_BTN3:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN3 , DIO_u8PORT_INPUT);
		break;
		case H_BTN_BTNID_BTN4:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN4 , DIO_u8PORT_INPUT);
		break;
		case H_BTN_BTNID_BTN5:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN5 , DIO_u8PORT_INPUT);
		break;
		case H_BTN_BTNID_BTN6:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN6 , DIO_u8PORT_INPUT);
		break;
		case H_BTN_BTNID_BTN7:
		MDIO_u8SetPinDirection( BTNS_PORT ,  BTN7 , DIO_u8PORT_INPUT);
		break;
		default:  local_u8_BtnVal = NOK; /* Wrong Button ID */ break;
	}
	return local_u8_BtnVal;
}
u8  H_BTN_u8_SetBtnVal(u8 copy_u8_BtnID){
	u8 local_u8_BtnVal = OK;
	switch (copy_u8_BtnID)
	{
		case H_BTN_BTNID_BTN0:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN0 , DIO_u8PORT_HIGH);
		break;
		case H_BTN_BTNID_BTN1:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN1 ,  DIO_u8PORT_HIGH);
		break;
		case H_BTN_BTNID_BTN2:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN2 ,  DIO_u8PORT_HIGH);
		break;
		case H_BTN_BTNID_BTN3:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN3 ,  DIO_u8PORT_HIGH);
		break;
		case H_BTN_BTNID_BTN4:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN4 ,  DIO_u8PORT_HIGH);
		break;
		case H_BTN_BTNID_BTN5:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN5 , DIO_u8PORT_HIGH);
		break;
		case H_BTN_BTNID_BTN6:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN6 ,  DIO_u8PORT_HIGH);
		break;
		case H_BTN_BTNID_BTN7:
		MDIO_u8SetPinValue( BTNS_PORT ,  BTN7 ,  DIO_u8PORT_HIGH);
		break;
		default: local_u8_BtnVal = NOK;/* Wrong Button ID */ break;
	}
	return local_u8_BtnVal;
}

u8   H_BTN_u8_GetBtnVal(u8 copy_u8_BtnID){
	u8 local_u8_BtnVal = OK;
	switch (copy_u8_BtnID)
	{
		case H_BTN_BTNID_BTN0:
		local_u8_BtnVal = MDIO_u8GetPinValue( BTNS_PORT, BTN0);
		break;
		case H_BTN_BTNID_BTN1:
		local_u8_BtnVal =  MDIO_u8GetPinValue( BTNS_PORT, BTN1);
		break;
		case H_BTN_BTNID_BTN2:
		local_u8_BtnVal =  MDIO_u8GetPinValue( BTNS_PORT, BTN2);
		break;
		case H_BTN_BTNID_BTN3:
		local_u8_BtnVal =  MDIO_u8GetPinValue( BTNS_PORT, BTN3);
		break;
		case H_BTN_BTNID_BTN4:
		local_u8_BtnVal =  MDIO_u8GetPinValue( BTNS_PORT, BTN4);
		break;
		case H_BTN_BTNID_BTN5:
		local_u8_BtnVal =  MDIO_u8GetPinValue( BTNS_PORT, BTN5);
		break;
		case H_BTN_BTNID_BTN6:
		local_u8_BtnVal =  MDIO_u8GetPinValue( BTNS_PORT, BTN6);
		break;
		case H_BTN_BTNID_BTN7:
		local_u8_BtnVal = MDIO_u8GetPinValue( BTNS_PORT, BTN7);
		break;
		default:  local_u8_BtnVal = NOK; /* Wrong Button ID */ break;
	}
	return local_u8_BtnVal;
}



  
  