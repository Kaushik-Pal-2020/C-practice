#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
typedef struct Node BST_node;

BST_node* I_search_BST(BST_node *, int );
BST_node* R_search_BST(BST_node *, int );
void I_insert_BST(BST_node **, int);
BST_node* R_insert_BST(BST_node *, int);
BST_node* create_BST_node(int);
void InOrder_traversal_BST_node(BST_node*);
void PreOrder_traversal_BST_node(BST_node*);
void PostOrder_traversal_BST_node(BST_node*);
BST_node* build_BST(int *, int);
void clear_BST(BST_node *);

int main()
{
    int arr[] = {10,20,30,40,50,60,70};
    unsigned int n = sizeof(arr)/sizeof(*arr);    
    BST_node *root = build_BST(arr, n);

    printf("\nPreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

    int key = 0;
    if(R_search_BST(root, key) != NULL)
        printf("\n\n%d is in Tree\n",key);

    clear_BST(root);
    return 0;
}
BST_node* I_search_BST(BST_node *root, int key)
{
    while(root)
    {
        if(root->data == key)
            return root;
        else if(root->data > key)
            root = root->lchild;
        else 
            root = root->rchild;
    }
    return NULL;
}
BST_node* R_search_BST(BST_node *root, int key)
{
    if(root)
    {
        if(root->data == key)
            return root;
        else if(root->data > key)
            R_search_BST(root->lchild, key);
        else 
            R_search_BST(root->rchild, key);
    }
}
BST_node* create_BST_node(int value)
{
    BST_node *newNode = (BST_node*)malloc(sizeof(BST_node));
    if(!newNode)
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
    if(newNode && (*root == NULL))
    {
        *root = newNode;
        return ;
    }
    BST_node *curr, *tail;
    tail = curr = *root;
    while(curr)
    {
        tail = curr;
        if(curr->data == value)
            return;
        else if(curr->data > value)
            curr = curr->lchild;
        else 
            curr = curr->rchild;
    }
    if(newNode->data > tail->data)
        tail->rchild = newNode;
    else 
        tail->lchild = newNode;
}
BST_node* R_insert_BST(BST_node *root, int value)
{
    if(root == NULL)
        return create_BST_node(value);
    
    if(root->data > value)
        root->lchild = R_insert_BST(root->lchild, value);
    else if(root->data < value)
        root->rchild = R_insert_BST(root->rchild, value);

    return root;
}
BST_node* build_BST(int *arr, int n)
{
    BST_node* root = NULL;
    register int i = 0;
    for(;i<n;i++)
        I_insert_BST(&root,arr[i]);
    return root;
}
void InOrder_traversal_BST_node(BST_node* root)
{
    if(root)
    {
        InOrder_traversal_BST_node(root->lchild);
        printf("%d ",root->data);
        InOrder_traversal_BST_node(root->rchild);
    }
}
void PreOrder_traversal_BST_node(BST_node* root)
{
    if(root)
    {
        printf("%d ",root->data);
        PreOrder_traversal_BST_node(root->lchild);
        PreOrder_traversal_BST_node(root->rchild);
    }
}
void PostOrder_traversal_BST_node(BST_node* root)
{
    if(root)
    {
        PostOrder_traversal_BST_node(root->lchild);
        PostOrder_traversal_BST_node(root->rchild);
        printf("%d ",root->data);
    }
}
void clear_BST(BST_node *root)
{
    if(root)
    {
        clear_BST(root->lchild);
        clear_BST(root->rchild);
        free(root);
    }
}