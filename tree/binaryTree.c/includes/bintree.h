#ifndef _BIN_TREE_
#define _BIN_TREE_

#include <stdlib.h>
#include <stdio.h>

typedef struct BinTreeNodeType
{
	char data;
	int visited;
	struct BinTreeNodeType *pParent;
	struct BinTreeNodeType *pLeftChild;
	struct BinTreeNodeType *pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);

void preorder_traversal(BinTreeNode *pNode);
void inorder_traversal(BinTreeNode *pNode);
void postorder_traversal(BinTreeNode *pNode);
void visited_zero_traversal(BinTreeNode *pNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif