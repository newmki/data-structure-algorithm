#include "linearQueue.h"

void displayLinearQueue(ArrayQueue* pQueue)
{
  if (pQueue == NULL)
  {
    printf("pQueue is NULL\n");
    return ;
  }
  for (int i = pQueue->front; i <= pQueue->rear; i++)
  {
    printf("%d ", pQueue->pElement[i].data);
  }
  printf("\n");
}
