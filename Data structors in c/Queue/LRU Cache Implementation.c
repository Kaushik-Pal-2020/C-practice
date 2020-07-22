#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

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
int isEmpty(struct Queue *);           // for basic linkedlist queue operation
int getFront(struct Queue *);          // for basic linkedlist queue operation
int length(struct Queue *);            // for basic linkedlist queue operation
void clear(struct Queue *);            // for basic linkedlist queue operation

void LRUcache(int *arr, int n, int k)
{
    int page_fault = 0;
    register int i;
    struct Queue *cache = createQueue();
    struct Node *HashTable[SIZE];
    struct Node *p, *q, *end;
    for (i = 0; i < SIZE; i++)
        HashTable[i] = NULL;
    int cache_length = 0;
    for (i = 0; i < n; i++)
    {
        if (HashTable[arr[i]] == NULL)
        {
            if (cache_length >= k)
            {
                HashTable[deleteFront(cache)] = NULL;
                cache_length--;
            }
            insertRear(cache, arr[i]);
            HashTable[arr[i]] = cache->rear;
            page_fault++;
            cache_length++;
        }
        else
        {
            p = HashTable[arr[i]];
            if ((p != cache->front) && (p != cache->rear))
            {
                q = p->prev;
                end = cache->rear;
                p->next->prev = q;
                q->next = p->next;
                p->prev = end;
                p->next = NULL;
                end->next = p;
                cache->rear = p;
            }
            else if (p == cache->front)
            {
                end = cache->rear;
                q = p->next;
                p->next = q->prev = NULL;
                end->next = p;
                p->prev = end;
                cache->rear = p;
                cache->front = q;
            }
        }
    }

    printf("Total No of page faults = %d\n", page_fault);
    p = cache->front;
    while (p)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
    clear(cache);
    free(cache);
}

int main()
{
    int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(arr) / sizeof(*arr);
    int k = 4;
    LRUcache(arr, n, k);
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