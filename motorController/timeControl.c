#include <stm32f10x.h>

#include "timeControl.h"

void initTimer(void)
{
	SystemCoreClockUpdate();
	SysTick->LOAD = SystemCoreClock / 10000 - 1; //0,1 ms
	SysTick->VAL = 0;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_TICKINT_Msk;
}

void timeWait(uint32_t lenght)
{	
	SysTick->VAL = 0;
	
	uint32_t count = 0;
	
	while(count != lenght) 
	{
		if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk ) count++;
	}
}
