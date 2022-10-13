#include "doublylist.h"
#include <stdlib.h>

void deleteDoublyList(DoublyList* pList)
{
  clearDoublyList(pList);
  pList->headerNode.pRLink = 0;
  pList->headerNode.pLLink = 0;
  free(pList);
}