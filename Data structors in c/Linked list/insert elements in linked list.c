#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *);
int insert(struct Node **, int, int);
int build(int *, int, struct Node **);
void clear(struct Node **);
int main()
{
    struct Node *root = NULL;
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    build(arr, 10, &root);
    insert(&root, 110, 11);
    display(root);
    clear(&root);
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
        if (insert(p, arr[i], 0))
        {
            return -1;
        }
    }
    return 0;
}
int insert(struct Node **head, int data, int pos)
{
    if (pos < 0)
    {
        printf("Invalid Index\n");
        return -1;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Unable to create a Node, out of memory\n");
        return -1;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (!(*head))
    {
        (*head) = newNode;
        return 0;
    }
    else if (pos == 0)
    {
        newNode->next = (*head);
        *head = newNode;
    }
    else
    {
        int i = 0;
        struct Node *tail, *curr;
        curr = tail = *head;
        for (; i < pos && tail; i++)
        {

            tail = curr;
            if (!tail)
                break;
            curr = curr->next;
        }
        if (!tail)
        {
            printf("Invalid Index\n");
            return -1;
        }
        tail->next = newNode;
        newNode->next = curr;
    }
    return 0;
}
