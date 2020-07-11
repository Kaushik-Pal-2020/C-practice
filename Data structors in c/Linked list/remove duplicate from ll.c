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
int remove_duplicate(struct Node **);
int main()
{
    struct Node *root = NULL;
    int arr[10] = {10, 10, 30, 40, 50, 70, 70, 70, 90, 90};
    build(arr, 10, &root);
    remove_duplicate(&root);
    display(root);
    clear(&root);
    return 0;
}
int remove_duplicate(struct Node **head)
{
    struct Node *curr, *tail;
    curr = tail = *head;
    int count = 0;
    while (curr->next)
    {
        tail = curr;
        curr = curr->next;
        if (tail->data == curr->data)
        {
            tail->next = curr->next;
            free(curr);
            curr = tail;
            count++;
        }
    }
    printf("Deleted %d elements\n", count);
    return 0;
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
