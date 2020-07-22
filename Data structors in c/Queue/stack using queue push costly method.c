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
struct Queue *q1, *q2;

void createQueue();                // for basic linkedlist queue operation
void enQueue(struct Queue *, int); // for basic linkedlist queue operation
int deQueue(struct Queue *);       // for basic linkedlist queue operation
int isEmpty(struct Queue *);       // for basic linkedlist queue operation
int peek(struct Queue *);          // for basic linkedlist queue operation
void clear(struct Queue *);        // for basic linkedlist queue operation

void display(struct Queue *);

void push_stack(int value)
{
    if (isEmpty(q1) == 1)
        enQueue(q1, value);
    else
    {
        while (isEmpty(q1) != 1)
            enQueue(q2, deQueue(q1));

        enQueue(q1, value);

        while (isEmpty(q2) != 1)
            enQueue(q1, deQueue(q2));
    }
}

int pop_stack()
{
    int v = deQueue(q1);
    printf("Deleted element = %d\n", v);
    return v;
}
int peek_stack()
{
    peek(q1);
}
void display_stack()
{
    display(q1);
}
int main()
{
    createQueue();
    push_stack(1);
    push_stack(2);
    push_stack(3);
    display_stack();
    pop_stack();
    display_stack();
    push_stack(10);
    push_stack(12);
    display_stack();
    clear(q1);
    clear(q2);
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
void createQueue()
{
    q1 = (struct Queue *)malloc(sizeof(struct Queue));
    q1->front = q1->rear = NULL;

    q2 = (struct Queue *)malloc(sizeof(struct Queue));
    q2->front = q2->rear = NULL;
}

void display(struct Queue *queue)
{
    struct Node *p = queue->front;
    printf("====================================\n");
    printf("%16s\n", "Displaying Stack");
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
