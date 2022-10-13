#include "linkedstack.h"

void	delete_test()
{
	LinkedStack *as = 0;
	StackNode ele;

	ele.data = 3;
	as = createLinkedStack();
	for (int i = 0; i < 3; i++)
		pushLS(as, ele);
	deleteLinkedStack(as);
}

void displayStack(LinkedStack *pStack)
{
	StackNode *origin = pStack->pTopElement;

	for (int i = 0; i < pStack->currentElementCount; i++)
	{
		printf("%c\n", pStack->pTopElement->data);
		pStack->pTopElement = pStack->pTopElement->pLink;
	}
	pStack->pTopElement = origin;
}


int		main(void)
{
	char c;
	LinkedStack *ls = 0;
	StackNode node;
	node.data = 0;
	StackNode *pop;

	while(1)
	{
		printf("put Create Push pOp pEek Delete: ");
		scanf(" %c", &c);
		switch (c)
		{
		case 'C':
			ls = createLinkedStack();
			break;
		case 'P':
			printf("put node : ");
			scanf(" %c", &c);
			node.data = c;
			pushLS(ls, node);
			break;
		case 'O':
			pop = popLS(ls);
			if (pop)
				printf("%c\n", pop->data);
			free(pop);
			break;
		case 'E':
			pop = peekLS(ls);
			if (pop)
				printf("%c\n", pop->data);
			break;
		case 'D':
			delete_test();
			system("leaks linkedstack");
			break;
		case 'Y':
			displayStack(ls);
			break;
		default:
			break;
		}
	}
}
