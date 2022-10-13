#include "circularQueue.h"

void displayCircularQueue(ArrayQueue* pQueue)
{
  if (pQueue == NULL)
  {
    printf("pQueue is NULL\n");
    return ;
  }
  printf("front: %d rear: %d ->", pQueue->front, pQueue->rear);
  for (int i = 0; i < pQueue->maxElementCount; i++)
  {
    if (pQueue->pElement[i].data == 'A')
    {
      printf("_ ");
    }
    else
    {
      printf("%d ", pQueue->pElement[i].data);
    }
  }
  printf("\n");
}
