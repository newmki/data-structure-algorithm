#include "doublylist.h"
#include <stdlib.h>

int removeDLElement(DoublyList* pList, int position)
{
  DoublyListNode *remove;
  DoublyListNode *prev;
  DoublyListNode *next;

  //����ó��
  if (position < 0 ||
      position >= pList->currentElementCount)
          return (FALSE);

  //������ ����� ������������
  remove = getDLElement(pList, position);
  //������ ����� ����(����)���
  prev = remove->pLLink;
  //������ ����� ����(������)���
  next = remove->pRLink;
  //����
  prev->pRLink = next;
  next->pLLink = prev;
  //header�� ��� ����
  if(position == 0)
  {
    pList->headerNode.pRLink = next;
    pList->headerNode.pLLink = next;
  }
  //�ʱ�ȭ �� �Ҵ�����
  remove->data = 0;
  remove->pLLink = 0;
  remove->pRLink = 0;
  free(remove);
  pList->currentElementCount--;

  return(TRUE);
}