#include <stm32f10x.h>

#include "pinRegistration.h"
#include "motorDescription.h"

#ifndef movingControl
#define movingControl

extern enum state fullStep[8][2];

void inquiryMotor(mDescriptor* motor);
void setSpeed(mDescriptor* motor, uint32_t speed);
void setDirection(mDescriptor* motor, enum dir direction);

#endif
