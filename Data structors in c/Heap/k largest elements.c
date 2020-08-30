#include <stdio.h>
#include <stdlib.h>

struct minHeap
{
    int *arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct minHeap minHeap;

minHeap *createminHeap(int);
void insertElement(minHeap *, int);
int deleteElement(minHeap *);
void clearHeap(minHeap *);

void kLargestElements(int *, int, int);
int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    kLargestElements(arr, n, k);
    return 0;
}
minHeap *createminHeap(int baseSize)
{
    minHeap *heap = (minHeap *)malloc(sizeof(minHeap));
    heap->arr = (int *)malloc(baseSize * sizeof(int));
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void insertElement(minHeap *heap, int val)
{
    heap->currentIndex++;
    register int i = heap->currentIndex;
    while (i > 1 && val < heap->arr[i / 2])
    {
        heap->arr[i] = heap->arr[i / 2];
        i /= 2;
    }
    heap->arr[i] = val;
}
int deleteElement(minHeap *heap)
{
    if (heap->currentIndex <= 0)
        return -999;
    int temp = heap->arr[1];
    int tempSwap = 0;
    heap->arr[1] = heap->arr[heap->currentIndex--];
    register int i = 1, j = 2;
    while (j <= heap->currentIndex)
    {
        if (heap->arr[j] > heap->arr[j + 1])
            j += 1;

        if (heap->arr[i] > heap->arr[j])
        {
            tempSwap = heap->arr[j];
            heap->arr[j] = heap->arr[i];
            heap->arr[i] = tempSwap;
        }
        else
            break;
    }
    return temp;
}
void clearHeap(minHeap *heap)
{
    free(heap->arr);
    free(heap);
    heap = NULL;
}
void kLargestElements(int *arr, int n, int k)
{
    minHeap *heap = createminHeap(n);
    int i;
    for (i = 0; i < n; i++)
    {
        insertElement(heap, arr[i]);
        if (heap->currentIndex > k)
            deleteElement(heap);
    }

    printf("%d Largest Elements in the array : ", k);
    while (heap->currentIndex)
        printf("%d, ", deleteElement(heap));

    clearHeap(heap);
}