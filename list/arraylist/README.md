# ArrayList

자료구조를 공부한다면 제일 먼저 공부하는 구조는 List입니다. List는 데이터를 연속적으로 저장하는 방식입니다. List는 ArrayList와 LinkedList두 가지 방식이 대표적인데, ArrayList부터 살펴봅시다.

ArrayList는 메모리상에 연속적으로 데이터를 저장하는 자료구조입니다. 메모리상에 연속적으로 저장한다는 의미는 즉, Element의 위치를 계산할 수 있다는 뜻이며, 이는 곧 자료의 검색이 매우 빠르다는 결과로 이어집니다. ArrayList로 데이터를 저장했을 때에 검색에 드는 시간 복잡도는 O(1)입니다.

그에 비해서 ArrayList는 Element를 추가하거나 삭제할 때에는, Time Complexity가 O(n)입니다. 만약 Element가 5개 저장되어 있는 ArrayList에서 Position = 0에 Element를 추가할 때에는 모든 원소를 움직여, position = 0이 비어 있도록 만들어주어야 하기 때문에 Time Complexity가 증가합니다. 삭제할 때에도 마찬가지입니다.

아래 헤더를 참고해서 ArrayList를 구현해 봅시다.

ArrayList구조체는 세 개의 변수를 가집니다. maxElementCount는 ArrayList가 가질 수 있는 최대 Element입니다. 나중에 살펴보시겠지만, LinkedList와 달리 ArrayList는 최대 Element를 갖기도 합니다. 특정 언어에서는 ArrayList에 계속해서 데이터를 입력할 수 있고, ArrayList의 크기는 자동으로 커지도록 설계되어 있기도 합니다. currentElementCount는 현재 ArrayList에 몇 개의 Element가 들어있는지를 나타냅니다. pElement는 maxElementCount만큼 크기가 할당되어 있습니다.
