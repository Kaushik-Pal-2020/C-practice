#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    unsigned int capacity;
    int front, rear;
    int *arr;
};

struct Queue *createQueue(int);    // basic queue operation using array
void enQueue(struct Queue *, int); // basic queue operation using array
int deQueue(struct Queue *);       // basic queue operation using array
int peek(struct Queue *);          // basic queue operation using array
int isFull(struct Queue *);        // basic queue operation using array
int isEmpty(struct Queue *);       // basic queue operation using array
void clear(struct Queue *);        // basic queue operation using array

void display(struct Queue *);

int main()
{
    struct Queue *q = createQueue(5);
    printf("is empty = %d\n", isEmpty(q));
    enQueue(q, 10);
    enQueue(q, 20);
    printf("is full = %d\n", isFull(q));
    enQueue(q, 30);
    enQueue(q, 40);
    printf("is full = %d\n", isFull(q));
    enQueue(q, 50);
    display(q);
    printf("is full = %d\n", isFull(q));

    deQueue(q);
    deQueue(q);
    display(q);
    printf("rear = %d and front = %d\n", q->front, q->rear);
    clear(q);
    return 0;
}

struct Queue *createQueue(int capacity)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(capacity * sizeof(int));
    return q;
}

void enQueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = value;
    }
    else
    {
        q->rear = (q->rear + 1) % q->capacity;
        q->arr[q->rear] = value;
    }
}

int deQueue(struct Queue *queue)
{
    if (!isEmpty(queue))
    {
        int data = queue->arr[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        return data;
    }
    return -999;
}

int peek(struct Queue *queue)
{
    if (!isEmpty(queue))
        return queue->arr[queue->rear];
    return -999;
}

int isFull(struct Queue *queue)
{
    if (((queue->rear + 1) % queue->capacity) == queue->front)
        return 1;
    return 0;
}

int isEmpty(struct Queue *queue)
{
    if ((queue->front == -1) && (queue->rear == -1))
        return 1;
    return 0;
}

void clear(struct Queue *queue)
{
    free(queue->arr);
    free(queue);
}

void display(struct Queue *queue)
{
    int i;
    printf("====================================\n");
    printf("%16s\n", "Displaying Queue");
    if (queue->front == 0)
        i = 0;
    else
        i = queue->front + 1;
    do
    {
        printf("%d ", queue->arr[i]);
        i = (i + 1) % queue->capacity;
    } while (i != ((queue->rear + 1) % queue->capacity));

    printf("\n====================================\n");
}
