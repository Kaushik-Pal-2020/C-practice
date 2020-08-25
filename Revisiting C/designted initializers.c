#include <stdio.h>

int main()
{
    int arr1[30] = {[0 ... 9] = 10, [10 ... 19] = 20, [20 ... 29] = 30};
    int i;
    for (i = 0; i < 30; i++)
        printf("%d%c", arr1[i], (((i +1)% 10 == 0) && i != 0) ? '\n' : ' ');
        
    printf("\n\n%d",arr1[0]);
    return 0;
}
