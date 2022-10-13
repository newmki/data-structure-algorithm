#include <stdio.h>
#include <stdlib.h>
#include "polylist.h"

int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
  
	ListNode *prev = getLLElement(pList, degree);
	ListNode *node;
	
	node = (ListNode*)malloc(sizeof(ListNode));
	
	node->coef = coef;
	node->degree = degree;
	node->pLink = 0;

	if (prev == 0)
	{
		node->pLink = pList->headerNode.pLink;
		pList->headerNode.pLink = node;
	  pList->currentElementCount++;
	}
  else if (prev->degree == degree)
  {
    prev->coef += coef;
    free(node);
  }
	else
	{
		
		node->pLink = prev->pLink;
		prev->pLink = node;
	  pList->currentElementCount++;
	}
	
	
	return (TRUE);
}