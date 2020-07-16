#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};

struct Stack *createStack(int);
void push(struct Stack *, int);
int pop(struct Stack *);
int peek(struct Stack *);
int isEmpty(struct Stack *);
void clear(struct Stack *);

void nextGreaterElement(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    // push(stack, arr[0]);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] > peek(stack)))
        {
            printf("greater element of %d = %d\n", pop(stack), arr[i]);
        }
        push(stack, arr[i]);
    }
    while (isEmpty(stack) == -1)
        printf("greater element of %d = null\n", pop(stack));
    clear(stack);
}
// time complexity = O(n)
// space complexity = O(n)

void nextGreaterElementSorted(int arr[], int n)
{
    int i = 0;
    struct Stack *s = createStack(n);
    int element, next;

    push(s, arr[0]);
    for (i = 1; i < n; i++)
    {
        next = arr[i];
        if (isEmpty(s) == -1)
        {
            // if stack is not empty, then pop an element from stack
            element = pop(s);
            while (element < next)
            {
                printf("\n %d --> %d", element, next);
                if (isEmpty(s) == 1)
                    break;
                element = pop(s);
            }
            if (element > next)
                push(s, element);
        }
        push(s, next);
    }
    while (isEmpty(s) == -1)
    {
        element = pop(s);
        next = -1;
        printf("\n %d --> %d", element, next);
    }
}
// time complexity = O(n)
// space complexity = O(n)

void printNGE(int arr[], int n)
{
    int next, i, j;
    for (i = 0; i < n; i++)
    {
        next = -1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        printf("%d -- %dn", arr[i], next);
    }
}
// time complexity = O(n^2)
// space complexity = O(1)

int main()
{
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
    nextGreaterElement(arr, 8);
    nextGreaterElementSorted(arr, 8);
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