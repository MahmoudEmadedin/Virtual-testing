/*
 * motor_driver.h
 *
 * Created: 2/17/2022 7:04:39 PM
 *  Author: mahmoud emad
 */ 
#include <avr/io.h>
#include "Dio.h"



/* Define of pins and ports */
#define in01_port B
#define in01_pin  4
#define in02_port B
#define in02_pin  0
#define En01_port D
#define En01_Pin  7



/* Definition of used functions*/
void MoterDriver_init();
void ColdSide();
void HotSide();
void stop_motor();