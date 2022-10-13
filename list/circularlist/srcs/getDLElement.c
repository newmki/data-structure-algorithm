#include <stdlib.h>
#include "doublylist.h"

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
  DoublyListNode *move;
  int cnt = 0;

  //position 예외처리
  if (position < 0 ||
      position >= pList->currentElementCount)
      return (FALSE);
  //순회할 노드
  move = pList->headerNode.pRLink;

  while (cnt < position)
  {
    move = move->pRLink;
    cnt++;
  }

  return (move);
}