#include "../includes/binsearchtree.h"
#include <stdio.h>
#include <stdlib.h>

// 인자가 없어서 pRootNode를 만들 필요가 없다.
BinSearchTree* createBinSearchTree()
{
	BinSearchTree *bst;

    if (!(bst = (BinSearchTree *)calloc(1, sizeof(BinSearchTree))))
        return (NULL);
    return(bst);
}

int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element)
{
    if (!pBinSearchTree)
        return (FALSE);
	BinSearchTreeNode *new_node;
	BinSearchTreeNode *tmp_node;
	BinSearchTreeNode *parent;
	
	if (searchInternalRecursiveBST(pBinSearchTree->pRootNode, element.key, &parent) != NULL)
			return (FALSE);
	if (!(new_node = (BinSearchTreeNode *)calloc(1, sizeof(BinSearchTreeNode))))
		return (FALSE);
    *new_node = element;
    if (pBinSearchTree->pRootNode == NULL)
		pBinSearchTree->pRootNode = new_node;
    else
    {
        tmp_node = pBinSearchTree->pRootNode;
		while (1)
		{
            // Go left
            if (tmp_node->key > new_node->key)
			{
				if (tmp_node->pLeftChild == NULL)
				{
					tmp_node->pLeftChild = new_node;
					break;
				}
				else
					tmp_node = tmp_node->pLeftChild;
			}	
            // Go Right
            else
            {
				if (tmp_node->pRightChild == NULL)
				{
					tmp_node->pRightChild = new_node;
					break;
				}
				else
					tmp_node = tmp_node->pRightChild;
            }
        }
    }
    return (TRUE);
}

int deleteElementBST(BinSearchTree* pBinSearchTree, int key)
{
    if (!pBinSearchTree)
        return (FALSE);
    BinSearchTreeNode *parent;
	
    BinSearchTreeNode *temp_node = searchInternalRecursiveBST(pBinSearchTree->pRootNode, key, &parent);
	if (temp_node == NULL)
		return (FALSE);
    
	// 말단일때
	if (temp_node->pLeftChild == NULL && temp_node->pRightChild == NULL)
    {
        if (parent->pLeftChild == temp_node)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
        temp_node->pLeftChild = NULL;
        temp_node->pRightChild = NULL;
		free(temp_node);
    }
	// 한쪽만 있을 때
    else if (temp_node->pLeftChild == NULL)
    {
        if (parent->pLeftChild == temp_node)
			parent->pLeftChild = temp_node->pRightChild;
		else
			parent->pRightChild = temp_node->pRightChild;
        temp_node->pLeftChild = NULL;
        temp_node->pRightChild = NULL;
		free(temp_node);
    }
    else if (temp_node->pRightChild == NULL)
    {
        if (parent->pLeftChild == temp_node)
			parent->pLeftChild = temp_node->pLeftChild;
		else
			parent->pRightChild = temp_node->pLeftChild;
        temp_node->pLeftChild = NULL;
        temp_node->pRightChild = NULL;
		free(temp_node);
    }
	// 둘 다 있을 때 Right -> 계속 Left
    else
    {
        BinSearchTreeNode *start = temp_node->pRightChild;
		while (start->pLeftChild)
		{
			start = start->pLeftChild;
		}
    }
}



// BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key, BinSearchTreeNode** parent)
// {
//     if (!pBinSearchTree)
//         return (NULL);
//     if (parent.)
// 	BinSearchTreeNode *curr;
	


// }

BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode* pTreeNode, int key, BinSearchTreeNode** parent)
{
    if (!pTreeNode)
		return (NULL);
    if (pTreeNode->key == key)
        return (pTreeNode);
	*parent = pTreeNode;
	if (pTreeNode->key > key)
		return(searchInternalRecursiveBST(pTreeNode->pLeftChild, key, parent));
	return(searchInternalRecursiveBST(pTreeNode->pRightChild, key, parent));
}

// BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key, BinSearchTreeNode** parent)
// {

// }


// void deleteBinSearchTree(BinSearchTree* pBinSearchTree)
// {

// }

// void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode)
// {

// }

void displayBinSearchTree(BinSearchTreeNode* pBinSearchTreeNode)
{
    if (!pBinSearchTreeNode)
		return ;
	displayBinSearchTree(pBinSearchTreeNode->pLeftChild);
    printf("key: %d, value: %c\n", pBinSearchTreeNode->key, pBinSearchTreeNode->value);
	displayBinSearchTree(pBinSearchTreeNode->pRightChild);
}

int main(void)
{
    BinSearchTreeNode BST1 = {1, 'A', 0, 0};
    BinSearchTreeNode BST5 = {5, 'E', 0, 0};
    BinSearchTreeNode BST2 = {2, 'B', 0, 0};
    BinSearchTreeNode BST4 = {4, 'D', 0, 0};
    BinSearchTreeNode BST3 = {3, 'C', 0, 0};
    BinSearchTreeNode BST6 = {6, 'F', 0, 0};
    BinSearchTree* BST = createBinSearchTree();
    insertElementBST(BST, BST1);
    insertElementBST(BST, BST3);
    insertElementBST(BST, BST4);
    insertElementBST(BST, BST2);
    insertElementBST(BST, BST6);
    insertElementBST(BST, BST5);
    displayBinSearchTree(BST->pRootNode);
    return (0);
}