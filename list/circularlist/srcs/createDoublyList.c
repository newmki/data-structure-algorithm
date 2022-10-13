#include "doublylist.h"
#include <stdlib.h>

DoublyList* createDoublyList()
{
    DoublyList *headPointer;
    //메모리 할당
    headPointer = (DoublyList*)malloc(sizeof(DoublyList));
    //초기화 작업
    headPointer->currentElementCount = 0;
    headPointer->headerNode.data = 0;
    headPointer->headerNode.pLLink = &headPointer->headerNode;
    headPointer->headerNode.pRLink = &headPointer->headerNode;
    
    return (headPointer);
}