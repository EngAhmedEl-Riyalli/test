
/**********************************************
 *** Author 	 : AHMED El-RIYALLI			***
 *** Version 	 : V1.0						***												
 *** Date		 : 03/03/2020				***
 *** Description : Bit Manipulation			***
 **********************************************/

/*****************************************************
 ** Gaurd of File, Will Call one Time when Included	**
 *****************************************************/

#ifndef		BIT_MATH_H_INCLUDED
#define		BIT_MATH_H_INCLUDED


#define SET_BIT(Reg, BitNumber)					(Reg |= (1<<BitNumber))
#define CLR_BIT(Reg, BitNumber)					(Reg &= ~(1<<BitNumber))
#define TOG_BIT(Reg, BitNumber)					(Reg ^= (1<<BitNumber))
#define GET_BIT(Reg, BitNumber)					((Reg>>BitNumber) & 0x01)
#define PUT_VAL(Reg, BitNumber, value)			(Reg = (~(1<<BitNumber) & Reg) | (value<<BitNumber))


#endif		/* BIT_MATH_H_INCLUDED */
