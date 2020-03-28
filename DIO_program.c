
/******************************************************
 *** Author 	 : AHMED El-RIYALLI					***
 *** Version 	 : V1.0								***												
 *** Date		 : 26/03/2020						***
 *** Description : DIO User Interfacing Functions	***
 ******************************************************/

/****************************
 **** STD LIB DIRECTIVES ****
 ****************************/
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Error_Status.h"

/***************************************
 **** SOFTWARE COMPONENT DIRECTIVES ****
 ***************************************/

#include "DIO_register.h"
#include "DIO_interface.h"

/******************************************************
 **** Software Component Functions Implementations ****
 ******************************************************/
 
/********************************************************************/
/* Description: This Function Used to Set Pin Direction.		  ***/
/*----------------------------------------------------------------***/
/*				Input : PORT Name, Pin ID, Direction.			  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		DIO_enuSetPinDirection(DIO_enuInterfacing_t enuPORTID, DIO_enuInterfacing_t enuPINID, DIO_enuInterfacing_t enuDIRECTION)
{
	Error_enuStatus_t error = ES_NOT_OK;
	
	if(enuPINID >= PIN0 && enuPINID <= PIN7)
	{
		error = ES_OK;
		
		switch(enuDIRECTION)
		{
			case OUTPUT :
				
						switch(enuPORTID)
						{
							case PORTA :		SET_BIT(DIO_PU8_DDRA, enuPINID);	break;
							case PORTB :		SET_BIT(DIO_PU8_DDRB, enuPINID);	break;
							case PORTC :		SET_BIT(DIO_PU8_DDRC, enuPINID);	break;
							case PORTD :		SET_BIT(DIO_PU8_DDRD, enuPINID);	break;
							
							default	   :		error =	ES_OUT_OF_RANGE; 			break;
						}
						
			break;
			
			case INPUT :
		
						switch(enuPORTID)
						{
							case PORTA :		CLR_BIT(DIO_PU8_DDRA, enuPINID);	break;
							case PORTB :		CLR_BIT(DIO_PU8_DDRB, enuPINID);	break;
							case PORTC :		CLR_BIT(DIO_PU8_DDRC, enuPINID);	break;
							case PORTD :		CLR_BIT(DIO_PU8_DDRD, enuPINID);	break;
								
							default	   :		error =	ES_OUT_OF_RANGE; 			break;
						}
				
			break;
			
			default   : 
						error =	ES_OUT_OF_RANGE; 
			break; 
		}
	}
	
	else
	{
		error = ES_OUT_OF_RANGE;
	}
	
	return error;
}

/********************************************************************/
/* Description: This Function Used to Set Pin Value.			  ***/
/*----------------------------------------------------------------***/
/*				Input : PORT Name, Pin ID, Value.				  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		DIO_enuSetPinValue(DIO_enuInterfacing_t enuPORTID, DIO_enuInterfacing_t enuPINID, DIO_enuInterfacing_t enuVALUE)
{
	Error_enuStatus_t 	error = ES_NOT_OK;
	
	if(enuPINID >= PIN0 && enuPINID <= PIN7)
	{
		error = ES_OK;
		
		switch(enuVALUE)
		{
			case HIGH :
				
						switch(enuPORTID)
						{
							case PORTA :		SET_BIT(DIO_PU8_PORTA, enuPINID);	break;
							case PORTB :		SET_BIT(DIO_PU8_PORTB, enuPINID);	break;
							case PORTC :		SET_BIT(DIO_PU8_PORTC, enuPINID);	break;
							case PORTD :		SET_BIT(DIO_PU8_PORTD, enuPINID);	break;
							
							default	   :		error = ES_OUT_OF_RANGE;			break;
						}
				
			break;
			
			case LOW  :
				
						switch(enuPORTID)
						{
							case PORTA :		CLR_BIT(DIO_PU8_PORTA, enuPINID);	break;
							case PORTB :		CLR_BIT(DIO_PU8_PORTB, enuPINID);	break;
							case PORTC :		CLR_BIT(DIO_PU8_PORTC, enuPINID);	break;
							case PORTD :		CLR_BIT(DIO_PU8_PORTD, enuPINID);	break;
							
							default	   :		error = ES_OUT_OF_RANGE;			break;
						}
				
			break;
			
			default	  :
						error = ES_OUT_OF_RANGE;	
			break;
		}
	}
	
	else
	{
		error = ES_OUT_OF_RANGE;
	}
	
	return error;
}

/********************************************************************/
/* Description: This Function Used to Toggle a Specific Pin.	  ***/
/*----------------------------------------------------------------***/
/*				Input : PORT Name, Pin ID						  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		DIO_enuTogglePin(DIO_enuInterfacing_t enuPORT_ID, DIO_enuInterfacing_t enuPIN_ID)
{
	Error_enuStatus_t	error = ES_NOT_OK;
	
	if(enuPIN_ID >= PIN0 && enuPIN_ID <= PIN7)
	{
		error = ES_OK;
		
		switch(enuPORT_ID)
		{
			case PORTA :	TOG_BIT(DIO_PU8_PORTA, enuPIN_ID);	break;
			case PORTB :	TOG_BIT(DIO_PU8_PORTB, enuPIN_ID);	break;
			case PORTC :	TOG_BIT(DIO_PU8_PORTC, enuPIN_ID);	break;
			case PORTD :	TOG_BIT(DIO_PU8_PORTD, enuPIN_ID);	break;
			
			default	   :	error = ES_OUT_OF_RANGE;			break;
		}
	}
	
	else
	{
		error = ES_OUT_OF_RANGE;
	}
	
	return error;
}

/********************************************************************/
/* Description: This Function Used to Get Pin Value.			  ***/
/*----------------------------------------------------------------***/
/*				Input : PORT Name, Pin ID, Pointer to Pin Value.  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		DIO_enuGetPinValue(DIO_enuInterfacing_t enuPORTID, DIO_enuInterfacing_t enuPINID, u8 *Pu8_PinValue)
{
	Error_enuStatus_t	error = ES_NOT_OK;
	
	if(enuPINID >= PIN0 && enuPINID <= PIN7)
	{
		error = ES_OK;
		
		switch(enuPORTID)
		{
			case PORTA :		*Pu8_PinValue = GET_BIT(DIO_PU8_PINA, enuPINID);	break;	 
			case PORTB :		*Pu8_PinValue = GET_BIT(DIO_PU8_PINB, enuPINID);	break;
			case PORTC :		*Pu8_PinValue = GET_BIT(DIO_PU8_PINC, enuPINID);	break;
			case PORTD :		*Pu8_PinValue = GET_BIT(DIO_PU8_PIND, enuPINID);	break;
			
			default	   :		error = ES_OUT_OF_RANGE;							break;
		}
	}
	
	else
	{
		error = ES_OUT_OF_RANGE;
	}
	
	return error;
}

/********************************************************************/
/* Description: This Function Used to Set Port Direction.		  ***/
/*----------------------------------------------------------------***/
/*				Input : PORT Name, Port Direction Value.		  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		DIO_enuSetPortDirection(DIO_enuInterfacing_t enuPORTID, u8 Copy_u8DirectionValue)
{
	Error_enuStatus_t	error = ES_OK;
		
	switch(enuPORTID)
	{
		case PORTA :	DIO_PU8_DDRA = Copy_u8DirectionValue;	break;
		case PORTB :	DIO_PU8_DDRB = Copy_u8DirectionValue;	break;
		case PORTC :	DIO_PU8_DDRC = Copy_u8DirectionValue;	break;
		case PORTD :	DIO_PU8_DDRD = Copy_u8DirectionValue;	break;
			
		default	   :	error = ES_OUT_OF_RANGE;				break;
	}
	
	return error;
}

/********************************************************************/
/* Description: This Function Used to Set Port Value.			  ***/
/*----------------------------------------------------------------***/
/*				Input : PORT Name, u8 Port Value.				  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		DIO_enuSetPortValue(DIO_enuInterfacing_t enuPORTID, u8 Copy_u8PortValue)
{
	Error_enuStatus_t	error = ES_OK;
		
	switch(enuPORTID)
	{
		case PORTA :	DIO_PU8_PORTA = Copy_u8PortValue;	break;
		case PORTB :	DIO_PU8_PORTB = Copy_u8PortValue;	break;
		case PORTC :	DIO_PU8_PORTC = Copy_u8PortValue;	break;
		case PORTD :	DIO_PU8_PORTD = Copy_u8PortValue;	break;
			
		default	   :	error = ES_OUT_OF_RANGE;			break;
	}
	
	return error;
}

/********************************************************************/
/* Description: This Function Used to Get Port Value.			  ***/
/*----------------------------------------------------------------***/
/*				Input : PORT Name, Pointer to Port Value.		  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		DIO_enuGetPortValue(DIO_enuInterfacing_t enuPORTID, u8 *Pu8_PortValue)
{
	Error_enuStatus_t	error = ES_OK;
	
	switch(enuPORTID)
	{
		case PORTA :	*Pu8_PortValue = DIO_PU8_PINA;	break;
		case PORTB :	*Pu8_PortValue = DIO_PU8_PINB;	break;
		case PORTC :	*Pu8_PortValue = DIO_PU8_PINC;	break;
		case PORTD :	*Pu8_PortValue = DIO_PU8_PIND;	break;
		
		default	   :	error = ES_OUT_OF_RANGE;
	}
	
	return error;
}