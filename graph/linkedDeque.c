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

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
  DequeNode *pNode;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (FALSE);
  }
  pNode = (DequeNode*)calloc(1, sizeof(DequeNode));
  if (pNode == NULL)
  {
    printf("pNode malloc failure\n");
    return (FALSE);
  }
  pNode->data = element.data;
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    pDeque->pFrontNode = pNode;
    pDeque->pRearNode = pNode;
  }
  else
  {
    pDeque->pFrontNode->pLLink = pNode;
    pNode->pRLink = pDeque->pFrontNode;
    pDeque->pFrontNode = pNode;
  }
  (pDeque->currentElementCount)++;
  return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
  DequeNode *pNode;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (FALSE);
  }
  pNode = (DequeNode*)calloc(1, sizeof(DequeNode));
  if (pNode == NULL)
  {
    printf("pNode malloc failure\n");
    return (FALSE);
  }
  pNode->data = element.data;
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    pDeque->pFrontNode = pNode;
    pDeque->pRearNode = pNode;
  }
  else
  {
    pDeque->pRearNode->pRLink = pNode;
    pNode->pLLink = pDeque->pRearNode;
    pDeque->pRearNode = pNode;
  }
  (pDeque->currentElementCount)++;
  return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pFrontNode;
		pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    pReturn->pRLink = NULL;
    if (pDeque->currentElementCount == 1)
    {
      pDeque->pRearNode = NULL;
    }
    else
    {
      pDeque->pFrontNode->pLLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pRearNode;
		pDeque->pRearNode = pDeque->pRearNode->pLLink;
    pReturn->pLLink = NULL;
    if (pDeque->currentElementCount == 1)
    {
      pDeque->pFrontNode = NULL;
    }
    else
    {
      pDeque->pRearNode->pRLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return ;
  }
  while (isLinkedDequeEmpty(pDeque) == FALSE)
  {
    DequeNode *pNode = deleteFrontLD(pDeque);
    pNode->pRLink = NULL;
    pNode->pLLink = NULL;
    free(pNode);
  }
  free(pDeque);
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
  }
  return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
  }
  if (pDeque->currentElementCount == 0 && pDeque->pFrontNode == NULL && pDeque->pRearNode == NULL)
  {
    return (TRUE);
  }
  return (FALSE);
}

void displayLinkedDeque(LinkedDeque* pDeque)
{
  DequeNode *pNode;
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return ;
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return ;
  }
  pNode = pDeque->pFrontNode;
  while (pNode != NULL)
  {
    printf("%d ", pNode->data);
    pNode = pNode->pRLink;
  }
  printf("\n");
}
/*
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
  system("leaks a.out");
  return (0);
}*/