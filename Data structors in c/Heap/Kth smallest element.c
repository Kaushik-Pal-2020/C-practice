#include <stdio.h>
#include <stdlib.h>

struct maxheap
{
    int *arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct maxheap maxheap;

maxheap *createMaxHeap(int);
void insertElement(maxheap *, int);
int deleteElement(maxheap *);
void clearHeap(maxheap *);
int kthSmallest(int *,int, int);

int main()
{
    int arr[] = {7,10,4,3,20,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1;

    int result = kthSmallest(arr, n, k);
    printf("%dth Smallest Element in the array = %d\n",k,result);
    return 0;
}
maxheap *createMaxHeap(int baseSize)
{
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));
    heap->arr = (int *)calloc(baseSize , sizeof(int));
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void insertElement(maxheap *heap, int val)
{
    heap->currentIndex++;
    register int i = heap->currentIndex;
    while (i > 1 && val > heap->arr[i / 2])
    {
        heap->arr[i] = heap->arr[i / 2];
        i /= 2;
    }
    heap->arr[i] = val;
}
int deleteElement(maxheap *heap)
{
    if (heap->currentIndex <= 0)
        return -999;
    int temp = heap->arr[1];
    int tempSwap = 0;
    heap->arr[1] = heap->arr[heap->currentIndex--];
    register int i = 1, j = 2;
    while (j < heap->currentIndex)
    {
        if (heap->arr[j] < heap->arr[j + 1])
            j += 1;

        if (heap->arr[i] < heap->arr[j])
        {
            tempSwap = heap->arr[j];
            heap->arr[j] = heap->arr[i];
            heap->arr[i] = tempSwap;
        }
        else
            break;
        j *= 2;
    }
    return temp;
}
void clearHeap(maxheap *heap)
{
    free(heap->arr);
    free(heap);
    heap = NULL;
}
int kthSmallest(int *arr,int n,int k)
{
    maxheap *heap = createMaxHeap(k);
    int i = 0;
    for(;i<n;i++)
    {
        insertElement(heap,arr[i]);
        if(heap->currentIndex >k)
            deleteElement(heap);
    }
    int result = deleteElement(heap);
    clearHeap(heap);
    return result;
}