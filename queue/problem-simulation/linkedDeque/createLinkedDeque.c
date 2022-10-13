#include "linkedDeque.h"

LinkedDeque* createLinkedDeque()
{
  LinkedDeque *pReturn;
  pReturn = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
  if (pReturn == NULL)
  {
    printf("malloc failure\n");
    return (NULL);
  }
  return (pReturn);
}