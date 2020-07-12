#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *);
void build(int *, int, struct Node **);
void append(struct Node **, int);
int peek(struct Node *, int);
int main()
{
    struct Node *head = NULL;
    int arr[] = {10, 20, 30, 40};
    build(arr, 4, &head);
    display(head);
    printf("%d\n", peek(head, 4));
    return 0;
}
int peek(struct Node *head, int pos)
{
    if (pos < 0)
    {
        printf("Invalid Index\n");
        return -1;
    }
    struct Node *curr = head;
    int i = 0;
    do
    {
        if (i == pos)
        {
            return curr->data;
        }
        curr = curr->next;
        i++;
    } while (i <= pos);
}
void append(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (!(*head))
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *t = *head;
        do
        {
            t = t->next;
        } while (t->next != (*head));
        t->next = newNode;
        newNode->next = *head;
    }
}
void build(int *arr, int n, struct Node **head)
{
    int i = 0;
    for (; i < n; i++)
    {
        append(head, arr[i]);
    }
}
void display(struct Node *head)
{
    struct Node *curr = head;
    printf("------------------------------------\n");
    do
    {
        printf("%d ->", curr->data);
        curr = curr->next;
    } while (curr != head);
    printf("\n------------------------------------\n");
}
