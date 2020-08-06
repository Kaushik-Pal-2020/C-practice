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

BinaryTree *create_BinaryTree();
BinaryTree *build_BinaryTree(BinaryTree *);
void preOrder_traversal(BinaryTree *);
void ineOrder_traversal(BinaryTree *);
void postOrder_traversal(BinaryTree *);
void clear_BinaryTree(BinaryTree *);
int count_BinaryTree(BinaryTree *);

void merge(int*, int, int, int);
void mergeSort(int *, int, int);
void storeInorderArray(BinaryTree*, int*);
void binaryTreeTo_BST(BinaryTree*);
void insertValueInorder(BinaryTree*, int *);

int main()
{
    BinaryTree *root = create_BinaryTree();
    root = build_BinaryTree(root);

    printf("\nPreOrder of binary Tree\n");
    preOrder_traversal(root);

    printf("\n\nInOrder of binary Tree\n");
    ineOrder_traversal(root);

    printf("\n\nPostOrder of binary Tree\n");
    postOrder_traversal(root);

    printf("\n\nAfter creating BST\n");
    binaryTreeTo_BST(root);

    printf("\nPreOrder of binary Tree\n");
    preOrder_traversal(root);

    printf("\n\nInOrder of binary Tree\n");
    ineOrder_traversal(root);

    printf("\n\nPostOrder of binary Tree\n");
    postOrder_traversal(root);

    clear_BinaryTree(root);
    return 0;
}

BinaryTree *create_BinaryTree()
{
    BinaryTree *root = NULL;
    return root;
}

BinaryTree *build_BinaryTree(BinaryTree *root)
{
    if (!root)
    {
        int data;
        root = (BinaryTree *)malloc(sizeof(BinaryTree));
        printf("Enter Root value = ");
        scanf("%d", &data);
        root->lchild = root->rchild = NULL;
        root->data = data;
    }
    Queue_Singly queue;
    createQueue(&queue, sizeof(BinaryTree *));
    enQueue_Singly(&queue, &root);
    BinaryTree **temp = (BinaryTree **)malloc(sizeof(BinaryTree *));
    while (!isEmpty_Singly(&queue))
    {
        deQueue_Singly(&queue, temp);
        int lchild_value, rchild_value;
        printf("\ncurrently entering data for %d node\nleft child value and right child value\n", (*temp)->data);
        scanf("%d %d", &lchild_value, &rchild_value);
        if (lchild_value != -1)
        {
            BinaryTree *l = (BinaryTree *)malloc(sizeof(BinaryTree));
            l->data = lchild_value;
            l->lchild = l->rchild = NULL;
            enQueue_Singly(&queue, &l);
            (*temp)->lchild = l;
        }
        else
            (*temp)->lchild = NULL;

        if (rchild_value != -1)
        {
            BinaryTree *r = (BinaryTree *)malloc(sizeof(BinaryTree));
            r->data = rchild_value;
            r->lchild = r->rchild = NULL;
            enQueue_Singly(&queue, &r);
            (*temp)->rchild = r;
        }
        else
            (*temp)->rchild = NULL;
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
int count_BinaryTree(BinaryTree *root)
{
    if (root)
    {
        int x = 0, y = 0;
        x = count_BinaryTree(root->lchild);
        y = count_BinaryTree(root->rchild);
        return x + y + 1;
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int *L = (int*)malloc(n1 *sizeof(int));
    int *R = (int*)malloc(n2 *sizeof(int));

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2;

        // Sort first and second halves 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
void storeInorderArray(BinaryTree* root, int* arr)
{
    static unsigned int i = 0;
    if (root)
    {
        storeInorderArray(root->lchild, arr);
        arr[i++] = root->data;
        storeInorderArray(root->rchild, arr);
    }
}
void insertValueInorder(BinaryTree* root, int *arr)
{
    static unsigned int i = 0;
    if (root)
    {
        insertValueInorder(root->lchild, arr);
        root->data = arr[i++];
        insertValueInorder(root->rchild, arr);
    }
}
void binaryTreeTo_BST(BinaryTree* root)
{
    int n = count_BinaryTree(root);
    int *arr = (int*)malloc(n* sizeof(int));
    storeInorderArray(root, arr);
    mergeSort(arr, 0, n-1);
    insertValueInorder(root, arr);
    free(arr);
}