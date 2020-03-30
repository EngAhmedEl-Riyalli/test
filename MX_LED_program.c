
/**********************************************************/
/**********************************************************/
/*** Author 	 : AHMED ASHRAF El-RIYALLI		***********/
/*** Version 	 : V1.0							***********/
/*** Date		 : 27/03/2020					***********/
/*** -------------------------------------------------- ***/
/*** Description : Seven Segment Implementation.		***/
/*** -------------------------------------------------- ***/
/**********************************************************/
/**********************************************************/

/****************************/
/*--- STD LIB DIRECTIVES ---*/
/****************************/
 
#include "STD_TYPES.h"
#include "Error_Status.h"

/***************************************/
/*--- SOFTWARE COMPONENT DIRECTIVES ---*/
/***************************************/

#include "DIO_interface.h"

#include "MX_LED_interface.h"
#include "MX_LED_private.h"
#include "MX_LED_config.h"



						/***   0 	 1    2	 	 3	   4	 5	   6	 7	   8	 9 	***/
const u8 MX_LED_DATA_G[20] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
							  0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xEF};
						/***   0. 	 1.    2.	 3.	   4.	 5.	   6.	 7.	   8.	 9. ***/
			
			
/******************************************************/
/**** Software Component Functions Implementations ****/
/******************************************************/

/********************************************************************/
/* Description: This Function Used to Initialize Seven Segment.	  ***/
/*----------------------------------------------------------------***/
/*				Input : void.			  						  ***/
/*				Return: void. 		  							  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/

		void	MX_LED_vidInit(void)
		{
			DIO_enuSetPinDirection(A_PORT, A_PIN, MX_LED_U8_OUTPUT);
			DIO_enuSetPinDirection(B_PORT, B_PIN, MX_LED_U8_OUTPUT);
			DIO_enuSetPinDirection(C_PORT, C_PIN, MX_LED_U8_OUTPUT);
			DIO_enuSetPinDirection(D_PORT, D_PIN, MX_LED_U8_OUTPUT);
			DIO_enuSetPinDirection(E_PORT, E_PIN, MX_LED_U8_OUTPUT);
			DIO_enuSetPinDirection(F_PORT, F_PIN, MX_LED_U8_OUTPUT);
			DIO_enuSetPinDirection(G_PORT, G_PIN, MX_LED_U8_OUTPUT);
			
		#if 	DOT_STATUS == DOT_CONNECTED
					
			DIO_enuSetPinDirection(DOT_PORT, DOT_PIN, MX_LED_U8_OUTPUT);
					
		#else
			
			#warning "Dot Pin is Not Connected"
					
			#endif	/* DOT_STATUS */		
			
		#if 	COMMON_STATUS == COMMON_CONNECTED
			
			DIO_enuSetPinDirection(COMMON_PORT, COMMON_PIN, MX_LED_U8_OUTPUT);
					
		#else
			
			#warning "Common Pin is Not Connected"
			
		#endif	/* DOT_STATUS */
		
		}

#if 	MX_LED_TYPE == COMMON_CATHODE
/***************************************************************************/
/* Description: This Function Used to Display Numbers ON Seven Segment.	 ***/
/*-----------------------------------------------------------------------***/
/*				Input : u8 Number.			  					  		 ***/
/*				Return: Error Status as User Defined Enum. 		  		 ***/
/***************************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   		 ***/
/***************************************************************************/

		Error_enuStatus_t		MX_LED_enuDisplay(u8 Copy_u8Number)
		{
			Error_enuStatus_t 	error = ES_NOT_OK;
			
		#if 	DOT_STATUS == DOT_CONNECTED
					
			if(Copy_u8Number <= 19)
			{
				error = ES_OK;
				
				DIO_enuSetPinValue(DOT_PORT, DOT_PIN, ((MX_LED_DATA_G[Copy_u8Number] >> 7) & 0x01));
				
		#else
				
			if(Copy_u8Number <= 9)
			{
				error = ES_OK;
					
		#endif	/* DOT_STATUS */
			
				DIO_enuSetPinValue(A_PORT, A_PIN, ( (MX_LED_DATA_G[Copy_u8Number] >> 0) & 0x01) );
				DIO_enuSetPinValue(B_PORT, B_PIN, ( (MX_LED_DATA_G[Copy_u8Number] >> 1) & 0x01) );
				DIO_enuSetPinValue(C_PORT, C_PIN, ( (MX_LED_DATA_G[Copy_u8Number] >> 2) & 0x01) );
				DIO_enuSetPinValue(D_PORT, D_PIN, ( (MX_LED_DATA_G[Copy_u8Number] >> 3) & 0x01) );
				
				DIO_enuSetPinValue(E_PORT, E_PIN, !!( MX_LED_DATA_G[Copy_u8Number] & (1 << 4) ) );
				DIO_enuSetPinValue(F_PORT, F_PIN, !!( MX_LED_DATA_G[Copy_u8Number] & (1 << 5) ) );
				DIO_enuSetPinValue(G_PORT, G_PIN, !!( MX_LED_DATA_G[Copy_u8Number] & (1 << 6) ) );
			}
			
			else
			{
				error = ES_OUT_OF_RANGE;
			}
			
			return error;
		}
		
		#if		COMMON_STATUS == COMMON_CONNECTED
/********************************************************************/
/* Description: This Function Used to Enable Seven Segment	by    ***/
/* 				Using The Common Pin.							  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void.				  					  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
			void	MX_LED_vidSetCommonPin(void)
			{
				DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, MX_LED_U8_LOW);
			}
				
/********************************************************************/
/* Description: This Function Used to Disable Seven Segment	by    ***/
/* 				Using The Common Pin.							  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void. 									  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/	
			void	MX_LED_vidClearCommonPin(void)
			{
				DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, MX_LED_U8_HIGH);
			}
		
		#endif	/* COMMON_STATUS */
		
/********************************************************************/
/* Description: This Function Used to Disable Seven Segment.	  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void. 									  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
		void	MX_LED_vidStop(void)
		{
			DIO_enuSetPinValue(A_PORT, A_PIN, MX_LED_U8_LOW);
			DIO_enuSetPinValue(B_PORT, B_PIN, MX_LED_U8_LOW);
			DIO_enuSetPinValue(C_PORT, C_PIN, MX_LED_U8_LOW);
			DIO_enuSetPinValue(D_PORT, D_PIN, MX_LED_U8_LOW);
			DIO_enuSetPinValue(E_PORT, E_PIN, MX_LED_U8_LOW);
			DIO_enuSetPinValue(F_PORT, F_PIN, MX_LED_U8_LOW);
			DIO_enuSetPinValue(G_PORT, G_PIN, MX_LED_U8_LOW);
			
		#if 	DOT_STATUS == DOT_CONNECTED
			
			DIO_enuSetPinValue(DOT_PORT, DOT_PIN, MX_LED_U8_LOW);
				
		#endif	/* DOT_STATUS */
		
		}
		
