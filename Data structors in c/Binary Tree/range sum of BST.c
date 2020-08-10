#include <stdio.h>
#include <stdlib.h>

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

void rangeSumBSTutil(BST_node* root, int L, int R, int *sum);
int rangeSumBST(BST_node* root, int L, int R);

int main()
{
    int arr[] ={ 5, 2, 13 };
    unsigned int n = sizeof(arr) / sizeof(*arr);
    BST_node *root = build_BST(arr, n);

    printf("************Before Transfromation************\n");

    printf("PreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

    int res = rangeSumBST(root, 2, 5);
    printf("\n\nrange sum = %d\n", res);
    clear_BST(root);
    return 0;
}
BST_node *create_BST_node(int dataue)
{
    BST_node *newNode = (BST_node *)malloc(sizeof(BST_node));
    if (!newNode)
    {
        printf("Out of memory\n");
        free(newNode);
        return NULL;
    }
    newNode->lchild = newNode->rchild = NULL;
    newNode->data = dataue;
    return newNode;
}
void I_insert_BST(BST_node **root, int dataue)
{
    BST_node *newNode = create_BST_node(dataue);
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
        if (curr->data == dataue)
            return;
        else if (curr->data > dataue)
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
void rangeSumBSTutil(BST_node* root, int L, int R, int *sum)
{
    if (root)
    {
        if (root->data >= L && root->data <=R)
        {
            *sum += root->data;
            rangeSumBSTutil(root->lchild, L, R, sum);
            rangeSumBSTutil(root->rchild, L, R, sum);
        }

        else if (root->data < L)
            rangeSumBSTutil(root->rchild, L, R, sum);
        else
            rangeSumBSTutil(root->lchild, L, R, sum);
    }
}
int rangeSumBST(BST_node* root, int L, int R)
{
    int sum = 0;
    rangeSumBSTutil(root, L, R, &sum);
    return sum;
}