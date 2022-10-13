#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ArrayGraphType
{
	int maxVertexCount;		// 최대 노드 개수
	int currentVertexCount;	// 현재 사용되는 노드의 개수
	int graphType;			// 그래프 종류: 1-Undirected, 2-Directed
	int **ppAdjEdge;		// 간선 저장을 위한 2차원 array
	int *pVertex;			// 노드 저장을 위한 1차원 array
} ArrayGraph;

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph);

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph);

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID);

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
