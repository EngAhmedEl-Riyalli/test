
/**************************************************
 *** Author 	 : AHMED El-RIYALLI				***
 *** Version 	 : V1.0							***												
 *** Date		 : 27/03/2020					***
 *** Description : LED Private Interfacing		***
 **************************************************/

/*****************************************************
 ** Gaurd of File, Will Call one Time when Included	**
 *****************************************************/

#ifndef			LED_PRIVATE_H_INCLUDED
#define			LED_PRIVATE_H_INCLUDED


/*****************************************************
 ** Ports Connections with MCAL "DIO"				**
 *****************************************************/

	#define LED_U8_PORT0			PORTA

	#define LED_U8_PORT1			PORTB

	#define LED_U8_PORT2			PORTC

	#define LED_U8_PORT3			PORTD
	
/******************************************************************
 ** High/Low and Input/Output Levels Connections with MCAL "DIO" **
 ******************************************************************/
	
	#define LED_U8_PORT_H			PORT_H
	#define LED_U8_PORT_L			PORT_L
	
	#define LED_U8_PIN_H			HIGH
	#define LED_U8_PIN_L			LOW
	
	#define LED_U8_PORT_I			PORT_I
	#define LED_U8_PORT_O			PORT_O
	
	#define LED_U8_PIN_I			INPUT
	#define LED_U8_PIN_O			OUTPUT
	



#endif		/* LED_PRIVATE_H_INCLUDED */
