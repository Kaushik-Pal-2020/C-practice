#include<stdio.h>
#include<stdlib.h>
typedef struct link_list
{
    int data;
    struct link_list *next;
}node;
void insert(node **head,int data)
{
    node *p=(node*)malloc(sizeof(node));
    p->data=data;
    p->next=NULL;
    if(*head==NULL)
    {
        *head=p;
    }
    else
    {
        node *q=*head;
        while(q->next)
        q=q->next;
        q->next=p;
    }
}
void display(node *head)
{
    node *q=head;
    printf("elements are in the LL\n");
    while(q)
    {
    printf("%d ->",q->data);
    q=q->next;
    }
    printf("\n");
}
void CheckSort(node *head)
{
    int flag=0;
    node *p=head;
    while(p->next)
    {
        if(p->data>p->next->data)
        {
            flag=1;
            break;
        }
        p=p->next;
    }
    if(flag==0)
    printf("LL is sorted\n");
    else
    {
        printf("LL is not sorted\n");
    }
    
}
int main()
{
    node *first=NULL;
    insert(&first,10);
    insert(&first,20);
    insert(&first,30);
    insert(&first,05);
    insert(&first,50);
    insert(&first,60);
    insert(&first,70);
    display(first);
    CheckSort(first);
    system("pause");
    return -98;
}