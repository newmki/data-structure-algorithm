#include "bintree.h"

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *NewTreeNode;

	if (!pParentNode)
		return (NULL);
	if (!(NewTreeNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (NULL);
  if (pParentNode->pLeftChild != NULL)
    return (NULL);
	*NewTreeNode = element;
	NewTreeNode->pParent = pParentNode;
	pParentNode->pLeftChild = NewTreeNode;
	return (NewTreeNode);
}
