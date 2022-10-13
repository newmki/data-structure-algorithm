#include "linkedDeque.h"

int main()
{
  LinkedDeque *LD = createLinkedDeque();
  DequeNode DN0 = {0, NULL, NULL};
  DequeNode DN1 = {1, NULL, NULL};
  DequeNode DN2 = {2, NULL, NULL};
  DequeNode DN3 = {3, NULL, NULL};
  insertRearLD(LD, DN2);
  insertRearLD(LD, DN3);
  insertFrontLD(LD, DN1);
  insertFrontLD(LD, DN0);
  displayLinkedDeque(LD);

  printf("%d\n", peekFrontLD(LD)->data);
  printf("%d\n", peekRearLD(LD)->data);
  
  {
    free(deleteFrontLD(LD));
    free(deleteRearLD(LD));
  }
  displayLinkedDeque(LD);
  return (0);
}
