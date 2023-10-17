/*
 * Vertiual testing.c
 *
 * Created: 11/10/2021 4:45:00 PM
 * Author : Mahmoud Emad
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "Bitwise.h"
#include "STD_Types.h"
#include "Dio.h"
#include "UART.h"
#include "temp_sesor.h"
#include "motor_driver.h"

int main(void)
{
	
	uint8 vout_str[3];
	sei(); // open the main interrupt switch
	MoterDriver_init();
	LCD_Init();
	Adc_Init();
	TempStart();
	PWM_MotorDriverInit();
	UART_Init();//instillation of bluetooth connection 
	uint8 UARTData = 0 ;
	ReturnValueType ret = NOK;
	uint8 Tempc =TempStart();
	U8Decimal2String(Tempc,vout_str);
    while (1) 
	
    {	temp_FeedBack(30);
	LCD_Postion(1,1);
	LCD_DataString("flavor-->spicy");
	LCD_Postion(2,1);
	LCD_DataString("Temp=");
	LCD_Postion(2,6);
	Tempc =TempStart();
	U8Decimal2String(Tempc,vout_str);
	LCD_DataString(vout_str);
	vout_str[3]= (0,0,0);
	LCD_Postion(2,9);
	LCD_DataString("c");
	while (statyState(30)==0)
	{
		temp_FeedBack(30);
		Tempc =TempStart();
		U8Decimal2String(Tempc,vout_str);
		LCD_Postion(2,6);
		LCD_DataString(vout_str);
		vout_str[3]= (0,0,0);
	}
	PWM_MotorDriverChanger(80);
	_delay_ms(3000);
	PWM_MotorDriver_stop();
	temp_FeedBack(35);
	while (statyState(35)==0)
	{
		temp_FeedBack(35);
		Tempc =TempStart();
		U8Decimal2String(Tempc,vout_str);
		LCD_Postion(2,6);
		LCD_DataString(vout_str);
		vout_str[3]= (0,0,0);
	}
 		/*if (UART_Receive(&UARTData) == OK)
		{
			 LCD_Command(ClearDispaly);
			 LCD_Postion(0,1);
			 LCD_DataString("bluetooth---> connected ");	
 			 UART_SendChar(UARTData);
 			 switch(UARTData)
			{
 				case 0x34:
				     temp_FeedBack(25);
					 LCD_Postion(1,1);
					 LCD_DataString("flavor--> mint");
					 LCD_Postion(2,1);
					 LCD_DataString("Temp=");
					 LCD_Postion(2,6);
					 Tempc =TempStart();
					 U8Decimal2String(Tempc,vout_str);
					 LCD_DataString(vout_str);
					 vout_str[3]= (0,0,0);
					 while (statyState(25)==0)
					 {
						 temp_FeedBack(25);
						 Tempc =TempStart();
						 U8Decimal2String(Tempc,vout_str);
						 LCD_Postion(2,6);
						 LCD_DataString(vout_str);
						 vout_str[3]= (0,0,0);
					 }
					 PWM_MotorDriverChanger(80);
					 _delay_ms(3000);
					 PWM_MotorDriver_stop();
					 temp_FeedBack(15);
					 while (statyState(15)==0)
					 {
						 temp_FeedBack(15);
						 Tempc =TempStart();
						 U8Decimal2String(Tempc,vout_str);
						 LCD_Postion(2,6);
						 LCD_DataString(vout_str);
						 vout_str[3]= (0,0,0);
					 }
					 
 				break;
 				
 				case 0x35: //5 in ascii table
					temp_FeedBack(30);
					LCD_Postion(1,1);
					LCD_DataString("flavor--> spicy");
					LCD_Postion(2,1);
					LCD_DataString("Temp=");
					LCD_Postion(2,6);
					Tempc =TempStart();
					U8Decimal2String(Tempc,vout_str);
					LCD_DataString(vout_str);
					vout_str[3]= (0,0,0);
					while (statyState(30)==0)
					{
						temp_FeedBack(30);
						Tempc =TempStart();
						U8Decimal2String(Tempc,vout_str);
						LCD_Postion(2,6);
						LCD_DataString(vout_str);
						vout_str[3]= (0,0,0);
					}
					PWM_MotorDriverChanger(80);
					_delay_ms(3000);
					PWM_MotorDriver_stop();
					temp_FeedBack(35);
					while (statyState(35)==0)
					{
						temp_FeedBack(35);
						Tempc =TempStart();
						U8Decimal2String(Tempc,vout_str);
						LCD_Postion(2,6);
						LCD_DataString(vout_str);
						vout_str[3]= (0,0,0);
					}
 				break;
				 default:
				 LCD_Postion(1,1);
				 LCD_DataString("sorry,try again");
				 break;
				 
 			}*/
		}
	
	}
