/**
 * @see https://taesung1993.tistory.com/m/48
 */

// 인접행렬 방식으로 구하기

const INF = Infinity;
const arr = [
  [0, 10, 1, 4, INF, INF],
  [10, 0, 2, 5, INF, INF],
  [1, 2, 0, 1, INF, 8],
  [4, 5, 1, 0, INF, 3],
  [INF, INF, INF, INF, 0, 2],
  [INF, INF, 8, 3, 2, 0],
];
const isVisit = new Array(6).fill(false);

const getMin = function (vertex) {
  let min = INF;
  let idx = 0;
  for (let i = 0; i < vertex.length; i++) {
    if (min > vertex[i] && !isVisit[i]) {
      min = vertex[i];
      idx = i;
    }
  }
  return idx;
};

const dist = function (start) {
  let v = arr[start - 1];
  let count = 0;
  let end = v.length;
  let min = 0;
  let startV = v;
  isVisit[start - 1] = true;

  while (count < end) {
    const idx = getMin(startV);
    min += startV[idx];
    const next = arr[idx];
    for (let i = 0; i < v.length; i++) {
      if (v[i] > next[i] + min && !isVisit[i]) {
        v[i] = next[i] + min;
      }
    }
    startV = arr[idx];
    isVisit[idx] = true;
    count++;
  }
  console.log(v);
};

const main = (function () {
  dist(1);
})();
