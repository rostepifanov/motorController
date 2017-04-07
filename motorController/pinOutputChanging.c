#include "pinOutputChanging.h"

void prepareRegisters(void)
{
	GPIOA->BSRR = 0x00;
	GPIOB->BSRR = 0x00;
	GPIOC->BSRR = 0x00;
}

void setBooleanOne(pDescriptor pin)
{
	switch (pin.type)  
  {  
	case typeA:
		GPIOA->BSRR = (uint32_t)0x0001 << pin.number;
		break;  
	case typeB:
		GPIOB->BSRR = (uint32_t)0x0001 << pin.number;	
		break;  
	case typeC: 
		GPIOC->BSRR = (uint32_t)0x0001 << pin.number;
		break;  
	}  
}

void setBooleanZero(pDescriptor pin)
{
	switch (pin.type)  
  {  
	case typeA:
		GPIOA->BSRR = (uint32_t)0x00010000 << pin.number;
		break;  
	case typeB:
		GPIOB->BSRR = (uint32_t)0x00010000 << pin.number;	
		break;  
	case typeC: 
		GPIOC->BSRR = (uint32_t)0x00010000 << pin.number;
		break;  
	}  
}
