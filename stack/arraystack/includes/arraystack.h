#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStackNodeType {
	char data;
} ArrayStackNode;

typedef struct ArrayStackType {
	int maxElementCount;		// 배열의 최대 개수
	int currentElementCount;	// 현재 배열에 들어가 있는 원소의 개수
	ArrayStackNode *pElement;	// array stack의 node
} ArrayStack;

/*
*** ArrayList와 array list node를 동적할당하는 함수
*/
ArrayStack* createArrayStack(int maxElementCount);

/*
*** array stack에 받은 element의 값을 push (반환 값 : 성공 여부)
*/
int pushAS(ArrayStack* pStack, ArrayStackNode element);
/*
*** array stack의 가장 마지막 인덱스의 element를 반환하고 삭제
*/
ArrayStackNode* popAS(ArrayStack* pStack);
/*
*** array stack의 가장 처음 인덱스의 element만 반환하는 함수
*/
ArrayStackNode* peekAS(ArrayStack* pStack);
/*
*** array stack을 동적할당 해제하고 삭제하는 함수
*/
void deleteArrayStack(ArrayStack* pStack);
/*
*** array stack의 가득 차있는지 확인 하는 함수
*/
int isArrayStackFull(ArrayStack* pStack);
/*
*** array stack이 비어있는지 확인 하는 함수
*/
int isArrayStackEmpty(ArrayStack* pStack);

/*
*** array stack 안의 데이터를 보는 함수
*/
void displayStack(ArrayStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif
