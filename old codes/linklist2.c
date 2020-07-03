#include<stdio.h>
#include<stdlib.h>
typedef struct link_list
{
    int data;
    struct link_list *next;
}node;
//void Insert(node **head,int data,int pos=-1);
void display(node *head);

void Insert(node **head,int data,int pos=-1)
{
    if(*head==NULL&&pos==0)
    {
        node *p;
        p=(node*)malloc(sizeof(node));
        p->data=data;
        p->next=NULL;
        *head=p;
    }
    else if(pos==0)
    {
        node *p=(node*)malloc(sizeof(node));
        p->data=data;
        p->next=*head;
        *head=p;
    } 
    else if(pos==-1)
    {
        node *q,*t;
        q=*head;
        t=(node*)malloc(sizeof(node));
        t->data=data;
        t->next=NULL;
        while(q->next)
        {
        q=q->next;
        }
        q->next=t;
    }
    else
    {
        node *p=(node*)malloc(sizeof(node)),*q=*head;
        int i;
        p->data=data;
        for(i=0;i<pos-1&&q;i++)
        q=q->next;
        p->next=q->next;
        q->next=p;
    }
}
void display(node *head)
{
    node *p=head;
    printf("elements in linklist are bellow \n");
    while(p)
    {
        printf("%d ->",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    node *first=NULL;
    Insert(&first,10);
    Insert(&first,20);
    Insert(&first,30);
    Insert(&first,40);
    display(first);
    system("pause");
    return -98;
}