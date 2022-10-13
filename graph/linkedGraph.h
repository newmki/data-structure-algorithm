#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include "linkedList.h"

typedef struct LinkedGraphType
{
	int maxVertexCount;		// �ִ� ��� ����
	int currentVertexCount;	// ���� ���Ǵ� ����� ����
	int currentEdgeCount;	// ���� ������ ����.
	int graphType;			// �׷��� ����: 1-Undirected, 2-Directed
	LinkedList** ppAdjEdge;	// ���� ������ ���� ���� ����Ʈ (������)�� �迭
	int *pVertex;			// ��� ������ ���� 1���� �迭
} LinkedGraph;

// �׷��� ����
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// �׷��� ����
void deleteLinkedGraph(LinkedGraph* pGraph);

// ���� �׷��� ���� �Ǵ�
int isEmptyLG(LinkedGraph* pGraph);

// ��� �߰�
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// ���� �߰�
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ����� ��ȿ�� ����.
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// ��� ����
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// ���� ����
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList* pList, int delVertexID);
int findGraphNodePosition(LinkedList* pList, int vertexID);

// ���� ���� ��ȯ
int getEdgeCountLG(LinkedGraph* pGraph);

// ��� ���� ��ȯ
int getVertexCountLG(LinkedGraph* pGraph);

// �ִ� ��� ���� ��ȯ
int getMaxVertexCountLG(LinkedGraph* pGraph);

// �׷��� ���� ��ȯ.
int getGraphTypeLG(LinkedGraph* pGraph);

// �׷��� ���� ���
void displayLinkedGraph(LinkedGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif