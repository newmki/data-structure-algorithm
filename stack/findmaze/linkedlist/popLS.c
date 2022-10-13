#include "linkedstack.h"

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *pop;

	if (isLinkedStackEmpty(pStack))
		return (FALSE);
	pop = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	pStack->currentElementCount--;
	return (pop);
}
