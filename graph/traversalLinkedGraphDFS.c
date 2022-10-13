#include "linkedgraph.h"

int all_visit(int *visited, int size)
{
	for(int i = 0; i < size; i++)
	{
		if (visited[i] == 0)
		{
			return (FALSE);
		}
	}
	return (TRUE);
}

void traversal_LG_DFS(LinkedGraph *pGraph, int *visited, int vertexID)
{
	visited[vertexID] = 1;
	printf("%d ", vertexID);
	if (all_visit(visited, pGraph->maxVertexCount) == 1)
	{
		return ;
	}
    ListNode *node = pGraph->ppAdjEdge[vertexID]->headerNode.pLink;
	while (node != NULL)
	{
		if (visited[node->data] == 0 && pGraph->pVertex[node->data] == USED)
		{
            traversal_LG_DFS(pGraph, visited, node->data);
		}
		node = node->pLink;
	}
}

int test6()
{
	LinkedGraph *pGraph = createLinkedGraph(8);
	if (!pGraph)
		printf("!!!\n");
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));

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

	printf("--------------traverse DFS start = 0-------------\n");
	traversal_LG_DFS(pGraph, visited, 0);
	printf("\n");
	printf("\n");

	deleteLinkedGraph(pGraph);
    free(visited);
	return (1);
}

int main()
{
	test6();
	printf("\n");
	system("leaks a.out");
	return (0);
}