#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int first, int end, int *data1, int *data2)
{
    int pivot = first;
    int j = pivot;
    int i = j + 1;

    if (first < end)
    {
        for (; i <= end; i++)
        {
            if (data1[i] < data1[pivot])
            {
                j++;
                swap(&data1[j], &data1[i]);
                swap(&data2[j], &data2[i]);
            }
        }
        swap(&data1[first], &data1[j]);
        swap(&data2[first], &data2[j]);
        pivot = j;
        quicksort(first, pivot - 1, data1, data2);
        quicksort(pivot + 1, end, data1, data2);
    }
}

int main()
{
    int idx;
    int team;
    int *time[2];
    int res, last;

    scanf ("%d", &team);
    time[0] = malloc(sizeof(int) * team);
    time[1] = malloc(sizeof(int) * team);
    for (idx = 0; idx < team; idx++)
        scanf("%d %d", &time[0][idx], &time[1][idx]);
    quicksort(0, team - 1, time[1], time[0]);
    // for (idx = 0; idx < team - 1; idx++)
    // {
    //     for (int j = 0; j < team - idx - 1; j++)
    //     {
    //         if (time[1][j] > time[1][j + 1])
    //         {
    //             tmp = time[1][j];
    //             time[1][j] = time[1][j + 1];
    //             time[1][j + 1] = tmp;
    //             tmp = time[0][j];
    //             time[0][j] = time[0][j + 1];
    //             time[0][j + 1] = tmp;
    //         }
    //     }
    // }
    res = 0;
    idx = 0;
    last = 0;
    while (idx < team)
    {
        if (time[0][idx] >= last)
        {
            last = time[1][idx];
            res++;
            idx++;
        }
        else
            idx++;
    }
    printf("%d", res);
    free(time[0]);
    free(time[1]);
    return (0);
}