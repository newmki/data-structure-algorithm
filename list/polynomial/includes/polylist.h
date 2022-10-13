#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	float coef;
  int degree;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode headerNode;
} LinkedList;

//
LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int degree);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
void reverseLinkedList(LinkedList *pList);
int addPolyNodeLast(LinkedList *pList, float coef, int degree);
void displayPolynomial(LinkedList *pList);
LinkedList *sumPolynomial(LinkedList *A, LinkedList *B);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif