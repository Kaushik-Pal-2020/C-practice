#include<stdio.h>
#include<stdlib.h>
void insert(int*, int, int, int);
void display(int *, int);
int main()
{
    int arr[10] = {8,3,7,12,6,9,10}, len = 10;
    insert(arr,len,22,3);
    display(arr,len);
    return 0;
}
void insert(int* arr, int n, int key, int pos)
{
    if(pos<n){
    int i=0;
    for(i=n-1; i>pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = key;
    }
}
void display(int *arr, int n)
{
    int i;
    printf("--------------------------------\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n--------------------------------\n");
}