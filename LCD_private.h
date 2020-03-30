
/**********************************************************/
/**********************************************************/
/*** Author 	 : AHMED ASHRAF El-RIYALLI		***********/
/*** Version 	 : V1.0							***********/
/*** Date		 : 28/03/2020					***********/
/*** -------------------------------------------------- ***/
/*** Description : LCD Private Interfacing.				***/
/*** -------------------------------------------------- ***/
/**********************************************************/
/**********************************************************/

/*****************************************************/
/** Gaurd of File, Will Call one Time when Included	**/
/*****************************************************/
 
#ifndef			LCD_PRIVATE_H_INCLUDED
#define			LCD_PRIVATE_H_INCLUDED

/*****************************************************/
/** User Can Select LCD by Two Options:		**********/
/** --------------------------------------- **********/
/** 1: 8_LINES for 8-Bit Data Connections	**********/
/** 2: 4_LINES for 4-Bit Data Connections	**********/
/*****************************************************/

	#define 	8_LINES		8
	#define 	4_LINES		4
	
/********************************************/
/**--------- MCAL DIO Definitions ---------**/
/********************************************/

	#define		LCD_PIN_HIGH		HIGH
	#define		LCD_PIN_LOW			LOW
	#define		LCD_PIN_OUT			OUTPUT



#endif		/* LCD_PRIVATE_H_INCLUDED */