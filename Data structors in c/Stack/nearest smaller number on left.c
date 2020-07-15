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

void NSNleft_basic(int arr[], int n)
{
    int i, j, flag;
    for (i = 0; i < n; i++)
    {
        flag = 0;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                printf("%d, ", arr[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("_, ");
    }
    printf("\n");
}
// time complexity = O(n^2)
// space complexity = O(1)
void NSNleft_stack(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    push(stack, arr[0]);
    printf("_, ");
    int i;
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] < peek(stack)))
            pop(stack);

        if (isEmpty(stack) == -1)
            printf("%d, ", peek(stack));
        else
            printf("_, ");
        push(stack, arr[i]);
    }
    printf("\n");
    clear(stack);
}
// time complexity = O(n)
// space complexity = O(n)
int main()
{
    int arr[] = {1, 6, 4, 10, 2, 5};
    int n = sizeof(arr) / sizeof(*arr);
    NSNleft_basic(arr, n);
    NSNleft_stack(arr, n);
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