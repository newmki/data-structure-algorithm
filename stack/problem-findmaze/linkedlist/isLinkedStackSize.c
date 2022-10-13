#include "linkedstack.h"

int isLinkedStackSize(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->currentElementCount);
}
