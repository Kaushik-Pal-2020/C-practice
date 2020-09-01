#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pair
{
    int key, value;
};
struct maxheap
{
    struct pair **arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct maxheap maxheap;

maxheap *createMaxHeap(int);
void insertElement(maxheap *, int, int);
struct pair *deleteElement(maxheap *);
void swap(int *, int *);

void kClosestNumber(int *, int, int, int);
int main()
{
    int arr[] = {10, 2, 14, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int x = 5;
    kClosestNumber(arr, n, x, k);
    return 0;
}
maxheap *createMaxHeap(int baseSize)
{
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));
    heap->arr = (struct pair **)malloc(sizeof(struct pair *));
    int i;
    for (i = 0; i <= baseSize + 1; i++)
    {
        heap->arr[i] = (struct pair *)malloc(sizeof(struct pair));
    }
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void insertElement(maxheap *heap, int key, int val)
{
    heap->currentIndex++;
    register int i = heap->currentIndex;
    while (i > 1 && val > heap->arr[i / 2]->value)
    {
        heap->arr[i]->value = heap->arr[i / 2]->value;
        heap->arr[i]->key = heap->arr[i / 2]->key;
        i /= 2;
    }
    heap->arr[i]->key = key;
    heap->arr[i]->value = val;
}
struct pair *deleteElement(maxheap *heap)
{
    struct pair *temp = (struct pair *)malloc(sizeof(struct pair));
    *temp = *(heap->arr[1]);

    int tempSwap = 0;
    heap->arr[1]->value = heap->arr[heap->currentIndex]->value;
    heap->arr[1]->key = heap->arr[heap->currentIndex]->key;
    heap->currentIndex--;
    register int i = 1, j = 2;
    while (j <= heap->currentIndex)
    {
        if (j + 1 <= heap->currentIndex)
        {
            if (heap->arr[j]->value < heap->arr[j + 1]->value)
                j += 1;
        }
        if (heap->arr[i]->value < heap->arr[j]->value)
        {
            swap(&(heap->arr[i]->key), &(heap->arr[j]->key));
            swap(&(heap->arr[i]->value), &(heap->arr[j]->value));
            j *= 2;
        }
        else
            break;
    }
    return temp;
}
void kClosestNumber(int *arr, int n, int x, int k)
{
    maxheap *heap = createMaxHeap(k);
    register int i;
    struct pair *temp = NULL;
    for (i = 0; i < n; i++)
    {
        insertElement(heap, arr[i], abs(arr[i] - x));
        if (heap->currentIndex > k)
        {
            temp = deleteElement(heap);
            free(temp);
        }
    }
    printf("closest values of %d are ", x);
    while (heap->currentIndex)
    {
        temp = deleteElement(heap);
        printf("%d, ", temp->key);
        free(temp);
    }
	free(heap->arr);
    free(heap);
}
void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
