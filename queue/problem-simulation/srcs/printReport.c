#include "simutil.h"

// 최종 시뮬레이션 결과(통계치) 출력.
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
  printf("평균 대기시간: %f\n", (double)totalWaitTime / serviceUserCount);
  int cnt = 0;
  DequeNode* curr = peekFrontLD(pWaitQueue);
  if (pWaitQueue == NULL || isLinkedDequeEmpty(pWaitQueue) == 1 || serviceUserCount <= 0)
  {
    return ;
  }
  while (curr != NULL)
  {
    cnt++;
    curr = curr->pRLink;
  }
  printf("서비스를 받지 못하고 돌아가는 사람은 %d명 입니다.\n", cnt);
}
