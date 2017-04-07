#include <stm32f10x.h>

#include "movingControl.h"
#include "timeControl.h"

void clockwiseFullStepODR(int pulseLenth)
{
	{
		GPIOA->ODR |= GPIO_ODR_ODR6; //+A6
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR &= ~GPIO_ODR_ODR6; //-A6
		GPIOB->ODR |= GPIO_ODR_ODR1; //+B1
		timeWait(pulseLenth);
	}
	{
		GPIOB->ODR &= ~GPIO_ODR_ODR1; //-B1
		GPIOA->ODR |= GPIO_ODR_ODR7; //+A7
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR &= ~GPIO_ODR_ODR7; //+A7
		GPIOB->ODR |= GPIO_ODR_ODR0; //+B0
		timeWait(pulseLenth);
		GPIOB->ODR &= ~GPIO_ODR_ODR0; //-B0
	}
}

void clockwiseFullStepODRDualForTwo(int pulseLenth)
{
	{
		GPIOA->ODR |= GPIO_ODR_ODR6; //+A6
		GPIOA->ODR |= GPIO_ODR_ODR7; //+A7
		
		GPIOB->ODR |= GPIO_ODR_ODR0; //+B0
		GPIOB->ODR |= GPIO_ODR_ODR1; //+B1
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR &= ~GPIO_ODR_ODR7; //-A7
		GPIOB->ODR &= ~GPIO_ODR_ODR1; //-B1
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR &= ~GPIO_ODR_ODR6; //-A6
		GPIOB->ODR &= ~GPIO_ODR_ODR0; //-B0
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR |= GPIO_ODR_ODR7; //+A7
		GPIOB->ODR |= GPIO_ODR_ODR1; //+B0
		timeWait(pulseLenth);
		GPIOA->ODR &= ~GPIO_ODR_ODR7; //-A7
		GPIOB->ODR &= ~GPIO_ODR_ODR1; //-B1
	}
}

void clockwiseFullStepODRDual(int pulseLenth)
{
	{
		GPIOA->ODR |= GPIO_ODR_ODR6; //+A6
		GPIOA->ODR |= GPIO_ODR_ODR7; //+A7
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR &= ~GPIO_ODR_ODR7; //-A7
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR &= ~GPIO_ODR_ODR6; //-A6
		timeWait(pulseLenth);
	}
	{
		GPIOA->ODR |= GPIO_ODR_ODR7; //+A7
		timeWait(pulseLenth);
		GPIOA->ODR &= ~GPIO_ODR_ODR7; //-A7
	}
}

void clockwiseFullStep(int pulseLenth)
{
	{
		GPIOA->BSRR = GPIO_BSRR_BS6; //+A6
		GPIOB->BSRR = GPIO_BSRR_BS0; //+B0
		timeWait(pulseLenth);
	}
	{
		GPIOB->BSRR = GPIO_BSRR_BS1 | GPIO_BSRR_BR0; //+B1 -B0
		timeWait(pulseLenth);
	}
	{
		GPIOA->BSRR = GPIO_BSRR_BS7 | GPIO_BSRR_BR6; //+A7 -A6
		timeWait(pulseLenth);
	}
	{
		GPIOB->BSRR = GPIO_BSRR_BS0 | GPIO_BSRR_BR1; //+B0 -B1
		timeWait(pulseLenth);
		GPIOA->BSRR = GPIO_BSRR_BR7; //-A7
		GPIOB->BSRR = GPIO_BSRR_BR0; //-B0
	}
}

void clockwiseHalfStep(int pulseLenth)
{
	{
		GPIOA->BSRR = GPIO_BSRR_BS6; //+A6
		timeWait(pulseLenth);
	}
	{
		GPIOB->BSRR = GPIO_BSRR_BS1; //+B1
		timeWait(pulseLenth);
	}
	{
		GPIOA->BSRR = GPIO_BSRR_BR6; //-A6
		timeWait(pulseLenth);
	}
	{
		GPIOA->BSRR = GPIO_BSRR_BS7; //+A7
		timeWait(pulseLenth);
	}
	{
		GPIOB->BSRR = GPIO_BSRR_BR1; //-B1
		timeWait(pulseLenth);
	}
	{
		GPIOB->BSRR = GPIO_BSRR_BS0; //+B0
		timeWait(pulseLenth);
	}
	{
		GPIOA->BSRR = GPIO_BSRR_BR7; //-A7
		timeWait(pulseLenth);
	}
	{
		GPIOA->BSRR = GPIO_BSRR_BS6; //+A6
		timeWait(pulseLenth);
		GPIOA->BSRR = GPIO_BSRR_BR6; //-A6
		GPIOB->BSRR = GPIO_BSRR_BR0; //-B0
	}
}

void contrClockwiseStep(void)
{
	GPIOA->BSRR = GPIO_BSRR_BS7 | GPIO_BSRR_BR6;
	GPIOB->BSRR = GPIO_BSRR_BS1 | GPIO_BSRR_BR0;
	
	timeWait(10);
	
	GPIOA->ODR &= ~GPIO_ODR_ODR7;
	GPIOB->ODR &= ~GPIO_ODR_ODR1;
}

void contrClockwiseFullStep(int pulseLenth)
{
	{
		GPIOA->BSRR = GPIO_BSRR_BS7; //+A7
		GPIOB->BSRR = GPIO_BSRR_BS0; //+B0
		timeWait(pulseLenth);
	}
	{
		GPIOB->BSRR = GPIO_BSRR_BS1 | GPIO_BSRR_BR0; //+B1 -B0
		timeWait(pulseLenth);
	}
	{
		GPIOA->BSRR = GPIO_BSRR_BS6 | GPIO_BSRR_BR7; //+A6 -A7
		timeWait(pulseLenth);
	}
	{
		GPIOB->BSRR = GPIO_BSRR_BS0 | GPIO_BSRR_BR1; //+B0 -B1
		timeWait(pulseLenth);
		GPIOA->BSRR = GPIO_BSRR_BR6; //-A6
		GPIOB->BSRR = GPIO_BSRR_BS0; //-B0
	}

}
