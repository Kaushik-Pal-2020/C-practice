#include <stdio.h>
#include <stdlib.h>

struct heapify
{
    int *arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct heapify heapify;

heapify *createHeapify();
void insertElement(heapify *, int);
int deleteElement(heapify *);
void clearHeap(heapify *);
heapify *buildHeapify(int *, int);
void swap(int *, int *);

void connectRopes(int *, int);
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    connectRopes(arr, n);
    return 0;
}
heapify *createHeapify(int baseSize)
{
    heapify *heap = (heapify *)malloc(sizeof(heapify));
    heap->arr = (int *)malloc(baseSize * sizeof(int));
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void insertElement(heapify *heap, int val)
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
int deleteElement(heapify *heap)
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
            swap(&(heap->arr[j]), &(heap->arr[i]));
        else
            break;
    }
    return temp;
}
void clearHeap(heapify *heap)
{
    free(heap->arr);
    free(heap);
    heap = NULL;
}
heapify *buildHeapify(int *arr, int n)
{
    heapify *heap = createHeapify(n + 1);
    int i, j;
    int lchild, rchild;
    //copying elemnts
    for (heap->currentIndex = 1; heap->currentIndex <= n; heap->currentIndex++)
        heap->arr[heap->currentIndex] = arr[heap->currentIndex - 1];

    heap->currentIndex--;
    for (i = heap->currentIndex / 2; i >= 1; i--)
    {
        j = i;
        while (2 * j <= n)
        {
            lchild = heap->arr[2 * j];
            if (2 * j + 1 <= n)
                rchild = heap->arr[2 * j + 1];
            else
                rchild = heap->arr[j] - 1;

            if (rchild <= lchild && rchild < heap->arr[j])
            {
                swap(&(heap->arr[j]), &(heap->arr[2 * j + 1]));
                j = 2 * j + 1;
            }
            else if (rchild > lchild && lchild < heap->arr[j])
            {
                swap(&(heap->arr[j]), &(heap->arr[2 * j]));
                j = 2 * j;
            }
            else
                break;
        }
    }
    return heap;
}
void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
void connectRopes(int *arr, int n)
{
    heapify *heap = buildHeapify(arr, n);
    int min1, min2, result = 0;
    while (heap->currentIndex != 1)
    {
        min1 = deleteElement(heap);
        min2 = deleteElement(heap);
        result = result + min1 + min2;
        insertElement(heap, min1 + min2);
    }
    printf("Connect Ropes to Minimise the Cost = %d\n", result);
    clearHeap(heap);
}