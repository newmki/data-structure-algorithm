#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNodeType
{
    int data;
    int weight;
    struct ListNodeType* pLink;
} ListNode;
typedef struct LinkedListType
{
    int currentElementCount;	// ???? ????? ?????? ????
    ListNode headerNode;		// ??? ???(Header Node)
} LinkedList;
LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_
#define TRUE		1
#define FALSE		0
#endif
