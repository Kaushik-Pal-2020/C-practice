/*
Given an array arr[] and a number k. The task is to delete k elements which are smaller than next element
 (i.e., we delete arr[i] if arr[i] < arr[i+1])
 or become smaller than next because next element is deleted.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};

struct Stack *createStack(int); // for normal stack operation
void push(struct Stack *, int); // for normal stack operation
int pop(struct Stack *);        // for normal stack operation
void display(struct Stack *);   // for normal stack operation
int peek(struct Stack *);       // for normal stack operation
int isEmpty(struct Stack *);    // for normal stack operation
int isFull(struct Stack *);     // for normal stack operation
void clear(struct Stack *);     // for normal stack operation

void deleteElements(int *arr, int n, int k)
{
    struct Stack *stack = createStack(n);
    int count = 0, i, j;
    push(stack, arr[0]);
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (peek(stack) < arr[i]) && (count < k))
        {
            pop(stack);
            count++;
        }
        push(stack, arr[i]);
        if (count > k)
            break;
    }
    int *temp_array = (int *)calloc(n, sizeof(int));
    j = stack->top + 1;
    for (; isEmpty(stack) == -1;)
        temp_array[stack->top] = pop(stack);

    for (; i < n; i++, j++)
        temp_array[j] = arr[i];

    for (i = 0; i < j; i++)
        printf("%d ", temp_array[i]);

    clear(stack);
}

int main()
{
    int arr[] = { 3, 100, 1 };
    int n = sizeof(arr) / sizeof(*arr);
    int k = 1;
    deleteElements(arr, n, k);
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

int isFull(struct Stack *stack)
{
    if (stack->top == stack->capacity - 1)
        return 1;
    return -1;
}

int pop(struct Stack *stack)
{
    return stack->arr[stack->top--];
}

void display(struct Stack *stack)
{
    char *arrow = "--> ";
    printf("===========================\n");
    int i = stack->top;
    for (; i >= 0; i--)
    {
        printf("%d %s", stack->arr[i], (i == 0) ? "\n" : arrow);
    }
    printf("===========================\n");
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
