#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

# include <stdlib.h>
# include <stdio.h>

typedef struct ArrayHeapNodeType
{
	int data;
} ArrayHeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount;
	int currentElementCount;
	ArrayHeapNode *pElement;
} ArrayHeap;

ArrayHeap* createArrayHeap(int maxElementCount);
int insertHeapAH(ArrayHeap* pHeap, ArrayHeapNode element);
ArrayHeapNode *deleteHeapAH(ArrayHeap* pHeap);
ArrayHeapNode *peekAH(ArrayHeap* pHeap);
void deleteArrayHeap(ArrayHeap* pHeap);
int isArrayHeapFull(ArrayHeap* pHeap);
int isArrayHeapEmpty(ArrayHeap* pHeap);
void displayArrayHeap(ArrayHeap* pHeap);


#endif

#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0

#endif