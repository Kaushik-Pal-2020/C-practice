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
void insert(struct Node**, int, int);
int del(struct Node **, int);
int main()
{
    struct Node *head = NULL;
    int arr[] = {10, 20, 30, 40};
    build(arr, 4, &head);
    display(head);
    insert(&head , 50, 2);
    display(head);
    del(&head,4);
    display(head);
    return 0;
}
int del(struct Node **head, int position)
{
    if(position < 0)
    {
        printf("Invalid Index\n");
        return -1;
    }
    if(*head == NULL)
    {
        printf("Head is null\n");
        return -1;
    }
    struct Node *curr = *head, *tail = NULL;
    int i=0, data;
    if(position == 0)
    {
        do
        {
            curr = curr->next;
        } while (curr->next != *head);
        tail = *head;
        data = tail->data;
        curr->next = tail->next;
        tail->next = NULL;
        *head = curr->next;
        free(tail);
        return data;
    }
    do
    {
        if(position == i)
            break;
        tail = curr;
        curr = curr->next;
        i++;
    } while (curr != *head);
    if(curr== *head || i<position)
        {
            printf("Invalid Index\n");
            return -1;
        }
    tail->next = curr->next;
    data = curr->data;
    curr->next = NULL;
    free(curr);
    return data;
}
void insert(struct Node** head, int value, int position)
{
    if(position < 0)
    {
        printf("Invalid Index\n");
        return;
    }
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if(!(*head))
        {
            newNode->next = *head;
            *head = newNode;
            return;
        }
    struct Node *curr = *head;
    int i = 0;
    if(position == 0)
    {
        do
        {
            curr = curr->next;
        } while (curr->next != *head);
        curr->next = newNode;
        newNode->next = *head;
        *head = newNode;
        return ;
    }
    do
    {
        if(i == position-1)
            break;
        curr = curr->next;
        i++;
    } while ((curr != *head));
    if((curr == *head) && i < position)
        {
            printf("Invalid Index\n");
            return;
        }  
    newNode->next = curr->next;
    curr->next = newNode;
    return;
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
