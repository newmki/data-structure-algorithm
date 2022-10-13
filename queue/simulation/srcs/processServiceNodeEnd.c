#include "simutil.h"

// 서비스 종료 처리.
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
  int endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
  if (endTime == currentTime)
  {
    pServiceNode->data.endTime = endTime;
    pServiceNode->data.status = end;
    //여기서 고객의 상태 출력
    if (pServiceNode != NULL)
      printSimCustomer(currentTime, pServiceNode->data);

    (*pServiceUserCount)++;
    (*pTotalWaitTime) = (*pTotalWaitTime) + (pServiceNode->data.startTime - pServiceNode->data.arrivalTime);//waiting time 더하기
    free(pServiceNode);
    return NULL;
  }
  return pServiceNode;
}
