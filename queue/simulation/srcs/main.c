#include "simutil.h"

int main(void)
{
  LinkedDeque *pArrivalQueue = createLinkedDeque();; // 고객 도착 큐
  LinkedDeque *pWaitQueue = createLinkedDeque(); // 고객 대기 큐
  DequeNode *pServiceNode = NULL; // 서비스 노드
  int endtime = 10;//종료 시간
  int totalWaitTime = 0;//총 대기 시간
  int userCount = 0;//총 유저 수
  insertCustomer(0, 3, pArrivalQueue);
  insertCustomer(2, 2, pArrivalQueue);
  insertCustomer(4, 1, pArrivalQueue);
  insertCustomer(6, 1, pArrivalQueue);
  insertCustomer(8, 3, pArrivalQueue);
  for(int currentTime = 0; currentTime < endtime; currentTime++)
  {
    //processArrival;
    processArrival(currentTime, pArrivalQueue, pWaitQueue);
    if (pServiceNode != NULL)
    {
      pServiceNode = processServiceNodeEnd(currentTime, pServiceNode, &userCount, &totalWaitTime);
    }
    if (pServiceNode == NULL)
    {
      pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
      if (pServiceNode != NULL)
          printSimCustomer(currentTime, pServiceNode->data);
    }
    printWaitQueueStatus(currentTime, pWaitQueue);
  };
  printReport(pWaitQueue, userCount, totalWaitTime);
  return (0);
}
