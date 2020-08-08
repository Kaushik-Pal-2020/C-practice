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

int countNodes_BST(BST_node*);
int medianBST(BST_node*);
BST_node* medianBST_util(BST_node *, int, int);
int main()
{
    int arr[] ={ 6, 3, 8, 1, 4, 7 };
    int res = 0;
    unsigned int n = sizeof(arr) / sizeof(*arr);
    BST_node *root = build_BST(arr, n);

    printf("PreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

    res = medianBST(root);
    printf("\n\nMedian of BST = %d\n", res);
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

int countNodes_BST(BST_node *root)
{
    int x=0, y=0;
    if (root)
    {
        x= countNodes_BST(root->lchild);
        y = countNodes_BST(root->rchild);
        return x+y+1;
    }
}
int medianBST(BST_node *root)
{
    int count = countNodes_BST(root);
    BST_node *l, *r;
    l = r = NULL;
    if (count % 2)
    {
        l = medianBST_util(root, count/2, 1);
        return l->data;
    }
    else
    {
        l = medianBST_util(root, count/2, 1);
        r = medianBST_util(root, (count/2)+1, 1);
        return (l->data + r->data)/2;
    }
}
BST_node* medianBST_util(BST_node *root, int length, int temp_flag)
{
    static short flag = 1;
    static unsigned int count = 0;
    static BST_node* tempNode =NULL;
    if (temp_flag == 1)
    {
        flag = 1;
        tempNode = NULL;
        count = 0;
    }
    if (root && flag)
    {
        medianBST_util(root->lchild, length, 0);
        count++;
        if (count == length)
        {
            flag = 0;
            tempNode = root;
            return root;
        }
        medianBST_util(root->rchild, length, 0);
    }
    if (flag == 0)
        return tempNode;
}