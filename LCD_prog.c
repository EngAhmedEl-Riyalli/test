
/**********************************************************
 *** Author 	 : AHMED El-RIYALLI						***
 *** Version 	 : V1.0									***												
 *** Date		 : 28/03/2020							***
 *** Description : LCD User Interfacing Implementation.	***
 **********************************************************/


/****************************/
/**-- STD LIB DIRECTIVES --**/
/****************************/
 
#include "STD_TYPES.h"
#include "Error_Status.h"

#include <util/delay.h>

/***************************************/
/**-- SOFTWARE COMPONENT DIRECTIVES --**/
/***************************************/

#include "DIO_interface.h"

#include "LCD_int.h"
#include "LCD_private.h"
#include "LCD_config.h"



/******************************************************/
/**** Software Component Functions Implementations ****/
/******************************************************/
 
/********************************************************************/
/* Description: This Function Used to Initialize LCD.		  	  ***/
/*----------------------------------------------------------------***/
/*				Input : void.			  						  ***/
/*				Return: void.			  						  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

#if 	LCD_MODE == 8_LINES

	void	LCD_vidInit(void)
	{
		_delay_ms(50);
		
	/*******************************************/
	/**** Function Set: 					****/
	/**** --------------------------------- ****/
	/**** Data Length:			 			****/
	/**** ----------- DL : 1 	8-bit mode  ****/
	/**** Number of Display Line: 			****/
	/**** ------------ N : 1	2-line		****/
	/**** Display Font Size:		    	****/
	/**** ------------ F : 0	5x7 pixel	****/
	/*******************************************/
	/**** 0b 0011 1000 >>> 0x38				****/
	/*******************************************/
	
		LCD_enuSendCommand(0x38);
		
		_delay_ms(1);
		
	/***************************************/
	/**** Display ON/OFF Control:		****/
	/**** ----------------------------- ****/
	/**** Display ON/OFF:			 	****/
	/**** ----------- D : 1		ON		****/
	/**** Cursor ON/OFF: 				****/
	/**** ----------- C : 0		OFF 	****/
	/**** Blinking ON/OFF:		    	****/
	/**** ----------- B : 0		OFF 	****/
	/***************************************/
	/**** 0b 0000 1100 >>> 0x0C			****/
	/***************************************/
		
		LCD_enuSendCommand(0x0C);
		
		_delay_ms(1);
		
	/***************************************/
	/**** Display Clear:				****/
	/**** ----------------------------- ****/
	/**** Clear DDRAM			 		****/
	/***************************************/
	/**** 0b 0000 0001 >>> 0x01			****/
	/***************************************/
		
		LCD_enuSendCommand(0x01);
		
		_delay_ms(2);
		
	/***************************************/
	/**** Entry Mode Set:				****/
	/**** ----------------------------- ****/
	/**** Increase/Decrease DDRAM by 1:	****/
	/**** ----------- I : 1	 Increase	****/
	/**** Shift The Entire Display:		****/
	/**** ----------- S : 0	 No Shift 	****/
	/***************************************/
	/**** 0b 0000 0110 >>> 0x06			****/
	/***************************************/
	
		LCD_enuSendCommand(0x06);
	}
	
/********************************************************************/
/* Description: This Function Used to Send Char to LCD.		  	  ***/
/*----------------------------------------------------------------***/
/*				Input : u8 1-byte of Data.			  			  ***/
/*				Return: Error Status as User Defined Enum.		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	Error_enuStatus_t	LCD_enuSendChar(u8 Copy_u8Data)
	{
		Error_enuStatus_t	error = ES_OK;
		
		DIO_enuSetPinValue(LCD_CONTROL_PORT, RS_PIN, LCD_PIN_HIGH);
		DIO_enuSetPinValue(LCD_CONTROL_PORT, RW_PIN, LCD_PIN_LOW);
		
		DIO_enuSetNibbleValue(LCD_DATA_PORT, LSN, (Copy_u8Data & 0x0F));
		DIO_enuSetNibbleValue(LCD_DATA_PORT, MSN, (Copy_u8Data >> 4));
		
		
		DIO_enuSetPinValue(LCD_CONTROL_PORT, E_PIN, LCD_PIN_HIGH);
		_delay_us(250);
		DIO_enuSetPinValue(LCD_CONTROL_PORT, E_PIN, LCD_PIN_LOW);
		_delay_us(250);
		
		return error;	
	}
	
/********************************************************************/
/* Description: This Function Used to Send String to LCD.		  ***/
/*----------------------------------------------------------------***/
/*				Input : u8 1-byte of Command.			  		  ***/
/*				Return: Error Status as User Defined Enum.		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	Error_enuStatus_t	LCD_enuSendCommand(u8 Copy_u8Data);
	{
		Error_enuStatus_t	error = ES_OK;
		
		DIO_enuSetPinValue(LCD_CONTROL_PORT, RS_PIN, LCD_PIN_LOW);
		DIO_enuSetPinValue(LCD_CONTROL_PORT, RW_PIN, LCD_PIN_LOW);
		
		DIO_enuSetNibbleValue(LCD_DATA_PORT, LSN, (Copy_u8Data & 0x0F));
		DIO_enuSetNibbleValue(LCD_DATA_PORT, MSN, (Copy_u8Data >> 4));
		
		
		DIO_enuSetPinValue(LCD_CONTROL_PORT, E_PIN, LCD_PIN_HIGH);
		_delay_us(250);
		DIO_enuSetPinValue(LCD_CONTROL_PORT, E_PIN, LCD_PIN_LOW);
		_delay_us(250);
		
		return error;
	}

#elif 	LCD_MODE == 4_LINES

#else

	#error	" Enter a Valid LCD_MODE "
	
#endif	/* LCD_MODE */
