#include <stdio.h>
#include <stdlib.h>
#include "QueueSingly.h"

struct AVLnode
{
    struct AVLnode *lchild;
    int data;
    int height;
    struct AVLnode *rchild;
};
typedef struct AVLnode AVLnode;

AVLnode *createNode_AVL(int);
AVLnode *Rinsert_AVL(AVLnode *, int);
AVLnode *LLRotation_AVL(AVLnode *);
AVLnode *RRRotation_AVL(AVLnode *);
int nodeHeight_AVL(AVLnode *);
int balanceFactor_AVL(AVLnode *);
void clearAVL(AVLnode *);
AVLnode *build_AVL(int *, int);
AVLnode *Inoder_predecessor_BST(AVLnode *);
AVLnode *Inoder_successor_BST(AVLnode *);
AVLnode *Delete_AVLnode(AVLnode *, int);

void preoderTraversal(AVLnode *);
void preoderTraversalUtil(AVLnode *);
void postoderTraversal(AVLnode *);
void postoderTraversalUtil(AVLnode *);
void inoderTraversal(AVLnode *);
void inoderTraversalUtil(AVLnode *);
void levelOrderTraversal(AVLnode *);

int main()
{
    int elements[] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
    int size = sizeof(elements) / sizeof(*elements);
    AVLnode *root = build_AVL(elements, size);
    preoderTraversal(root);
    postoderTraversal(root);
    inoderTraversal(root);
    levelOrderTraversal(root);
    printf("\n\n\n");
    Delete_AVLnode(root, 10);
    preoderTraversal(root);
    postoderTraversal(root);
    inoderTraversal(root);
    levelOrderTraversal(root);
    clearAVL(root);
    return 0;
}
AVLnode *createNode(int data)
{
    AVLnode *newNode = (AVLnode *)malloc(sizeof(AVLnode));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    newNode->height = 1;
    return newNode;
}
void preoderTraversal(AVLnode *root)
{
    printf("===============PREORDER TRAVERSAL===============\n");
    preoderTraversalUtil(root);
    printf("\n================================================\n");
}
void preoderTraversalUtil(AVLnode *root)
{
    if (root)
    {
        printf("%d, ", root->data);
        preoderTraversalUtil(root->lchild);
        preoderTraversalUtil(root->rchild);
    }
}
void postoderTraversal(AVLnode *root)
{
    {
        printf("==============POSTORDER TRAVERSAL===============\n");
        postoderTraversalUtil(root);
        printf("\n================================================\n");
    }
}
void postoderTraversalUtil(AVLnode *root)
{
    if (root)
    {
        postoderTraversalUtil(root->lchild);
        postoderTraversalUtil(root->rchild);
        printf("%d, ", root->data);
    }
}
void inoderTraversal(AVLnode *root)
{
    printf("===============INORDER TRAVERSAL================\n");
    inoderTraversalUtil(root);
    printf("\n================================================\n");
}
void inoderTraversalUtil(AVLnode *root)
{
    if (root)
    {
        inoderTraversalUtil(root->lchild);
        printf("%d, ", root->data);
        inoderTraversalUtil(root->rchild);
    }
}
AVLnode *Rinsert_AVL(AVLnode *root, int data)
{
    if (!root)
        return createNode(data);

    else if (root->data > data)
        root->lchild = Rinsert_AVL(root->lchild, data);

    else if (root->data < data)
        root->rchild = Rinsert_AVL(root->rchild, data);

    else
        return root;

    // updating each parent nodes height
    root->height = nodeHeight_AVL(root);
    int balanceFactor = balanceFactor_AVL(root);

    // case 1 : checking if it is lchild skewed(LL imbalanced),if yes then do LLRotation
    if (balanceFactor > 1 && data < root->lchild->data)
        return LLRotation_AVL(root);

    //case 2 : if it is rchild skewed(RR imbalanced), if yes then do RRRotation
    else if (balanceFactor < -1 && data > root->rchild->data)
        return RRRotation_AVL(root);

    //case 3 : if it is LR imbalanced, if yes then do LRRotation
    else if (balanceFactor > 1 && data > root->lchild->data)
    {
        // first need to do RR-rotaion on root->lchild then perform LL on root
        root->lchild = RRRotation_AVL(root->lchild);
        return LLRotation_AVL(root);
    }

    //case 3 : if it is RL imbalanced, if yes then do RLRotation
    else if (balanceFactor < -1 && data < root->rchild->data)
    {
        // first need to do LL-rotaion on root->rchild then perform RR on root
        root->rchild = LLRotation_AVL(root->rchild);
        return RRRotation_AVL(root);
    }

    // finally return root
    return root;
}
int nodeHeight_AVL(AVLnode *root)
{
    int heightlchildSubTree, heightrchildSubTree;
    heightlchildSubTree = (root && root->lchild) ? root->lchild->height : 0;
    heightrchildSubTree = (root && root->rchild) ? root->rchild->height : 0;
    return (heightlchildSubTree > heightrchildSubTree) ? heightlchildSubTree + 1 : heightrchildSubTree + 1;
}
int balanceFactor_AVL(AVLnode *root)
{
    int heightlchildSubTree, heightrchildSubTree;
    heightlchildSubTree = (root && root->lchild) ? root->lchild->height : 0;
    heightrchildSubTree = (root && root->rchild) ? root->rchild->height : 0;
    return heightlchildSubTree - heightrchildSubTree;
}
AVLnode *LLRotation_AVL(AVLnode *root)
{
    AVLnode *LNode = root->lchild;
    AVLnode *LRNode = LNode->rchild;

    LNode->rchild = root;
    root->lchild = LRNode;

    root->height = nodeHeight_AVL(root);
    LNode->height = nodeHeight_AVL(LNode);

    return LNode;
}
AVLnode *RRRotation_AVL(AVLnode *root)
{
    AVLnode *RNode = root->rchild;
    AVLnode *RLNode = RNode->lchild;

    RNode->lchild = root;
    root->rchild = RLNode;

    root->height = nodeHeight_AVL(root);
    RNode->height = nodeHeight_AVL(RNode);

    return RNode;
}
void clearAVL(AVLnode *root)
{
    if (root)
    {
        clearAVL(root->lchild);
        clearAVL(root->rchild);
        free(root);
    }
}
AVLnode *build_AVL(int *arr, int n)
{
    int i = 0;
    AVLnode *root = NULL;
    for (; i < n; i++)
        root = Rinsert_AVL(root, arr[i]);
    return root;
}
void levelOrderTraversal(AVLnode *root)
{
    Queue_Singly queue;
    createQueue(&queue, sizeof(AVLnode *));
    enQueue_Singly(&queue, &root);
    AVLnode **currNode = (AVLnode **)malloc(sizeof(AVLnode *));
    unsigned int n = 1, copy_n;
    unsigned int level = 1;
    register int i = 0;
    printf("=============LEVEL ORDER TRAVERSAL==============\n");
    while (isEmpty_Singly(&queue) != 1)
    {
        printf("%d level :      ", level);
        copy_n = n;
        for (i = 0; i < copy_n; i++)
        {
            deQueue_Singly(&queue, currNode);
            n--;
            printf("%d, ", (*currNode)->data);
            if ((*currNode)->lchild)
            {
                enQueue_Singly(&queue, &((*currNode)->lchild));
                n++;
            }

            if ((*currNode)->rchild)
            {
                enQueue_Singly(&queue, &((*currNode)->rchild));
                n++;
            }
        }
        level++;
        if (isEmpty_Singly(&queue) == 0)
            printf("\n");
    }
    free(currNode);
    clear_Singly(&queue);
    printf("\n===============================================\n");
}
AVLnode *Inoder_predecessor_BST(AVLnode *root)
{
    while (root && root->rchild)
        root = root->rchild;
    return root;
}
AVLnode *Inoder_successor_BST(AVLnode *root)
{
    while (root && root->lchild)
        root = root->lchild;
    return root;
}

