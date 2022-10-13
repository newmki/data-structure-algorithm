#include "circularQueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
  ArrayQueue *pReturn;
  
  pReturn = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
	if (pReturn == NULL)
  {
    printf("malloc error\n");
    return (NULL);
  }
  pReturn->pElement = (ArrayQueueNode*)calloc(maxElementCount, sizeof(ArrayQueueNode));
  if (pReturn->pElement == NULL)
  {
    printf("pElement malloc error\n");
    free(pReturn);
    return (NULL);
  }
  pReturn->maxElementCount = maxElementCount;
  return (pReturn);
}
