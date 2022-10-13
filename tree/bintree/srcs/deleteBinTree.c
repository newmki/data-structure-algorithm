#include "bintree.h"

void deleteBinTree(BinTree* pBinTree)
{
	BinTreeNode *pRootNode = pBinTree->pRootNode;

	if (!pBinTree)
		return ;
	while (pRootNode->pLeftChild != NULL || pRootNode->pRightChild != NULL)
		deleteBinTreeNode(pRootNode);
	free(pRootNode);
	pBinTree->pRootNode = NULL;
	free(pBinTree);
	return ;
}
