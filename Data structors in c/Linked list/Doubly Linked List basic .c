#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct DoublyLL
{
    Node *head;
    Node *end;
    int length;
} DoublyLL;

void append(DoublyLL *, int);
void build(int *, int, DoublyLL *);
void display(DoublyLL *);
void clear(DoublyLL *);
void insert(DoublyLL *, int, int);

int main()
{
    DoublyLL d1 = {NULL, NULL, 0};
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    build(arr, 10, &d1);
    display(&d1);
    insert(&d1, 3, 110);
    display(&d1);
    clear(&d1);
    return 0;
}
void insert(DoublyLL *main, int pos, int value)
{
    if (pos < 0)
    {
        printf("Invalid Index");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    if (main->head == NULL)
    {
        main->head = newNode;
        main->end = main->head;
        main->length++;
        return;
    }
    if (pos > main->length)
    {
        printf("Invalid Index");
        return;
    }
    if (pos == main->length)
    {
        main->end->next = newNode;
        newNode->prev = main->end;
        main->end = newNode;
        main->length++;
        return;
    }
    if (pos <= (main->length / 2))
    {
        int i = 0;
        Node *p, *q = NULL;
        p = main->head;
        while (i < pos)
        {
            p = p->next;
        }
        newNode->prev = q;
        p->prev = newNode;
        newNode->next = p;
        if (pos == 0)
            main->head = newNode;
        else
            q->next = newNode;
    }
    else
    {
        int i = main->length;
        Node *p, *q = NULL;
        p = main->end;
        while (i > pos)
        {
            q = p->prev;
            i--;
            if (i != pos)
                p = q;
        }
        q->next = newNode;
        newNode->prev = q;
        p->prev = newNode;
        newNode->next = p;
    }
}
void clear(DoublyLL *main)
{
    printf("Clearing memory ...\n");
    Node *p = main->end;
    Node *q = NULL;
    while (p != main->head)
    {
        q = p->prev;
        q->next = NULL;
        free(p);
        p = q;
    }
    main->head->next = NULL;
    free(main->head);
    free(main->end);
    printf("All memory is cleared\n");
}
void display(DoublyLL *main)
{
    Node *p = main->head;
    printf("========================================\n");
    while (p)
    {
        printf("%d ->", p->data);
        p = p->next;
    }
    printf("\n========================================\n");
}
void build(int *arr, int n, DoublyLL *main)
{
    int i = 0;
    for (; i < n; i++)
    {
        append(main, arr[i]);
    }
}
void append(DoublyLL *main, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    if (main->head == NULL)
    {
        main->head = newNode;
        main->end = main->head;
    }
    else
    {
        main->end->next = newNode;
        newNode->prev = main->end;
        main->end = newNode;
    }
    main->length++;
}
