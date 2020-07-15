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

int *NSNleft_stack(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    push(stack, 0);
    int *left = (int *)malloc(sizeof(int) * n);
    left[0] = -1;
    int i;
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] < arr[peek(stack)]))
            pop(stack);

        if (isEmpty(stack) == -1)
            left[i] = peek(stack);
        else
            left[i] = -1;
        push(stack, i);
    }
    clear(stack);
    return left;
}
int *NSNright_stack(int arr[], int n)
{
    int *right = (int *)malloc(sizeof(int) * n);
    struct Stack *stack = createStack(n);
    push(stack, 0);
    int i;
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] < arr[peek(stack)]))
            right[pop(stack)] = i;

        push(stack, i);
    }
    while (isEmpty(stack) == -1)
    {
        right[pop(stack)] = n + 1;
    }
    clear(stack);
    return right;
}
int *maximumAreaHistogram(int arr[], int n)
{
    int *area = (int *)malloc(n * sizeof(int));
    int *left = NSNleft_stack(arr, n);
    int *right = NSNright_stack(arr, n);
    int i, width, max = 0, ar;
    for (i = 0; i < n; i++)
    {
        width = right[i] - left[i] - 1; // width between histogram
        area[i] = width * arr[i];
        if (area[i] > max)
            max = arr[i];
    }
    free(left);
    free(right);
    printf("maximum area = %d\n", max);
    return area;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(arr) / sizeof(*arr);
    int *p = maximumAreaHistogram(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d->", p[i]);
    }
    printf("\n");
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