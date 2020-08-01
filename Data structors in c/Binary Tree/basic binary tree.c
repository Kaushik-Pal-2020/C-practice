#include <stdio.h>
#include <stdlib.h>
#include "QueueSingly.h"

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

// void build_BinaryTree(BinaryTree *root)
// {
//     if (!root)
//     {
//         root = (BinaryTree *)malloc(sizeof(BinaryTree));
//         printf("Enter Root value = %d\n", &root->data);
//         root->lchild = root->rchild = NULL;
//     }
//     Queue_Singly *queue = createQueue();
//     enQueue_Singly();
//     int lchild_value, rchild_value;
//     printf("")
// }

int main()
{
    Queue_Singly queue;
    size_t n = sizeof(int);
    createQueue(&queue, sizeof(int));
    int i = 5;
    for (; i < 15; i += 2)
        enQueue_Singly(&queue, &i);
    display_Singly(&queue);
    clear_Singly(&queue);
    return 0;
}