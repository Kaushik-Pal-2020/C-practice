#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[3][3];
    printf("enter numbers for matrix 3x3 \n");
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nlets now display the matrix\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    system("pause");
}