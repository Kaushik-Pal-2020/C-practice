/*
Input : Queue[] = { 5, 1, 2, 3, 4 }
Output : Yes
Pop the first element of the given Queue i.e 5.
Push 5 into the stack.
Now, pop all the elements of the given Queue and push them to
second Queue.
Now, pop element 5 in the stack and push it to the second Queue.
 
Input : Queue[] = { 5, 1, 2, 6, 3, 4 }
Output : No
Push 5 to stack.
Pop 1, 2 from given Queue and push it to another Queue.
Pop 6 from given Queue and push to stack.
Pop 3, 4 from given Queue and push to second Queue.
Now, from using any of above operation, we cannot push 5
into the second Queue because it is below the 6 in the stack.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
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

struct Queue *createQueue();       // for basic linkedlist queue operation
void enQueue(struct Queue *, int); // for basic linkedlist queue operation
int deQueue(struct Queue *);       // for basic linkedlist queue operation
int isEmpty(struct Queue *);       // for basic linkedlist queue operation
int peek(struct Queue *);          // for basic linkedlist queue operation
void clear(struct Queue *);        // for basic linkedlist queue operation

struct Stack *createStack(int);       //for basic array stack operation
void push_stack(struct Stack *, int); //for basic array stack operation
int pop_stack(struct Stack *);        //for basic array stack operation
int peek_stack(struct Stack *);       //for basic array stack operation
int isEmpty_stack(struct Stack *);    //for basic array stack operation
int isFull_stack(struct Stack *);     //for basic array stack operation
void clear_stack(struct Stack *);     //for basic array stack operation

void display(struct Queue *);

struct Queue *checkSorted(int arr[], int n)
{
    struct Queue *main_queue = createQueue();
    struct Queue *tmp = createQueue();
    struct Stack *stack = createStack(n);
    register int i;
    for (i = 0; i < n; i++)
        enQueue(main_queue, arr[i]);

    int expected_element = 1;

    for (i = 0; i < n; i++)
    {
        if (expected_element == main_queue->front->data)
        {
            enQueue(tmp, deQueue(main_queue));
            expected_element++;
        }
        else if ((expected_element != main_queue->front->data) && (main_queue->front->data <= peek_stack(stack)))
        {
            push_stack(stack, deQueue(main_queue));
        }
        else
        {
            printf("It can not be sorted\n");
            clear(main_queue);
            clear(tmp);
            clear_stack(stack);
            return NULL;
        }
    }
    while (isEmpty_stack(stack) == -1)
        enQueue(tmp, pop_stack(stack));

    printf("Queue is sorted\n");

    clear(main_queue);
    clear_stack(stack);
    return tmp;
}
int main()
{
    int arr[] = { 5, 1, 2, 5, 3, 4 };
    int n = sizeof(arr) / sizeof(*arr);
    struct Queue *queue = checkSorted(arr, n);
    if (queue != NULL)
    {
    	display(queue);
    	clear(queue);
	}
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

int peek(struct Queue *queue)
{
    if (!isEmpty(queue))
        return queue->rear->data;
    return -999;
}

void enQueue(struct Queue *queue, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(*newNode));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue))
        queue->front = queue->rear = newNode;
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int deQueue(struct Queue *queue)
{
    int data = -999;
    if (!isEmpty(queue))
    {
        struct Node *p = queue->front;
        data = p->data;
        if (queue->front == queue->rear)
            queue->front = queue->rear = NULL;
        else
            queue->front = p->next;
        free(p);
    }
    return data;
}

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(*q));
    q->front = q->rear = NULL;
    return q;
}

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
