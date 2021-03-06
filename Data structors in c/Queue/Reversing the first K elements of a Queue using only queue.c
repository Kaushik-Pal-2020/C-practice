/*
Input : Q = [10, 20, 30, 40, 50, 60, 
            70, 80, 90, 100]
        k = 5
Output : Q = [50, 40, 30, 20, 10, 60, 
             70, 80, 90, 100]
using queue and stack 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};

struct Queue *createQueue();           // for basic linkedlist queue operation
void insertRear(struct Queue *, int);  // for basic linkedlist queue operation
void insertFront(struct Queue *, int); // for basic linkedlist queue operation
int deleteFront(struct Queue *);       // for basic linkedlist queue operation
int isEmpty(struct Queue *);           // for basic linkedlist queue operation
int length(struct Queue *);            // for basic linkedlist queue operation
void clear(struct Queue *);            // for basic linkedlist queue operation

struct Stack *createStack(int);       //for basic array stack operation
void push_stack(struct Stack *, int); //for basic array stack operation
int pop_stack(struct Stack *);        //for basic array stack operation
int peek_stack(struct Stack *);       //for basic array stack operation
int isEmpty_stack(struct Stack *);    //for basic array stack operation
int isFull_stack(struct Stack *);     //for basic array stack operation
void clear_stack(struct Stack *);     //for basic array stack operation

void display(struct Queue *queue)
{
    struct Node *p = queue->front;
    printf("====================================\n");
    printf("%16s\n", "Displaying Queue");
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n====================================\n");
}

void pushedIntoStack(struct Queue *queue, int k, struct Stack *stack)
{
    if (isEmpty(queue) == 1)
        return;
    if (k > 0)
    {
        int value = deleteFront(queue);
        pushedIntoStack(queue, k - 1, stack);
        push_stack(stack, value);
    }
}
void reverseKElements(struct Queue *queue, int k, int n)
{
    struct Stack *stack = createStack(n);
    register int i = 0;
    pushedIntoStack(queue, k, stack);

    while (isEmpty_stack(stack) == -1)
        insertFront(queue, pop_stack(stack));

    clear_stack(stack);
}
int main()
{
    struct Queue *queue = createQueue();
    insertRear(queue, 10);
    insertRear(queue, 20);
    insertRear(queue, 30);
    insertRear(queue, 40);
    insertRear(queue, 50);
    insertRear(queue, 60);
    insertRear(queue, 70);
    insertRear(queue, 80);
    insertRear(queue, 90);
    insertRear(queue, 100);
    display(queue);
    int k = 2;
    reverseKElements(queue, k, 10);
    display(queue);
    clear(queue);
    free(queue);
    return 0;
}

int isEmpty(struct Queue *queue)
{
    if ((queue->front == NULL) && (queue->rear == NULL))
    {
        return 1;
    }
    return 0;
}
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(*q));
    q->front = q->rear = NULL;
    return q;
}

void clear(struct Queue *queue)
{
    struct Node *p = queue->front, *q = NULL;
    while (q)
    {
        q = p;
        q = q->next;
        free(p);
    }
    free(queue);
}

void insertRear(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(*newNode));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (q->rear == NULL && q->front == NULL)
        q->rear = q->front = newNode;
    else
    {
        newNode->prev = q->rear;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void insertFront(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(*newNode));
    newNode->data = value;
    newNode->prev = newNode->next = NULL;

    if (q->rear == NULL && q->front == NULL)
        q->rear = q->front = newNode;
    else
    {
        newNode->next = q->front;
        q->front->prev = newNode;
        q->front = newNode;
    }
}

int deleteFront(struct Queue *q)
{
    int data = -999;
    if (!isEmpty(q))
    {
        struct Node *p = q->front;
        data = p->data;
        q->front = p->next;
        q->front->prev = p->next = NULL;
        free(p);
    }
    return data;
}
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push_stack(struct Stack *stack, int value)
{
    if (isFull_stack(stack) == -1)
        stack->arr[++stack->top] = value;
    else
        printf("Stack Overflow , Can not insert %d\n", value);
}

int isEmpty_stack(struct Stack *stack)
{
    if (stack->top == -1)
        return 1;
    return -1;
}
int isFull_stack(struct Stack *stack)
{
    if (stack->top == stack->capacity - 1)
        return 1;
    return -1;
}

int pop_stack(struct Stack *stack)
{
    if (isEmpty_stack(stack) == 1)
    {
        printf("Stack underflow\n");
        return -999;
    }
    return stack->arr[stack->top--];
}

int peek_stack(struct Stack *stack)
{
    return stack->arr[stack->top];
}

void clear_stack(struct Stack *stack)
{
    free(stack->arr);
    free(stack);
}
