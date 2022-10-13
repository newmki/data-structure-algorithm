#include "simutil.h"

// 고객 도착 큐에 고객 추가.
void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue)
{
  if (pQueue == NULL)
  {
    printf("pQueue is NULL\n");
    return ;
  }
  if (arrivalTime < 0 || processTime < 0)
  {
    printf("Negative time is wrong\n");
    return ;
  }
  DequeNode pNode;
  pNode.data.status = arrival;
  pNode.data.arrivalTime = arrivalTime;
  pNode.data.serviceTime = processTime;
  pNode.data.startTime = 0;
  pNode.data.endTime = 0;
  // 대기 도착 큐에 넣기
  if (insertRearLD(pQueue, pNode) == 0)
  {
    printf("insertRear failure\n");
    return ;
  }
}
