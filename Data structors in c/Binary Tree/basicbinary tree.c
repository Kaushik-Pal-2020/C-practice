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
BinaryTree *search_BinaryTree(BinaryTree *, int);
int sum_BinaryTree(BinaryTree *);
int height_BinaryTree(BinaryTree *);
int count_BinaryTree(BinaryTree *);
int leaf_BinaryTree(BinaryTree *);
int maxElement_BinaryTree(BinaryTree *);
int minElement_BinaryTree(BinaryTree *);
void levelOrderTraversal_BinaryTree(BinaryTree*);
int main()
{
    BinaryTree *root = create_BinaryTree();
    root = build_BinaryTree(root);
    printf("\nPreOrder of binary Tree\n");
    preOrder_traversal(root);
	printf("\n\n");
    //search_BinaryTree(root, 2);
    int sum = sum_BinaryTree(root);
    printf("\ntotal sum of all nodes = %d\n", sum);

    int count = height_BinaryTree(root);
    printf("\nheight of binary tree = %d\n", count);

    int xy = count_BinaryTree(root);
    printf("\ntotal no of nodes = %d\n", xy);

    int leaf = leaf_BinaryTree(root);
    printf("\ntotal no of leaf nodes = %d\n", leaf);

    int max = maxElement_BinaryTree(root);
    printf("\nmax element  = %d\n", max);

    int min = minElement_BinaryTree(root);
    printf("\nmin element  = %d\n", min);

    levelOrderTraversal_BinaryTree(root);
    
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
BinaryTree *search_BinaryTree(BinaryTree *root, int key)
{
    if (root && root->data != key)
    {
        BinaryTree *l = search_BinaryTree(root->lchild, key);
        BinaryTree *r = search_BinaryTree(root->rchild, key);
        if (l)
            return l;
        return r;
    }
    else
    {
        if (!root && root->data == key)
        {
            printf("found element\n");
            return root;
        }
        else
            return NULL;
    }
}
int sum_BinaryTree(BinaryTree *root)
{
    if (root)
    {
        int x = 0, y = 0;
        x = sum_BinaryTree(root->lchild);
        y = sum_BinaryTree(root->rchild);
        return x + y + root->data;
    }
}
int height_BinaryTree(BinaryTree *root)
{
    if (root)
    {
        int x = 0, y = 0;
        x = height_BinaryTree(root->lchild);
        y = height_BinaryTree(root->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
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
int leaf_BinaryTree(BinaryTree *root)
{
    int x = 0, y = 0;
    if (root)
    {
        x = leaf_BinaryTree(root->lchild);
        y = leaf_BinaryTree(root->rchild);
        if ((root->lchild == NULL) && (root->rchild == NULL))
            return x + y + 1;
        else
            return x + y;
    }
    else
        return 0;
}
int maxElement_BinaryTree(BinaryTree *root)
{
    int x = INT_MIN, y = INT_MIN;
    if (root)
    {
        x = maxElement_BinaryTree(root->lchild);
        y = maxElement_BinaryTree(root->rchild);
        if (root->data >= x && root->data >= y)
            return root->data;
        if (y >= x && root->data <= y)
            return y;
        else
            return x;
    }
}
int minElement_BinaryTree(BinaryTree *root)
{
    int x = INT_MAX, y = INT_MAX;
    if (root)
    {
        x = minElement_BinaryTree(root->lchild);
        y = minElement_BinaryTree(root->rchild);
        if (root->data <= x && root->data <= y)
            return root->data;
        if (y <= x && root->data >= y)
            return y;
        else
            return x;
    }
    return INT_MAX;
}
void levelOrderTraversal_BinaryTree(BinaryTree* root)
{
    Queue_Singly q;
    createQueue(&q, sizeof(BinaryTree*));
    enQueue_Singly(&q, &root);
    printf("\nLevel order traversal\n");
    BinaryTree **temp = (BinaryTree**)malloc(sizeof(BinaryTree*));
    while(!isEmpty_Singly(&q))
    {
        deQueue_Singly(&q, temp);
        printf("%d ",(*temp)->data);
        
        if((*temp)->lchild)
            enQueue_Singly(&q, &((*temp)->lchild));
        if((*temp)->rchild)
            enQueue_Singly(&q, &((*temp)->rchild));
    }
    clear_Singly(&q);
    free(temp);
}
