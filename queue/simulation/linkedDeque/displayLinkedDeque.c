#include "linkedDeque.h"

void displayLinkedDeque(LinkedDeque* pDeque)
{
  DequeNode *pNode;
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return ;
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return ;
  }
  pNode = pDeque->pFrontNode;
  while (pNode != NULL)
  {
    // printf("%d ", pNode->data);
    pNode = pNode->pRLink;
  }
  printf("\n");
}
