#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* random;
    struct Node* next;
};
int append(struct Node **root, int data);
void clear(struct Node **current)
{
    while ((*current)->next)
    {
        struct Node *p, *t;
        p = t = (*current);
        while (p->next)
        {
            t = p;
            p = p->next;
        }
        t->next = NULL;
        free(p);
    }
    struct Node *p = *current;
    free(p);
    printf("Cleared all Heap memory\n");
}
void display(struct Node *root)
{
    printf("---------------------------------\n");
    printf("%26s\n", "Displaying linked list");
    while (root)
    {
        printf("current Node Value = %-6d and random pointer points to %6d\n",root->data,root->random->data);
        root = root->next;
    }
    printf("\n---------------------------------\n");
}
int build(int *arr, int n, struct Node **p)
{
    int i = 0;
    for (; i < n; i++)
    {
        if (append(p, arr[i]))
        {
            return -1;
        }
    }
    return 0;
}
struct Node* cloneRandom(struct Node**);
int main()
{
    struct Node *head=NULL;
    int arr[] = {1,2,3,4,5};
    build(arr, 5 ,&head);
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head;
    head->next->next->next->next->random =  head->next;
    display(head);
    struct Node *p = cloneRandom(&head);
    display(p);
    clear(&head);
    clear(&p);
    return 0;
}
struct Node* cloneRandom(struct Node** head)
{
    struct Node *clone = NULL, *end;
    struct Node *forward, *tail, *curr;
    forward = tail = *head;
    // making copy of forward's data into clone's
    while(forward)
    {
        struct Node *p = (struct Node*)malloc(sizeof(struct Node));
        p->data = forward->data;
        p->random = p->next = NULL;
        if(clone == NULL)
        {
            clone = p;
            end = clone;
        }
        else{
            end->next = p;
            end = p;
        }
        forward = forward->next;
    }
    forward = *head;
    curr = clone;
    while(forward)
    {
        tail = forward;
        forward = forward->next;
        tail->next = curr;
        curr->random = tail->random;
        curr = curr->next;
    }
    curr = clone;
    while(curr)
    {
        curr->random = curr->random->next;
        curr = curr->next;
    }
    return clone;
}
int append(struct Node **root, int data)
{
    // 0 means successfully created a node and done inserting
    // else -1 means out of memory or something else happend
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode) //unable to create a node
        return -1;

    newNode->data = data;
    newNode->next = NULL;

    if (!(*root))
        *root = newNode;
    else
    {
        struct Node *p = *root;

        while (p->next)
        {
            p = p->next;
        }
        p->next = newNode;
    }
    return 0;
}
