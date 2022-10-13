#include "arraystack.h"

int isArrayStackFull(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->maxElementCount == pStack->currentElementCount);
}
