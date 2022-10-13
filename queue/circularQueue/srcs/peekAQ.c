#include "circularQueue.h"

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
  if (pQueue == NULL)
  {
    printf("pQueue is NULL\n");
    return (FALSE);
  }
  if (isArrayQueueEmpty(pQueue) == FALSE)
  {
  	return (&pQueue->pElement[pQueue->front]);
  }
  else//queue is empty
  {
    printf("pQueue is empty\n");
  }
  return (NULL);
}
