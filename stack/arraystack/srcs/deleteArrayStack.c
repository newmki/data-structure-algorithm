#include "arraystack.h"

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return ;
	for (int i = 0; i < pStack->maxElementCount; i++)
		pStack->pElement[i].data = 0;
	free(pStack->pElement);
	pStack->pElement = 0;
	free(pStack);
}
