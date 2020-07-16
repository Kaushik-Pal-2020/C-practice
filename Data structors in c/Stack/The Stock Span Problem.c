#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};

struct Stack *createStack(int); // only for stack
void push(struct Stack *, int); // only for stack
int pop(struct Stack *);        // only for stack
int peek(struct Stack *);       // only for stack
int isEmpty(struct Stack *);    // only for stack
void clear(struct Stack *);     // only for stack

void stockSpanBasic(int *arr, int n)
{
    int i, j, count;
    for (i = 0; i < n; i++)
    {
        count = 1;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
                break;
            count++;
        }
        printf("%d ", count);
    }
    printf("\n");
}
// time complexity = O(n^2)
// space complexity = O(1)

void stockSpanStack(int *prices, int n)
{
    struct Stack *s = createStack(n);
    push(s, 0);
    int i;
    printf("1 ");
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(s) == -1) && prices[i] >= prices[peek(s)])
            pop(s);

        if (isEmpty(s) == 1)
            printf("%d ", i + 1);
        else
            printf("%d ", i - peek(s));
        push(s, i);
    }
    printf("\n");
    clear(s);
}
int main()
{
    int stock[] = {100, 80, 60, 70, 60, 75, 85};
    int n_of_days = 7;
    stockSpanBasic(stock, n_of_days);
    stockSpanStack(stock, n_of_days);
    return 0;
}
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int value)
{
    stack->arr[++stack->top] = value;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        return 1;
    return -1;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack) == 1)
    {
        printf("Stack underflow\n");
        return -999;
    }
    return stack->arr[--stack->top];
}

int peek(struct Stack *stack)
{
    return stack->arr[stack->top];
}

void clear(struct Stack *stack)
{
    free(stack->arr);
    free(stack);
}