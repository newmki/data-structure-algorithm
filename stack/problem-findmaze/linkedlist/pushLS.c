#include "linkedstack.h"

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new;

	if (!pStack)
		return (FALSE);
	if (!(new = (StackNode *)calloc(1, sizeof(StackNode))))
		return (FALSE);
	*new = element;
	new->pLink = pStack->pTopElement;
	pStack->pTopElement = new;
	pStack->currentElementCount++;
	return (TRUE);
}
