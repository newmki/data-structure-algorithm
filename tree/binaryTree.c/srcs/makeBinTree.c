#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *bintree;

	if (!(bintree = (BinTree*)calloc(1, sizeof(BinTree))))
		return (NULL);
	if (!(bintree->pRootNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode))))
  {
    free(bintree);
		return (NULL);
  }
	*bintree->pRootNode = rootNode;
	bintree->pRootNode->pParent = NULL;
	return (bintree);
}
