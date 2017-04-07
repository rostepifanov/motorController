#include <stm32f10x.h>

#include "initModule.h"
#include "pinRegistration.h"
#include "timeControl.h"

#include "movingControl.h"

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

void initLed(void)
{
	pDescriptor led;
	led.number = 13;
	led.type = typeC;
	
	recordPushPullModePin(led);
	recordOutputModePin(led);
}

void initFirstMotor(void)
{
	//PB10 - black
	//PC14 - white
	//PB11 - gray
	//PC15 - violet
	
	{//B10
		GPIOB->CRH &= ~GPIO_CRH_CNF10;
		GPIOB->CRH &= ~GPIO_CRH_MODE10;
		GPIOB->CRH |= GPIO_CRH_MODE10_1;
	}
	{//B11
		GPIOB->CRH &= ~GPIO_CRH_CNF11;
		GPIOB->CRH &= ~GPIO_CRH_MODE11;
		GPIOB->CRH |= GPIO_CRH_MODE11_1;
	}
	{//C14
		GPIOC->CRH &= ~GPIO_CRH_CNF14;
		GPIOC->CRH &= ~GPIO_CRH_MODE14;
		GPIOC->CRH |= GPIO_CRH_MODE14_1;
	}
	{//C15
		GPIOC->CRH &= ~GPIO_CRH_CNF15;
		GPIOC->CRH &= ~GPIO_CRH_MODE15;
		GPIOC->CRH |= GPIO_CRH_MODE15_1;
	}
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
	
	//initMotor();
	
	initTimer();
}
