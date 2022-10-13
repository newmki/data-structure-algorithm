#include "findmaze.h"

int safe(int x, int y)
{
    return (0 <= x && x < WIDTH && 0 <= y && y < HEIGHT);
}

int isSamePosition(MapPosition a, MapPosition b)
{
    return (a.x == b.x && a.y == b.y);
}

void findPath(  int mazeArray[HEIGHT][WIDTH],
                MapPosition startPos,
                MapPosition endPos,
                LinkedStack *pStack)
{
    // 동 남 서 북
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    pushLSMapPosition(pStack, startPos);
    while (!isLinkedStackEmpty(pStack))
    {
        MapPosition curPos = peekLS(pStack)->data;
        int flag = FALSE;
        mazeArray[curPos.y][curPos.x] = 2;
        // mazeArray[startPos.y][startPos.x] = 2;

        // 같은 위치인 경우
        if (isSamePosition(curPos, endPos))
        {
            return ;
        }
        // 현재 위치에서 동서남북을 보자
        for (int i = 0; i < 4; i++)
        {
            int nx = curPos.x + dx[i];
            int ny = curPos.y + dy[i];

            // 맵의 안에 있으면서, 통로인 경우
            if (safe(nx, ny) && mazeArray[ny][nx] == 0)
            {
                MapPosition nextPos = {nx, ny};
                pushLSMapPosition(pStack, nextPos);
                flag = TRUE;
                break ;
            }
        }
        // 현재 위치에서 동서남북 탐색에 실패했을 경우
        if (flag == FALSE)
        {
            free(popLS(pStack));
        }
    }
}
