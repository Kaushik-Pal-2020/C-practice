#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int num;
    printf("\tenter the number which one you want the table\n");
    scanf("%d",&num);
    //printf("%d\n",num);
    int i=1;
    int tmp;
    for(i;i<=10;i++)
    {
       printf("-------");
        printf("--%d--",i);
        printf("-------");
       tmp=pow(num,i);
        printf("  %d  ",tmp);
         printf("------");
       printf("\n");
    }
system("pause");
}