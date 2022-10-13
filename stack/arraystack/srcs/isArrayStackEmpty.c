#include "arraystack.h"

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	return (pStack->currentElementCount == 0);
}
