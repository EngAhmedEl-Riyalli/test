
/**********************************************
 *** Author 	 : AHMED El-RIYALLI			***
 *** Version 	 : V1.0						***												
 *** Date		 : 26/03/2020				***
 *** Description : Error Stat. Discrip.		***
 **********************************************/

/*****************************************************
 ** Gaurd of File, Will Call one Time when Included	**
 *****************************************************/
 
#ifndef		ERROR_STATUS_H_INCLUDED
#define		ERROR_STATUS_H_INCLUDED
 
 
	typedef enum Error_enuStatus{
		 
		ES_NOT_OK,
		ES_OK,
		ES_OUT_OF_RANGE
		 
	}Error_enuStatus_t;
	 
	 
 
#endif		 /* ERROR_STATUS_H_INCLUDED */