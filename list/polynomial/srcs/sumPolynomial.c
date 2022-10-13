#include "polylist.h"

LinkedList *sumPolynomial(LinkedList *A, LinkedList *B)
{
  LinkedList *C = createLinkedList();
  ListNode *ANode = A->headerNode.pLink;
  ListNode *BNode = B->headerNode.pLink;

  //A리스트의 노드들을 전부 C에 합함
  while (ANode)
  {
    addPolyNodeLast(C, ANode->coef, ANode->degree);
    ANode = ANode->pLink;
  }
  //B리스트의 노드들을 전부 C에 합함
  while (BNode)
  {
    addPolyNodeLast(C, BNode->coef, BNode->degree);
    BNode = BNode->pLink;
  }
  return (C);
}
