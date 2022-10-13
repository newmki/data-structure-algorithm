#include <stdlib.h>
#include "doublylist.h"

void clearDoublyList(DoublyList* pList)
{
  while(removeDLElement(pList, 0));
}