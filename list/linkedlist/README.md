# LinkedList

LinkedList는 여러 자료구조중 List의 한 종류로, Node는 data와 pLink로 이루어져있습니다. data는 데이터를 담는 변수이고, pLink는 다음 Node를 가리키는 포인터입니다. 따라서 Node가 pLink로 계속 이어저 있습니다.

LinkedList의 장점은 Node를 추가하거나 삭제할 때입니다. ArrayList는 메모리가 이어져 있는 순차접근이지만, LinkedList는 Random Access이기 때문에 크기에 구애받지 않고, 계속해서 Node를 추가할 수 있습니다.

가장 중점적으로 봐야할 동작은 세 가지 입니다.

- getLLElement

- addLLElement

- removeLLElement

삽입, 삭제, 조회가 자료구조에서 가장 중요한 동작입니다.

# 참고 링크

https://www.nextree.co.kr/p6506/
