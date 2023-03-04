/*
 * register.h
 *
 * Created: 1/31/2023 6:13:51 AM
 *  Author: ROAA AIMAN 
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
// DIO REGISTER
#define PORTA_REG *((volatile u8*) 0x3B)
#define DDRA_REG *((volatile u8*) 0x3A)
#define PINA_REG *((volatile u8*) 0x39)

#define PORTB_REG *((volatile u8*) 0x38)
#define DDRB_REG *((volatile u8*) 0x37)
#define PINB_REG *((volatile u8*) 0x36)

#define PORTC_REG *((volatile u8*) 0x35)
#define DDRC_REG *((volatile u8*) 0x34)
#define PINC_REG *((volatile u8*) 0x33)

#define PORTD_REG *((volatile u8*) 0x32)
#define DDRD_REG *((volatile u8*) 0x31)
#define PIND_REG *((volatile u8*) 0x30)

//INTERRPUT REGISTER
#define GICR	 		*((volatile u8*)0x5B) //general interrupt control (SIE)
#define GICR_INT0		6 //INT 0

#define GIFR		 	*((volatile u8*)0x5A)  //general interrupt flag (PIF)(read only)

#define MCUCR		 	*((volatile u8*)0x55) // CONTROL REGISTER

#define MCUCR_ISC01		1//INT0
#define MCUCR_ISC00		0//INT0

#define SREG		*((volatile u8*)0x5F)
#define SREG_I		7

/*Timer/Counter Control Register*/
#define	TCCR0			*((volatile u8*) 0x53) //timer0 control register
#define	TCCR0_CS00		0     // prescaler bit0
#define	TCCR0_CS01		1     // prescaler bit1
#define	TCCR0_CS02		2     // prescaler bit2
#define	TCCR0_WGM01		3    //waveform generation mode bit1
#define	TCCR0_WGM00		6  //waveform generation mode bit0

/*Timer/Counter Register*/
#define	TCNT0		*((volatile u8*) 0x52)

/*Timer/Counter Interrupt Mask Register*/
#define	TIMSK		*((volatile u8*) 0x59)
#define	TIMSK_OCIE0		1
#define	TIMSK_TOIE0		0


/*Timer/Counter Interrupt Flag Register*/
#define	TIFR		*((volatile u8*) 0x58)
#define	TIFR_OCF0		1	/* Timer/Counter0 Output Compare Match Interrupt Enable*/
#define	TIFR_TOV0		0	/*Timer/Counter0 Overflow Interrupt Enable*/






#endif /* REGISTER_H_ */