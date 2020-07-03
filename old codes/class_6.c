#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int val=986547,j=1;
    while(j<=3)
    {
        for(int x=0;x<=9;x++)
        printf("%d",x);
        j++;
    }
    printf("\n");
    printf("%010d\n",val);
    float Fvalue=2560.192547836;
    //printf("%-16.6f",Fvalue);
    
    char name[]="Engineering College";
    printf("%-35s",name);printf("K\n");
    system("pause");
}