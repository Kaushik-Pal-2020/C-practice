#include <stdio.h>
void missingDuplicate(int *, int);
int main()
{
    int arr[] = {3, 1, 2, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    missingDuplicate(arr, n);
    return 0;
}
void missingDuplicate(int *arr, int n)
{
    int i, expression1, expression2, missing, duplicate;
    expression1 = expression2 = 0;
    for (i = 0; i < n; i++)
    {
        expression2 += (arr[i] * arr[i]);
        expression1 += arr[i];
    }
    int sum1, sum2;
    sum1 = n * (n + 1) / 2;           // sum 1 to N
    sum2 = sum1 * (2 * n + 1) / 3;    // sum 1^2 to N^2
    expression1 = expression1 - sum1; // x-y=c1
    expression2 = expression2 - sum2; // x^2 - y^2 = c2

    int interState = expression2 / expression1; // x^2 - y^2 / x-y = c2/c1; (x+y)(x-y)/(x-y) = c2/c1 ;x+y = c3
    duplicate = (interState + expression1) / 2; // x+y+x-y = c3+c1; x = (c3+c1)/2
    missing = duplicate - expression1;          // y = x - c1
    printf("Missing Number = %d and Duplicate Number = %d\n", missing, duplicate);
}