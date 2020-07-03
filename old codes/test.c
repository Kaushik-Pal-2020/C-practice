#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int arr[]={1,2,3,4,5};
    ptr=arr;
    printf("%d",sizeof(ptr));
    char re='a';
    char *ptr3;
    ptr3=&re;
    printf("\n%d",sizeof(ptr3));
    system("PAUSE");
    return 0;
}