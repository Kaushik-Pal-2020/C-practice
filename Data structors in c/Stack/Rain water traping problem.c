/*
 before doing this question we need to learn maximum element on it's left side as well as right side
 look maximum element on right side of an array.c and maximum element on left side of an array.c from array subfolder
 then proceed this question
 */

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
int getMin(int x, int y)
{
    return (x > y) ? y : x;
}
void rainWaterTraping(int *arr, int n)
{
    int *left = maximumLeft(arr, n);
    int *right = maximumRight(arr, n);
    int *water = (int *)malloc(n * sizeof(int));

    int i, max = 0;
    for (i = 0; i < n; i++)
    {
        water[i] = (getMin(left[i], right[i]) - arr[i]);
        max += water[i];
    }

    printf("Maximum water can be hold = %d units\n", max);
    free(left);
    free(right);
    free(water);
}
int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(int);
    rainWaterTraping(arr, n);
    return 0;
}