#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    for(i=1;i<=5;i++)
    {
        if((i%2)!=0)
        continue;
        printf("%d",i);
    }
    system("pause");
}