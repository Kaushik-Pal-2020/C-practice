#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
struct node
{
    int data;
    struct node *next;
};
int Del(struct node*p);
void insert(struct node*p,int data);
void display(int *arr,int n);
void binsort(int *arr,int n);
int Findmax(int *arr,int n);
int main()
{
    int arr[]={6,3,9,10,15,6,8,12,3,6};
    int n=sizeof(arr)/sizeof(int);
    binsort(arr,n);
    display(arr,n);
    system("pause");
    return -9;
}
int Findmax(int *arr,int n)
{
    int i=0,max=INT_MIN;
    for(;i<n;i++)
    {
        if(arr[i]>max)
        max=arr[i];
    }
    return max;
}
void display(int *arr,int n)
{
        int i=0;
    for(;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
void binsort(int *arr,int n)
{
    int max,i,j;
    max=Findmax(arr,n);
    struct node **bin;
    bin=(struct node **)malloc(max+1,sizeof(struct node));
    for(i=0;i<max+1;i++)
    bin[i]=NULL;
    for(i=0;i<n;i++)
    {
        insert(bin[arr[i]],arr[i]);
    }
    i=j=0;
    while(i<max+1)
    {
        while(bin[i]!=NULL)
        {
            arr[j++]=Del(bin[i]);
        }
        i++;
    }
}
void insert(struct node*p,int data)
{
    if(p==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    }
    else
    {
    struct node *t,*q=p;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
        while(q->next!=NULL)
        q=q->next;
    q->next=t;
    }
}
int Del(struct node*p)
{
    struct node *temp;
    p=p->next;
   // free(temp);
    return temp->data;
}