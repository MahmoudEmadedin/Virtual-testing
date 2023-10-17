/*
 * ADC.c
 *
 * Created: 10/28/2021 3:25:17 PM
 *  Author: Mahmoud Emad
 */ 
#include "ADC.h"
void Adc_Init(void) 
{
ADCSRA |=(1<<ADEN); // enable adc
}

void Adc_ChannelInit(uint8 ADC_Channel)
{
	
			Dio_PinSetDirection(A,ADC_Channel,PinInput);// make the pin as input
			ADMUX= (ADMUX & ~0x1F) | (ADC_Channel & 0x1F) ;
	
}
int Adc_ReadChannel(uint8 ADC_Channel , uint16* Adc_Data)
{
	ADCSRA |= (1<<ADSC) ; // start conversion
	while (GetBit(ADCSRA,ADIF) == 0);
	*Adc_Data = ADCL ;
	*Adc_Data |= (uint16) (ADCH<<8) ;// pointer point to adc 
	return *Adc_Data;
}