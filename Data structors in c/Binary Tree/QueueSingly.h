#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef QueueSingly
#define QueueSingly .h
struct Node_Singly
{
    void *data;
    struct Node_Singly *next;
};

struct Queue_Singly
{
    struct Node_Singly *front;
    struct Node_Singly *rear;
    size_t memSize;
};

int isEmpty_Singly(struct Queue_Singly *queue)
{
    if ((queue->front == NULL) && (queue->rear == NULL))
    {
        return 1;
    }
    return 0;
}

void peek_Singly(struct Queue_Singly *queue, void *data)
{
    if (!isEmpty_Singly(queue))
    {
        memcpy(data, queue->front->data, queue->memSize);
    }
}

void enQueue_Singly(struct Queue_Singly *queue, void *value)
{
    struct Node_Singly *newNode = (struct Node_Singly *)malloc(sizeof(*newNode));
    newNode->data = malloc(queue->memSize);
    if (!newNode)
    {
        printf("Out of Memory\n");
        free(newNode);
        return;
    }
    memcpy(newNode->data, value, queue->memSize);
    newNode->next = NULL;

    if (isEmpty_Singly(queue))
        queue->front = queue->rear = newNode;
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void deQueue_Singly(struct Queue_Singly *queue, void *data)
{
    if (!isEmpty_Singly(queue))
    {
        struct Node_Singly *temp = queue->front;
        memcpy(data, temp->data, queue->memSize);
        if (queue->front == queue->rear)
            queue->front = queue->rear = NULL;
        else
            queue->front = temp->next;

        free(temp->data);
        free(temp);
    }
}

void createQueue(struct Queue_Singly *q, size_t memSize)
{
    q->front = q->rear = NULL;
    q->memSize = memSize;
}

void display_Singly(struct Queue_Singly *queue)
{
    printf("====================================\n");
    printf("%16s\n", "Displaying Queue");
    struct Node_Singly *p = queue->front;
    int data;
    while (p)
    {
        memcpy(&data, p->data, queue->memSize);
        printf("%d ", data);
        p = p->next;
    }
    printf("\n====================================\n");
}

void clear_Singly(struct Queue_Singly *queue)
{
    struct Node_Singly *p = queue->front, *q = NULL;
    while (q)
    {
        q = p;
        q = q->next;
        free(p->data);
        free(p);
    }
    queue->front = queue->rear = NULL;
    queue->memSize = 0;
}
typedef struct Queue_Singly Queue_Singly;
#endif