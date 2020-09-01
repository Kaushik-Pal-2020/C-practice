#include <stdio.h>
void missingDuplicateMultiple(int *, int);
void swap(int *, int *);

int main()
{
    int arr[] = {3, 1, 2, 5, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    missingDuplicateMultiple(arr, n);
    return 0;
}
void missingDuplicateMultiple(int *arr, int n)
{
    int i = 0, missing, duplicate;
    //swap sort
    while (i < n)
    {
        if ((arr[i] - 1 == i) || (arr[arr[i] - 1] == arr[i]))
            i++;
        else
            swap(&(arr[i]), &(arr[arr[i] - 1]));
    }

    for (i = 0; i < n; i++)
    {
        if (arr[i] - 1 != i)
            printf("Missing Number = %d and Duplicate Number = %d\n", i + 1, arr[i]);
    }
}
void swap(int *val1, int *val2)
{
    int temp = *val2;
    *val2 = *val1;
    *val1 = temp;
}