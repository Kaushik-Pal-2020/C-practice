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
int minElement_BST(BST_node *);
int maxElement_BST(BST_node *);
int height_BST(BST_node *);
BST_node *Inoder_predecessor_BST(BST_node *);
BST_node *Inoder_successor_BST(BST_node *);
BST_node *Delete_BST_node(BST_node *, int);
int countNodes_BST(BST_node *);
int isBST_space(BST_node *);
void InOrder_insert(BST_node *, int *);
int checkIs_BST(BST_node *);
int checkIs_BST_util(BST_node *, int, int);
int checkIs_BST_Inorder(BST_node *);
int main()
{
    int arr[] = {12, 5, 15, 3, 7, 13, 17, 1, 9, 19};
    unsigned int n = sizeof(arr) / sizeof(*arr);
    BST_node *root = build_BST(arr, n);

    printf("PreOrder Traversal\n");
    PreOrder_traversal_BST_node(root);

    printf("\n\nInOrder Traversal\n");
    InOrder_traversal_BST_node(root);

    printf("\n\nPostOrder Traversal\n");
    PostOrder_traversal_BST_node(root);

    int key = 1;
    if (R_search_BST(root, key) != NULL)
        printf("\n\n%d is in Tree\n", key);
    else
        printf("\n\n%d is not  in Tree\n", key);

    int min = minElement_BST(root);
    printf("\nminimum element in binary tree = %d\n", min);

    int max = maxElement_BST(root);
    printf("\nmaximum element in binary tree = %d\n", max);

    if (checkIs_BST_Inorder(root) == 1)
        printf("Yes, it is a BST\n");
    else
        printf("No, it is not a BST\n");

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
int minElement_BST(BST_node *root)
{
    int min = INT_MAX;
    if (root)
    {
        min = minElement_BST(root->lchild);
        return (root->data < min) ? root->data : min;
    }
    return INT_MAX;
}
int maxElement_BST(BST_node *root)
{
    int min = INT_MIN;
    if (root)
    {
        min = maxElement_BST(root->rchild);
        return (root->data > min) ? root->data : min;
    }
    return INT_MIN;
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
BST_node *Inoder_predecessor_BST(BST_node *root)
{
    while (root && root->rchild)
        root = root->rchild;
    return root;
}
// Inoder_successor_BST is nothing but finding maxValue Node in root tree/sub-tree
// maxValue can be found in right most node of the tree
BST_node *Inoder_successor_BST(BST_node *root)
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
                BST_node *preNode = Inoder_predecessor_BST(root->lchild);
                root->data = preNode->data;
                root->lchild = Delete_BST_node(root->lchild, preNode->data);
            }
            else
            {
                BST_node *succNode = Inoder_successor_BST(root->rchild);
                root->data = succNode->data;
                root->rchild = Delete_BST_node(root->rchild, succNode->data);
            }
        }
    }
    return root;
}
int countNodes_BST(BST_node *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = countNodes_BST(root->lchild);
        y = countNodes_BST(root->rchild);
        return x + y + 1;
    }
}
// in this method we are storing in-order traversal in aux-array
// then traversing whole array and checking if next element is greater or not
// if it is greater then no BST; at-last it returns yes BST
// time complexity : O(n)
// space complexity : O(n)
int isBST_space(BST_node *root)
{
    int n = countNodes_BST(root);
    int *arr = (int *)malloc(n * sizeof(int));
    InOrder_insert(root, arr);
    register int i = 0;
    for (; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            free(arr);
            return 0;
        }
    }
    free(arr);
    return 1;
}
void InOrder_insert(BST_node *root, int *arr)
{
    static unsigned int i = 0;
    if (root)
    {
        InOrder_insert(root->lchild, arr);
        arr[i++] = root->data;
        InOrder_insert(root->rchild, arr);
    }
}
int checkIs_BST(BST_node *root)
{
    return checkIs_BST_util(root, INT_MIN, INT_MAX);
}

int checkIs_BST_util(BST_node *root, int minValue, int maxValue)
{
    if (!root)
        return 1;
    if (root->data > minValue && root->data < maxValue)
    {
        checkIs_BST_util(root->lchild, minValue, root->data);
        checkIs_BST_util(root->rchild, root->data, minValue);
        return 1;
    }
    else
        return 0;
}
int checkIs_BST_Inorder(BST_node *root)
{
    static int prevValue = INT_MIN;
    static unsigned short flag = 1;
    if (root && flag)
    {
        checkIs_BST_Inorder(root->lchild);
        if (root->data > prevValue)
            prevValue = root->data;
        else
            flag = 0;
        checkIs_BST_Inorder(root->rchild);
        return flag;
    }
}