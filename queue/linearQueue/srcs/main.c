#include "linearQueue.h"

int main()
{
  int maxElementCount = 5;
  ArrayQueue *AQ = createArrayQueue(maxElementCount);
  ArrayQueueNode AQN0 = {0};
  ArrayQueueNode AQN1 = {1};
  ArrayQueueNode AQN2 = {2};
  ArrayQueueNode AQN3 = {3};
  enqueueAQ(AQ, AQN0);
  enqueueAQ(AQ, AQN1);
  enqueueAQ(AQ, AQN2);
  enqueueAQ(AQ, AQN3);
  displayLinearQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayLinearQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayLinearQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayLinearQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayLinearQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayLinearQueue(AQ);
  
  return (0);
}
