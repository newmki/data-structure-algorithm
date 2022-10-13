#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxElementCount;
	int currentElementCount;
	int front;
	int rear;
	ArrayQueueNode *pElement;
} ArrayQueue;

#include <stdio.h>
#include <stdlib.h>

ArrayQueue* createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);
void displayLinearQueue(ArrayQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif
