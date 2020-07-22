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

struct Queue *createQueue();           // for basic linkedlist queue operation
void insertFront(struct Queue *, int); // for basic linkedlist queue operation
int deleteFront(struct Queue *);       // for basic linkedlist queue operation
int isEmpty(struct Queue *);           // for basic linkedlist queue operation
int getFront(struct Queue *);          // for basic linkedlist queue operation
void clear(struct Queue *);            // for basic linkedlist queue operation

void display(struct Queue *);

int main()
{
    struct Queue *q = createQueue();
    /*
    pop = deleteFront
    push = insertFront
    */
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
int getFront(struct Queue *q)
{
    if (q->front)
        return q->front->data;
    return -999;
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
    printf("%16s\n", "Displaying Queue stack");
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