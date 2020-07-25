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

struct Queue *createQueue();       // for basic linkedlist queue operation
void enQueue(struct Queue *, int); // for basic linkedlist queue operation
int deQueue(struct Queue *);       // for basic linkedlist queue operation
int isEmpty(struct Queue *);       // for basic linkedlist queue operation
int peek(struct Queue *);          // for basic linkedlist queue operation
void clear(struct Queue *);        // for basic linkedlist queue operation

void display(struct Queue *);

void interLeaveQueue(struct Queue *q)
{
    struct Queue *temp = createQueue();
    struct Node *fast;
    fast = q->front;
    while (fast)
    {
        if (fast->next == NULL)
        {
            enQueue(temp, deQueue(q));
            break;
        }
        fast = fast->next->next;
        enQueue(temp, deQueue(q));
    }
    fast = temp->front;
    do
    {
        enQueue(q, deQueue(temp));
        enQueue(q, deQueue(q));
    } while ((isEmpty(temp) != 1) && (q->front != fast));

    if (isEmpty(temp) != 1)
        enQueue(q, deQueue(temp));

    free(temp->front);
    free(temp->rear);
    free(temp);
}
int main()
{
    struct Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    // enQueue(q, 50);
    display(q);
    interLeaveQueue(q);
    display(q);
    clear(q);
    free(q);
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