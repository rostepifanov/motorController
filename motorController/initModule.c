#include <stm32f10x.h>

#include "initModule.h"
#include "pinRegistration.h"
#include "timeControl.h"
#include "motorDescription.h"

//CNF
//00: General purpose output push-pull
//01: General purpose output Open-drain
//10: Alternate function output Push-pull
//11: Alternate function output Open-drain
		
//MODE
//00: Input mode (reset state)
//01: Output mode, max speed 10 MHz.
//10: Output mode, max speed 2 MHz.
//11: Output mode, max speed 50 MHz

static void initLed(void)
{
	pDescriptor led;
	led.number = 13;
	led.type = typeC;
	
	recordPushPullModePin(led);
	recordOutputModePin(led);
}

static void initClockGPIO(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
}

void init(void)
{
	initClockGPIO();
	
	initLed();
	
	initTimer();
}

 void initMotor(mDescriptor motor)
{
	recordPushPullModePin(motor.pinA1);
	recordOutputModePin(motor.pinA1);
	
	recordPushPullModePin(motor.pinA2);
	recordOutputModePin(motor.pinA2);
	
	recordPushPullModePin(motor.pinB1);
	recordOutputModePin(motor.pinB1);
	
	recordPushPullModePin(motor.pinB2);
	recordOutputModePin(motor.pinB2);
}
