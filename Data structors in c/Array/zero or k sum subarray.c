#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

bool zeroSumSubArray(const int *arr,const int n)
{
    int sum = 0;
    bool flag = false;
    int *HashTable = (int*)calloc(1000,sizeof(int));
    for(register int i = 0;i<n;i++)
    {
        sum += arr[i];
        if(HashTable[sum] == 0)
           HashTable[sum] = 1;
        else
        {
            flag = true;
            break;
        }
    }
    free(HashTable);
    return flag;
}

bool kSumSubArray(const int *arr,const int n,int k)
{
    int sum = 0;
    bool flag = false;
    int *HashTable = (int*)calloc(1000,sizeof(int));
    for(register int i = 0;i<n;i++)
    {
        sum += arr[i];
        if(sum-k>=0){
            if(HashTable[sum-k] == 0)
            HashTable[sum-k] = 1;
            else
            {
                flag = true;
                break;
            }
        }
        else
            HashTable[sum] = 1;
    }
    free(HashTable);
    return flag;
}

void kSumSub(const int *arr,const int n,int k)
{
    int sum = 0;
    bool flag = false;
    int *HashTable_positive = (int*)calloc(1000,sizeof(int));
    int *HashTable_negative = (int*)calloc(1000,sizeof(int));

    for(register int i = 0;i<n;i++)
    {
        sum += arr[i];
        if(sum < 0 && HashTable_negative[abs(sum)]==0)
            HashTable_negative[abs(sum)] = i+1;

        else if(sum >= 0 && HashTable_positive[sum]==0)
            HashTable_positive[sum] = i+1;
        if(sum==k)
        {
            printf("From index 0 to %d\n",i);
            flag = true;
            break;
        }
        else if((sum - k )>= 0)
        {
            if(HashTable_positive[sum-k] != 0)
                {
                    printf("From index %d to %d\n",HashTable_positive[sum-k],i);
                    flag = true;
                    break;
                }
        }
        else if ((sum - k )<0)
        {
            if(HashTable_negative[abs(sum-k)] != 0)
                {
                    printf("From index %d to %d\n",HashTable_negative[abs(sum-k)],i);
                    flag = true;
                    break;
                }
        }
        
    }
    free(HashTable_positive);
    free(HashTable_negative);
    if(flag==false)
        printf("No element found\n");
}
int main()
{
    const int arr[] = {6,10,2,-2,-20,10};
    const int n = sizeof(arr)/sizeof(*arr);
    // printf("zero sum sub array exists : %d\n",zeroSumSubArray(arr,n));
    // printf("k sum sub array exists : %d\n",kSumSubArray(arr,n,-10));
    kSumSub(arr, n, -10);
    return 0;
}