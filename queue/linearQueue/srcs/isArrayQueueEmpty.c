#include "linearQueue.h"

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
  if (pQueue->currentElementCount != 0)
    return (FALSE);
  return (TRUE);
}
