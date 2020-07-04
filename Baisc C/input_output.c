#include <stdio.h>
#include <stdlib.h>
main()
{
    char arr[50];
    char *ptr;
    // if we want to enter names with space then
    // method 1
    printf("enter your name :\t");
    scanf("%[^\n]", arr);
    fflush(stdin);
    // clearing buffer
    printf("your name is = %s\n", arr);
    printf("--------------------------------\n");
    //  meethod 2
    printf("enter your name :\t");
    fgets(arr, 50, stdin);
    printf("your name is = %s\n", arr);
    printf("--------------------------------\n");
    // in method 1 buffer over will happen thats why we need to use fflush()
    // but in case of method 2 we are explicitly giving size of buffer
    system("pause");
    return 0;
}