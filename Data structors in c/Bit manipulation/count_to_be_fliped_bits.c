// Count number of bits to be flipped to convert A to B
#include<stdio.h>
#include<stdlib.h>
int count_flip(int a, int b)
{
    int count = 0;
    while(a && b)
    {
        if(a^b)
            count++;
        a >>= 1;
        b >>= 1;
    }
    return count;
}
int main()
{
    int a=10,b=20;
    printf("to transer %d -> %d, steps need = %d\n",a,b,count_flip(a,b));
    system("pause");
    return 0;
}