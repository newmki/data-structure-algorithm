#ifndef _FIND_MAZE_
#define _FIND_MAZE_

#include "../includes/linkedstack.h"
#define WIDTH   4
#define HEIGHT  4

void findPath(  int mazeArray[HEIGHT][WIDTH],
                MapPosition startPos,
                MapPosition endPos,
                LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif
