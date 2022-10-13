#include <stdio.h>
#include "doublylist.h"

void displayDoublyList(DoublyList* pList)
{
  DoublyListNode *move;
  int cnt = 0;
  move = pList->headerNode.pRLink;
  while (cnt < pList->currentElementCount * 2)
  {
    printf("%d ", move->data);
    cnt++;
    move = move->pRLink;
  }
  printf("\n");
}