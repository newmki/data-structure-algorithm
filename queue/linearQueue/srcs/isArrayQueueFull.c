#include "linearQueue.h"

int isArrayQueueFull(ArrayQueue* pQueue)
{
  if (pQueue == NULL)
    return (FALSE);
  if (pQueue->rear == pQueue->maxElementCount - 1 || pQueue->currentElementCount == pQueue->maxElementCount)
    return (TRUE);
  return (FALSE);
}