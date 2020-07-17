/*
VLA created on stack, so we got a big problem
using VLA can create poor quality code
if stack has no memory but still we use VLA we would not know that stack is out of memory ;ERROR
Stack is mainly for fixed size memory. Unlike heap , if we consume stack memory more than its limit ; :(
using VLA is easy and need not write more lines but ,WHY ?

main problem is we do not know where our code is going to be used and don't know our machine stack size
stack size depend on compiler, architecture of machine, OS , and mainly on CODE
*/

#include <stdio.h>
int main()
{
    int n;
    printf("How many students data do you want to enter\n");
    scanf("%d", &n);

    int arr[n]; // VLA
    int i, max = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        max += arr[i];
    }
    printf("total of all numbeer = %d\n", max);
    return 0;
}