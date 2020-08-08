/*
this traversal in iterative version of recursive-inorder
i'm using this algorithm in BST, but it can be applied in others trees
Morris algorithm is unique, because it does not use any stack to return back to its successor node
Time Complexity : O(n)
Space Complexity : O(1)
if we are short on Ram then we can use this algorithm
*/
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

BST_node *Inoder_predecessor_BST(BST_node *, BST_node *);
void MorrisInorderTraversal(BST_node*);
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

    MorrisInorderTraversal(root);
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
BST_node *Inoder_predecessor_BST(BST_node *root, BST_node *curr)
{
    while (root && root->rchild && root->rchild != curr)
        root = root->rchild;
    return root;
}
void MorrisInorderTraversal(BST_node *root)
{
    printf("\n\nThis is Morris Inorder Traversal\n");
    BST_node *pre = NULL;
    while (root)
    {
        if (!root->lchild)
        {
            printf("%d ", root->data);
            root = root->rchild;
        }
        else
        {
            pre = Inoder_predecessor_BST(root->lchild, root);
            if (pre->rchild)
            {
                pre->rchild = NULL;
                printf("%d ", root->data);
                root = root->rchild;
            }
            else
            {
                pre->rchild = root;
                root = root->lchild;
            }
        }
    }
}