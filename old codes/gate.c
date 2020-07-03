#include<stdio.h>
int r()
{
    static int num=7;
    return num--;
}
main()
{
     for(r();r()!=0;r())
     printf("%d",r());
     getchar();
     return 0;
     
}