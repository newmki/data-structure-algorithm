#include <stdio.h>
#define SIZE 8

void merge(int *array, int left, int middle, int right)
{
    int leftIndex = left;
    int rightIndex = middle + 1;
    int newArrayIndex = left;
    int newArray[SIZE];

    while (leftIndex <= middle && rightIndex <= right)
    {
        if (array[leftIndex] <= array[rightIndex])
        {
            newArray[newArrayIndex++] = array[leftIndex++];
        }
        else
        {
            newArray[newArrayIndex++] = array[rightIndex++];
        }
    }
    while (leftIndex <= middle)
    {
        newArray[newArrayIndex++] = array[leftIndex++];
    }
    while (newArrayIndex <= right)
    {
        newArray[newArrayIndex++] = array[rightIndex++];
    }
    for (int i = left; i <= right; i++)
    {
        array[i] = newArray[i];
    }
}

void display(int *array)
{
    for (int i = 0; i < SIZE; i++)
    {
      printf("%d ", array[i]);
    }
    printf("\n");
}

void mergesort(int *array, int left, int right)
{
    int middle;

    if (left < right)
    {
        middle = (left + right) / 2;
        mergesort(array, left, middle);
        mergesort(array, middle + 1, right);
        merge(array, left, middle, right);
        display(array);
    }
}

int main()
{
    int array[SIZE] = {2, 4, 5, 7, 1, 2, 3, 6};
    display(array);
    mergesort(array, 0, SIZE - 1);
}