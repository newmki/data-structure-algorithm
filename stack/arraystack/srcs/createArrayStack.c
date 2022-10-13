#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *as;

	as = (ArrayStack *)calloc(1, sizeof(ArrayStack));
	if (!as)
		return (FALSE);
	as->maxElementCount = maxElementCount;
	as->currentElementCount = 0;
	as->pElement = (ArrayStackNode *)calloc(maxElementCount, sizeof(ArrayStackNode));
	if (!as->pElement)
		return (FALSE);
	return (as);
}
