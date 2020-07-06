#include<stdio.h>
#include<stdlib.h>
void display(int m, int n, int arr[m][n]);
int main()
{
    int arr[3][4] = {{1,2,3,4},{10,20,30,40},{100,200,300,400}};
    int (*ptr)[4] = arr;
    int *p = &arr[0][0];
    display(3, 4, arr);
    printf("value at arr[2] = %d\n",**(arr+2));
    printf("address of arr[1][3] = %d\n",*(ptr+1)+3);
    printf("value of arr[0][1] = %d\n",*(p+1));
    system("pause");
    return 0;
}
void display(int m, int n, int arr[m][n])
{
    int i, j;
    printf("---------------------------------\n");
    for (i = 0;i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("Address of arr[%d][%d] = %d\n",i,j,(*(arr+i)+j));
        printf("\n");
    }
    printf("---------------------------------\n");
}
