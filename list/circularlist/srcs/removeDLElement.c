#include "doublylist.h"
#include <stdlib.h>

int removeDLElement(DoublyList* pList, int position)
{
  DoublyListNode *remove;
  DoublyListNode *prev;
  DoublyListNode *next;

  //예외처리
  if (position < 0 ||
      position >= pList->currentElementCount)
          return (FALSE);

  //삭제할 노드의 정보가져오기
  remove = getDLElement(pList, position);
  //삭제할 노드의 이전(왼쪽)노드
  prev = remove->pLLink;
  //삭제할 노드의 이후(오른쪽)노드
  next = remove->pRLink;
  //연결
  prev->pRLink = next;
  next->pLLink = prev;
  //header와 노드 연결
  if(position == 0)
  {
    pList->headerNode.pRLink = next;
    pList->headerNode.pLLink = next;
  }
  //초기화 후 할당해제
  remove->data = 0;
  remove->pLLink = 0;
  remove->pRLink = 0;
  free(remove);
  pList->currentElementCount--;

  return(TRUE);
}