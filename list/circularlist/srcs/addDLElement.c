#include <stdlib.h>
#include <stdio.h>
#include "doublylist.h"

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
  DoublyListNode *new_node;
  DoublyListNode *next;
  DoublyListNode *prev;
  DoublyListNode *last;
  DoublyListNode *first;

  //예외처리
  if (position < 0 ||
      position > pList->currentElementCount)
      return (FALSE);
  
  //노드를 새로 할당
  new_node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
  new_node->data = element.data;
  new_node->pLLink = new_node;
  new_node->pRLink = new_node;

  //리스트가 비어있을경우,
  if  (pList->currentElementCount == 0)
  {
    pList->headerNode.pRLink = new_node;
    pList->headerNode.pLLink = new_node;
  }
  else if(position == 0)
  {
    //원형 연결리스트의 마지막노드.
    last = pList->headerNode.pRLink->pLLink;
    //헤더와 연결된 첫번째노드.
    first = last->pRLink;
    //새로운 노드의 오른쪽 == 기존의 첫번째
    new_node->pRLink = first;
    //새로운 노드의 왼쪽 == 기존의 마지막
    new_node->pLLink = last;
    //기존의 첫노드의 왼쪽 == 새로운 노드
    first->pLLink = new_node;
    //기존의 마지막 노드의 오른쪽 == 새로운노드
    last->pRLink = new_node;
    //헤더와 새로운 노드를 연결.
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