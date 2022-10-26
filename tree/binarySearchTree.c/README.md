# binary search tree

- 검색은 key로 한다.
- CS에서 key는 유일한 값.
- python에서 dictionary는 key:value
- hashing은 search를 위한 자료구조
- binary search tree는 찾는데 필요한 자료구조
- 왼쪽은 나보다 작은 키 값
- 오른쪽은 나보다 큰 키 값
- 이 친구는 fully completed binary tree는 아니다.
- 키는 유일하므로, 키가 이미 있다면 insert불가합니다. 따라서 insert하려면 search를 해야 합니다.
- insert, delete할 때 bst가 유지되어야 합니다.
- delete를 할 때 child가 두 개일 경우 고려해야 한다.
- delete를 할 때 왜 후보가 왼쪽 오른쪽으로 간 녀석이 되는가?!
- 1, 2, 3, 4, 5를 순서대로 넣으면 밸런스가 깨진다. BST에서 balance가 중요하다. heap은 complete binary tree이므로 자연스럽게 balance가 유지되지만, BST는 그렇지 않다. 그걸 유지하기 위해 AVL트리가 생겼다.
- AVL Tree
- RB Tree
- 편향 트리는 binary 트리가 아니다.
- 힘들게 Tree를 만드는 이유는 이득이 있기 때문이다.


- https://makemethink.tistory.com/136
- https://asfirstalways.tistory.com/325
- https://www.techiedelight.com/insertion-in-bst/
- https://www.techiedelight.com/deletion-from-bst/