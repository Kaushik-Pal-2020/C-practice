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
int kthSmallest(int *, int, int);
void sumOfElements(int *, int, int, int);
int main()
{
    int arr[] = {1, 3, 12, 5, 15, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k1 = 3;
    int k2 = 6;
    sumOfElements(arr, n, k1, k2);
    return 0;
}
maxheap *createMaxHeap(int baseSize)
{
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));
    heap->arr = (int *)calloc(baseSize, sizeof(int));
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
    while (j <= heap->currentIndex)
    {
        if (heap->arr[j] < heap->arr[j + 1])
            j += 1;

        if (heap->arr[i] < heap->arr[j])
        {
            tempSwap = heap->arr[j];
            heap->arr[j] = heap->arr[i];
            heap->arr[i] = tempSwap;
            j *= 2;
        }
        else
            break;
    }
    return temp;
}
void clearHeap(maxheap *heap)
{
    free(heap->arr);
    free(heap);
    heap = NULL;
}
int kthSmallest(int *arr, int n, int k)
{
    maxheap *heap = createMaxHeap(k);
    int i = 0;
    for (; i < k; i++)
        insertElement(heap, arr[i]);

    for (i = k; i < n; i++)
    {
        insertElement(heap, arr[i]);
        deleteElement(heap);
    }
    int result = deleteElement(heap);
    clearHeap(heap);
    return result;
}
void sumOfElements(int *arr, int n, int k1, int k2)
{
    int k1Value = kthSmallest(arr, n, k1);
    int k2Value = kthSmallest(arr, n, k2);
    int i = 0, sum = 0;
    for (; i < n; i++)
    {
        if (arr[i] > k1Value && arr[i] < k2Value)
            sum += arr[i];
    }
    printf("Sum of Elements between %d smallest and %d smallest numbers = %d\n", k1, k2, sum);
}