/*
 * motor_driver.c
 *
 * Created: 2/17/2022 7:04:24 PM
 *  Author: Mahmoud Emad
 */ 
#include "motor_driver.h"
void MoterDriver_init()
{
	Dio_PinSetDirection (En01_port,En01_Pin,PinOutput); // set the enable 1 as output
	Dio_PinSetDirection (in01_port,in01_pin,PinOutput); // set the I/P as out put
	Dio_PinSetDirection (in02_port,in02_pin,PinOutput); // set the I/P as out put
}
void ColdSide()
{
	// enable on
	Dio_PinWrite(En01_port, En01_Pin,PinHigh);

	//Hot direction
	Dio_PinWrite(in01_port,in01_pin,PinHigh);
	
	// cool direction
	Dio_PinWrite(in02_port,in02_pin,PinLow);

	
}

void HotSide()
{
	// enable on
	Dio_PinWrite(En01_port, En01_Pin,PinHigh);

	//cool direction
	Dio_PinWrite(in01_port,in01_pin,PinLow);
	
	// cool direction
	Dio_PinWrite(in02_port,in02_pin,PinHigh);
}

void stop_motor()
{
	// enable OFF
	Dio_PinWrite(En01_port, En01_Pin,PinLow);

}


