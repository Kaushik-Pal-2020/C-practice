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

struct Queue *createQueue();          // for basic linkedlist queue operation
void insertRear(struct Queue *, int); // for basic linkedlist queue operation
int deleteFront(struct Queue *);      // for basic linkedlist queue operation
int deleteRear(struct Queue *);       // for basic linkedlist queue operation
int isEmpty(struct Queue *);          // for basic linkedlist queue operation
int getRear(struct Queue *);          // for basic linkedlist queue operation
int getFront(struct Queue *);         // for basic linkedlist queue operation
void clear(struct Queue *);           // for basic linkedlist queue operation

void slidingWindowMaximum(int arr[], int n, int k)
{
    struct Queue *q = createQueue();
    register int i = 0;
    for (; i < k; i++)
    {
        if (isEmpty(q) == 1)
            insertRear(q, i);
        else
        {
            while ((isEmpty(q) == 0) && (arr[i] > arr[getRear(q)]))
                deleteRear(q);
            insertRear(q, i);
        }
    }
    printf("%d  ", arr[getFront(q)]);
    for (i = k; i < n; i++)
    {
        if (getFront(q) <= i - k)
            deleteFront(q);

        while ((isEmpty(q) == 0) && (arr[i] > arr[getRear(q)]))
            deleteRear(q);
        insertRear(q, i);
        printf("%d  ", arr[getFront(q)]);
    }
    clear(q);
}
int main()
{
    int arr[] = {2, 3, 1, 5, 7, 1, 2, 5, 4, 3};
    int n = sizeof(arr) / sizeof(*arr);
    int k = 3;
    slidingWindowMaximum(arr, n, k);
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
int getRear(struct Queue *q)
{
    if (q->rear)
        return q->rear->data;
    return -999;
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
int deleteFront(struct Queue *q)
{
    int data = -999;
    if (!isEmpty(q))
    {
        struct Node *p = q->front;
        data = p->data;
        q->front = p->next;
        if (q->front)
            q->front->prev = p->next = NULL;
        else
            q->rear = NULL;
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
        if (q->rear)
            q->rear->next = p->prev = NULL;
        else
            q->front = NULL;
        free(p);
    }
    return data;
}