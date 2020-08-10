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

BST_node* mirrornewBST(BST_node *);
void addElementsBST(BST_node *, long long int*);
BST_node* convertBST(BST_node*);


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

    printf("\n************After Transfromation************\n");
    convertBST(root);

    printf("\nPreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

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
BST_node* mirrornewBST(BST_node *root)
{
    BST_node *lchild, *rchild;
    lchild = rchild = NULL;
    if (root)
    {
        lchild = mirrornewBST(root->lchild);
        rchild = mirrornewBST(root->rchild);
        root->lchild = rchild;
        root->rchild = lchild;
        return root;
    }
    else
        return NULL;
}
void addElementsBST(BST_node *root, long long int *sum)
{
    if (root)
    {
        addElementsBST(root->lchild, sum);
        *sum += root->data;
        root->data = *sum;
        addElementsBST(root->rchild, sum);
    }
}
BST_node* convertBST(BST_node* root)
{
    if (!root)
        return root;
    root = mirrornewBST(root);
    long long int initial_sum = 0;
    addElementsBST(root, &initial_sum);
    return mirrornewBST(root);
}