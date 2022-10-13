#include "circularQueue.h"

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
  ArrayQueueNode *pNode;
  
  if (pQueue == NULL)
  {
    printf("pQueue is NULL\n");
    return (FALSE);
  }
  if (isArrayQueueEmpty(pQueue) == FALSE)
  {
    pNode = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode));
  	if (pNode == NULL)
 		{
    	printf("pNode malloc failure\n");
    	return (FALSE);
  	}
    pNode->data = pQueue->pElement[pQueue->front].data;
    pQueue->pElement[pQueue->front].data = 'A';
    pQueue->currentElementCount--;
    pQueue->front = (pQueue->front + 1) % (pQueue->maxElementCount);
    //pQueue->front++;
  }
  else//queue is empty
  {
    printf("pQueue is empty\n");
    return (NULL);
  }
  return (pNode);
}
