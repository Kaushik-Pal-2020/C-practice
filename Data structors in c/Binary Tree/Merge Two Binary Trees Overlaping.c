// Input: 
// 	Tree 1                     Tree 2                  
//           10                        5                             
//          / \                       / \                            
//         5   15                    2   7                        
//        /                         / \   \                      
//       1                         1  3   9                  
// Output: 
// Merged tree: Tree 3
// 	     15
// 	    / \
// 	   7   22
// 	  / \   \ 
// 	 2   3   9


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

BinaryTree *mergeBinaryTree(BinaryTree*, BinaryTree*);
int main()
{
    int arr1[] ={ 10, 5, 15, 1 };
    int arr2[] ={ 5, 2, 7, 1, 3, -1, 9 };
    int n1 = sizeof(arr1)/ sizeof(*arr1);
    int n2 = sizeof(arr2)/ sizeof(*arr2);

    BinaryTree *root1 = NULL;
    BinaryTree *root2 = NULL;
    root1 = build_BinaryTree(root1, arr1, n1);

    root2 = build_BinaryTree(root2, arr2, n2);

    BinaryTree *root = mergeBinaryTree(root1, root2);

    printf("\nPreOrder of binary Tree\n");
    preOrder_traversal(root);
    printf("\n\n");
    levelOrderTraversal_BinaryTree(root);

    printf("\n\nInOrder of binary Tree\n");
    ineOrder_traversal(root);

    printf("\n\nPostOrder of binary Tree\n");
    postOrder_traversal(root);

    clear_BinaryTree(root);
    clear_BinaryTree(root1);
    clear_BinaryTree(root2);
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
        int lchild_value = arr[i];
        int rchild_value;
        if (i == n-1)
            rchild_value = -1;
        else
            rchild_value = arr[i+1];

        if (lchild_value != -1)
        {
            BinaryTree *l = (BinaryTree *)malloc(sizeof(BinaryTree));
            l->data = lchild_value;
            l->lchild = l->rchild = NULL;
            enQueue_Singly(&queue, &l);
            (*temp)->lchild = l;
        }
        if (rchild_value != -1)
        {
            BinaryTree *r = (BinaryTree *)malloc(sizeof(BinaryTree));
            r->data = rchild_value;
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
BinaryTree *mergeBinaryTree(BinaryTree *b1, BinaryTree *b2)
{
    if (!b1 && !b2)
        return NULL;

    else if (!b1 && b2)
        return create_BinaryNode(b2->data);

    else if (!b2 && b1)
        return create_BinaryNode(b1->data);

    else
    {
        BinaryTree *root = create_BinaryNode(b1->data + b2->data);
        root->lchild = mergeBinaryTree(b1->lchild, b2->lchild);
        root->rchild = mergeBinaryTree(b1->rchild, b2->rchild);
        return root;
    }
}