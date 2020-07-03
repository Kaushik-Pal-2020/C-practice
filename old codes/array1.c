#include<stdio.h>
#include<stdlib.h>
void Runtest(int arr[],int n);
void display(int arr[],int n);
int main()
{
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    Runtest(arr,n);
    display(arr,n);
    system("pause");
    return 0;
}
void Runtest(int *arr,int n)
{
    int i=0;
    for(i;i<n;i++)
    arr[i]=arr[i]*2;
    display(arr,n);
}
void display(int *arr,int n)
{
    int i=0;
    for(i;i<n;i++)
    printf("%d  ",arr[i]);
    printf("\n");
}