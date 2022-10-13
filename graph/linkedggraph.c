#include "linkedgraph.h"

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *LG;

	if (maxVertexCount <= 0)
	{
		printf("maxVertexCount가 음수입니다.\n");
		return (NULL);
	}
	LG = (LinkedGraph*)calloc(1, sizeof(LinkedGraph));
	if (LG == NULL)
	{
		printf("LinkedGraph malloc 실패.\n");
		return (NULL);
	}
	LG->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (LG->pVertex == NULL)
	{
		free(LG);
		printf("LinkedGraph->pVertex malloc 실패.\n");
		return (NULL);
	}
	LG->ppAdjEdge = (LinkedList **)calloc(maxVertexCount, sizeof(LinkedList *));
	if (LG->ppAdjEdge == NULL)
	{
		free(LG->pVertex);
		free(LG);
		printf("LinkedGraph->ppAdjEdge malloc 실패.\n");
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		LG->ppAdjEdge[i] = createLinkedList();
		if (LG->ppAdjEdge[i] == NULL)
		{
			for(int j = 0; j < i; j++)
			{
				free(LG->ppAdjEdge[j]);
			}
			free(LG->ppAdjEdge);
			free(LG->pVertex);
			free(LG);
            return (NULL);
		}
	}
	LG->currentEdgeCount = 0;
	LG->currentVertexCount = 0;
	LG->maxVertexCount = maxVertexCount;
	LG->graphType = GRAPH_UNDIRECTED;
	return (LG);
}

LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *LG = createLinkedGraph(maxVertexCount);

	if (LG != NULL)
		LG->graphType = GRAPH_DIRECTED;
	return (LG);
}

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph)
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
			deleteLinkedList(pGraph->ppAdjEdge[i]); //free->deleteLL
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
int isEmptyLG(LinkedGraph* pGraph)
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
int addVertexLG(LinkedGraph* pGraph, int vertexID)
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
//간선 있는지 검사 있으면 position 없으면 -1
int findGraphNodePosition(LinkedList *list, int toVertexID)
{
	ListNode *node = list->headerNode.pLink;
	int index = 0;
	while (node != NULL)
	{
		if (node->data == toVertexID)
		{
			return (index);
		}
		node = node->pLink;
		index++;
	}
	return (-1);
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
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
	if (findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID) >= 0)
	{
		printf("ppAdjEdge에 %d에서 %d로 가는 간선이 이미 있습니다.\n", fromVertexID, toVertexID);
		return (FALSE);
	}
	ListNode addElement = {toVertexID, 0, 0};
	if (addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, addElement) == 1)
	{
		printf("ppAdjEdge에 %d에서 %d로 가는 간선을 추가했습니다.\n", fromVertexID, toVertexID);
		pGraph->currentEdgeCount++;
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            ListNode addElement1 = {fromVertexID, 0, 0};
            addLLElement(pGraph->ppAdjEdge[toVertexID], 0, addElement1);
        }
		return (TRUE);
	}
	printf("간선 추가 실패\n");
	return (FALSE);
}

int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
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
	if (findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID) >= 0)
	{
		printf("ppAdjEdge에 %d에서 %d로 가는 간선이 이미 있습니다.\n", fromVertexID, toVertexID);
		return (FALSE);
	}
	ListNode addElement = {toVertexID, weight, 0};
	if (addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, addElement) == 1)
	{
		printf("ppAdjEdge에 %d에서 %d로 가는 간선을 추가했습니다.\n", fromVertexID, toVertexID);
		pGraph->currentEdgeCount++;
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            ListNode addElement1 = {fromVertexID, weight, 0};
            addLLElement(pGraph->ppAdjEdge[toVertexID], 0, addElement1);
        }
		return (TRUE);
	}
	printf("간선 추가 실패\n");
	return (FALSE);
}

// 노드의 유효성 점검.
// 자기 자신을 향하는 노드 x, 중복 간선 x.
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
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
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (findGraphNodePosition(pGraph->ppAdjEdge[i], i) >= 0)
		{
			printf("자기 자신을 가리키는 %d노드가 있습나다.\n", i);
			return (FALSE);
		}
	}
	// node 이차원 배열 할당
	int **node = (int**)calloc(pGraph->maxVertexCount, sizeof(int));
	if (node == NULL)
	{
		printf("malloc failure\n");
	}
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		node[i] = (int*)calloc(pGraph->maxVertexCount, sizeof(int));
		if (node[i] == NULL)
		{
			for(int j = 0; j < i; j++)
			{
				free(node[j]);
			}
			free(node);
		}
	}
	//순회하면서 node에 넣기
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for(int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (findGraphNodePosition(pGraph->ppAdjEdge[i], j) >= 0)
			{
				node[i][j]++;
			}
		}
	}
	//node 순회하면서 2 이상 있으면 중복 있는 것
	//질문해보자
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for(int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (node[i][j] >= 2)
			{
				printf("%d->%d는 중복입니다. \n", i, j);
				return (FALSE);
			}
		}
	}
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		free(node[i]);
	}
	free(node);
	return (TRUE);
}

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
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
	for(int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (findGraphNodePosition(pGraph->ppAdjEdge[i], vertexID) >= 0)
		{
			removeEdgeLG(pGraph, i, vertexID);
			pGraph->currentEdgeCount--;
		}
	}
	pGraph->currentEdgeCount -= getLinkedListLength(pGraph->ppAdjEdge[vertexID]);
	clearLinkedList(pGraph->ppAdjEdge[vertexID]);
	pGraph->currentVertexCount--;
	return (FALSE);
}

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
	printf("%d->%d간선을 제거했습니다.\n", fromVertexID, toVertexID);
	pGraph->currentEdgeCount--;
    return (TRUE);
}

//내부함수, 노드를 지우려면 이 함수가 필요
void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int position = findGraphNodePosition(pList, delVertexID);
	if (position == -1)
	{
		printf("제거할 간선이 없습니다\n");
		return ;
	}
	removeLLElement(pList, delVertexID);
}

// 간선 개수 반환
int getEdgeCountLG(LinkedGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	return (pGraph->currentEdgeCount);
}

// 노드 개수 반환
int getVertexCountLG(LinkedGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	return (pGraph->currentVertexCount);
}

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	return (pGraph->maxVertexCount);
}

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return (FALSE);
	}
	return (pGraph->graphType);
}

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph)
{
	if (pGraph == NULL)
	{
		printf("pGraph is NULL\n");
		return ;
	}
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
			printf("%d ", findGraphNodePosition(pGraph->ppAdjEdge[fromVertexID], toVertexID) + 1);
		}
		printf("\n");
	}
	return ;
}

void test4()
{
	LinkedGraph *pGraph = createLinkedDirectedGraph(8);
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
	deleteLinkedGraph(pGraph);
}