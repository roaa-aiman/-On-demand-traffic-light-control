/*
 * DIO.c
 *
 * Created: 1/31/2023 7:58:37 AM
 *  Author: lenovo
 */ 

#include "../../Utilities/register.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"

/* DIO file */
#include "DIO.h"



u8 MDIO_u8SetPortDirection( u8 copy_u8PortId , u8 copy_u8PortDirection)
{    u8 Local_u8ErorrState=OK;
	switch (copy_u8PortId )
	{
		case DIO_u8PORTA: if ( copy_u8PortDirection == DIO_u8PORT_OUTPUT)
		{
			DDRA_REG = 0XFF ;
		}
		else if ( copy_u8PortDirection == DIO_u8PORT_INPUT)
		{
			DDRA_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		case DIO_u8PORTB: if (  copy_u8PortDirection == DIO_u8PORT_OUTPUT)
		{
			DDRB_REG = 0XFF ;
		}
		else if ( copy_u8PortDirection == DIO_u8PORT_INPUT)
		{
			DDRB_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		case DIO_u8PORTC: if (  copy_u8PortDirection == DIO_u8PORT_OUTPUT)
		{
			DDRC_REG = 0XFF ;
		}
		else if ( copy_u8PortDirection == DIO_u8PORT_INPUT)
		{
			DDRC_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		case DIO_u8PORTD: if (  copy_u8PortDirection == DIO_u8PORT_OUTPUT)
		{
			DDRD_REG = 0XFF ;
		}
		else if (copy_u8PortDirection == DIO_u8PORT_INPUT                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       )
		{
			DDRD_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		default :  Local_u8ErorrState= NOK;/*invalid port id */ break ;
	}
	
	return Local_u8ErorrState;
	
}

u8 MDIO_voidSetPortValue( u8 copy_u8PortId , u8 copy_u8PortValue)
{u8 Local_u8ErorrState= OK;
	switch ( copy_u8PortId )
	{
		case DIO_u8PORTA: if (  copy_u8PortValue == DIO_u8PORT_HIGH )
		{
			PORTA_REG = 0XFF ;
		}
		else if ( copy_u8PortValue == DIO_u8PORT_LOW )
		{
			PORTA_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		case DIO_u8PORTB: if (  copy_u8PortValue == DIO_u8PORT_HIGH)
		{
			PORTB_REG = 0XFF ;
		}
		else if ( copy_u8PortValue == DIO_u8PORT_LOW )
		{
			PORTB_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		case DIO_u8PORTC: if (  copy_u8PortValue == DIO_u8PORT_HIGH)
		{
			PORTC_REG = 0XFF ;
		}
		else if (copy_u8PortValue == DIO_u8PORT_LOW )
		{
			PORTC_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		case DIO_u8PORTD: if (  copy_u8PortValue == DIO_u8PORT_HIGH)
		{
			PORTD_REG = 0XFF ;
		}
		else if ( copy_u8PortValue == DIO_u8PORT_LOW )
		{
			PORTD_REG = 0X00 ;
		}
		else
		{
			Local_u8ErorrState=NOK; 
		}
		break ;
		default : Local_u8ErorrState= NOK;
		/*invalid port id */ break ;
	}
	return Local_u8ErorrState;
}

u8 MDIO_u8SetPinDirection( u8 copy_u8PortId ,  u8 copy_u8PinId , u8 copy_u8PinDirection)
{
	u8 Local_u8ErorrState= OK;
	if ( copy_u8PinId<=DIO_u8PIN7)
	{
		switch ( copy_u8PortId)
		{
			case DIO_u8PORTA: if (  copy_u8PinDirection == DIO_u8PIN_OUTPUT)
			{
				SET_BIT( DDRA_REG ,  copy_u8PinId ) ;
			}
			else if ( copy_u8PinDirection == DIO_u8PIN_INPUT)
			{
				CLR_BIT( DDRA_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			case DIO_u8PORTB: if ( copy_u8PinDirection == DIO_u8PIN_OUTPUT)
			{
				SET_BIT( DDRB_REG ,  copy_u8PinId ) ;
			}
			else if (copy_u8PinDirection == DIO_u8PIN_INPUT)
			{
				CLR_BIT( DDRB_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			case DIO_u8PORTC: if (  copy_u8PinDirection == DIO_u8PIN_OUTPUT)
			{
				SET_BIT( DDRC_REG ,  copy_u8PinId ) ;
			}
			else if ( copy_u8PinDirection == DIO_u8PIN_INPUT)
			{
				CLR_BIT( DDRC_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			case DIO_u8PORTD: if (  copy_u8PinDirection == DIO_u8PIN_OUTPUT)
			{
				SET_BIT( DDRD_REG , copy_u8PinId ) ;
			}
			else if ( copy_u8PinDirection == DIO_u8PIN_INPUT)
			{
				CLR_BIT( DDRD_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			default : Local_u8ErorrState= NOK ;/*invalid port id */ break ;
		}
	}
	else
	{
		Local_u8ErorrState= NOK;
	}
	return  Local_u8ErorrState ;
}

u8 MDIO_u8SetPinValue( u8 copy_u8PortId, u8 copy_u8PinId , u8 copy_u8PinValue)
{
	u8 Local_u8ErorrState= OK;
	if ( copy_u8PinId<=DIO_u8PIN7)
	{
		switch ( copy_u8PortId)
		{
			case DIO_u8PORTA: if ( copy_u8PinValue ==  DIO_u8PIN_HIGH)
			{
				SET_BIT( PORTA_REG ,  copy_u8PinId ) ;
			}
			else if ( copy_u8PinValue == DIO_u8PIN_LOW )
			{
				CLR_BIT( PORTA_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			case DIO_u8PORTB: if (  copy_u8PinValue ==  DIO_u8PIN_HIGH)
			{
				SET_BIT( PORTB_REG ,  copy_u8PinId ) ;
			}
			else if ( copy_u8PinValue == DIO_u8PIN_LOW )
			{
				CLR_BIT( PORTB_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			case DIO_u8PORTC:  if ( copy_u8PinValue ==  DIO_u8PIN_HIGH)
			{
				SET_BIT( PORTC_REG ,  copy_u8PinId ) ;
			}
			else if (copy_u8PinValue  == DIO_u8PIN_LOW )
			{
				CLR_BIT( PORTC_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			case DIO_u8PORTD: if (  copy_u8PinValue ==  DIO_u8PIN_HIGH)
			{
				SET_BIT( PORTD_REG ,  copy_u8PinId ) ;
			}
			else if ( copy_u8PinValue == DIO_u8PIN_LOW )
			{
				CLR_BIT( PORTD_REG ,  copy_u8PinId ) ;
			}
			else
			{
				Local_u8ErorrState=NOK; 
			}
			break ;
			default : Local_u8ErorrState=NOK; /*invalid port id */ break ;
		}
	}
	else
	{
		Local_u8ErorrState=NOK;
	}
	return  Local_u8ErorrState ;
	
}


u8 MDIO_u8TogPinValue( u8 copy_u8PortId, u8 copy_u8PinId )
{ u8 Local_u8ErorrState= OK;
	switch ( copy_u8PortId)
	{
		case DIO_u8PORTA: TOG_BIT( PORTA_REG ,  copy_u8PinId  );
		break ;
		case DIO_u8PORTB: TOG_BIT( PORTB_REG ,  copy_u8PinId  );
		break ;
		case DIO_u8PORTC:  TOG_BIT( PORTC_REG , copy_u8PinId  );
		break ;
		case DIO_u8PORTD: TOG_BIT( PORTD_REG ,  copy_u8PinId  );
		break ;
		default :  Local_u8ErorrState= NOK;/*invalid port id */ break ;
	}
	return  Local_u8ErorrState ;
}

u8  MDIO_u8GetPinValue( u8 copy_u8PortId, u8 copy_u8PinId )
{
	u8 Local_u8PinState= OK ;
	switch ( copy_u8PortId)
	{
		case DIO_u8PORTA:  Local_u8PinState = GET_BIT( PINA_REG ,  copy_u8PinId );
		break ;
		case DIO_u8PORTB: Local_u8PinState = GET_BIT( PINB_REG ,  copy_u8PinId );
		break ;
		case DIO_u8PORTC:  Local_u8PinState = GET_BIT( PINC_REG ,  copy_u8PinId );
		break ;
		case DIO_u8PORTD: Local_u8PinState = GET_BIT( PIND_REG ,  copy_u8PinId );
		break ;
		default : Local_u8PinState= NOK;/*invalid port id */ break ;
		
	}
	return Local_u8PinState ;
}

