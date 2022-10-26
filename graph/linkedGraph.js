/**
 * @see https://velog.io/@jangws/20.-%EA%B7%B8%EB%9E%98%ED%94%84Graph-%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-JS
 */

export class Graph {
  constructor() {
    this.adjacencyList = {};
  }

  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) {
      this.adjacencyList[vertex] = [];
    }
  }

  addEdge(vertex1, vertex2) {
    this.adjacencyList[vertex1].push(vertex2);
    this.adjacencyList[vertex2].push(vertex1);
  }

  removeEdge(vertex1, vertex2) {
    this.adjacencyList[vertex1] = this.adjacencyList[vertex1].filter(
      (v) => v !== vertex2
    );
    this.adjacencyList[vertex2] = this.adjacencyList[vertex2].filter(
      (v) => v !== vertex1
    );
  }

  removeVertex(vertex) {
    // 정점과 연결된 모든 간선을 제거하기 위해 해당 정점의 배열에 대해 루프를 돌면서,
    while (this.adjacencyList[vertex].length) {
      // 삭제하려는 정점의 간선들을 removeEdge 메서드를 사용해서 모두 삭제한다.
      const adjacentVertex = this.adjacencyList[vertex].pop();
      this.removeEdge(vertex, adjacentVertex);
    }
    // 정점도 삭제한다.
    delete this.adjacencyList[vertex];
  }
}
