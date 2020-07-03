#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    
};
void insert(struct node*p,int data);
void display(struct node *p);
int main()
{
    struct node *t1;
    t1=(struct node*)malloc(sizeof(struct node));
    t1->data=100;
    t1->next=NULL;
    insert(t1,65);
    insert(t1,52);
    insert(t1,21);
    insert(t1,04);
    insert(t1,49);
    display(t1);
    system("pause");
    return -6;

}
void insert(struct node*p,int data)
{
    struct node *t,*q=p;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
    if(p!=NULL)
    {
        while(q->next!=NULL)
        q=q->next;
    q->next=t;
    }
    else
    {
        p=t;
    }  
}
void display(struct node *p)
{
    struct node *temp;
    temp=p;
    while(temp)
    {
        printf("%d ,",temp->data);
        temp=temp->next;
    }
}