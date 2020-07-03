#include<stdio.h>
#include<stdlib.h>
void IMergesort(int *arr,int n);
void merge(int *arr,int l,int mid,int h);
void RMergesort(int *arr,int l,int h);
void display(int *arr,int n);
int main()
{
    int arr[]={8,3,7,4,9,2,6,5,1};
    int n=sizeof(arr)/sizeof(int);
    RMergesort(arr,0,n);
    display(arr,n);
    system("pause");
    return 0;
}
void IMergesort(int *arr,int n)
{
    int p,i,l,mid,h;
    for(p=2;p<=n;p*=2)
    {
        for(i=0;i+p-1<=n;i+=p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            merge(arr,l,mid,h);
        }
    }
    if(n%2!=0)
    merge(arr,0,p/2-1,n);
}
void merge(int *arr,int l,int mid,int h)
{
    int i,j,k;
    i=k=l;
    j=mid+1;
    int Bak[h+1];
    while(i<=mid&&j<=h)
    {
        if(arr[i]<arr[j])
        Bak[k++]=arr[i++];
        else
        Bak[k++]=arr[j++];        
    }
    while(i<=mid)
    Bak[k++]=arr[i++];
    while(j<=h)
    Bak[k++]=arr[j++];
    for(i=l;i<=h;i++)
    arr[i]=Bak[i];
}
void display(int *arr,int n)
{
    int i=0;
    for(i;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}
void RMergesort(int *arr,int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        RMergesort(arr,l,mid);
        RMergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}