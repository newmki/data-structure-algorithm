#include "bintree.h"

int main()
{
	BinTreeNode rootNode_a = {'a', 0, 0, 0, 0};
	BinTreeNode rootNode_b = {'b', 0, 0, 0, 0};
	BinTreeNode rootNode_c = {'c', 0, 0, 0, 0};
	BinTreeNode rootNode_d = {'d', 0, 0, 0, 0};
	BinTreeNode rootNode_e = {'e', 0, 0, 0, 0};
	BinTreeNode rootNode_f = {'f', 0, 0, 0, 0};
	BinTreeNode rootNode_g = {'g', 0, 0, 0, 0};
	BinTreeNode rootNode_h = {'h', 0, 0, 0, 0};
	BinTreeNode rootNode_i = {'i', 0, 0, 0, 0};
	BinTreeNode rootNode_j = {'j', 0, 0, 0, 0};
	BinTreeNode rootNode_k = {'k', 0, 0, 0, 0};
	BinTreeNode rootNode_l = {'l', 0, 0, 0, 0};
	BinTreeNode rootNode_m = {'m', 0, 0, 0, 0};
	BinTree *bintree = makeBinTree(rootNode_a);
	BinTreeNode *curr;

	insertLeftChildNodeBT(bintree->pRootNode, rootNode_b);
	insertRightChildNodeBT(bintree->pRootNode, rootNode_c);
	curr = getLeftChildNodeBT(bintree->pRootNode);
	insertLeftChildNodeBT(curr, rootNode_d);
	insertLeftChildNodeBT(curr->pLeftChild, rootNode_h);
	insertRightChildNodeBT(curr->pLeftChild, rootNode_i);
	insertRightChildNodeBT(curr, rootNode_e);
	insertLeftChildNodeBT(curr->pRightChild, rootNode_j);

	curr = getRightChildNodeBT(bintree->pRootNode);
	insertLeftChildNodeBT(curr, rootNode_f);
	insertRightChildNodeBT(curr->pLeftChild, rootNode_k);
	insertRightChildNodeBT(curr, rootNode_g);
	insertLeftChildNodeBT(curr->pRightChild, rootNode_l);
	insertRightChildNodeBT(curr->pRightChild, rootNode_m);

	printf("=========preorder===========\n");
	preorder_traversal(bintree->pRootNode);
	printf("\n===========done============\n");

	printf("\n=========inorder===========\n");
	inorder_traversal(bintree->pRootNode);
	printf("\n===========done============\n");

	printf("\n=========postorder===========\n");
	postorder_traversal(bintree->pRootNode);
	printf("\n===========done==============\n");

	deleteBinTree(bintree);

	return 0;
}
