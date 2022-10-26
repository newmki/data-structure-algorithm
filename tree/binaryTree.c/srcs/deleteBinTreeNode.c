#include "bintree.h"

void deleteBinTreeNode(BinTreeNode* pNode)
{
	BinTreeNode *curr;

	if (!pNode)
		return ;
	curr = pNode;
	while (curr)
	{
		if (curr->pRightChild)
			curr = curr->pRightChild;
		else if (curr->pLeftChild)
			curr = curr->pLeftChild;
		else
			break ;
	}
	if (curr->pParent == NULL)
	{
		free(curr);
		return ;
	}
	if (curr->pParent->pRightChild == curr)
		curr->pParent->pRightChild = NULL;
	else if (curr->pParent->pLeftChild == curr)
		curr->pParent->pLeftChild = NULL;
	pNode->data = curr->data;
	free(curr);
}
