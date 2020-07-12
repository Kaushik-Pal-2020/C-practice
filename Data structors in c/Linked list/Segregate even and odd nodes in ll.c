#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *);
int append(struct Node **, int);
int build(int *, int, struct Node **);
void clear(struct Node **);
void segregateLinkedList(struct Node**);
int main()
{
    struct Node *root = NULL;
    int arr[10] = {0, 2, 4, 6, 8, 10, 11};
    build(arr, 7, &root);
    segregateLinkedList(&root);
    display(root);
    clear(&root);
    return 0;
}
void segregateLinkedList(struct Node** head)
{
    struct Node *end,*forward,*curr = NULL;
    struct Node *end_tmp,*tail; 
    end = forward = *head;
    int count_odd_nodes = 0;
    // we need to at last node of the linkedlist
    while(end->next)
    {
        end = end->next;
        if(((end->data)%2) != 0)
        	count_odd_nodes++;
    }
    // there is only one odd node at end then no need to go through loop
    if(count_odd_nodes == 1 && ((end->data)%2) != 0)
    	return;
    //else
    end_tmp = end;
    //end at last now last node
    while(curr != end_tmp)
    {
    	if(curr != end) //if curr at end so we can not assign tail to curr
    		tail = curr;// insted tail at previous node so need not to worry
        curr = forward;
        forward = forward->next; // sliding pointers 
        if(((curr->data)%2) != 0) // checking of node value is odd or not
        {
        // if it is odd then we pop the node and append at end of ll using end pointer
            if(curr == *head)
                *head = forward;
                
            else
            	tail->next = curr->next; // breaking linking with curr node
            	
			end->next = curr; 
            end = curr; // changing end node to curr and removing loop
            curr->next = NULL;
            
        }
    }
}
void clear(struct Node **current)
{
    while ((*current)->next)
    {
        struct Node *p, *t;
        p = t = (*current);
        while (p->next)
        {
            t = p;
            p = p->next;
        }
        t->next = NULL;
        free(p);
    }
    struct Node *p = *current;
    free(p);
    printf("Cleared all Heap memory\n");
}
void display(struct Node *root)
{
    printf("---------------------------------\n");
    printf("%26s\n", "Displaying linked list");
    while (root)
    {
        printf("%d(%u)-> ", root->data, root);
        root = root->next;
    }
    printf("\n---------------------------------\n");
}
int build(int *arr, int n, struct Node **p)
{
    int i = 0;
    for (; i < n; i++)
    {
        if (append(p, arr[i]))
        {
            return -1;
        }
    }
    return 0;
}
int append(struct Node **root, int data)
{
    // 0 means successfully created a node and done inserting
    // else -1 means out of memory or something else happend
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (!newNode) //unable to create a node
        return -1;

    newNode->data = data;
    newNode->next = NULL;

    if (!(*root))
        *root = newNode;
    else
    {
        struct Node *p = *root;

        while (p->next)
        {
            p = p->next;
        }
        p->next = newNode;
    }
    return 0;
}
