#include "linkedDeque.h"

void deleteLinkedDeque(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return ;
  }
  while (isLinkedDequeEmpty(pDeque) == FALSE)
  {
    DequeNode *pNode = deleteFrontLD(pDeque);
    pNode->pRLink = NULL;
    pNode->pLLink = NULL;
    free(pNode);
  }
}
