#include "circularQueue.h"

void deleteArrayQueue(ArrayQueue* pQueue)
{
  if (pQueue != NULL)
  {
    if (pQueue->pElement != NULL)
    {
      free(pQueue->pElement);
      pQueue->pElement = NULL;
    }
    free(pQueue);
  }
}
