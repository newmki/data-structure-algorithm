#include "linkedstack.h"

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (!pStack->pTopElement)
		return (TRUE);
	return (FALSE);
}