#elif	MX_LED_TYPE == COMMON_ANODE
/***************************************************************************/
/* Description: This Function Used to Display Numbers ON Seven Segment.	 ***/
/*-----------------------------------------------------------------------***/
/*				Input : u8 Number.			  					  		 ***/
/*				Return: Error Status as User Defined Enum. 		  		 ***/
/***************************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   		 ***/
/***************************************************************************/
		Error_enuStatus_t		MX_LED_enuDisplay(u8 Copy_u8Number)
		{
			Error_enuStatus_t	error = ES_NOT_OK;
			
		#if 	DOT_STATUS == DOT_CONNECTED
			
			if(Copy_u8Number <= 19)
			{
				error = ES_OK;
				
				DIO_enuSetPinValue(DOT_PORT, DOT_PIN, !((MX_LED_DATA_G[Copy_u8Number] >> 7) & 0x01));	
		#else
				
			if(Copy_u8Number <= 9)
			{
				error = ES_OK;
					
		#endif	/* DOT_STATUS */
			
				DIO_enuSetPinValue(A_PORT, A_PIN, !( (MX_LED_DATA_G[Copy_u8Number] >> 0) & 0x01) );
				DIO_enuSetPinValue(B_PORT, B_PIN, !( (MX_LED_DATA_G[Copy_u8Number] >> 1) & 0x01) );
				DIO_enuSetPinValue(C_PORT, C_PIN, !( (MX_LED_DATA_G[Copy_u8Number] >> 2) & 0x01) );
				DIO_enuSetPinValue(D_PORT, D_PIN, !( (MX_LED_DATA_G[Copy_u8Number] >> 3) & 0x01) );
				
				DIO_enuSetPinValue(E_PORT, E_PIN, !( MX_LED_DATA_G[Copy_u8Number] & (1 << 4) ) );
				DIO_enuSetPinValue(F_PORT, F_PIN, !( MX_LED_DATA_G[Copy_u8Number] & (1 << 5) ) );
				DIO_enuSetPinValue(G_PORT, G_PIN, !( MX_LED_DATA_G[Copy_u8Number] & (1 << 6) ) );
			}
			
			else
			{
				error = ES_OUT_OF_RANGE;
			}
			
			return error;
		}
		
		
		#if		COMMON_STATUS == COMMON_CONNECTED
/********************************************************************/
/* Description: This Function Used to Enable Seven Segment	by    ***/
/* 				Using The Common Pin.							  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void.				  					  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
			void	MX_LED_enuSetCommonPin(void)
			{
				DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, MX_LED_U8_HIGH);
			}
				
/********************************************************************/
/* Description: This Function Used to Disable Seven Segment	by    ***/
/* 				Using The Common Pin.							  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void.				  					  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
			void	MX_LED_enuStopCommonPin(void)
			{
				DIO_enuSetPinValue(COMMON_PORT, COMMON_PIN, MX_LED_U8_LOW);
			}
		
		#endif	/* COMMON_STATUS */

/********************************************************************/
/* Description: This Function Used to Disable Seven Segment.	  ***/
/*----------------------------------------------------------------***/
/*				Input : void.				  					  ***/
/*				Return: void. 									  ***/
/********************************************************************/
/* Pre-Conditions: This Function Doesn't need any Pre-Condition   ***/
/********************************************************************/
		void	MX_LED_vidStop(void)
		{
			DIO_enuSetPinValue(A_PORT, A_PIN, MX_LED_U8_HIGH);
			DIO_enuSetPinValue(B_PORT, B_PIN, MX_LED_U8_HIGH);
			DIO_enuSetPinValue(C_PORT, C_PIN, MX_LED_U8_HIGH);
			DIO_enuSetPinValue(D_PORT, D_PIN, MX_LED_U8_HIGH);
			DIO_enuSetPinValue(E_PORT, E_PIN, MX_LED_U8_HIGH);
			DIO_enuSetPinValue(F_PORT, F_PIN, MX_LED_U8_HIGH);
			DIO_enuSetPinValue(G_PORT, G_PIN, MX_LED_U8_HIGH);
			
		#if 	DOT_STATUS == DOT_CONNECTED
			
			DIO_enuSetPinValue(DOT_PORT, DOT_PIN, MX_LED_U8_HIGH);
					
		#endif	/* DOT_STATUS */
		
		}
				
#else
	
	#error "Wrong Seven Segment TYPE" 

#endif /* MX_LED_TYPE */
