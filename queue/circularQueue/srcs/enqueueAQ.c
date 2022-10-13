#include "circularQueue.h"

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
      pQueue->rear = (pQueue->rear + 1) % (pQueue->maxElementCount);
      //(pQueue->rear)++;
      pQueue->pElement[pQueue->rear].data = element.data;
    }
    (pQueue->currentElementCount)++;
  }
  // max = 4
  // 0 1 2 3 front 0 rear 3
  // _ _ _ 3 front 3 rear 3
  // 4 5 _ 3 rear 1 front 3
  // 4 5 _ _ rear 1 front 0

  // _ _ _ _ rear 1 front 2
  else//pQueue is full
  {
    printf("pQueue is Full\n");
    return (FALSE);
  }
  return (TRUE);
}
