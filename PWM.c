/*
 * PWM.c
 *
 * Created: 11/28/2021 6:02:40 PM
 *  Author: mahmoud emad
 */ 
#include <avr/io.h>
#include "STD_Types.h"
#include "Dio.h"
#include "PWM.h"
void PWM_Init()
{
	//set the pin as output mode
	Dio_PinSetDirection(D,PD5,PinOutput);
	Dio_PinWrite(D,PD5,PinHigh);
	
	TCCR1A &=~(1<<WGM01);//set ctc mode
	TCCR1A &=~(1<<WGM00);//set ctc mode
	TCCR1B |=(1<<WGM12);//set ctc mode
	TCCR1A |= (1<<FOC1A); //forced compare mode
	TCCR1B &=~ (1<<WGM13);//set ctc mode
	TCCR1A &=~(1<<COM1A1);//toggle ctc mode
	TCCR1A |=(1<<COM1A0);//toggle ctc mode
	TCCR1B |=(1<<CS10);//set the prescaller
	TCCR1B |=(1<<CS11);//set the prescaller
	TCCR1B &=~(1<<CS12);//set the prescaller
	TIMSK |=(1<<OCIE1A); //enable ctc interrupt 
}

void PWM_changer (uint8 typ )
{
	
	switch (typ)
	{
		//1---> 50hz
		case 1 :
			OCR1AL=0b11000100;
			OCR1AH=0b00001001;//2500 ticks
			break;
		
		//2---> 100hz	
		case 2 :
		OCR1AL=0b11110010;
		OCR1AH=0b00001100;// 1250 ticks
		break;
		
		//3---> 400hz
		case 3 :
		OCR1AL=0b00101111;
		OCR1AH=0b00000001;//312 ticks
		break;

		//4---> 800hz
		case 4 :
// 		OCR1AL=0b10011100;
// 		OCR1AH=0b00000000;//165 ticks
OCR1A=8;
		break;

		//5---> 1000hz
		case 5 :
		OCR1AL=0b01111101;
		OCR1AH=0x00000000;//125 ticks
		break;
		default:
		break;
	}
	
	

}

void PWM_ON ()
{
	TCCR1B |=(1<<CS10);//set the prescaller
	TCCR1B |=(1<<CS11);//set the prescaller
	TCCR1B &=~(1<<CS12);//set the prescaller
}

void PWM_OFF ()
{
	TCCR1B &=~(1<<CS10);//timer off
	TCCR1B &=~(1<<CS11);//timer off
	TCCR1B &=~(1<<CS12);//timer off
}
ISR(TIMER1_COMPA_vect) //ISR for timer 1a compare mode
{
	ToggleBit(PORTD,PD5);
}