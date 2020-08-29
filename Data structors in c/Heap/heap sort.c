#include <stdio.h>
#include <stdlib.h>

struct maxheap
{
    int *arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct maxheap maxheap;

maxheap *createMaxHeap();
void insertElement(maxheap *, int);
int deleteElement(maxheap *);
void clearHeap(maxheap *);
void heapSort(int *, int);
int main()
{
    int arr[] = {100,90,80,70,60,50,40,30,20,10};
    heapSort(arr, sizeof(arr) / sizeof(*arr));
    for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
        printf("%d, ", arr[i]);
    return 0;
}
void heapSort(int *arr, int n)
{
    maxheap *h = createMaxHeap(n);
    register int i = 0;
    for (; i < n; i++)
        insertElement(h, arr[i]);

    for (i = n - 1; i >= 0; i--)
        arr[i] = deleteElement(h);

    clearHeap(h);
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
    }
    return temp;
}
void clearHeap(maxheap *heap)
{
    free(heap->arr);
    free(heap);
    heap = NULL;
}
maxheap *createMaxHeap(int size)
{

    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));
    heap->size = size + 1;
    heap->arr = (int *)malloc(heap->size * sizeof(int));
    heap->currentIndex = 0;
    return heap;
}