AVLnode *Delete_AVLnode(AVLnode *root, int key)
{
    // if root is empty node then simply return null
    if (!root)
        return root;

    if (root->data > key)
        root->lchild = Delete_AVLnode(root->lchild, key);
    else if (root->data < key)
        root->rchild = Delete_AVLnode(root->rchild, key);

    else // now we found element
    {
        // node with only one child or no child
        if ((root->lchild == NULL) || (root->rchild == NULL))
        {
            AVLnode *temp = root->lchild ? root->lchild : root->rchild;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the rchild subtree)
            AVLnode *temp = Inoder_successor_BST(root->rchild);
            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->rchild = Delete_AVLnode(root->rchild, temp->data);
        }
    }
    if (root == NULL)
        return root;

    root->height = nodeHeight_AVL(root);
    int balance_factor = balanceFactor_AVL(root);

    //case 1 : do LL rotaion on root
    if (balance_factor > 1 && balanceFactor_AVL(root->lchild) >= 0)
        return LLRotation_AVL(root);

    //case 2:do LR rotaion
    else if (balance_factor > 1 && balanceFactor_AVL(root->lchild) < 0)
    {
        root->lchild = RRRotation_AVL(root->lchild);
        return LLRotation_AVL(root);
    }

    //case 3 : do RR Rotation on root
    else if (balance_factor < -1 && balanceFactor_AVL(root->rchild) <= 0)
        return RRRotation_AVL(root);

    // case 4 : do Rl rotaion
    else if (balance_factor < -1 && balanceFactor_AVL(root->rchild) > 0)
    {
        root->rchild = LLRotation_AVL(root->rchild);
        return RRRotation_AVL(root);
    }
    return root;
}