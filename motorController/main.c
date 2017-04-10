#include <stm32f10x.h>

#include "initModule.h"
#include "movingControl.h"
#include "timeControl.h"
#include "motorHardDescription.h"

#include "pinOutputChanging.h"
 
typedef struct vehicleDescriptor
{
	mDescriptor motorOne;
	mDescriptor motorTwo;
	mDescriptor motorThree;
	mDescriptor motorFour;
} vDescriptor;

vDescriptor test;

void SysTick_Handler(void)
{
	//inquiryMotor(&test.motorOne);
}

int main(void) 
{
	init();
	
	motorHardDescription(&test.motorOne);
	initMotor(test.motorOne);
	setSpeed(&test.motorOne, 14);
	setDirection(&test.motorOne, clockwise);
	
	while (1)
	{
		inquiryMotor(&test.motorOne);
//		disactivePins(test.motorOne);
//		test.motorOne.motorState = fullStep[test.motorOne.motorState][test.motorOne.dirRotation]; 
//		activePins(test.motorOne);
		timeWait(1);
	}
}
