- 실제로 대학교에서는 구현하는 경우는 거의 없다.
- 매우 빡빡한 스케쥴
- 알고리즘을 공부했으면 좋겠다.
- 정통 알고리즘은 학교에서 배우는 알고리즘
- 정통 알고리즘이 베이스가 되어 있어야 한다.
- 코딩테스트는 의문이 든다.
- 앞으로 시간을 내서 공부를 해야 합니다.
- 다음주 화요일이 마지막 모임

# 그래프

- 그래프 = 노드 + 간선
- vertex + edge
- 트리는 사이클이 없지만, 그래프는 사이클이 존재한다.
- 간선의 방향성
- 간선의 가중치

# 그래프의 개념

- 인접
- 부속
- 차수
- in-degree, out-degree
- 모든 공부의 기본은 용어입니다.
- 영어로 된 용어에 익숙해져야 합니다.
- semetric graph
- matrix from to
- matrix는 매우 간단하지만, 안쓰는 메모리 공간이 많다. allocation 메모리가 커서 낭비가 심하다.
- 인접행렬을 이용한 구현
- 인접리스트를 이용한 구현 doubly or linked

# 탐색

- traverse
- DFS stack
- BFS queue
- 두 가지를 이용해서 탐색하자

# 신장 트리

- spanning tree, 신장 트리
- 트리는 사이클이 없다.
- 하나의 노드라도 한 번은 연결되어 있다.
- 노드가 n이면 edge는 n - 1
- minimum spanning tree
- weight가 가장 작은 tree를 찾아라
- graph에서 minimum spanning tree는 한개이다.
- 답이 있는 문제가 있는데, 너무 시간이 많이 걸리는 문제가 있다.
- 인간은 경험에 의해서 답이 빨리 나오지만, 기계는 그렇지 않으므로 모든 경우를 다 해보거나, 아니면 학습을 시킨다. 학습을 시키면 정답은 아니지만, 최적의 답 근접한 답을 찾는다. 이제 딥러닝입니다.
- np problem
- MST
- Heap 이용

# Kruskal

- 사이클이 존재하는지 확인
- undirected

# Prim

- undirected

# Dijkstra

- directed
- start에서 모든 노드로 가는 최단 거리를 구한다.
- 매우 중요한 알고리즘!

# Floyd

- Dijkstra의 확장판...
