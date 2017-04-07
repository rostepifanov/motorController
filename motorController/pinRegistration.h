#ifndef pinRegistration
#define pinRegistration

enum typePin
{
	typeA,
	typeB,
	typeC
};

typedef struct pinDescriptor
{
int number;
enum typePin type;
} pDescriptor;

void recordOutputModePin(pDescriptor pin);
void recordPushPullModePin(pDescriptor pin);

#endif
