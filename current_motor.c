/*
 * current_motor.c
 *
 * Created: 2/18/2022 1:22:02 AM
 *  Author: Mahmoud Emad
 */ 
#include "current_motor.h"
int MotorCurrentSensor ()
{
	uint16 CurrentSensor, *CurrentSensorptr,Vo, vostr[10];
	CurrentSensorptr=&CurrentSensor;
	LCD_Init();

	Adc_ChannelInit(ADC0);
	CurrentSensor =Adc_ReadChannel(ADC0 , CurrentSensorptr);
	Vo = (CurrentSensor/200) ; /*Temperature (°C) */
	U8Decimal2String(Vo,vostr);
	LCD_Init();
	LCD_Postion(2,1);
	//LCD_DataString(" Current =");
	LCD_Postion(2,10);
	LCD_DataString(vostr);
	return CurrentSensor;
}