#include <stdio.h>
#include <stdlib.h>
#include "QueueSingly.h"
#include <stdbool.h>
#include <limits.h>

struct BinaryTree
{
    struct BinaryTree *lchild;
    int data;
    struct BinaryTree *rchild;
};

typedef struct BinaryTree BinaryTree;

BinaryTree *create_BinaryNode(int);
BinaryTree *build_BinaryTree(BinaryTree *, int*, int);
void preOrder_traversal(BinaryTree *);
void ineOrder_traversal(BinaryTree *);
void postOrder_traversal(BinaryTree *);
void clear_BinaryTree(BinaryTree *);
void levelOrderTraversal_BinaryTree(BinaryTree*);

int heightTree(BinaryTree* root);
void storeElementsArray(BinaryTree *root, int *n, double *arr, Queue_Singly *q);
double* averageOfLevels(BinaryTree* root, int* returnSize);

int main()
{
    int arr1[] ={ 3, 9, 20, -1, -1, 15, 7 };
    int n1 = sizeof(arr1)/ sizeof(*arr1);


    BinaryTree *root = NULL;
    root = build_BinaryTree(root, arr1, n1);

    printf("\nPreOrder of binary Tree\n");
    preOrder_traversal(root);
    printf("\n\n");
    levelOrderTraversal_BinaryTree(root);

    printf("\n\nInOrder of binary Tree\n");
    ineOrder_traversal(root);

    printf("\n\nPostOrder of binary Tree\n");
    postOrder_traversal(root);

    int n = 0;
    double *arr = averageOfLevels(root, &n);
    clear_BinaryTree(root);
    return 0;
}

BinaryTree *create_BinaryNode(int data)
{
    BinaryTree *root = (BinaryTree*)malloc(sizeof(BinaryTree));
    root->data = data;
    root->lchild = root->rchild = NULL;
    return root;
}

BinaryTree *build_BinaryTree(BinaryTree *root, int *arr, int n)
{
    if (!root)
    {
        int data;
        root = (BinaryTree *)malloc(sizeof(BinaryTree));
        root->lchild = root->rchild = NULL;
        root->data = arr[0];
    }
    int i = 1;
    Queue_Singly queue;
    createQueue(&queue, sizeof(BinaryTree *));
    enQueue_Singly(&queue, &root);
    BinaryTree **temp = (BinaryTree **)malloc(sizeof(BinaryTree *));
    while (!isEmpty_Singly(&queue) && i<n)
    {
        deQueue_Singly(&queue, temp);
        int lchild_dataue = arr[i];
        int rchild_dataue;
        if (i == n-1)
            rchild_dataue = -1;
        else
            rchild_dataue = arr[i+1];

        if (lchild_dataue != -1)
        {
            BinaryTree *l = (BinaryTree *)malloc(sizeof(BinaryTree));
            l->data = lchild_dataue;
            l->lchild = l->rchild = NULL;
            enQueue_Singly(&queue, &l);
            (*temp)->lchild = l;
        }
        if (rchild_dataue != -1)
        {
            BinaryTree *r = (BinaryTree *)malloc(sizeof(BinaryTree));
            r->data = rchild_dataue;
            r->lchild = r->rchild = NULL;
            enQueue_Singly(&queue, &r);
            (*temp)->rchild = r;
        }
        i += 2;
    }
    clear_Singly(&queue);
    return root;
}
void preOrder_traversal(BinaryTree *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder_traversal(root->lchild);
    preOrder_traversal(root->rchild);
}
void ineOrder_traversal(BinaryTree *root)
{
    if (root)
    {
        ineOrder_traversal(root->lchild);
        printf("%d ", root->data);
        ineOrder_traversal(root->rchild);
    }
}
void postOrder_traversal(BinaryTree *root)
{
    if (root)
    {
        postOrder_traversal(root->lchild);
        postOrder_traversal(root->rchild);
        printf("%d ", root->data);
    }
}
void clear_BinaryTree(BinaryTree *root)
{
    if (root)
    {
        clear_BinaryTree(root->lchild);
        clear_BinaryTree(root->rchild);
        free(root);
    }
}
void levelOrderTraversal_BinaryTree(BinaryTree* root)
{
    Queue_Singly q;
    createQueue(&q, sizeof(BinaryTree*));
    enQueue_Singly(&q, &root);
    printf("\nLevel order traversal\n");
    BinaryTree **temp = (BinaryTree**)malloc(sizeof(BinaryTree*));
    while (!isEmpty_Singly(&q))
    {
        deQueue_Singly(&q, temp);
        printf("%d ", (*temp)->data);

        if ((*temp)->lchild)
            enQueue_Singly(&q, &((*temp)->lchild));
        if ((*temp)->rchild)
            enQueue_Singly(&q, &((*temp)->rchild));
    }
    clear_Singly(&q);
    free(temp);
}

int heightTree(BinaryTree* root)
{
    int x, y;
    if (root)
    {
        x = heightTree(root->lchild);
        y = heightTree(root->rchild);
        return (x>1) ? x+1 : y+1;
    }
    else
        return 0;
}
void storeElementsArray(BinaryTree *root, int *n, double *arr, Queue_Singly *q)
{
    int level = *n, prevLevel = *n;
    int i = 0;
    double total = 0;
    int count = 0;
    BinaryTree **temp = (BinaryTree**)malloc(sizeof(BinaryTree*));
    while (!isEmpty_Singly(q))
    {
        deQueue_Singly(q, temp);

        prevLevel = level;
        level = heightTree((*temp));
        printf("%lf\n", total);

        if (prevLevel == level)
        {
            total += (*temp)->data;
            count++;
        }
        else
        {
            arr[i] = total/count;
            count = total = 0;
            i++;
        }
        if ((*temp)->lchild)
            enQueue_Singly(q, &((*temp)->lchild));
        if ((*temp)->rchild)
            enQueue_Singly(q, &((*temp)->rchild));
    }
    arr[i++] = total/count;
    clear_Singly(q);
    free(temp);
}
double* averageOfLevels(BinaryTree* root, int* returnSize)
{
    int n = heightTree(root);
    *returnSize = n;
    double *arr = (double*)malloc(n*sizeof(double));

    Queue_Singly q;
    createQueue(&q, sizeof(BinaryTree*));
    enQueue_Singly(&q, &root);

    storeElementsArray(root, returnSize, arr, &q);
    return arr;

}