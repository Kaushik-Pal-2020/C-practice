#include<stdio.h>
#include<stdlib.h>


struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};
int minElement=-65000;

struct Stack* createStack(int);
void push(struct Stack*, int);
int pop(struct Stack*);
void display(struct Stack*);
int peek(struct Stack*);
int isEmpty(struct Stack*);
int isFull(struct Stack*);
void clear(struct Stack*);

int getMin(struct Stack *);

int main()
{
    struct Stack *s = createStack(50);
    push(s, 85);
    display(s);
    push(s, 42);
    display(s);
    push(s, 12);
    display(s);
    printf("%d\n",getMin(s));
    push(s, 106);
    display(s);
    push(s, 4);
    display(s);
    push(s, 977);
    display(s);
    display(s);
    printf("%d\n",getMin(s));
    pop(s);
    display(s);
    pop(s);
    display(s);
    pop(s);
    display(s);
    printf("%d\n",getMin(s));
    clear(s);
    return 0;
}

int getMin(struct Stack *stack)
{
    if(stack->top==-1)
        return -1;

    return minElement;
}
struct Stack* createStack(int capacity)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

void push(struct Stack* stack, int value)
{
    if(isFull(stack) == -1)
    {
        if(stack->top == -1)
        {
            minElement = value;
            stack->arr[++stack->top] = value;
        }       
        else if(value >= minElement)
            stack->arr[++stack->top] = value;
        else
        {
            minElement = value;
            stack->arr[++stack->top] = (2*value)-minElement;
        }
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
    if(peek(stack) <= minElement)
        return stack->arr[stack->top--];
    else if(peek(stack) > minElement)
    {
        int data = minElement;
        minElement = (2*minElement) - peek(stack);
        stack->top--;
        return data;
    }
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
    if(stack->top==-1)
        return -1;
    else if(stack->arr[stack->top] > minElement)
        return stack->arr[stack->top];

    else if(stack->arr[stack->top] <= minElement)
        return minElement;
}

void clear(struct Stack* stack)
{
    printf("Clearing memory ...\n");
    free(stack->arr);
    free(stack);
    printf("Cleared memory");
}
