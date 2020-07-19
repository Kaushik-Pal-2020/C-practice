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
void insertRear(struct Queue *, int);  // for basic linkedlist queue operation
void insertFront(struct Queue *, int); // for basic linkedlist queue operation
int deleteFront(struct Queue *);       // for basic linkedlist queue operation
int deleteRear(struct Queue *);        // for basic linkedlist queue operation
int isEmpty(struct Queue *);           // for basic linkedlist queue operation
int getRear(struct Queue *);           // for basic linkedlist queue operation
int getFront(struct Queue *);          // for basic linkedlist queue operation
int length(struct Queue *);            // for basic linkedlist queue operation
void clear(struct Queue *);            // for basic linkedlist queue operation

void display(struct Queue *);

int main()
{
    struct Queue *q = createQueue();
    insertRear(q, 10);
    insertRear(q, 20);
    insertRear(q, 30);
    insertRear(q, 40);
    insertRear(q, 50);
    display(q);
    insertFront(q, 60);
    display(q);
    deleteFront(q);
    deleteRear(q);
    display(q);
    printf("Front element = %d , Rear Element = %d\n", getFront(q), getRear(q));
    printf("size = %d\n", length(q));
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

int length(struct Queue *q)
{
    int count = 0;
    struct Node *p = q->front;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int getRear(struct Queue *q)
{
    if (q->rear)
        return q->rear->data;
    return -999;
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

int deleteRear(struct Queue *q)
{
    int data = -999;
    if (!isEmpty(q))
    {
        struct Node *p = q->rear;
        data = p->data;
        q->rear = p->prev;
        q->rear->next = p->prev = NULL;
        free(p);
    }
    return data;
}