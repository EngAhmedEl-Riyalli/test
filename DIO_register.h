
/**********************************************
 *** Author 	 : AHMED El-RIYALLI			***
 *** Version 	 : V1.0						***												
 *** Date		 : 26/03/2020				***
 *** Description : DIO Register Addresses	***
 **********************************************/

/*****************************************************
 ** Gaurd of File, Will Call one Time when Included	**
 *****************************************************/
 
#ifndef		DIO_REGISTER_H_INCLUDED
#define		DIO_REGISTER_H_INCLUDED
 
 
 
	/*********************** PORT A Registers *******************/
	#define		DIO_PU8_PINA			*( (volatile u8 *) 0x39 )
	#define		DIO_PU8_DDRA			*( (volatile u8 *) 0x3A )
	#define		DIO_PU8_PORTA			*( (volatile u8 *) 0x3B )

	/*********************** PORT B Registers *******************/
	#define		DIO_PU8_PINB			*( (volatile u8 *) 0x36 )
	#define		DIO_PU8_DDRB			*( (volatile u8 *) 0x37 )
	#define		DIO_PU8_PORTB			*( (volatile u8 *) 0x38 )

	/*********************** PORT C Registers *******************/
	#define		DIO_PU8_PINC			*( (volatile u8 *) 0x33 )
	#define		DIO_PU8_DDRC			*( (volatile u8 *) 0x34 )
	#define		DIO_PU8_PORTC			*( (volatile u8 *) 0x35 )

	/*********************** PORT D Registers *******************/
	#define		DIO_PU8_PIND			*( (volatile u8 *) 0x30 )
	#define		DIO_PU8_DDRD			*( (volatile u8 *) 0x31 )
	#define		DIO_PU8_PORTD			*( (volatile u8 *) 0x32 )
	 
 
#endif		/* DIO_REGISTER_H_INCLUDED */