#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
main()
{

    int x = 1234567, y = 1234;
    printf("%d\n", x);
    printf("%-10d\n", x);
    printf("%10d\n", x);
    printf("%010d\n", x);
    printf("value of x =%20d\n", x);
    printf("value of x =%20d\n", y);
    system("pause");
    return 0;
}