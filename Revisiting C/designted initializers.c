#include <stdio.h>

int main()
{
    int arr1[31] = {[0 ... 10] = 10, [11 ... 20] = 20, [21 ... 30] = 30};
    int i;
    for (i = 0; i <= 30; i++)
        printf("%d%c", arr1[i], (((i % 10) == 0) && i != 0) ? '\n' : ' ');
        
    printf("\n\n%d",arr1[0]);
    return 0;
}
