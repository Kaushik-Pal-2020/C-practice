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

int getMax(int arr[], int n)
{
    int i = 1, max = arr[0];
    for (; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int *getHashTable(int arr[], int n)
{
    int max = getMax(arr, n);
    int *hash = (int *)calloc(max + 1, sizeof(int));
    int i = 0;
    for (; i < n; i++)
        ++hash[arr[i]];
    return hash;
}

int *nextGreaterFrequency(int arr[], int n)
{
    int *hash = getHashTable(arr, n);
    struct Stack *stack = createStack(n);
    int *results = (int *)malloc(n * sizeof(int));
    int i;

    push(stack, 0);
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (hash[arr[i]] > hash[arr[peek(stack)]]))
            results[pop(stack)] = arr[i];
        push(stack, i);
    }

    while (isEmpty(stack) == -1)
        results[pop(stack)] = -1;

    clear(stack);
    free(hash);
    return results;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *p = nextGreaterFrequency(arr, n);
    int i = 0;
    for (; i < n; i++)
    {
        printf("%d --> %d \n", arr[i], p[i]);
    }
    free(p);
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
    return stack->arr[stack->top--];
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
