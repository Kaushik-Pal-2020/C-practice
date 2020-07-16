/*
  this question is alo known as nearest greater to right
 */
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

int *nextGreaterElement(int arr[], int n)
{
    int *right = (int *)calloc(n, sizeof(int));
    struct Stack *stack = createStack(n);
    push(stack, 0);
    int i = 0;
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] > arr[peek(stack)]))
            right[pop(stack)] = i + 1;

        push(stack, i);
    }
    while (isEmpty(stack) == -1)
        right[pop(stack)] = 0;

    clear(stack);
    return right;
}

int *pGEstack(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    int *left = (int *)calloc(n, sizeof(int));
    push(stack, 0);
    left[0] = 0;
    int i = 1;
    for (; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] >= arr[peek(stack)]))
        {
            pop(stack);
        }
        if (isEmpty(stack) == 1)
            left[i] = 0;
        else
            left[i] = peek(stack) + 1;

        push(stack, i);
    }
    printf("\n");
    clear(stack);
    return left;
}
void maxproductNGLR(int arr[], int n)
{
    int *left = pGEstack(arr, n);
    int *right = nextGreaterElement(arr, n);
    int max = 0, i, product;
    for (i = 0; i < n; i++)
    {
        product = left[i] * right[i];
        printf("%d, ", product);
        if (product > max)
            max = product;
    }
    printf("\nMaximum Product = %d\n", max);
    free(left);
    free(right);
}

int main()
{
    int arr[] = {15, 4, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxproductNGLR(arr, n);
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