#include "findmaze.h"

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
    if (isLinkedStackEmpty(pStack))
    {
        printf("찾을 수 없는 경로입니다.\n");
        return ;
    }
    while (!isLinkedStackEmpty(pStack))
    {
        StackNode *ans = popLS(pStack);

        // printf("x: %d y: %d\n", ans->data.x, ans->data.y);
        mazeArray[ans->data.y][ans->data.x] = 2;
        free(ans);
    }
    printMaze(mazeArray);
}
