#include "linkedstack.h"
#include "findmaze.h"

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
    printf("\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%d ", mazeArray[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
