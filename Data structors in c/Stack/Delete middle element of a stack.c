#include <stdio.h>
#include <stdlib.h>

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

void deleteMiddleElement(struct Stack *stack)
{
    static int count = 0;
    static int pos = 0;
    if (isEmpty(stack) == -1)
    {
        count++;
        int x = pop(stack);
        deleteMiddleElement(stack);
        if (pos != (count / 2))
            push(stack, x);
        pos++;
    }
}

int main()
{
    struct Stack *s = createStack(5);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    printf("Before deleting middle element \n");
    display(s);

    deleteMiddleElement(s);

    printf("After deleting middle element \n");
    display(s);
    clear(s);
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
    if (isFull(stack) == -1)
        stack->arr[++stack->top] = value;
    else
        printf("Stack Overflow , Can not insert %d\n", value);
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
    if (isEmpty(stack) == 1)
    {
        printf("Stack underflow\n");
        return -999;
    }
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
    printf("Clearing memory ...\n");
    free(stack->arr);
    free(stack);
    printf("Cleared memory");
}
