
/**************************************************
 *** Author 	 : AHMED El-RIYALLI				***
 *** Version 	 : V1.0							***												
 *** Date		 : 27/03/2020					***
 *** Description : LED User Interfacing			***
 **************************************************/
 
 /****************************
 **** STD LIB DIRECTIVES ****
 ****************************/
 
#include "STD_TYPES.h"
#include "Error_Status.h"

/***************************************
 **** SOFTWARE COMPONENT DIRECTIVES ****
 ***************************************/

#include "DIO_interface.h"

#include "LED_private.h"
#include "LED_interface.h"

/******************************************************
 **** Software Component Functions Implementations ****
 ******************************************************/

/********************************************************************/
/* Description: This Function Used to Initialize LED PORT.		  ***/
/*----------------------------------------------------------------***/
/*				Input : LED PORT ID, PORT Initial State.		  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		LED_enuInitPort(LED_enuInterfacing_t enuLED_PORT_ID, LED_enuInterfacing_t enuLED_INIT_STATE)
{
	Error_enuStatus_t	error = ES_OK;
	
	switch(enuLED_INIT_STATE)
	{
		case LED_ON  :
			
					 switch(enuLED_PORT_ID)
					 {
					 	/**** WARNING : NOL ALL MCAL OUTPUT = 1, HIGH = 1, LOW = 0  ***/
					 	case LED_PORT0 :
											DIO_enuSetPortDirection(LED_U8_PORT0, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT0, LED_U8_PORT_H);
						break;
								
					 	case LED_PORT1 :
											DIO_enuSetPortDirection(LED_U8_PORT1, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT1, LED_U8_PORT_H);
						break;
								
					 	case LED_PORT2 :
											DIO_enuSetPortDirection(LED_U8_PORT2, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT2, LED_U8_PORT_H);
						break;
								
					 	case LED_PORT3 :
											DIO_enuSetPortDirection(LED_U8_PORT3, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT3, LED_U8_PORT_H);
						break;
						
						default	  	   : 
											error = ES_OUT_OF_RANGE;		
						break;
					 }
				
		break;
		
		case LED_OFF :
			
					 switch(enuLED_PORT_ID)
					 {
					 	case LED_PORT0 :
											DIO_enuSetPortDirection(LED_U8_PORT0, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT0, LED_U8_PORT_L);
						break;
						
					 	case LED_PORT1 :
											DIO_enuSetPortDirection(LED_U8_PORT1, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT1, LED_U8_PORT_L);
						break;
						
					 	case LED_PORT2 :
											DIO_enuSetPortDirection(LED_U8_PORT2, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT2, LED_U8_PORT_L);
						break;
						
					 	case LED_PORT3 :
											DIO_enuSetPortDirection(LED_U8_PORT3, LED_U8_PORT_O);
											DIO_enuSetPortValue(LED_U8_PORT3, LED_U8_PORT_L);
						break;
						
						default   	   : 
											error = ES_OUT_OF_RANGE;		
						break;
					 }
			
		break;
		
		default 	 :
						error = ES_OUT_OF_RANGE;
		break;
	}
	
	return error;
}

