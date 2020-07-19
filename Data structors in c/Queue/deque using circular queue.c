#include <stdlib.h>
#include <stdio.h>

struct Queue
{
    unsigned int capacity;
    int front, rear;
    int *arr;
};

struct Queue *createQueue(int);         // basic queue operation using array
void enQueueFront(struct Queue *, int); // basic queue operation using array
void enQueueRear(struct Queue *, int);  // basic queue operation using array
int deQueueFront(struct Queue *);       // basic queue operation using array
int deQueueRear(struct Queue *);        // basic queue operation using array
int peekFront(struct Queue *);          // basic queue operation using array
int peekRear(struct Queue *);           // basic queue operation using array
int isFull(struct Queue *);             // basic queue operation using array
int isEmpty(struct Queue *);            // basic queue operation using array
void clear(struct Queue *);             // basic queue operation using array

void display(struct Queue *);

void func1(struct Queue *q)
{
    int value;
    printf("Enter value \n");
    scanf("%d", &value);
    enQueueFront(q, value);
}

void func2(struct Queue *q)
{
    int value;
    printf("Enter value \n");
    scanf("%d", &value);
    enQueueRear(q, value);
}

void func3(struct Queue *q)
{
    int c1 = isFull(q);
    int c2 = isEmpty(q);
    printf("Is full = %s and Is Empty = %s\n", (c1 == 1) ? "True" : "False", (c2 == 1) ? "True" : "False");
}
int main()
{
    struct Queue *q = createQueue(5);
    int choice;
    printf("\n Normal Deque");
    printf("\n 1.Insert Element at front");
    printf("\n 2.Insert Element at rear");
    printf("\n 3.Delete Element at front");
    printf("\n 4.Delete Element at rear");
    printf("\n 5.Display");
    printf("\n 6.Front Element");
    printf("\n 7.Rear Element");
    printf("\n 8.Conditions");
    printf("\n 9.Display\n");
    do
    {
        printf("\nchoice = ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            func1(q);
            break;

        case 2:
            func2(q);
            break;

        case 3:
            printf("Deleted Element = %d\n", deQueueFront(q));
            break;

        case 4:
            printf("Deleted Element = %d\n", deQueueRear(q));
            break;

        case 5:
            display(q);
            break;

        case 6:
            printf("Front Element = %d\n", peekFront(q));
            break;

        case 7:
            printf("Rear Element = %d\n", peekRear(q));
            break;

        case 8:
            func3(q);
            break;

        case 9:
            clear(q);
            return 1;
            break;

        default:
            printf("Invalid Index\n");
            break;
        }

    } while (1);
    return 0;
}
struct Queue *createQueue(int size)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->capacity = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(size * sizeof(int));
    return q;
}

void enQueueFront(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q))
        q->front = q->rear = 0;
    else
    {
        if (q->front == 0)
            q->front = q->capacity - 1;
        else
            q->front--;
    }
    q->arr[q->front] = value;
}

void enQueueRear(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }
    if (isEmpty(q))
        q->front = q->rear = 0;
    else
    {
        if (q->rear == q->capacity - 1)
            q->rear = 0;
        else
            q->rear++;
    }
    q->arr[q->rear] = value;
}

int deQueueFront(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -999;
    }
    int data = q->arr[q->front];
    if (q->rear == q->front)
        q->front = q->rear = -1;

    else if (q->front == q->capacity - 1)
        q->front = 0;

    else
        q->front++;

    return data;
}
int deQueueRear(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -999;
    }
    int data = q->arr[q->rear];
    if (q->rear == q->front)

        q->front = q->rear = -1;
    else if (q->rear == 0)
        q->rear = q->capacity - 1;

    else
        q->rear--;

    return data;
}

int peekFront(struct Queue *q)
{
    if (!isEmpty(q))
        return q->arr[q->front];
    return -999;
}

int peekRear(struct Queue *q)
{
    if (!isEmpty(q))
        return q->arr[q->rear];
    return -999;
}

int isFull(struct Queue *q)
{
    if (((q->front == 0) && (q->rear == (q->capacity - 1))) || (q->front == (q->rear + 1)))
        return 1;
    return 0;
}

int isEmpty(struct Queue *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}

void clear(struct Queue *q)
{
    free(q->arr);
    free(q);
}

void display(struct Queue *q)
{
    if (!isEmpty(q))
    {
        printf("\n====================================\n");
        printf("%16s\n", "Displaying Queue");
        int i = q->front;
        do
        {
            printf("%d  ", q->arr[i]);
            i = (i + 1) % q->capacity;
        } while (i != ((q->rear + 1) % q->capacity));
        printf("\n====================================\n");
    }
}
