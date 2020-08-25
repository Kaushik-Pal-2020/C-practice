#include <stdio.h>
#include <stdlib.h>

struct ThreadedBst
{
    int val;
    struct ThreadedBst *left;
    struct ThreadedBst *right;
    char rightThread;
};
typedef struct ThreadedBst ThreadedBst;
ThreadedBst *insertNode(ThreadedBst *, ThreadedBst *, ThreadedBst *);
ThreadedBst *buildThreadedBST(int *, int);
ThreadedBst *createNode(int);
void linearInorderTraversal(ThreadedBst *);
int main()
{
    int arr[] = {10, 5, 15, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    ThreadedBst *root = buildThreadedBST(arr, n);
    linearInorderTraversal(root);
    return 0;
}
ThreadedBst *insertNode(ThreadedBst *root, ThreadedBst *newNode, ThreadedBst *prevNode)
{
    if (!root)
    {
        if (!prevNode)
            return newNode;
        else
        {
            newNode->right = prevNode;
            prevNode->rightThread = '1';
        }
    }
    else if (root->val < newNode->val)
        root->left = insertNode(root->left, newNode, root);

    else if (root->val > newNode->val)
    {
        if (root->rightThread == '0')
            root->right = insertNode(root->right, newNode, prevNode);

        else
        {
            root->right = insertNode(root->right, newNode, prevNode);
            root->rightThread = '0';
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
        root = insertNode(root, temp, NULL);
    }
    return root;
}
ThreadedBst *createNode(int val)
{
    ThreadedBst *newNode = (ThreadedBst *)malloc(sizeof(ThreadedBst));
    newNode->left = newNode->right = NULL;
    newNode->rightThread = '0';
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