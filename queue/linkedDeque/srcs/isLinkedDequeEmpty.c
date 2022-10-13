#include "linkedDeque.h"

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
  }
  if (pDeque->currentElementCount == 0 && pDeque->pFrontNode == NULL && pDeque->pRearNode == NULL)
  {
    return (TRUE);
  }
  return (FALSE);
}
