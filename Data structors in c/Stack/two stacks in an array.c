#include<stdio.h>
#include<stdlib.h>

struct TwoStack
{
    int *arr;
    int top1;
    int top2;
    int capacity;
};

void display(struct TwoStack*);
void push1(struct TwoStack*, int);
void push2(struct TwoStack*, int);
int pop1(struct TwoStack*);
int pop2(struct TwoStack*);
int isEmpty1(struct TwoStack*);
int isEmpty2(struct TwoStack*);
int isFull(struct TwoStack*);
struct TwoStack* createStack();
void clear(struct TwoStack*);

int main()
{
    struct TwoStack *ts = createStack();
    push1(ts ,10);
    push2(ts, 100);
    pop1(ts);
    pop1(ts);
    pop2(ts);
    //printf("poping elements = %d\n",pop1(ts));
    // printf("poping elements = %d\n",pop2(ts));
    display(ts);
    clear(ts);
    return 0; 
}

void push1(struct TwoStack* stack, int value)
{
    if(isFull(stack) == 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top1] = value;
}

void push2(struct TwoStack* stack, int value)
{
    if(isFull(stack) == 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[--stack->top2] = value;
}

struct TwoStack* createStack()
{
    struct TwoStack *stack = (struct TwoStack*)malloc(sizeof(struct TwoStack));
    stack->capacity = 10;
    stack->top1 = -1;
    stack->top2 = stack->capacity;
    stack->arr = (int*)calloc(stack->capacity,sizeof(int));
}

int isEmpty1(struct TwoStack *stack)
{
    if(stack->top1 < 0)
        return 1;
    return -1;
}

int isEmpty2(struct TwoStack *stack)
{
    if(stack->top2 > stack->capacity)
        return 1;
    return -1;
}

int isFull(struct TwoStack* stack)
{
    if(stack->top1 == (stack->top2)-1)
        return 1;
    return -1;
}
void clear(struct TwoStack* stack)
{
    printf("Clearing All memory\n");
    free(stack->arr);
    free(stack);
}

void display(struct TwoStack* stack)
{
    printf("===========================\n");
    int i=0;
    for(;i<stack->capacity;i++)
    {
        printf("%d ->",stack->arr[i]);
    }
    printf("\n===========================\n");
}

int pop1(struct TwoStack* stack)
{
    if(isEmpty1(stack) == 1)
    {
        printf("Stack1 is Underflow\n");
        return -999;
    }
    int data = stack->arr[stack->top1];
    stack->arr[stack->top1] = 0;
    stack->top1--;
    return data;
}

int pop2(struct TwoStack* stack)
{
    if(isEmpty2(stack) == 1)
    {
        printf("Stack2 is Underflow\n");
        return -999;
    }
    int data = stack->arr[stack->top2];
    stack->arr[stack->top2] = 0;
    stack->top2++;
    return data;
}