/*
 * temp_sesor.h
 *
 * Created: 2/17/2022 9:46:00 PM
 *  Author: Mahmoud Emad
 */ 
#include <avr/io.h>
#include "ADC.h"
#include "STD_Types.h"
#include "motor_driver.h"
#include "StringHandler.h"
#include "LCD.h"
#define tempSensor 3

int TempStart ();
void temp_FeedBack (uint16 Reg_Temp);
ReturnValueType statyState(uint16 Reg_Temp);
void PWM_MotorDriverInit();
int PWM_MotorDriverChanger (uint16 duty);
void PWM_MotorDriver_stop();



