# heap

- max Heap 구현하기
- complete binary tree
- array로 만들기
- max heap은 delete는 항상 root에서 일어난다. 그래서 delete를 하면 가장 큰 값이 나온다.
- insert는 가장 마지막에 넣기
- 그리고 parent와 비교하기. parent는 / 2 child는 _ 2 ,_ 2 + 1
- insert가 parent보다 크다면 swap
- 자기 자리를 찾아가는 computation Time은 log2(n);
- index는 1부터
- 힙을 사용하는 이유는 우선순위가 가장 높거나, 작거나!
- max Heap일 때 다 꺼내면 desc sort ordering이다.
- Heap을 이용해서 sorting하면 nlog2(n)이다.
- quick Sort는 평균적으로 nlog2(n)이다. 하지만 worst case 는 n^2
- sorting시 Heap은 반드시 nlog2(n)을 보장한다.

- header는 없다. 사실 header를 만드는것이 프로그래밍의 반이다.
- 삽질을 합시다. 원래 header를 주면 안된다.
- header를 안주니까 너무 이상하게 만들고, 구천을 헤매길래... 줬다. 그런데 원래 주면 안된다.
- 스스로 생각을 해봅시다.

- insert는 제일 마지막에 넣고, 