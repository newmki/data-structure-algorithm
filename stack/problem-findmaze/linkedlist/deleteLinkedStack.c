#include "linkedstack.h"

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode *pop;

	if(!pStack)
		return ;
	while((pop = popLS(pStack)))
		free(pop);
	free(pStack);
}
