#include <stdio.h>
#include <stdlib.h>

struct minHeap
{
    int *arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct minHeap minHeap;

minHeap *createminHeap();
void increaseSize(minHeap *);
void insertElement(minHeap *, int);
int deleteElement(minHeap *);
void clearHeap(minHeap *);

int main()
{
    minHeap *heap = createminHeap();
    for (int i = 10; i < 1000; i += (i * 2) - 10)
        insertElement(heap, i);

    for (int i = 1; i < heap->size; i++)
        printf(" %d", deleteElement(heap));
    clearHeap(heap);
    return 0;
}
minHeap *createminHeap()
{
    int baseSize = 6;
    minHeap *heap = (minHeap *)malloc(sizeof(minHeap));
    heap->arr = (int *)malloc(baseSize * sizeof(int));
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void increaseSize(minHeap *heap)
{
    heap->size = heap->size * 2 - 1;
    heap->arr = (int *)realloc(heap->arr, heap->size * sizeof(int));
}
void insertElement(minHeap *heap, int val)
{
    heap->currentIndex++;
    register int i = heap->currentIndex;
    if (heap->currentIndex > heap->size)
        increaseSize(heap);

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
    while (j < heap->currentIndex)
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