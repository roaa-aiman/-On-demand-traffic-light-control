/*
 * EXTI.h
 *
 * Created: 1/31/2023 9:29:06 AM
 *  Author: lenovo
 */ 


#ifndef EXTI_H_
#define EXTI_H_

#define INT0_SENS     FALLING_EDGE
#define INTO_INITIAL_STATE  ENABLED

#define LOW_LEVEL     1
#define ON_CHANGE     2
#define FALLING_EDGE  3
#define RISING_EDGE   4

#define ENABLED       1
#define DISABLED      2

u8 M_EXTI_voidInt0Init(void);


#endif /* EXTI_H_ */