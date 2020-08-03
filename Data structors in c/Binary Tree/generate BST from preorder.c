#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stackLL.h"

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
typedef struct Node BST_node;

BST_node *I_search_BST(BST_node *, int);
BST_node *R_search_BST(BST_node *, int);
void I_insert_BST(BST_node **, int);
BST_node *R_insert_BST(BST_node *, int);
BST_node *create_BST_node(int);
void InOrder_traversal_BST_node(BST_node *);
void PreOrder_traversal_BST_node(BST_node *);
void PostOrder_traversal_BST_node(BST_node *);
BST_node *build_BST(int *, int);
void clear_BST(BST_node *);
int height_BST(BST_node *);
BST_node *Inoder_predecessor(BST_node *);
BST_node *Inoder_successor(BST_node *);
BST_node *Delete_BST_node(BST_node *, int);
BST_node *build_BST_preOrder(int *, int);

int main()
{
    int arr[] = {30, 20, 10, 15, 25, 40, 50, 45};
    unsigned int n = sizeof(arr) / sizeof(*arr);
    BST_node *root = build_BST_preOrder(arr, n);

    printf("PreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

    clear_BST(root);
    return 0;
}
BST_node *I_search_BST(BST_node *root, int key)
{
    while (root)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->lchild;
        else
            root = root->rchild;
    }
    return NULL;
}
BST_node *R_search_BST(BST_node *root, int key)
{
    if (root)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            R_search_BST(root->lchild, key);
        else
            R_search_BST(root->rchild, key);
    }
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
BST_node *R_insert_BST(BST_node *root, int value)
{
    if (root == NULL)
        return create_BST_node(value);

    if (root->data > value)
        root->lchild = R_insert_BST(root->lchild, value);
    else if (root->data < value)
        root->rchild = R_insert_BST(root->rchild, value);

    return root;
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
int height_BST(BST_node *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = height_BST(root->lchild);
        y = height_BST(root->rchild);
        return (x > y) ? x + 1 : y + 1;
    }
}
// Inoder_predecessor_BST is nothing but finding minValue Node in root tree/sub-tree
// minValue can be found in left most node of the tree
BST_node *Inoder_predecessor(BST_node *root)
{
    while (root && root->rchild)
        root = root->rchild;
    return root;
}
// Inoder_successor_BST is nothing but finding maxValue Node in root tree/sub-tree
// maxValue can be found in right most node of the tree
BST_node *Inoder_successor(BST_node *root)
{
    while (root && root->lchild)
        root = root->lchild;
    return root;
}

BST_node *Delete_BST_node(BST_node *root, int key)
{
    // if root is empty node then simply return null
    if (!root)
        return root;

    if (root->data > key)
        root->lchild = Delete_BST_node(root->lchild, key);
    else if (root->data > key)
        root->rchild = Delete_BST_node(root->rchild, key);

    else // now we found element
    {
        // case 1 : if node has no child
        if (!root->lchild && !root->rchild)
        {
            free(root);
            root = NULL;
            return root;
        }

        // case 2 : if node has only 1 child
        if (root->lchild && !root->rchild)
        {
            BST_node *curr = root;
            root = root->lchild;
            free(curr);
        }
        else if (!root->lchild && root->rchild)
        {
            BST_node *curr = root;
            root = root->rchild;
            free(curr);
        }

        // case 3 : if node has 2 or more child
        else
        {
            // now checking which side has more nodes by height of that sub-tree
            if (height_BST(root->lchild) > height_BST(root->rchild))
            {
                BST_node *preNode = Inoder_predecessor(root->lchild);
                root->data = preNode->data;
                root->lchild = Delete_BST_node(root->lchild, preNode->data);
            }
            else
            {
                BST_node *succNode = Inoder_successor(root->rchild);
                root->data = succNode->data;
                root->rchild = Delete_BST_node(root->rchild, succNode->data);
            }
        }
    }
    return root;
}
BST_node *build_BST_preOrder(int *arr, int n)
{
    Stack stack;
    createStack(&stack, sizeof(BST_node *));
    register unsigned int i = 0;
    BST_node *root = create_BST_node(arr[i]);
    i++;
    BST_node **temp = &root;
    BST_node **temp_only_for_peek = (BST_node **)malloc(sizeof(BST_node *));
    BST_node *p = NULL;
    push_Stack(&stack, &root);
    while (i < n)
    {
        if (arr[i] < (*temp)->data)
        {
            BST_node *newNode = create_BST_node(arr[i]);
            i++;
            (*temp)->lchild = newNode;
            push_Stack(&stack, &newNode);
            p = newNode;
            temp = &p;
        }
        else
        {
            peek_Stack(&stack, temp_only_for_peek);
            if ((arr[i] > (*temp)->data) && (isEmpty_Stack(&stack) == 0) &&
                (arr[i] < (*temp_only_for_peek)->data))
            {
                BST_node *newNode = create_BST_node(arr[i]);
                i++;
                (*temp)->rchild = newNode;
                p = newNode;
                temp = &p;
            }
            else if ((arr[i] > (*temp)->data) && (isEmpty_Stack(&stack) == 1))
            {
                BST_node *newNode = create_BST_node(arr[i]);
                i++;
                (*temp)->rchild = newNode;
                p = newNode;
                temp = &p;
            }
            else
                pop_Stack(&stack, temp);
        }
    }
    free(temp_only_for_peek);
    clear_Stack(&stack);
    return root;
}