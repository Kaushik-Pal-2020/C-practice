#include <stdio.h>
void swap(int *, int *);
void reverse(int *arr, int n);
int isSorted(int *, int);
int main()
{
    int len = 4, i;
    int arr[] = {1, 2, 4, 5};
    printf("Is array is sorted = %s\n", isSorted(arr, len) ? "True" : "False");
    reverse(arr, len);
    for (i = 0; i < len; i++)
        printf("%d%c", arr[i], (i == len - 1) ? '\n' : ' ');
    printf("Is array is sorted = %s\n", isSorted(arr, len) ? "True" : "False");
    return 0;
}
void reverse(int *arr, int n)
{
    int i, j;
    for (i = 0, j = n - 1; i <= j; i++, j--)
    {
        swap((arr + i), (arr + j));
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int isSorted(int *arr, int n)
{
    n--;
    while (n)
    {
        if (arr[n] < arr[--n])
            return 0;
    }
    return 1;
}