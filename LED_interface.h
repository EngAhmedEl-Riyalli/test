
/**************************************************
 *** Author 	 : AHMED El-RIYALLI				***
 *** Version 	 : V1.0							***												
 *** Date		 : 27/03/2020					***
 *** Description : LED User Interfacing			***
 **************************************************/

/*****************************************************
 ** Gaurd of File, Will Call one Time when Included	**
 *****************************************************/
 
#ifndef			LED_INTERFACE_H_INCLUDED
#define			LED_INTERFACE_H_INCLUDED

	
	typedef enum LED_enuInterfacing{
		
		LED_PORT0,
		LED_PORT1,
		LED_PORT2,
		LED_PORT3,
		
		LED_PIN0 = 0,
		LED_PIN1 = 1,
		LED_PIN2 = 2,
		LED_PIN3 = 3,
		LED_PIN4 = 4,
		LED_PIN5 = 5,
		LED_PIN6 = 6,
		LED_PIN7 = 7,

		LED_OFF  = 0,
		LED_ON   = 1,
		LED_TOG  = 2
		
	}LED_enuInterfacing_t;
	
	
	
	Error_enuStatus_t		LED_enuInitPort(LED_enuInterfacing_t, LED_enuInterfacing_t);
	
	Error_enuStatus_t		LED_enuControlPort(LED_enuInterfacing_t, u8);
	
	Error_enuStatus_t		LED_enuInit(LED_enuInterfacing_t, LED_enuInterfacing_t, LED_enuInterfacing_t);
	
	Error_enuStatus_t		LED_enuControl(LED_enuInterfacing_t, LED_enuInterfacing_t, LED_enuInterfacing_t);




#endif		/* LED_INTERFACE_H_INCLUDED */
