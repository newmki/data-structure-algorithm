#include "arraygraph.h"

/*
typedef struct ArrayGraphType
{
	int maxVertexCount;		// 최대 노드 개수
	int currentVertexCount;	// 현재 사용되는 노드의 개수
	int graphType;			// 그래프 종류: 1-Undirected, 2-Directed
	int **ppAdjEdge;		// 간선 저장을 위한 2차원 array
	int *pVertex;			// 노드 저장을 위한 1차원 array
} ArrayGraph;
*/

ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *AG;

	if (maxVertexCount <= 0)
	{
		printf("maxVertexCount가 음수입니다.\n");
		return (NULL);
	}
	AG = (ArrayGraph *)calloc(1, sizeof(ArrayGraph));
	if (AG == NULL)
	{
		printf("ArrayGraph malloc 실패\n");
		return (NULL);
	}
	AG->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (AG->pVertex == NULL)
	{
		printf("pVertex malloc 실패\n");
		free(AG->pVertex);
		free(AG);
		return (NULL);
	}
	AG->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	if (AG->ppAdjEdge == NULL)
	{
		printf("ppAdjEdge malloc 실패\n");
		free(AG->ppAdjEdge);
		free(AG->pVertex);
		free(AG);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		AG->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
		if (AG->ppAdjEdge[i] == NULL)
		{
			printf("ppAdjEdge[i] malloc 실패\n");
			for (int j = 0; j < i; j++)
			{
				free(AG->ppAdjEdge[j]);
			}
			free(AG->ppAdjEdge);
			free(AG->pVertex);
			free(AG);
			return (NULL);
		}
	}
	AG->graphType = GRAPH_UNDIRECTED;
	AG->maxVertexCount = maxVertexCount;
	return (AG);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *AG = createArrayGraph(maxVertexCount);
	if (AG != NULL)
		AG->graphType = GRAPH_DIRECTED;
	return (AG);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return ;
	}
	if (pGraph->pVertex != NULL)
	{
		free(pGraph->pVertex);
		printf("pVertex is free\n");
		pGraph->pVertex = NULL;
	}
	if (pGraph->ppAdjEdge != NULL)
	{
		for(int i = 0; i < pGraph->maxVertexCount; i++)
		{
			free(pGraph->ppAdjEdge[i]);
			pGraph->ppAdjEdge[i] = NULL;
		}
		free(pGraph->ppAdjEdge);
		printf("ppAdjEdge is free\n");
		pGraph->ppAdjEdge = NULL;
	}
	free(pGraph);
	printf("pGraph is free\n");
	pGraph = NULL;
	return ;
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	if (pGraph->currentVertexCount == 0)
	{
		printf("pGraph is Empty!!!");
		return (TRUE);
	}
	return (FALSE);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	if (vertexID >= pGraph->maxVertexCount)
	{
		printf("unvalid vertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == USED)
	{
		printf("pVertex에서 %d가 이미 사용중입니다.\n", vertexID);
		return (FALSE);
	}
	printf("pVertex에 %d를 추가했습니다.\n", vertexID);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (TRUE);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	if (fromVertexID >= pGraph->maxVertexCount || toVertexID >= pGraph->maxVertexCount)
	{
		printf("unvalid vertexID\n");
		return (FALSE);
	}
	if (pGraph->ppAdjEdge[fromVertexID][toVertexID] == 1)
	{
		printf("ppAdjEdge에 %d에서 %d로 가는 간선이 이미 있습니다.\n", fromVertexID, toVertexID);
		return (FALSE);
	}
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	// 그래프가 방향성이 없다면 대칭으로 간선을 추가해줘야 한다.
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	printf("ppAdjEdge에 %d에서 %d로 가는 간선을 추가했습니다.\n", fromVertexID, toVertexID);
	return (TRUE);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	if (fromVertexID >= pGraph->maxVertexCount || toVertexID >= pGraph->maxVertexCount)
	{
		printf("unvalid vertexID\n");
		return (FALSE);
	}
	if (pGraph->ppAdjEdge[fromVertexID][toVertexID] != 0)
	{
		printf("ppAdjEdge에 %d에서 %d로 가는 간선이 이미 있습니다.\n", fromVertexID, toVertexID);
		return (FALSE);
	}
	printf("ppAdjEdge에 %d에서 %d로 가는 간선을 %d 가중치로 추가했습니다.\n", fromVertexID, toVertexID, weight);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (TRUE);
}

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)//자기 자신을 향하는 노드 x, 중복 간선 x.
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
	{
		return (FALSE);
	}
	if (pGraph->ppAdjEdge[vertexID][vertexID] != 0)
	{
		return (FALSE);
	}
	return (TRUE);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	if (vertexID >= pGraph->maxVertexCount)
	{
		printf("unvalid vertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		printf("node doesn't exists\n");
        return (FALSE);
	}
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[vertexID][i] != 0)
		{
			removeEdgeAG(pGraph, vertexID, i);
		}
		if (pGraph->ppAdjEdge[i][vertexID] != 0)
		{
			removeEdgeAG(pGraph, i, vertexID);
		}
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (TRUE);
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	if (fromVertexID >= pGraph->maxVertexCount || toVertexID >= pGraph->maxVertexCount)
	{
		printf("unvalid vertexID\n");
		return (FALSE);
	}
	if (pGraph->ppAdjEdge[fromVertexID][toVertexID] == 0)
	{
		printf("edge not exists\n");
	}
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (TRUE);
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return ;
	}
	// printf("--------------ppAdjEdge---------------");
	// printf("\n");
  // printf("vertex : ");
	// for (int vertexID = 0; vertexID < pGraph->maxVertexCount; vertexID++)
	// {
	// 	printf("%d ", pGraph->pVertex[vertexID]);
	// }
	printf("\n\n");
	printf("   ");
	for (int vertexID = 0; vertexID < pGraph->maxVertexCount; vertexID++)
	{
		printf("%d ", vertexID);
	}
	printf("\n");
	printf("------------------\n");
	for (int fromVertexID = 0; fromVertexID < pGraph->maxVertexCount; fromVertexID++)
	{
		printf("%d |", fromVertexID);
		for (int toVertexID = 0; toVertexID < pGraph->maxVertexCount; toVertexID++)
		{
			printf("%d ", pGraph->ppAdjEdge[fromVertexID][toVertexID]);
		}
		printf("\n");
	}
	return ;
}

void test1()
{
    printf("UNDIRECTED WITH 가중치 없음\n\n");
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
    deleteArrayGraph(pGraph);
}