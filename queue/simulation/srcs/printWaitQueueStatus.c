#include "simutil.h"

// 대기 열의 상태를 출력.
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{
  int cnt = 0;
  if (pWaitQueue == NULL || isLinkedDequeEmpty(pWaitQueue) == 1)
  {
    printf("현재 %d시, 대기자 수는 0명 입니다.\n", currentTime);
    return ;
  }
  DequeNode* curr = peekFrontLD(pWaitQueue);
  while (curr != NULL)
  {
    cnt++;
    curr = curr->pRLink;
  }
  printf("현재 %d시, 대기자 수는 %d명 입니다.\n", currentTime, cnt);
}
