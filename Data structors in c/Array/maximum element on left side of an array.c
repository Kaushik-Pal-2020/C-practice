#include <stdio.h>
#include <stdlib.h>

int *maximumLeft(int *arr, int n)
{
    int *left = (int *)malloc(n * sizeof(int));
    left[0] = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > left[i - 1])
            left[i] = arr[i];
        else
            left[i] = left[i - 1];
    }
    return left;
}

int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *p = maximumLeft(arr, n);
    int i;
    for (i = 0; i < n; i++)
        printf("%d, ", *(p + i));
    free(p);
    return 0;
}