#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BIT 16
int flip_bits(char *arr, int n);
int complement(char *arr, int n);
main()
{
    char arr[BIT];
    int chk_code,len;
    printf("Enter a binary number :\t");
    fgets(arr,BIT,stdin);
    len = strlen(arr);
    chk_code = flip_bits(arr,len);

    if (chk_code == -1)
        printf("\nIncorrect Binary Number\n");

    printf("1s compliment = %016s\n",arr);
    chk_code = complement(arr, len);
    if (chk_code == -1)
        printf("\nBit overflow\n");

    printf("2s compliment = %016s\n",arr);
    system("pause");
    return 0;
}
int flip_bits(char *arr, int n)
{
    int i = 0;
    for(; i<n-1; i++){
        if (arr[i] == '1')
            arr[i] = '0';
        else if(arr[i] == '0')
            arr[i] = '1';
        else
            return -1;
    }
    return 0;
};
int complement(char *arr, int n)
{
    int i = n-2;
    for(; i>=0; i--)
    {
        if(arr[i] == '0')
        {
            arr[i] = '1';
            return 0;
        }
    }
    return -1;
}