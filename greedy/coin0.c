#include <stdio.h>
#include <stdlib.h>

int main()
{
    int type, cost;
    int *coin;
    int sum, i;

    scanf("%d %d", &type, &cost);
    coin = malloc(sizeof(int) * type);
    for (i = 0; i < type; i++)
        scanf("%d", &coin[i]);
    sum = 0;
    i = type - 1;
    while (i >= 0 && coin[i] > cost)
        i--;
    while (cost)
    {
        sum += cost / coin[i];
        cost %= coin[i];
        i--;
    }
    printf("%d", sum);
    free(coin);
}