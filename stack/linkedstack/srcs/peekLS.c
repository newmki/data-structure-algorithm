#include "linkedstack.h"

StackNode* peekLS(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->pTopElement);
}
