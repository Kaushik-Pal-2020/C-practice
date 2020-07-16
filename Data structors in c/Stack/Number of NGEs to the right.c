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

// time complexity = O(n)
// space complexity = O(n)
int *nextGreaterElement(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    int *result = (int *)malloc(n * sizeof(int));
    push(stack, 0);
    int i = 0;
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] > arr[peek(stack)]))
            result[pop(stack)] = arr[i];

        push(stack, i);
    }
    while (isEmpty(stack) == -1)
        result[pop(stack)] = -1;

    clear(stack);
    return result;
}

int main()
{
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *res = nextGreaterElement(arr, n);
    int i;
    for (i = 0; i < n; i++)
        printf("%d, ", res[i]);
    printf("\n");
    int q;
    int key;
    scanf("%d", &n);
    while (q > 0)
    {
        scanf("%d", &key);
        printf("%d -->%d\n", arr[key], res[key]);
        q--;
    }
    free(res);
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
