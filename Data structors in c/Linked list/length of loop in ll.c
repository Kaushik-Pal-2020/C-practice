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
int loopLength(struct Node *);
int main()
{
    struct Node *root = NULL;
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    printf("%d\n", build(arr, 10, &root));
    display(root);
    root->next->next->next->next->next->next->next->next->next = root;
    printf("Length of the loop = %d\n", loopLength(root));
    return 0;
}
int loopLength(struct Node *head)
{
    struct Node *fast, *slow;
    slow = fast = head;
    while (fast && slow)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (!fast)
    {
        printf("There is no loop in LinkedList\n");
        return -1;
    }
    int length = 1;
    do
    {
        fast = fast->next;
        length++;
    } while (slow != fast);
    return length;
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
