#include <stm32f10x.h>

#include "pinRegistration.h"

#ifndef movingControl
#define movingControl

typedef enum direction 
{
	clockwise,
	contrClockwise
} dir;

enum state 
{
	A1,
	A2,
	B1,
	B2,
	A1B1,
	B1A2,
	A2B2,
	B2A1
};
	
enum state fullStep[4][2] =
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

//typedef struct motorDescriptor
//{
//	//for 0.1 ms
//	pDescriptor pinA1;
//	pDescriptor pinA2;
//	pDescriptor pinB1;
//	pDescriptor pinB2;
//	uint_32 pulseTimeInTick;
//	uint_32 tickTime;
//	state motorState;
//	dir dirRotation;
//} mDescriptor;

void clockwiseFullStepODR(int pulseLenth);
void clockwiseFullStep(int pulseLenth);
void clockwiseHalfStep(int pulseLenth);

void contrClockwiseStep(void);
void contrClockwiseFullStep(int pulseLenth);

void clockwiseFullStepODRDual(int pulseLenth);

void clockwiseFullStepODRDualForTwo(int pulseLenth);

#endif
