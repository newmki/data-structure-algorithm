#include "bintree.h"

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *NewTreeNode;

	if (!pParentNode)
		return (NULL);
	if (!(NewTreeNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (NULL);
  if (pParentNode->pRightChild != NULL)
    return (NULL);
	*NewTreeNode = element;
	NewTreeNode->pParent = pParentNode;
	pParentNode->pRightChild = NewTreeNode;
	return (NewTreeNode);
}
