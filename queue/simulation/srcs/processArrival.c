#include "simutil.h"

// 고객 도착 처리.
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
  if (pArrivalQueue == NULL)
  {
    printf("pArrivalQueue is NULL\n");
    return ;
  }
  if (isLinkedDequeEmpty(pArrivalQueue) == 1)//빈 리스트이면
  {
    return ;
  }
  while (isLinkedDequeEmpty(pArrivalQueue) == 0)
  {
    if (currentTime != peekFrontLD(pArrivalQueue)->data.arrivalTime)
    {
        break;
    }
    else
    {
        insertRearLD(pWaitQueue, *(deleteFrontLD(pArrivalQueue)));
    }
  }
}
