#include "linkedDeque.h"

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("peekRearLD: pDeque is Empty\n");
    return (NULL);
  }
  return (pDeque->pRearNode);
}
