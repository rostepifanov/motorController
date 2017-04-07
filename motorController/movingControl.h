#include <stm32f10x.h>

#include "pinRegistration.h"

#ifndef movingControl
#define movingControl

enum dir
{
	clockwise,
	contrClockwise
};

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



typedef struct motorDescriptor
{
	//for 0.1 ms
	pDescriptor pinA1;
	pDescriptor pinA2;
	pDescriptor pinB1;
	pDescriptor pinB2;
	uint32_t pulseTimeInTick;
	uint32_t tickCounter;
	enum state motorState;
	enum dir dirRotation;
} mDescriptor;

void clockwiseFullStepODR(int pulseLenth);
void clockwiseFullStep(int pulseLenth);
void clockwiseHalfStep(int pulseLenth);

void contrClockwiseStep(void);
void contrClockwiseFullStep(int pulseLenth);

void clockwiseFullStepODRDual(int pulseLenth);

void clockwiseFullStepODRDualForTwo(int pulseLenth);

#endif
