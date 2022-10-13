#include "arraystack.h"

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (isArrayStackEmpty(pStack))
		return (FALSE);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}
