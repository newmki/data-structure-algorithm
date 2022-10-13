#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE		1
#define FALSE		0

typedef struct HeapElementType
{
	int weight;
  int fromVertex;
  int toVertex;
} HeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	HeapNode *pElement;	// 원소 저장을 위한 1차원 배열
} ArrayHeap;

ArrayHeap* createHeap(int maxElementCount)
{
    ArrayHeap* pHeap;
  
  if (maxElementCount < 0)
  {
    printf("maxElementCount minus\n");
  }
  pHeap = (ArrayHeap *)malloc(sizeof(ArrayHeap));
  if (!pHeap)
  {
    printf("pHeap malloc failure\n");
    return (NULL);
  }
  pHeap->maxElementCount = maxElementCount;
  pHeap->currentElementCount = 0;
  pHeap->pElement = (HeapNode*)malloc(sizeof(HeapNode) * maxElementCount);
  if (!(pHeap->pElement))
  {
    printf("pElement malloc failure\n");
    free(pHeap);
    return (NULL);
  }
  memset(pHeap->pElement, 0, sizeof(HeapNode) * maxElementCount);
  return (pHeap);
}

void deleteArrayHeap(ArrayHeap* pHeap)
{
	if (pHeap == NULL)
  {
  	printf("[error] Null Parameter : pHeap\n");
    return ;
  }
  if (pHeap->pElement != NULL)
  {
    free(pHeap->pElement);
  }
  free(pHeap);
  pHeap = 0;
}

int isArrayHeapFull(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] Null Parameter : pHeap\n");
  	return (FALSE);
  }
  if (pHeap->maxElementCount == pHeap->currentElementCount)
  {
    return (TRUE);
  }
  return (FALSE);
}
int isArrayHeapEmpty(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
	}
  if (pHeap->currentElementCount == 0)
  {
    return (TRUE);
  }
  return (FALSE);
}
int insertMaxHeapNode(ArrayHeap* pHeap, HeapNode element)
{
  if (isArrayHeapFull(pHeap))
  {
    printf("[error] Heap is full\n");
    return (FALSE);
  }
  //트리의 마지막 자리에 임시 저장
  pHeap->currentElementCount++;
  int i = pHeap->currentElementCount; // 1부터 처음 인덱스 시작되니까.
  while(i != 1 && (element.weight > pHeap->pElement[i/2].weight))
  {
    pHeap->pElement[i] = pHeap->pElement[i/2];
    i = i/2;
  }
  pHeap->pElement[i] = element;
  return (TRUE);
}

HeapNode *deleteMaxHeapNode(ArrayHeap* pHeap)
{
  HeapNode *pReturn;
  
	if (pHeap == NULL)
  {
  	printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  if (isArrayHeapEmpty(pHeap))
  {
    printf("[error] Heap is empty: pHeap\n");
    return (FALSE);
  }
  pReturn = (HeapNode *)malloc(sizeof(HeapNode));
  if (pReturn == NULL)
  {
  	printf("[error] malloc failure : pReturn\n");
    return (FALSE);
  }
  //step1
  *pReturn = (pHeap->pElement[1]);
  //step2
  int i = pHeap->currentElementCount;
  HeapNode *temp = &(pHeap->pElement[i]);
  pHeap->currentElementCount--;
  //step3
  int parent = 1;
 	int child = 2;
  while (child <= pHeap->currentElementCount)
  {
    if ((child < pHeap->currentElementCount) 
        && pHeap->pElement[child].weight < pHeap->pElement[child + 1].weight)
      child++;
    if (temp->weight >= pHeap->pElement[child].weight)
      break;
    pHeap->pElement[parent] = pHeap->pElement[child];
    parent = child;
    child *= 2;
  }
  pHeap->pElement[parent] = *temp;
	return (pReturn);
}

int insertMinHeapNode(ArrayHeap* pHeap, HeapNode element)
{
  if (isArrayHeapFull(pHeap))
  {
    printf("[error] Heap is full\n");
    return (FALSE);
  }
  //트리의 마지막 자리에 임시 저장
  pHeap->currentElementCount++;
  int i = pHeap->currentElementCount; // 1부터 처음 인덱스 시작되니까.
  while(i != 1 && (element.weight < pHeap->pElement[i/2].weight))
  {
    pHeap->pElement[i] = pHeap->pElement[i/2];
    i = i/2;
  }
  pHeap->pElement[i] = element;
  return (TRUE);
}
HeapNode *deleteMinHeapNode(ArrayHeap* pHeap)
{
  HeapNode *pReturn;
  
	if (pHeap == NULL)
  {
  	printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  if (isArrayHeapEmpty(pHeap))
  {
    printf("[error] Heap is empty: pHeap\n");
    return (FALSE);
  }
  pReturn = (HeapNode *)malloc(sizeof(HeapNode));
  if (pReturn == NULL)
  {
  	printf("[error] malloc failure : pReturn\n");
    return (FALSE);
  }
  //step1
  *pReturn = (pHeap->pElement[1]);
  //step2
  int i = pHeap->currentElementCount;
  HeapNode *temp = (&pHeap->pElement[i]);
  pHeap->currentElementCount--;
  //step3
  int parent = 1;
 	int child = 2;
  while (child <= pHeap->currentElementCount)
  {
    if ((child < pHeap->currentElementCount) 
        && pHeap->pElement[child].weight > pHeap->pElement[child + 1].weight)
      child++;
    if (temp->weight <= pHeap->pElement[child].weight)
      break;
    pHeap->pElement[parent] = pHeap->pElement[child];
    parent = child;
    child *= 2;
  }
  pHeap->pElement[parent] = *temp;
  return (pReturn);
}

HeapNode* getHeapNode(ArrayHeap* pHeap, int position)
{
	HeapNode *pReturn;
  
	if (pHeap == NULL)
  {
  	printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  return (&pHeap->pElement[position]);
}

void displayArrayHeap(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return ;
  }
  int i = 1;
  while (i <= pHeap->currentElementCount)
  {
    printf("weight [%d] %d -> %d\n", pHeap->pElement[i].weight, pHeap->pElement[i].fromVertex, pHeap->pElement[i].toVertex);
    i++;
  }
}

void clearArrayHeap(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return ;
  }
  memset(pHeap->pElement, 0, sizeof(HeapNode) * pHeap->maxElementCount);
  free(pHeap->pElement);
  pHeap->currentElementCount = 0;
  free(pHeap);
  pHeap = 0;
}

int getArrayHeapLength(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  return (pHeap->currentElementCount);
}
/*
void test()
{
  ArrayHeap *heap = createHeap(10);
  //weight , fromVertex, toVertex 순서
  HeapNode h1 = {4, 1, 0};
  HeapNode h2 = {2, 1, 2};
  HeapNode h3 = {3, 0, 2};
  HeapNode h4 = {1, 3, 4};
  HeapNode h5 = {6, 4, 5};
  HeapNode h6 = {5, 3, 5};
  HeapNode h7 = {1, 2, 3};
  insertMinHeapNode(heap, h1);
  insertMinHeapNode(heap, h2);
  insertMinHeapNode(heap, h3);
  insertMinHeapNode(heap, h4);
  insertMinHeapNode(heap, h5);
  insertMinHeapNode(heap, h6);
  insertMinHeapNode(heap, h7);

  //HeapNode *root = deleteMinHeapNode(heap);
  //printf("%d %d->%d\n", root->weight, root->fromVertex, root->toVertex);
  displayArrayHeap(heap);
  //free(root);
  // root = 0;
  clearArrayHeap(heap);
}
int main()
{
    test();
    //system("leaks a.out");
    return 0;
}*/