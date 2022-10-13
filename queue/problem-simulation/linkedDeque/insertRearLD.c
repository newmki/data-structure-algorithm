#include "linkedDeque.h"

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
  DequeNode *pNode;
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (FALSE);
  }
  pNode = (DequeNode*)calloc(1, sizeof(DequeNode));
  if (pNode == NULL)
  {
    printf("pNode malloc failure\n");
    return (FALSE);
  }
  pNode->data = element.data;
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    pDeque->pFrontNode = pNode;
    pDeque->pRearNode = pNode;
  }
  else
  {
    pDeque->pRearNode->pRLink = pNode;
    pNode->pLLink = pDeque->pRearNode;
    pDeque->pRearNode = pNode;
  }
  (pDeque->currentElementCount)++;
  return (TRUE);
}
