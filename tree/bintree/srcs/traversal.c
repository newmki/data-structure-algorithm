#include "bintree.h"

void preorder_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
  printf("%c ", pNode->data);
	preorder_traversal(pNode->pLeftChild);
	preorder_traversal(pNode->pRightChild);
}


void inorder_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	inorder_traversal(pNode->pLeftChild);
  printf("%c ", pNode->data);
	inorder_traversal(pNode->pRightChild);
}

void postorder_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	postorder_traversal(pNode->pLeftChild);
	postorder_traversal(pNode->pRightChild);
  printf("%c ", pNode->data);
}

void visited_zero_traversal(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	pNode->visited = 0;
	visited_zero_traversal(pNode->pLeftChild);
	visited_zero_traversal(pNode->pRightChild);
}
