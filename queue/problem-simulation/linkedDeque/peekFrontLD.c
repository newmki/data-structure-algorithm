#include "linkedDeque.h"

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    return (NULL);
  }
  return (pDeque->pFrontNode);
}
