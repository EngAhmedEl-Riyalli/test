
/**********************************************************/
/**********************************************************/
/*** Author 	 : AHMED ASHRAF El-RIYALLI		***********/
/*** Version 	 : V1.0							***********/
/*** Date		 : 27/03/2020					***********/
/*** -------------------------------------------------- ***/
/*** Description : Seven Segment Private Interfacing.	***/
/*** -------------------------------------------------- ***/
/**********************************************************/
/**********************************************************/

/*****************************************************/
/** Gaurd of File, Will Call one Time when Included	**/
/*****************************************************/

#ifndef			MX_LED_PRIVATE_H_INCLUDED
#define 		MX_LED_PRIVATE_H_INCLUDED

	
/*****************************************************/
/************** Seven Segment Type *******************/
/*****************************************************/
	#define 	COMMON_CATHODE					0
	#define 	COMMON_ANODE					1
	
/*****************************************************/
/************** Dot Display For Seven Segment ********/
/*****************************************************/
	#define 	DOT_CONNECTED					1
	#define 	DOT_NOT_CONNECTED				0
	
/*****************************************************/
/************** Seven Segment Common Power ***********/
/*****************************************************/
	#define 	COMMON_CONNECTED				2
	#define 	COMMON_NOT_CONNECTED			3

/*****************************************************/
/************** MCAL DIO OUTPUT maybe "0" or "1" *****/
/*****************************************************/
	#define 	MX_LED_U8_OUTPUT				OUTPUT

/*****************************************************/
/************** We Can't Use HIGH and LOW Direct *****/
/************** 		Why ?!!					 *****/
/************** If DIO Defined HIGH With Another *****/
/************** Name We Will Have to Change The  *****/
/************** Entire File 					 *****/
/*****************************************************/
	#define 	MX_LED_U8_HIGH					HIGH
	#define 	MX_LED_U8_LOW					LOW


	
#endif		/* MX_LED_PRIVATE_H_INCLUDED */