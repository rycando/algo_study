#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  s_stack{
    unsigned int    max_size;
    int             top_index;
    int             *data;
}               t_stack;

int com_find(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
            return (0);
        str1++;
        str2++;
    }
    return (1);
}

int main()
{
    t_stack *stack;
    size_t  max;
    char    *com;
    int     num;

    stack = malloc(sizeof(t_stack));
    scanf("%zd", &max);
    stack->max_size = max;
    stack->top_index = -1;
    stack->data = malloc(sizeof(int) * stack->max_size);
    while (1)
    {
        com = malloc(sizeof(char) * 6);
        memset(com, 0, 6);
        fflush(stdin);
        scanf("%s %d", com, &num);
        if (com_find(com, "push"))
        {
            stack->top_index++;
            stack->data[stack->top_index] = num;
        }
        else if (com_find(com, "pop"))
        {
            if (stack->top_index >= 0)
            {
                printf("%d\n", stack->data[stack->top_index]);
                stack->top_index--;
            }
            else
                printf("-1\n");
        }
        else if (com_find(com, "size"))
            printf("%d\n", stack->top_index + 1);
        else if (com_find(com, "empty"))
        {
            if (stack->top_index == -1)
                printf("1\n");
            else
                printf("0\n");
        }
        else if (com_find(com, "top"))
        {
            if (stack->top_index == -1)
                printf("-1\n");
            else
                printf("%d\n", stack->data[stack->top_index]);
        }
        printf("");
    }
    free(stack->data);
    free(stack);
    return (0);
}