#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[20];
    printf("enter your name\n");
    scanf("%s",&str);
    int value=strlen(str);
    printf("length of '%s' = %d\n",str,value);
    system("pause");
    return 0;
}