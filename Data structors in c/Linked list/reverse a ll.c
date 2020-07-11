#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *);
int append(struct Node **, int);
int build(int *, int, struct Node **);
void clear(struct Node **);
int reverse(struct Node **);
int reverse_recursive(struct Node **, struct Node *);
int main()
{
    struct Node *root = NULL;
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    build(arr, 10, &root);
    display(root);
    reverse(&root);
    display(root);
    clear(&root);
    return 0;
}
int reverse(struct Node **head)
{
    struct Node *forward = *head, *current, *tail;
    current = tail = NULL;
    while (forward)
    {
        tail = current;
        current = forward;
        forward = forward->next;
        current->next = tail;
    }
    *head = current;
    return -1;
}
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
        printf("%d(%u)-> ", root->data, root);
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
