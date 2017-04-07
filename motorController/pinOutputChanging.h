#include <stm32f10x.h>

#include "pinRegistration.h"

#ifndef pinOutputChanging
#define pinOutputChanging

void prepareRegisters(void);
void setBooleanOne(pDescriptor pin);
void setBooleanZero(pDescriptor pin);

#endif
