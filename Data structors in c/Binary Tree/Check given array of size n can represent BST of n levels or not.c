#include<stdio.h>
#include<limits.h>

int checkArray_BST(int *arr, int n)
{
    if (n==0 || n==1)
        return 1;
    int mini=INT_MIN, mid=arr[0], maxi=INT_MAX;
    int i=1;
    while (i<n) {
        if (arr[i]>mini && arr[i]<mid) {
            maxi=mid;
            mid=arr[i];
            ++i;
        }
        else if (arr[i]>mid && arr[i]<maxi) {
            mini=mid;
            mid=arr[i];
            ++i;
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    int arr[] ={ 512, 330, 78, 11, 8 };
    int n = sizeof(arr)/ sizeof(*arr);

    int res = checkArray_BST(arr, n);
    printf("Can we form BST from this level order traversal = %d\n", res);
    return 0;
}