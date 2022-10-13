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

  //����ó��
  if (position < 0 ||
      position > pList->currentElementCount)
      return (FALSE);
  
  //��带 ���� �Ҵ�
  new_node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
  new_node->data = element.data;
  new_node->pLLink = new_node;
  new_node->pRLink = new_node;

  //����Ʈ�� ����������,
  if  (pList->currentElementCount == 0)
  {
    pList->headerNode.pRLink = new_node;
    pList->headerNode.pLLink = new_node;
  }
  else if(position == 0)
  {
    //���� ���Ḯ��Ʈ�� ���������.
    last = pList->headerNode.pRLink->pLLink;
    //����� ����� ù��°���.
    first = last->pRLink;
    //���ο� ����� ������ == ������ ù��°
    new_node->pRLink = first;
    //���ο� ����� ���� == ������ ������
    new_node->pLLink = last;
    //������ ù����� ���� == ���ο� ���
    first->pLLink = new_node;
    //������ ������ ����� ������ == ���ο���
    last->pRLink = new_node;
    //����� ���ο� ��带 ����.
    pList->headerNode.pRLink = new_node;
    pList->headerNode.pLLink = new_node;
  }
  else
  {
    //����Ʈ�� ������� �������, position�� 0�̾ getDLElemet�� �� left�� ���� ��尡�־ ����.
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