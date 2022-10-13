#include "circularQueue.h"

int isArrayQueueFull(ArrayQueue* pQueue)
{
  if (pQueue == NULL)
    return (FALSE);
  if (pQueue->currentElementCount == pQueue->maxElementCount)
    return (TRUE);
  return (FALSE);
}
