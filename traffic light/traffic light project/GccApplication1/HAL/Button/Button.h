/*
 * Button.h
 *
 * Created: 1/31/2023 9:20:17 AM
 *  Author: lenovo
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

/* Configuration parameters for buttons connection */
#define BTNS_PORT  DIO_u8PORTD

#define BTN0     DIO_u8PIN0
#define BTN1     DIO_u8PIN1
#define BTN2     DIO_u8PIN2
#define BTN3     DIO_u8PIN3
#define BTN4     DIO_u8PIN4
#define BTN5     DIO_u8PIN5
#define BTN6     DIO_u8PIN6
#define BTN7     DIO_u8PIN7
/*
 * Argument and Return Indecations for caller 
 */
#define H_BTN_BTNID_BTN0   0
#define H_BTN_BTNID_BTN1   1
#define H_BTN_BTNID_BTN2   2
#define H_BTN_BTNID_BTN3   3
#define H_BTN_BTNID_BTN4   4
#define H_BTN_BTNID_BTN5   5
#define H_BTN_BTNID_BTN6   6
#define H_BTN_BTNID_BTN7   7

/*
 * Public Function Prototypes 
 */
u8 H_BTN_void_Init(u8 copy_u8_BtnID);
u8 H_BTN_u8_SetBtnVal(u8 copy_u8_BtnID);
u8   H_BTN_u8_GetBtnVal(u8 copy_u8_BtnID);
u8 Button_u8SetCallBack(void (*Copy_voidCallBackFunction)(void));




#endif /* BUTTON_H_ */