#include <stm32f10x.h>

#include "initModule.h"
#include "movingControl.h"
#include "timeControl.h"
 
typedef struct vehicleDescriptor
{
	mDescriptor motorOne;
	mDescriptor motorTwo;
	mDescriptor motorThree;
	mDescriptor motorFour;
} vDescriptor;
 
//void inquiryMotor(mDescriptor motor)
//{
//	motor.tickCounter++;
//	if(motor.tickCounter != motor.pulseTimeInTick)
//	{
//		motor
//	}

//}
	

void SysTick_Handler(void)
{


}

int main(void) 
{
	init();

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
