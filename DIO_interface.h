
/**************************************************
 *** Author 	 : AHMED El-RIYALLI				***
 *** Version 	 : V1.0							***												
 *** Date		 : 26/03/2020					***
 *** Description : DIO Interface AVR ATmega32	***
 **************************************************/

/*****************************************************
 ** Gaurd of File, Will Call one Time when Included	**
 *****************************************************/
 
#ifndef 		DIO_INTERFACE_H_INCLUDED
#define 		DIO_INTERFACE_H_INCLUDED

	
	/*******************************************************
	 *** DIO User Interfacing Function Arguments(Inputs) ***
	 *******************************************************/

	typedef enum DIO_enuInterfacing{
		
	/** DIO Ports Names **/
		PORTA  = 0,
		PORTB  = 1,
		PORTC  = 2,
		PORTD  = 3,
		
	/** DIO Ports Pins **/
		PIN0   = 0,
		PIN1   = 1,
		PIN2   = 2,
		PIN3   = 3,
		PIN4   = 4,
		PIN5   = 5,
		PIN6   = 6,
		PIN7   = 7,
		
	/** DIO Directions **/
		INPUT  = 0,
		OUTPUT = 1,
		
		PORT_O = 0xFF,
		PORT_I = 0x00,
		
	/** DIO Output Levels **/
		LOW    = 0,
		HIGH   = 1,
		
		PORT_H = 0xFF,
		PORT_L = 0x00
		
	}DIO_enuInterfacing_t;


	/*************************************************************************************************************
	 ********************** DIO User Interfacing Functions	******************************************************
	 *************************************************************************************************************/

	Error_enuStatus_t		DIO_enuSetPinDirection(DIO_enuInterfacing_t, DIO_enuInterfacing_t, DIO_enuInterfacing_t);

	Error_enuStatus_t		DIO_enuSetPinValue(DIO_enuInterfacing_t, DIO_enuInterfacing_t, DIO_enuInterfacing_t);
	
	Error_enuStatus_t		DIO_enuTogglePin(DIO_enuInterfacing_t, DIO_enuInterfacing_t);

	Error_enuStatus_t		DIO_enuGetPinValue(DIO_enuInterfacing_t, DIO_enuInterfacing_t, u8 *);

	Error_enuStatus_t		DIO_enuSetPortDirection(DIO_enuInterfacing_t, u8);

	Error_enuStatus_t		DIO_enuSetPortValue(DIO_enuInterfacing_t, u8);
	
	Error_enuStatus_t		DIO_enuGetPortValue(DIO_enuInterfacing_t, u8 *);


#endif		/* DIO_INTERFACE_H_INCLUDED */