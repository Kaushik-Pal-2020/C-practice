#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "QueueSingly.h"

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
typedef struct Node BST_node;

void I_insert_BST(BST_node **, int);
BST_node *create_BST_node(int);
void InOrder_traversal_BST_node(BST_node *);
void PreOrder_traversal_BST_node(BST_node *);
void PostOrder_traversal_BST_node(BST_node *);
BST_node *build_BST(int *, int);
void clear_BST(BST_node *);

int numberOfTriplets_BST(BST_node *, int);
int numberOfTriplets_BST_util(BST_node *, Queue_Singly *, int);

int main()
{
    int arr[] ={ 6, -13, 14, -8, 13, 15, 7 };
    int res = 0;
    unsigned int n = sizeof(arr) / sizeof(*arr);
    BST_node *root = build_BST(arr, n);

    printf("PreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

    res = numberOfTriplets_BST(root, 0);
    printf("%d", res);
    clear_BST(root);
    return 0;
}
BST_node *create_BST_node(int value)
{
    BST_node *newNode = (BST_node *)malloc(sizeof(BST_node));
    if (!newNode)
    {
        printf("Out of memory\n");
        free(newNode);
        return NULL;
    }
    newNode->lchild = newNode->rchild = NULL;
    newNode->data = value;
    return newNode;
}
void I_insert_BST(BST_node **root, int value)
{
    BST_node *newNode = create_BST_node(value);
    if (newNode && (*root == NULL))
    {
        *root = newNode;
        return;
    }
    BST_node *curr, *tail;
    tail = curr = *root;
    while (curr)
    {
        tail = curr;
        if (curr->data == value)
            return;
        else if (curr->data > value)
            curr = curr->lchild;
        else
            curr = curr->rchild;
    }
    if (newNode->data > tail->data)
        tail->rchild = newNode;
    else
        tail->lchild = newNode;
}
BST_node *build_BST(int *arr, int n)
{
    BST_node *root = NULL;
    register int i = 0;
    for (; i < n; i++)
        I_insert_BST(&root, arr[i]);
    return root;
}
void InOrder_traversal_BST_node(BST_node *root)
{
    if (root)
    {
        InOrder_traversal_BST_node(root->lchild);
        printf("%d ", root->data);
        InOrder_traversal_BST_node(root->rchild);
    }
}
void PreOrder_traversal_BST_node(BST_node *root)
{
    if (root)
    {
        printf("%d ", root->data);
        PreOrder_traversal_BST_node(root->lchild);
        PreOrder_traversal_BST_node(root->rchild);
    }
}
void PostOrder_traversal_BST_node(BST_node *root)
{
    if (root)
    {
        PostOrder_traversal_BST_node(root->lchild);
        PostOrder_traversal_BST_node(root->rchild);
        printf("%d ", root->data);
    }
}
void clear_BST(BST_node *root)
{
    if (root)
    {
        clear_BST(root->lchild);
        clear_BST(root->rchild);
        free(root);
    }
}
int numberOfTriplets_BST(BST_node *root, int k)
{
    int count, i, tempValue=0;
    Queue_Singly q;
    createQueue(&q, sizeof(root->data));
    for (i = 0; i < 3; i++)
        enQueue_Singly(&q, &tempValue);

    count = numberOfTriplets_BST_util(root, &q, k);
    clear_Singly(&q);
    return count;
}
int numberOfTriplets_BST_util(BST_node *root, Queue_Singly *q, int k)
{
    static int sum = 0;
    static unsigned int count = 0;
    static unsigned int flag = 0;
    int temp;
    if (root && sum <= k)
    {
        numberOfTriplets_BST_util(root->lchild, q, k);
        deQueue_Singly(q, &temp);
        sum -= temp;
        enQueue_Singly(q, &(root->data));
        sum += root->data;
        flag++;
        if (flag >= 3 && sum == k)
            count++;
        numberOfTriplets_BST_util(root->rchild, q, k);
        return count;
    }
    if (sum > k)
        return count;
}