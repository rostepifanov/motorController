#include <stm32f10x.h>

#include "initModule.h"
#include "movingControl.h"
#include "timeControl.h"

#include "pinOutputChanging.h"
 
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
 
 enum state fullStep[8][2] =
{
  [A1B1][clockwise] = B1A2,
  [B1A2][clockwise] = A2B2,
	[A2B2][clockwise] = B2A1,
	[B2A1][clockwise] = A1B1,
	
	[A1B1][contrClockwise] = B2A1,
  [B2A1][contrClockwise] = A2B2,
	[A2B2][contrClockwise] = B1A2,
	[B1A2][contrClockwise] = A1B1
};
 
typedef struct vehicleDescriptor
{
	mDescriptor motorOne;
	mDescriptor motorTwo;
	mDescriptor motorThree;
	mDescriptor motorFour;
} vDescriptor;

void motorStep(mDescriptor motor)
{
	motor.motorState = fullStep[motor.motorState][motor.dirRotation];
}

void activePins(mDescriptor motor)
{
	switch(motor.motorState)
	{  
	case A1B1:
		setBooleanOne(motor.pinA1);
		setBooleanOne(motor.pinB1);
		break;  
	case B1A2:
		setBooleanOne(motor.pinB1);
		setBooleanOne(motor.pinA2);
		break;  
	case A2B2: 
		setBooleanOne(motor.pinA2);
		setBooleanOne(motor.pinB2);
		break; 
	case B2A1: 
		setBooleanOne(motor.pinB2);
		setBooleanOne(motor.pinA1);
		break;	
	}  	
}

void disactivePins(mDescriptor motor)
{
	switch(motor.motorState)
	{  
	case A1B1:
		setBooleanZero(motor.pinA1);
		setBooleanZero(motor.pinB1);
		break;  
	case B1A2:
		setBooleanZero(motor.pinB1);
		setBooleanZero(motor.pinA2);
		break;  
	case A2B2: 
		setBooleanZero(motor.pinA2);
		setBooleanZero(motor.pinB2);
		break; 
	case B2A1: 
		setBooleanZero(motor.pinB2);
		setBooleanZero(motor.pinA1);
		break;	
	}  	
}

void inquiryMotor(mDescriptor motor)
{
	motor.tickCounter++;
	if(motor.tickCounter != motor.pulseTimeInTick)
	{
		disactivePins(motor);
		motorStep(motor); 
		activePins(motor);
	}
}
	
mDescriptor motorOne;

void motorHardDescription(void)
{
	pDescriptor pin;
	pin.type = typeC;
	pin.number = 15;
	motorOne.pinA1 = pin;
	
	pin.type = typeB;
	pin.number = 11;
	motorOne.pinA2 = pin;
	
	pin.type = typeC;
	pin.number = 14;
	motorOne.pinB2 = pin;
	
	pin.type = typeB;
	pin.number = 10;
	motorOne.pinB1 = pin;
}

vDescriptor test;

void SysTick_Handler(void)
{
	inquiryMotor(test.motorOne);
}

int main(void) 
{
	init();
	
	motorHardDescription();
	
	initMotor(motorOne);
	
	test.motorOne = motorOne;
	
	//for(int i = 0; i < 500; i++)
	//{
	//	clockwiseFullStepODRDual(14);
	//}
	
	while (1)
	{
	//	clockwiseFullStepODRDualForTwo(14);
		GPIOC->BSRR = GPIO_BSRR_BR13;
	}
}
