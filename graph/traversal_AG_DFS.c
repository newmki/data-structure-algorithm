#include "arraygraph.h"

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

void traversal_AG_DFS(ArrayGraph *pGraph, int *visited, int vertexID)
{
	visited[vertexID] = 1;
	printf("%d ", vertexID);
	if (all_visit(visited, pGraph->maxVertexCount) == 1)
	{
		return ;
	}
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[vertexID] == USED && pGraph->ppAdjEdge[vertexID][i] != 0)
		{
			if (visited[i] == 0)
				traversal_DFS(pGraph, visited, i);
		}
	}
}

int test()
{
	ArrayGraph *pGraph = createArrayGraph(8);
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
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


	printf("--------------traverse DFS start = 0-------------\n");
	traversal_AG_DFS(pGraph, visited, 4);
	printf("\n");
	printf("\n");

	deleteArrayGraph(pGraph);
	free(visited);
	visited = 0;
	return (1);
}

int main()
{
	test();
	system("leaks a.out");
	return (0);
}