#include "linearQueue.h"

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
  if (pQueue == NULL)
  {
    printf("pQueue is NULL\n");
    return (FALSE);
  }
  if (isArrayQueueFull(pQueue) == FALSE)
  {
    if (isArrayQueueEmpty(pQueue) == TRUE)
    {
      pQueue->pElement[pQueue->rear].data = element.data;
    }
    else
    {
      (pQueue->rear)++;
      pQueue->pElement[pQueue->rear].data = element.data;
    }
    (pQueue->currentElementCount)++;
  }
  else//pQueue is full
  {
    printf("pQueue is Full\n");
    return (FALSE);
  }
  return (TRUE);
}
