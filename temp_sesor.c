/*
 * temp_sesor.c
 *
 * Created: 2/17/2022 9:45:36 PM
 *  Author: Mahmoud Emad
 */ 
#include "temp_sesor.h"
int TempStart ()
{
	uint16 temp, *tempptr,Vout;
	
	tempptr = &temp;
	Adc_ChannelInit(tempSensor);
	temp =Adc_ReadChannel(tempSensor , tempptr);
	Vout = ((temp)*0.48828125) ; /*Temperature (°C) */
	
	
	return Vout;
	
}



void temp_FeedBack (uint16 Reg_Temp)
{
	uint16 Temp=TempStart() ;
	if (Temp > Reg_Temp )
	{
		ColdSide();
	}

	else if (Temp< Reg_Temp)
	{ 
		HotSide();		
	}
	else
	{
		stop_motor();
	}
}
ReturnValueType statyState(uint16 Reg_Temp)
{
	uint16 Temp=TempStart() ;
	if (Temp == Reg_Temp)
	{
		return OK;
	}
	else
	{
		return NOK;
	}
}

 void PWM_MotorDriverInit()
 {
	TCCR2 |= ((1<<WGM20)|(1<<WGM21));// activate fast PWM
	TCCR2 |= (1<<CS22);//select the Prescaler
 }
 
 int PWM_MotorDriverChanger (uint16 duty)
 {
	 OCR2= duty;
 }
 
 void PWM_MotorDriver_stop()
 {
	 TCCR2 &=~ ((1<<CS20)|(1<<CS21));//turn off the prescaler
 }