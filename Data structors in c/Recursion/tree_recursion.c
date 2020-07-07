#include<stdio.h>
#include<stdlib.h>
void fun(int);
int main()
{
    fun(3);
    system("pause");
    return 0;
}
void fun(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        fun(n-1);
        fun(n-1);
    }

}
