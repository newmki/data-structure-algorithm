#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayListNode *pElement;	// 원소 저장을 위한 1차원 배열
} ArrayList;

ArrayList* createArrayList(int maxElementCount);

ArrayListNode* getALElement(ArrayList* pList, int position);
int addALElement(ArrayList* pList, int position, ArrayListNode element);
int removeALElement(ArrayList* pList, int position);

void clearArrayList(ArrayList* pList);
void deleteArrayList(ArrayList* pList);

int isArrayListFull(ArrayList* pList);
int getArrayListLength(ArrayList* pList);
void displayArrayList(ArrayList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif