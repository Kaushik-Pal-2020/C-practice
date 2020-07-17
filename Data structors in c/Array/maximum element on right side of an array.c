#include <stdio.h>
#include <stdlib.h>

int *maximumRight(int *arr, int n)
{
    int *right = (int *)malloc(n * sizeof(int));
    right[n - 1] = arr[n - 1];
    int i;
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] > right[i + 1])
            right[i] = arr[i];
        else
            right[i] = right[i + 1];
    }
    return right;
}

int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *p = maximumRight(arr, n);
    int i;
    for (i = 0; i < n; i++)
        printf("%d, ", *(p + i));
    free(p);
    return 0;
}