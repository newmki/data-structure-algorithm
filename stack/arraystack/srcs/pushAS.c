#include "arraystack.h"

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	if (!pStack)
		return (FALSE);
	if (isArrayStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount++].data = element.data;
	return (TRUE);
}
