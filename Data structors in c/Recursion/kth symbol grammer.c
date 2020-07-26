#include<stdio.h>

int kthGrammer(int n, int k)
{
    if(n==1 && k==1)
        return 0;
    int mid = (1<<(n-1))/2;
    if(k <=mid)
        return kthGrammer(n-1,k);
    else
        return !kthGrammer(n-1,k-mid);
}

int main()
{
    printf("id = %d\n",kthGrammer(4, 5));
    return 0;
}