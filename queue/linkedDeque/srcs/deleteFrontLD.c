#include "linkedDeque.h"

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pFrontNode;
		pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    pReturn->pRLink = NULL;
    if (pDeque->currentElementCount == 1)
    {
      pDeque->pRearNode = NULL;
    }
    else
    {
      pDeque->pFrontNode->pLLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}
