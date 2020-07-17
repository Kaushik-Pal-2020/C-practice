#include<stdio.h>
#include<stdlib.h>


struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};
struct Stack supporting_stack;

struct Stack* createStack(int);
void push(struct Stack*, int);
int pop(struct Stack*);
void display(struct Stack*);
int peek(struct Stack*);
int isEmpty(struct Stack*);
int isFull(struct Stack*);
void clear(struct Stack*);

int getMin();

int main()
{
    struct Stack *s = createStack(50);
    push(s, 85);
    push(s, 42);
    push(s, 12);
    push(s, 106);
    push(s, 4);
    push(s, 977);
    display(s);
    //push(s, 100);
    display(&supporting_stack);

    pop(s);
    pop(s);
    display(&supporting_stack);
    clear(s);
    return 0;
}

int getMin()
{
    return peek(&supporting_stack);
}
struct Stack* createStack(int capacity)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    supporting_stack.top = stack->top = -1;
    supporting_stack.capacity = stack->capacity = capacity;
    stack->arr = (int*)malloc(stack->capacity*sizeof(int));
    supporting_stack.arr = (int*)malloc(supporting_stack.capacity*sizeof(int));
    return stack;
}

void push(struct Stack* stack, int value)
{
    if(isFull(stack) == -1)
    {
        stack->arr[++stack->top] = value;
        if(value < peek(&supporting_stack))
            push(&supporting_stack, value);
    }
    else
        printf("Stack Overflow , Can not insert %d\n",value);
}

int isEmpty(struct Stack* stack)
{
    if(stack->top == -1)
        return 1;
    return -1;
}

int isFull(struct Stack* stack)
{
    if(stack->top == stack->capacity-1)
        return 1;
    return -1;
}

int pop(struct Stack* stack)
{
    if(isEmpty(stack) == 1)
    {
        printf("Stack underflow\n");
        return -999;
    }
    int data = stack->arr[stack->top--];
    if(data == peek(&supporting_stack))
        pop(&supporting_stack);
    return data;
}

void display(struct Stack* stack)
{
    char *arrow = "-->";
    printf("===========================\n");
    int i = stack->top;
    for(;i >=0 ;i--)
    {
        printf("%d %s",stack->arr[i],(i==0) ? "\n" : arrow);
    }
    printf("===========================\n");
}

int peek(struct Stack* stack)
{
    return stack->arr[stack->top];
}

void clear(struct Stack* stack)
{
    printf("Clearing memory ...\n");
    free(stack->arr);
    free(supporting_stack.arr);
    free(stack);
    printf("Cleared memory");
}
