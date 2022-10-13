#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack *LS;
	if (!(LS = (LinkedStack *)calloc(1, sizeof(LinkedStack))))
		return (FALSE);
	return (LS);
}
