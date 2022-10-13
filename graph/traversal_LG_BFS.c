#include "linkedDeque.h"
#include "linkedgraph.h"

void traversal_LG_BFS(LinkedGraph *pGraph, int vertexID)
{
	LinkedDeque *LD = createLinkedDeque();
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));

	DequeNode node1 = {vertexID, 0, 0};
	insertRearLD(LD, node1);
	visited[vertexID] = 1;
    ListNode *node = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
	while(isLinkedDequeEmpty(LD) == FALSE)
	{
		DequeNode *temp = peekFrontLD(LD);
		ListNode *next = pGraph->ppAdjEdge[temp->data]->headerNode.pLink;
		while (next != NULL)
		{
			if (visited[next->data] == 0)
			{
				DequeNode insert = {next->data, 0, 0};
				insertRearLD(LD, insert);
				visited[next->data] = 1;
			}
			next = next->pLink;
		}
		DequeNode *delete = deleteFrontLD(LD);
		printf("delete: %d ", delete->data);
		free(delete);
		delete = 0;
	}
	printf("\n");
	free(visited);
	deleteLinkedDeque(LD);
	LD = 0;
}


int test5()
{
	LinkedGraph *pGraph = createLinkedGraph(8);
	if (!pGraph)
		printf("!!!\n");
	for(int i = 0; i < 8; i++)
	{
		addVertexLG(pGraph, i);
	}
	addEdgeLG(pGraph, 0, 1);
	addEdgeLG(pGraph, 0, 2);
	addEdgeLG(pGraph, 1, 3);
	addEdgeLG(pGraph, 1, 4);
	addEdgeLG(pGraph, 3, 7);
	addEdgeLG(pGraph, 4, 5);
	addEdgeLG(pGraph, 5, 2);
	addEdgeLG(pGraph, 2, 6);
	displayLinkedGraph(pGraph);
	printf("\n");

	printf("--------------traverse BFS start = 0-------------\n");
	traversal_LG_BFS(pGraph, 1);
	printf("\n");
	printf("\n");

	deleteLinkedGraph(pGraph);
	return (1);
}

int main()
{
	test5();
	printf("\n");
	system("leaks a.out");
	return (0);
}