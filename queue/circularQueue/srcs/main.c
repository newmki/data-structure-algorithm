#include "circularQueue.h"

int main()
{
  int maxElementCount = 4;
  ArrayQueue *AQ = createArrayQueue(maxElementCount);
  ArrayQueueNode AQN0 = {0};
  ArrayQueueNode AQN1 = {1};
  ArrayQueueNode AQN2 = {2};
  ArrayQueueNode AQN3 = {3};
  ArrayQueueNode AQN5 = {5};
  enqueueAQ(AQ, AQN0);
  enqueueAQ(AQ, AQN1);
  enqueueAQ(AQ, AQN2);
  enqueueAQ(AQ, AQN3);
  displayCircularQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayCircularQueue(AQ);
  enqueueAQ(AQ, AQN5);
  displayCircularQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayCircularQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayCircularQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayCircularQueue(AQ);
  
  free(dequeueAQ(AQ));
  displayCircularQueue(AQ);

  enqueueAQ(AQ, AQN0);
  displayCircularQueue(AQ);
  enqueueAQ(AQ, AQN1);
  displayCircularQueue(AQ);
  enqueueAQ(AQ, AQN2);
  displayCircularQueue(AQ);
  enqueueAQ(AQ, AQN3);
  displayCircularQueue(AQ);
  
  free(dequeueAQ(AQ));
  free(dequeueAQ(AQ));
  free(dequeueAQ(AQ));
  free(dequeueAQ(AQ));
  free(dequeueAQ(AQ));
  free(dequeueAQ(AQ));
  return (0);
}
