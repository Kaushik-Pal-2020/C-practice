#include <stdio.h>
#include<stdlib.h>
int main()
{
    const char a='A', b='3', c='@',d='2.3'; 
    
    printf("Value of a is %c\nValue of b is %c\nValue of c is %c\n%c",a,b,c,d);
    
    printf("ASCII value of a is %d\nASCII value of b is %d\nASCII value of c is %d\n%d",a,b,c,d);
    system("pause");
    return 0;
}