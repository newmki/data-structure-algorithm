#include "simutil.h"

// 서비스 시작 처리.
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{
  if (pWaitQueue == NULL || isLinkedDequeEmpty(pWaitQueue) == 1)
  {
    return (NULL);
  }
  DequeNode* pServiceNode = deleteFrontLD(pWaitQueue);
  pServiceNode->data.status = start;
  pServiceNode->data.startTime = currentTime;
  return (pServiceNode);
}