/********************************************************************/
/* Description: This Function Used to Initialize LED Pin.		  ***/
/*----------------------------------------------------------------***/
/*				Input : LED PORT ID,  Pin ID, Pin Initial State.  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		LED_enuInit(LED_enuInterfacing_t enuLED_PORT_ID, LED_enuInterfacing_t enuLED_PIN_ID, LED_enuInterfacing_t enuLED_INIT_STATE)
{
	Error_enuStatus_t	error = ES_NOT_OK;
	
	if(enuLED_PIN_ID >= LED_PIN0 && enuLED_PIN_ID <= LED_PIN7)
	{
		error = ES_OK;
		
		switch(enuLED_INIT_STATE)
		{
			case LED_ON  :
			
						 switch(enuLED_PORT_ID)
						 {
							case LED_PORT0 :
												DIO_enuSetPinDirection(LED_U8_PORT0 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT0, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							case LED_PORT1 :
												DIO_enuSetPinDirection(LED_U8_PORT1 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT1, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							case LED_PORT2 :
												DIO_enuSetPinDirection(LED_U8_PORT2 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT2, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							case LED_PORT3 :
												DIO_enuSetPinDirection(LED_U8_PORT3 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT3, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							default		   :
												error = ES_OUT_OF_RANGE;
							break;
						 }	
						 
			break;
			
			case LED_OFF :
			
						 switch(enuLED_PORT_ID)
						 {
							case LED_PORT0 :
												DIO_enuSetPinDirection(LED_U8_PORT0 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT0, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							case LED_PORT1 :
												DIO_enuSetPinDirection(LED_U8_PORT1 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT1, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							case LED_PORT2 :
												DIO_enuSetPinDirection(LED_U8_PORT2 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT2, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							case LED_PORT3 :
												DIO_enuSetPinDirection(LED_U8_PORT3 , enuLED_PIN_ID, LED_U8_PIN_O);
												DIO_enuSetPinValue(LED_U8_PORT3, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							default		   :
												error = ES_OUT_OF_RANGE;
							break;
						 }	
					
			break;
			
			default		 :
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
/* Description: This Function Used to Control LED Pin.		  	  ***/
/*----------------------------------------------------------------***/
/*				Input : LED PORT ID,  Pin ID, Pin Operation.	  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		LED_enuControl(LED_enuInterfacing_t enuLED_PORT_ID, LED_enuInterfacing_t enuLED_PIN_ID, LED_enuInterfacing_t enuLED_OP)
{
	Error_enuStatus_t	error = ES_NOT_OK;
	
	if(enuLED_PIN_ID >= LED_PIN0 && enuLED_PIN_ID <= LED_PIN7)
	{
		error = ES_OK;
		
		switch(enuLED_OP)
		{
			case LED_ON  :

						 switch(enuLED_PORT_ID)
						 {
							case LED_PORT0 :
												DIO_enuSetPinValue(LED_U8_PORT0, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							case LED_PORT1 :
												DIO_enuSetPinValue(LED_U8_PORT1, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							case LED_PORT2 :
												DIO_enuSetPinValue(LED_U8_PORT2, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							case LED_PORT3 :
												DIO_enuSetPinValue(LED_U8_PORT3, enuLED_PIN_ID, LED_U8_PIN_H);
							break;
							
							default		   :
												error = ES_OUT_OF_RANGE;
							break;
						 }
			
			break;
			
			case LED_OFF :

						 switch(enuLED_PORT_ID)
						 {
							case LED_PORT0 :
												DIO_enuSetPinValue(LED_U8_PORT0, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							case LED_PORT1 :
												DIO_enuSetPinValue(LED_U8_PORT1, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							case LED_PORT2 :
												DIO_enuSetPinValue(LED_U8_PORT2, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							case LED_PORT3 :
												DIO_enuSetPinValue(LED_U8_PORT3, enuLED_PIN_ID, LED_U8_PIN_L);
							break;
							
							default		   :
												error = ES_OUT_OF_RANGE;
							break;
						 }
			
			break;
			
			case LED_TOG :

						 switch(enuLED_PORT_ID)
						 {
							case LED_PORT0 :
												DIO_enuTogglePin(LED_U8_PORT0, enuLED_PIN_ID);
							break;
							
							case LED_PORT1 :
												DIO_enuTogglePin(LED_U8_PORT1, enuLED_PIN_ID);
							break;
							
							case LED_PORT2 :
												DIO_enuTogglePin(LED_U8_PORT2, enuLED_PIN_ID);
							break;
							
							case LED_PORT3 :
												DIO_enuTogglePin(LED_U8_PORT3, enuLED_PIN_ID);
							break;
							
							default		   :
												error = ES_OUT_OF_RANGE;
							break;
						 }
		
			break;
			
			default		 :
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
/* Description: This Function Used to Control LED PORT.		  	  ***/
/*----------------------------------------------------------------***/
/*				Input : LED PORT ID, LED Port Value.	 	  	  ***/
/*				Return: Error Status as User Defined Enum. 		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

Error_enuStatus_t		LED_enuControlPort(LED_enuInterfacing_t enuLED_PORT_ID, u8 Copy_u8PortValue)
{
	Error_enuStatus_t	error = ES_OK;

	/**	If The Microcontroller Logic "1" = 0V We Must Complement The User Value **/
	if( ! LED_U8_PIN_H )
	{
		Copy_u8PortValue = ~Copy_u8PortValue;
	}
	/******************************************************************************/
		
	switch(enuLED_PORT_ID)
	{
		case LED_PORT0 :	DIO_enuSetPortValue(LED_U8_PORT0, Copy_u8PortValue);	break;
		case LED_PORT1 :	DIO_enuSetPortValue(LED_U8_PORT1, Copy_u8PortValue);	break;
		case LED_PORT2 :	DIO_enuSetPortValue(LED_U8_PORT2, Copy_u8PortValue);	break;
		case LED_PORT3 :	DIO_enuSetPortValue(LED_U8_PORT3, Copy_u8PortValue);	break;
			
		default		   :	error = ES_OUT_OF_RANGE;	break;
	}
	
	return error;
}