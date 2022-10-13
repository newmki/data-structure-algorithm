#include "arraystack.h"

void dfs(ArrayStackNode *node, int idx, int size) {
	if (size == idx)
		return ;
	dfs(node, idx+1, size);
	printf("%c\n", node[idx].data);
}

void displayStack(ArrayStack *pStack)
{
	dfs(pStack->pElement, 0, pStack->currentElementCount);

}
