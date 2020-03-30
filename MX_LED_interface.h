
/**********************************************************/
/**********************************************************/
/*** Author 	 : AHMED ASHRAF El-RIYALLI		***********/
/*** Version 	 : V1.0							***********/
/*** Date		 : 27/03/2020					***********/
/*** -------------------------------------------------- ***/
/*** Description : Seven Segment User Interfacing.		***/
/*** -------------------------------------------------- ***/
/**********************************************************/
/**********************************************************/

/*****************************************************/
/** Gaurd of File, Will Call one Time when Included	**/
/*****************************************************/
 
#ifndef			MX_LED_INTERFACE_H_INCLUDED
#define			MX_LED_INTERFACE_H_INCLUDED



/********************************************************************/
/* Description: This Function Used to Initialize Seven Segment.	  ***/
/*----------------------------------------------------------------***/
/*				Input : void.			  						  ***/
/*				Return: void. 		  							  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	void	MX_LED_vidInit(void);
	
/***************************************************************************/
/* Description: This Function Used to Display Numbers ON Seven Segment.	 ***/
/*-----------------------------------------------------------------------***/
/*				Input : u8 Number.			  					  		 ***/
/*				Return: Error Status as User Defined Enum. 		  		 ***/
/***************************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   		 ***/
/***************************************************************************/	
	Error_enuStatus_t	MX_LED_enuDisplay(u8);
	
/********************************************************************/
/* Description: This Function Used to Enable Seven Segment	by    ***/
/* 				Using The Common Pin.							  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void. 		  							  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	void	MX_LED_vidSetCommonPin(void);

/********************************************************************/
/* Description: This Function Used to Disable Seven Segment	by    ***/
/* 				Using The Common Pin.							  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void. 		  							  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	void	MX_LED_vidClearCommonPin(void);
	
/********************************************************************/
/* Description: This Function Used to Disable Seven Segment.	  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void. 									  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
	void	MX_LED_vidStop(void);

	


#endif		/* MX_LED_INTERFACE_H_INCLUDED */	
