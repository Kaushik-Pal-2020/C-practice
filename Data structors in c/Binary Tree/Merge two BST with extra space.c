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
int countNodes_BST(BST_node *);

BST_node* mergeBSTs(BST_node*, BST_node*);
void storeElementsArray_BST(BST_node *, int *);
void merge(int arr[], int, int, int);
void mergeSort(int arr[], int, int);

int main()
{
    int arr1[] ={ 3, 1, 5 };
    unsigned int n1 = sizeof(arr1) / sizeof(*arr1);
    BST_node *root1 = build_BST(arr1, n1);

    int arr2[] ={ 4, 2, 6 };
    unsigned int n2 = sizeof(arr2) / sizeof(*arr2);
    BST_node *root2 = build_BST(arr2, n2);

    BST_node *root = mergeBSTs(root1, root2);

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
void storeElementsArray_BST(BST_node *root, int *arr)
{
    static int i = 0;
    if (root)
    {
        storeElementsArray_BST(root->lchild, arr);
        arr[i++] = root->data;
        storeElementsArray_BST(root->rchild, arr);
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
BST_node* mergeBSTs(BST_node *h1, BST_node *h2)
{
    int i, j, mid;
    int n = countNodes_BST(h1) + countNodes_BST(h2);
    int *elements = (int*)malloc(n* sizeof(int));

    storeElementsArray_BST(h1, elements);
    storeElementsArray_BST(h2, elements);

    mergeSort(elements, 0, n-1);
    mid = n/2;
    BST_node *newRoot = create_BST_node(elements[mid]);
    i = mid-1;
    j = mid+1;
    while (i>=0 && j < n)
    {
        if (i-1 >= 0)
            I_insert_BST(&newRoot, elements[i-1]);
        if (j+1 < n)
            I_insert_BST(&newRoot, elements[j+1]);

        I_insert_BST(&newRoot, elements[i]);
        I_insert_BST(&newRoot, elements[j]);
        i -= 2;
        j += 2;
    }
    while (i >= 0)
        I_insert_BST(&newRoot, elements[i--]);

    while (j <n)
        I_insert_BST(&newRoot, elements[j++]);

    free(elements);
    return newRoot;
}
