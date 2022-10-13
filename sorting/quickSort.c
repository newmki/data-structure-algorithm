#include <stdio.h>

#define SIZE 7

int partition(int *array, int left, int right)
{
    int pivot = array[left];
    int i = left;
    int j = right;
    int temp;

    printf("left: %d, right: %d\n", left, right);
    while (i < j)
    {
        while (pivot < array[j])
        {
            j--;
        }
        while (i < j && pivot >= array[i])
        {
            i++;
        }
        //swap
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    array[left] = array[i];
    array[i] = pivot;
    
    return i;
}

void quicksort(int *array, int left, int right)
{
    int pivot;
    if (left >= right)
    {
        return ;
    }

    pivot = partition(array, left, right);

    quicksort(array, left, pivot - 1);
    quicksort(array, pivot + 1, right);
}

void display(int *array)
{
    for (int i = 0; i < SIZE; i++)
    {
      printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[SIZE] = {30, 70, 40, 20, 10, 50, 80};
    display(array);
    quicksort(array, 0, SIZE - 1);
    display(array);
}
