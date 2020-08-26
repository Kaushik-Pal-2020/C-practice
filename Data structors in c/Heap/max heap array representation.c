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
void increaseSize(maxheap *);
void insertElement(maxheap *, int);
int deleteElement(maxheap *);
void clearHeap(maxheap *);

int main()
{
    maxheap *heap = createMaxHeap();
    for (int i = 10; i < 1000; i += (i * 2) - 10)
        insertElement(heap, i);

    for (int i = 1; i < heap->size; i++)
        printf(" %d", deleteElement(heap));
    clearHeap(heap);
    return 0;
}
maxheap *createMaxHeap()
{
    int baseSize = 6;
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));
    heap->arr = (int *)malloc(baseSize * sizeof(int));
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void increaseSize(maxheap *heap)
{
    heap->size = heap->size * 2 - 1;
    heap->arr = (int *)realloc(heap->arr, heap->size * sizeof(int));
}
void insertElement(maxheap *heap, int val)
{
    heap->currentIndex++;
    register int i = heap->currentIndex;
    if (heap->currentIndex > heap->size)
        increaseSize(heap);

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