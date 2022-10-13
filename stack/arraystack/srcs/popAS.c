#include "arraystack.h"

ArrayStackNode* popAS(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (isArrayStackEmpty(pStack))
		return (FALSE);
	return (&pStack->pElement[--pStack->currentElementCount]);
}
