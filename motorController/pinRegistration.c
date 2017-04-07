#include <stm32f10x.h>

#include "pinRegistration.h"

const uint32_t byteStride = 4;

void recordOutputModePin(pDescriptor pin)
{
	switch (pin.type)  
  {  
	case typeA:
		if(pin.number < 8)
		{
			GPIOA->CRL &= ~(uint32_t)(0x3 << pin.number * byteStride);
			GPIOA->CRL |= (uint32_t)(0x2 << pin.number * byteStride);
		}		
		else
		{
			GPIOA->CRH &= ~(uint32_t)(0x3 << (pin.number - 8) * byteStride);
			GPIOA->CRH |= (uint32_t)(0x2 << (pin.number - 8) * byteStride);
		}
		break;  
	case typeB:
		if(pin.number < 8)
		{
			GPIOB->CRL &= ~(uint32_t)(0x3 << pin.number * byteStride);
			GPIOB->CRL |= (uint32_t)(0x2 << pin.number * byteStride);
		}		
		else
		{
			GPIOB->CRH &= ~(uint32_t)(0x3 << (pin.number - 8) * byteStride);
			GPIOB->CRH |= (uint32_t)(0x2 << (pin.number - 8) * byteStride);
		}		
		break;  
	case typeC: 
		if(pin.number < 8)
		{
			GPIOC->CRL &= ~(uint32_t)(0x3 << pin.number * byteStride);
			GPIOC->CRL |= (uint32_t)(0x2 << pin.number * byteStride);
		}		
		else
		{
			GPIOC->CRH &= ~(uint32_t)(0x3 << (pin.number - 8) * byteStride);
			GPIOC->CRH |= (uint32_t)(0x2 << (pin.number - 8) * byteStride);
		}		
		break;  
	}  
	
}

void recordPushPullModePin(pDescriptor pin)
{
	switch (pin.type)  
  {  
	case typeA:
		if(pin.number < 8)
		{
			GPIOA->CRL &= ~(uint32_t)(0xC << pin.number * byteStride);
		}		
		else
		{
			GPIOA->CRH &= ~(uint32_t)(0xC << (pin.number - 8) * byteStride);
		}
		break;  
	case typeB:
		if(pin.number < 8)
		{
			GPIOB->CRL &= ~(uint32_t)(0xC << pin.number * byteStride);
		}		
		else
		{
			GPIOB->CRH &= ~(uint32_t)(0xC << (pin.number - 8) * byteStride);
		}		
		break;  
	case typeC: 
		if(pin.number < 8)
		{
			GPIOC->CRL &= ~(uint32_t)(0xC << pin.number * byteStride);
		}		
		else
		{
			GPIOC->CRH &= ~(uint32_t)(0xC << (pin.number - 8) * byteStride);
		}		
		break;  
	}  
	
}