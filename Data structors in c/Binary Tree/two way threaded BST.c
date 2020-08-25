#include <stdio.h>
#include <stdlib.h>

struct ThreadedBst
{
    int val;
    struct ThreadedBst *left;
    struct ThreadedBst *right;
    int rightThread;
    int leftThread;
};
typedef struct ThreadedBst ThreadedBst;

ThreadedBst *insertNode(ThreadedBst *, ThreadedBst *, ThreadedBst *, ThreadedBst *);
ThreadedBst *buildThreadedBST(int *, int);
ThreadedBst *createNode(int);
void linearInorderTraversal(ThreadedBst *);
void clearThreadedBST(ThreadedBst *);
int main()
{
    int arr[] = {10, 5, 15, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    ThreadedBst *root = buildThreadedBST(arr, n);
    linearInorderTraversal(root);
    clearThreadedBST(root);
    return 0;
}
ThreadedBst *insertNode(ThreadedBst *root, ThreadedBst *newNode, ThreadedBst *prevLeftNode, ThreadedBst *prevRightNode)
{
    if (!root)
    {
        if (!prevLeftNode && !prevRightNode)
            return newNode;

        newNode->left = prevRightNode;
        newNode->right = prevLeftNode;

        if (newNode->left)
            newNode->leftThread = 1;

        if (newNode->right)
            newNode->rightThread = 1;

        return newNode;
    }
    else if (root->val > newNode->val)
    {
        if (root->leftThread == 0)
            root->left = insertNode(root->left, newNode, root, prevRightNode);
        else
        {
            root->left = insertNode(NULL, newNode, root, prevRightNode);
            root->leftThread = 0;
        }
    }

    else if (root->val < newNode->val)
    {
        if (root->rightThread == 0)
            root->right = insertNode(root->right, newNode, prevLeftNode, root);

        else
        {
            root->right = insertNode(NULL, newNode, prevLeftNode, root);
            root->rightThread = 0;
        }
    }
    return root;
}

ThreadedBst *buildThreadedBST(int *arr, int size)
{
    ThreadedBst *root = NULL, *temp = NULL;
    int i = 0;
    for (; i < size; i++)
    {
        temp = createNode(arr[i]);
        root = insertNode(root, temp, NULL, NULL);
    }
    return root;
}
ThreadedBst *createNode(int val)
{
    ThreadedBst *newNode = (ThreadedBst *)malloc(sizeof(ThreadedBst));
    newNode->left = newNode->right = NULL;
    newNode->rightThread = newNode->leftThread = 0;
    newNode->val = val;
    return newNode;
}
void linearInorderTraversal(ThreadedBst *root)
{
    ThreadedBst *currNode = root, *prev = NULL;
    while (currNode)
    {
        prev = currNode;
        currNode = currNode->left;
    }
    if (prev)
    {
        while (prev)
        {
            printf("%d, ", prev->val);
            prev = prev->right;
        }
    }
}
void clearThreadedBST(ThreadedBst *root)
{
    ThreadedBst *prev = NULL;
    while (root->left)
        root = root->left;

    prev = root;
    if (root)
    {
        while (root)
        {
            prev = root->right;
            free(root);
            root = prev;
        }
    }
    root = NULL;
}
