#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void display(struct Node*);
int append(struct Node**, int);
int build(int *, int, struct Node**);
int findNthNode(struct Node*, int);
int main()
{
    struct Node *root=NULL;
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    printf("%d\n",build(arr, 10, &root));
    findNthNode(root,5);
    display(root);
    return 0;
}
int findNthNode(struct Node* curr, int n)
{
    struct Node *fast, *slow;
    int tempPos = n;
    fast = slow = curr;
    // now we need to traverse fast up to n-1 times
    while(n-1)
    {
        fast = fast->next;
        n--;
    }
    if(!fast)
        return -1; // fast pointer hit end of the ll and go beyond


    // move fast upto last node
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    // now slow at nth pos from end
    printf("%d pos from end = %d (%u)\n",tempPos, slow->data, slow);
    return 0;
}

void display(struct Node* root)
{
    printf("---------------------------------\n");
    printf("%26s\n","Displaying linked list");
    while(root)
    {
        printf("%d(%u)-> ",root->data,root);
        root = root->next;
    }
    printf("\n---------------------------------\n");
}
int append(struct Node** root, int data)
{
    // 0 means successfully created a node and done inserting 
    // else -1 means out of memory or something else happend
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if(!newNode) //unable to create a node
        return -1;

    newNode->data = data;
    newNode->next = NULL;

    if(!(*root))
        *root = newNode;
    else
    {
        struct Node* p = *root; 
        
        while(p->next)
        {
            p = p->next;
        }
        p->next = newNode;
    }
    return 0;
    
}
int build(int *arr, int n, struct Node** p)
{
    int i=0;
    for(; i<n; i++)
    {
        if(append(p, arr[i])){
        	return -1;
		}
    }
    return 0;
}

