#include "polylist.h"
#include <stdio.h>

void displayPolynomial(LinkedList *pList)
{
  ListNode *curr;

  curr = pList->headerNode.pLink;
  while (curr)
  {
    printf("%.1fX^%d", curr->coef, curr->degree);
    if(curr->pLink)
      printf(" + ");
    curr = curr->pLink;
  }
  printf("\n");
}