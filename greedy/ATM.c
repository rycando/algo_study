#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int tmp;
    int sum;
    int *time;
    
    sum = 0;
    scanf("%d", &n);
    time = malloc (sizeof(int) * n);
    for (int i = 0; i < n ; i++)
        scanf("%d", &time[i]);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (time[j] > time[j + 1])
            {
                tmp = time[j];
                time[j] = time[j + 1];
                time[j + 1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
        sum += (n - i) * time[i];
    printf("%d", sum);
    free(time);
    return (0);
}