#include <stdio.h>
#include <stdlib.h>
void copy(int *, int *, int);
int *merge(int *, int, int *, int);
void union_arr(int *, int *, int *, int *);
void display(int *, int);
void intersection(int *, int *, int *, int *);
void difference(int *, int *, int *, int *);
int main()
{
    int len1 = 5, a[] = {1, 2, 3, 4, 5}, b[] = {3, 4, 6, 7, 8}, len2 = 5;
    int *arr1 = (int *)malloc(len1 * sizeof(int));
    int *arr2 = (int *)malloc(len2 * sizeof(int));
    copy(arr1, a, len1);
    copy(arr2, b, len2);
    display(arr1, len1);
    display(arr2, len2);
    // union_arr(arr1, &len1, arr2, &len2);
    // intersection(arr1, &len1, arr2, &len2);
    // difference(arr1, &len1, arr2, &len2);
    int *t = merge(arr1, len1, arr2, len2);
    // display(arr1, len1);
    // display(arr2, len2);
    display(t, len1 + len2);
    free(arr1);
    free(arr2);

    return 0;
}
int *merge(int *arr1, int len1, int *arr2, int len2)
{
    int i, j, k, len = len1 + len2;
    i = j = k = 0;
    int *temp = (int *)malloc(len * sizeof(int));
    while (i < len1 && j < len2)
    {
        if (arr1[i] >= arr2[j])
        {
            temp[k++] = arr2[j++];
            i++;
        }
        else if (arr1[i] < arr2[j])
            temp[k++] = arr1[i++];
    }
    for (; i < len1; i++, k++)
        temp[k] = arr1[i];
    for (; j < len2; j++, k++)
        temp[k] = arr2[j];
    return temp;
}
void union_arr(int *arr1, int *len1, int *arr2, int *len2)
{
    int n1 = *len1, n2 = *len2;
    int i, j, k, len = n1 + n2;
    i = j = k = 0;
    int *temp = (int *)malloc(len * sizeof(int));
    while (i < n1 && j < n2)
    {
        if (arr1[i] > arr2[j])
            temp[k++] = arr2[j++];
        else if (arr1[i] < arr2[j])
            temp[k++] = arr1[i++];
        else
        {
            temp[k++] = arr1[i++];
            j++;
        }
    }
    for (; i < n1; i++, k++)
        temp[k] = arr1[i];
    for (; j < n2; j++, k++)
        temp[k] = arr2[j];
    len = k;
    arr1 = (int *)realloc(arr1, len * sizeof(int));
    copy(arr1, temp, len);
    *len1 = len;
    free(temp);
}
void copy(int *dest, int *source, int size)
{
    int i = 0;
    for (; i < size; i++)
        dest[i] = source[i];
}
void display(int *arr, int n)
{
    int i = 0;
    printf("---------------------------------\n");
    for (; i < n; i++)
        printf("%d%s", arr[i], (i == n - 1) ? "\n" : ", ");
    printf("---------------------------------\n");
}
void intersection(int *arr1, int *len1, int *arr2, int *len2)
{
    int n1 = *len1, n2 = *len2;
    int i, j, k, len = n1 + n2;
    i = j = k = 0;
    int *temp = (int *)malloc(len * sizeof(int));
    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            temp[k++] = arr1[i++];
            j++;
        }
        else if (arr1[i] > arr2[j])
            j++;
        else
            i++;
    }
    len = k;
    arr1 = (int *)realloc(arr1, len * sizeof(int));
    copy(arr1, temp, len);
    *len1 = len;
    free(temp);
}
void difference(int *arr1, int *len1, int *arr2, int *len2)
{
    int n1 = *len1, n2 = *len2;
    int i, j, k, len = n1 + n2;
    i = j = k = 0;
    int *temp = (int *)malloc(len * sizeof(int));
    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
            j++;
        else
            temp[k++] = arr1[i++];
    }
    for (; i < n1; i++, k++)
        temp[k] = arr1[i];
    len = k;
    arr1 = (int *)realloc(arr1, len * sizeof(int));
    copy(arr1, temp, len);
    *len1 = len;
    free(temp);
}