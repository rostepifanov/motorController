#include <stm32f10x.h>

#include "movingControl.h"
#include "timeControl.h"
#include "pinOutputChanging.h"

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

static void activePins(mDescriptor motor)
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

static void disactivePins(mDescriptor motor)
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

void inquiryMotor(mDescriptor* motor)
{
	motor->tickCounter++;
	if(motor->tickCounter == motor->pulseTimeInTick)
	{
		disactivePins(*motor);
		motor->motorState = fullStep[motor->motorState][motor->dirRotation];  
		activePins(*motor);
		motor->tickCounter = 0;
	}
}

void setSpeed(mDescriptor* motor, uint32_t speed)
{
	motor->pulseTimeInTick = speed;
	motor->tickCounter = 0;
}
void setDirection(mDescriptor* motor, enum dir direction)
{
	motor->dirRotation = direction;
}
