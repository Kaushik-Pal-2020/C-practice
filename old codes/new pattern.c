#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,l,m,n;
    printf("please enter the value of n:\t");
    scanf("%d",&n);
    if(n%2!=0)
    n=n+1;
    n=n/2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        printf("*");
        for(k=n-1;k>=i;k--)
        printf("`");
        for(m=n-1;m>=i;m--)
        printf("*");
        for(l=0;l<i;l++)
        printf("`");
        printf("\n");
    }
    getch();
    return 0;
}
