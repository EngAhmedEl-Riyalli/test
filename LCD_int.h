
/**********************************************************/
/**********************************************************/
/*** Author 	 : AHMED ASHRAF El-RIYALLI		***********/
/*** Version 	 : V1.0							***********/
/*** Date		 : 28/03/2020					***********/
/*** -------------------------------------------------- ***/
/*** Description : LCD User Interfacing.				***/
/*** -------------------------------------------------- ***/
/**********************************************************/
/**********************************************************/


/*****************************************************/
/** Gaurd of File, Will Call one Time when Included	**/
/*****************************************************/
 
#ifndef			LCD_INT_H_INCLUDED
#define			LCD_INT_H_INCLUDED



/*******************************************/
/**** LCD Connections Interfacing: 		****/
/**** --------------------------------- ****/
/**** 1- LCD Control Port and Pins.		****/
/**** 2- LCD Data Port and Pins.		****/
/*******************************************/

#define 	LCD_CONTROL_PORT		PORTB
#define		RS_PIN					PIN0
#define 	RW_PIN					PIN1
#define		E_PIN					PIN2

#define 	LCD_DATA_PORT			PORTA
#define		D0_PIN					PIN0
#define 	D1_PIN					PIN1
#define		D2_PIN					PIN2
#define		D3_PIN					PIN3
#define 	D4_PIN					PIN4
#define		D5_PIN					PIN5
#define 	D6_PIN					PIN6
#define		D7_PIN					PIN7

/**************************************************/
/**** Software Component Functions Prototypes. ****/
/**************************************************/

/********************************************************************/
/* Description: This Function Used to Initialize LCD.		  	  ***/
/*----------------------------------------------------------------***/
/*				Input : void.			  						  ***/
/*				Return: void.			  						  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	void	LCD_vidInit(void);
 
/********************************************************************/
/* Description: This Function Used to Send Char to LCD.		  	  ***/
/*----------------------------------------------------------------***/
/*				Input : u8 1-byte of Data.			  			  ***/
/*				Return: Error Status as User Defined Enum.		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	Error_enuStatus_t	LCD_enuSendChar(u8 Copy_u8Data);
	
/********************************************************************/
/* Description: This Function Used to Send String to LCD.		  ***/
/*----------------------------------------------------------------***/
/*				Input : u8 1-byte of Command.			  		  ***/
/*				Return: Error Status as User Defined Enum.		  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	Error_enuStatus_t	LCD_enuSendCommand(u8 Copy_u8Data);



#endif		/* LCD_INT_H_INCLUDED */