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
int del_index(struct Node **, int);
int del_value(struct Node **, int);
void clear(struct Node **);
int main()
{
    struct Node *root = NULL;
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    build(arr, 10, &root);
    del_value(&root, 10);
    display(root);
    clear(&root);
    return 0;
}
int del_value(struct Node **current, int key)
{
    struct Node *p, *tail;
    p = tail = *current;
    while (p && p->data != key)
    {
        tail = p;
        p = p->next;
    }
    if (!p)
    {
        printf("%d key does not exist\n", key);
        return -1;
    }
    if (p == (*current))
        (*current) = (*current)->next;
    else
        tail->next = p->next;
    free(p);
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
int del_index(struct Node **current, int index)
{
    if (index < 0)
    {
        printf("Invalid Index(under flowing) means under 0\n");
        return -1;
    }

    else
    {
        struct Node *tmp = NULL;
        int data;
        if (index == 0)
        {
            tmp = *current;
            data = (*current)->data;
            (*current) = (*current)->next;
        }
        else
        {
            struct Node *slide = *current;
            int i = 0;
            for (; i < index - 1 && slide; i++)
            {
                slide = slide->next;
            }
            if (!slide || !slide->next)
            {
                printf("Invalid Index(overflowing) means index is higher than length\n");
                return -1;
            }
            tmp = slide->next;
            data = tmp->data;
            slide->next = tmp->next;
        }
        free(tmp);
        printf("Successfully deleted element\n");
        return data;
    }
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
