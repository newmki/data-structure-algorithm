#include "bintree.h"

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (NULL);
	return (pBinTree->pRootNode);
}
