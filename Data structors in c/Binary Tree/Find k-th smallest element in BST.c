#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int count_Noes_BST(BST_node *);
int kthSmallestElement(BST_node *, int);
BST_node *kthSmallestElement_util(BST_node *, int);

int main()
{
    int arr[] = {12, 5, 15, 3, 7, 13, 17};
    unsigned int n = sizeof(arr) / sizeof(*arr);
    BST_node *root = build_BST(arr, n);

    printf("PreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

    printf("\n\n");
    printf("%dth smallest element =  %d\n", 8, kthSmallestElement(root, 8));

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
int count_Noes_BST(BST_node *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = count_Noes_BST(root->lchild);
        y = count_Noes_BST(root->rchild);
        return x + y + 1;
    }
}
int kthSmallestElement(BST_node *root, int k)
{
    int count = count_Noes_BST(root);
    if (k < 0 && k > count)
        return -1;
    BST_node *resNode = kthSmallestElement_util(root, k);
    if (resNode)
        return resNode->data;
    return -1;
}
BST_node *kthSmallestElement_util(BST_node *root, int k)
{
    static unsigned int nNode = 0;
    static BST_node *result = NULL;
    if (result)
        return result;
    if (root)
    {
        kthSmallestElement_util(root->lchild, k);
        nNode++;
        if (nNode == k)
        {
            result = root;
        }
        kthSmallestElement_util(root->rchild, k);
        return result;
    }
}
