#include "findmaze.h"

int		main(void)
{
	int mazeArray[HEIGHT][WIDTH] = {
		{1, 1, 1, 1},
		{0, 0, 0, 0},
		{1, 0, 1, 1},
		{1, 0, 1, 1}
	};
	int answerArray[HEIGHT][WIDTH] = {
		{1, 1, 1, 1},
		{0, 0, 0, 0},
		{1, 0, 1, 1},
		{1, 0, 1, 1}
	};
	LinkedStack *LS = createLinkedStack();
	MapPosition startPos;
	MapPosition endPos;
	printMaze(mazeArray);

	printf("startPos x: ");
	scanf(" %d", &startPos.x);
	printf("startPos y: ");
	scanf(" %d", &startPos.y);
	printf("endPos x: ");
	scanf(" %d", &endPos.x);
	printf("endPos y: ");
	scanf(" %d", &endPos.y);
	findPath(mazeArray, startPos, endPos, LS);
	showPath(LS, answerArray);
	return (0);
}
