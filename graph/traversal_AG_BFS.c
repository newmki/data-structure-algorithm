#include "linkedDeque.h"
#include "arraygraph.h"

/*
typedef struct DequeNodeType
{
	char data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;
*/
void traversal_AG_BFS(ArrayGraph *pGraph, int vertexID)
{
	LinkedDeque *LD = createLinkedDeque();
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
		
	DequeNode node = {vertexID, 0, 0};
	insertRearLD(LD, node);
	visited[vertexID] = 1;
	while(isLinkedDequeEmpty(LD) == FALSE)
	{
		DequeNode *temp = peekFrontLD(LD);
		for(int i = 0; i < pGraph->maxVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[temp->data][i] != 0 && visited[i] == 0 && pGraph->pVertex[temp->data] == USED)
			{
				DequeNode insert = {i, 0, 0};
				insertRearLD(LD, insert);
				visited[i] = 1;
			}
		}
		// printf("peek: %d, delete: %d ", temp->data, deleteFrontLD(LD)->data);
		DequeNode *delete = deleteFrontLD(LD);
		printf("%d ", delete->data);
		free(delete);
		delete = 0;
	}
	printf("\n");
	free(visited);
	deleteLinkedDeque(LD);
	LD = 0;
}


int test()
{
	ArrayGraph *pGraph = createArrayGraph(8);
	for(int i = 0; i < 8; i++)
	{
		addVertexAG(pGraph, i);
	}
	addEdgeAG(pGraph, 0, 1);
	addEdgeAG(pGraph, 0, 2);
	addEdgeAG(pGraph, 1, 3);
	addEdgeAG(pGraph, 1, 4);
	addEdgeAG(pGraph, 3, 7);
	addEdgeAG(pGraph, 4, 5);
	addEdgeAG(pGraph, 5, 2);
	addEdgeAG(pGraph, 2, 6);
	displayArrayGraph(pGraph);
	printf("\n");


	printf("--------------traverse BFS start = 0-------------\n");
	traversal_AG_BFS(pGraph, 1);
	printf("\n");
	printf("\n");

	deleteArrayGraph(pGraph);
	return (1);
}

int main()
{
	test();
    printf("\n");
	system("leaks a.out");
	return (0);
}