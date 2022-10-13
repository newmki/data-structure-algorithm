#include <stdlib.h>
#include "doublylist.h"

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
  DoublyListNode *new_node;
  DoublyListNode *next;
  DoublyListNode *prev;

  //예외처리
  if (position < 0 ||
      position > pList->currentElementCount)
      return (FALSE);
  
  //노드를 새로 할당
  new_node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
  new_node->data = element.data;
  new_node->pLLink = 0;
  new_node->pRLink = 0;

  //리스트가 비어있을경우,
  if  (pList->currentElementCount == 0)
  {
    new_node->pRLink = pList->headerNode.pRLink;
    new_node->pLLink = pList->headerNode.pLLink;
    pList->headerNode.pRLink = new_node;
    pList->headerNode.pLLink = new_node;
  }
  else
  {
    //리스트가 비어있지 않은경우, position이 0이어도 getDLElemet한 후 left를 보면 헤드가있어서 가능.
    next = getDLElement(pList, position);
    prev = next->pLLink;
    new_node->pLLink = prev;
    new_node->pRLink = next;
    prev->pRLink = new_node;
    next->pLLink = new_node;
  }
  pList->currentElementCount++;

  return (TRUE);
}