#include "linkedDeque.h"

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("RLD: pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pRearNode;
        pDeque->pRearNode = pDeque->pRearNode->pLLink;
    pReturn->pLLink = NULL;
    if (pDeque->currentElementCount == 1)
    {
      pDeque->pFrontNode = NULL;
    }
    else
    {
      pDeque->pRearNode->pRLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}
