/*
 * DIO.h
 *
 * Created: 1/31/2023 7:59:33 AM
 *  Author: lenovo
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/register.h"

/* user interface DIRECTION */
#define DIO_u8PIN_OUTPUT  1
#define DIO_u8PIN_INPUT   0

#define DIO_u8PORT_OUTPUT  	1
#define DIO_u8PORT_INPUT   0

/* user interface VALUE */
#define DIO_u8PIN_HIGH  1
#define DIO_u8PIN_LOW   0

#define DIO_u8PORT_HIGH  1
#define DIO_u8PORT_LOW   0

/* user interface ports */
#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3
/* user interface PINS */
#define DIO_u8PIN0  0
#define DIO_u8PIN1  1
#define DIO_u8PIN2  2
#define DIO_u8PIN3  3
#define DIO_u8PIN4  4
#define DIO_u8PIN5  5
#define DIO_u8PIN6  6
#define DIO_u8PIN7  7
/* PORT FUNCTIONS */
u8 MDIO_u8SetPortDirection( u8 copy_u8PortId , u8 copy_u8PortDirection);
u8 MDIO_u8SetPortValue( u8 copy_u8PortId , u8 copy_u8PortValue);
/* PIN FUNCTIONS */
u8 MDIO_u8SetPinDirection( u8 copy_u8PortId , u8 copy_u8PinId , u8 copy_u8PinDirection);
u8 MDIO_u8SetPinValue( u8 copy_u8PortId, u8 copy_u8PinId , u8 copy_u8PinValue);
u8 MDIO_u8TogPinValue( u8 copy_u8PortId, u8 copy_u8PinId );
u8 MDIO_u8GetPinValue( u8 copy_u8PortId, u8 copy_u8PinId );



#endif /* DIO_H_ */