#include <stdio.h>
#include <stdlib.h>
#include "QueueSingly.h"
#include <stdbool.h>

struct BinaryTree
{
    struct BinaryTree *lchild;
    int data;
    struct BinaryTree *rchild;
};

typedef struct BinaryTree BinaryTree;

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
    BinaryTree **temp;
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
    printf("All done\n");
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
        if (!root)
        {
            printf("found element\n");
            return root;
        }
        else
            return NULL;
    }
}
int main()
{
    BinaryTree *root = create_BinaryTree();
    root = build_BinaryTree(root);
    preOrder_traversal(root);
    search_BinaryTree(root, 2);
    clear_BinaryTree(root);
    return 0;
}
