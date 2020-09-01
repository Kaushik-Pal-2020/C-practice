#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 1000

struct pair
{
    int frequency;
    int value;
};
typedef struct pair pair;

struct minHeap
{
    pair *arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct minHeap minHeap;

minHeap *createminHeap(int);
void insertElement(minHeap *, int, int);
pair *deleteElement(minHeap *);
void clearHeap(minHeap *);
int *basicHash(int *, int, int *);
void swap(int *, int *);

void topKFrequentNumbers(int *, int, int);
int main()
{
    int arr[] = {1, 1, 1, 3, 2, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    topKFrequentNumbers(arr, n, k);
    return 0;
}
minHeap *createminHeap(int baseSize)
{
    minHeap *heap = (minHeap *)malloc(sizeof(minHeap));
    heap->arr = (pair *)malloc((baseSize + 1) * sizeof(pair));
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void insertElement(minHeap *heap, int frequency, int value)
{
    heap->currentIndex++;
    register int i = heap->currentIndex;
    while (i > 1 && frequency < heap->arr[i / 2].frequency)
    {
        heap->arr[i].frequency = heap->arr[i / 2].frequency;
        heap->arr[i].value = heap->arr[i / 2].value;
        i /= 2;
    }
    heap->arr[i].frequency = frequency;
    heap->arr[i].value = value;
}

pair *deleteElement(minHeap *heap)
{
    pair *temp = (pair *)malloc(sizeof(pair));
    temp->frequency = heap->arr[1].frequency;
    temp->value = heap->arr[1].value;

    int tempSwap = 0;
    heap->arr[1].frequency = heap->arr[heap->currentIndex].frequency;
    heap->arr[1].value = heap->arr[heap->currentIndex].value;
    heap->currentIndex--;
    register int i = 1, j = 2;
    while (j <= heap->currentIndex)
    {
        if (j + 1 <= heap->currentIndex)
            if (heap->arr[j].frequency > heap->arr[j + 1].frequency)
                j += 1;

        if (heap->arr[i].frequency > heap->arr[j].frequency)
        {
            swap(&(heap->arr[i].frequency), &(heap->arr[j].frequency));
            swap(&(heap->arr[i].value), &(heap->arr[j].value));
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
void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
int *basicHash(int *arr, int n, int *totalElements)
{
    int *hash = (int *)calloc(HASH_SIZE, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 0)
            *totalElements = *totalElements + 1;
        hash[arr[i]] += 1;
    }
    return hash;
}
void topKFrequentNumbers(int *arr, int n, int k)
{
    minHeap *heap = createminHeap(n);
    int i, j = 0, l = 0;
    int *hash = basicHash(arr, n, &j);
    pair **deleteLater = (pair **)malloc(n * sizeof(pair *));
    for (i = 0; i < HASH_SIZE; i++)
    {
        if (j == 0)
            break;
        if (hash[i] != 0)
        {
            insertElement(heap, -hash[i], i);
            j--;
        }
    }
    printf("Top %d frequent numbers\n", k);
    while (heap->currentIndex)
    {
        deleteLater[l] = deleteElement(heap);
        for (i = 0; i < -deleteLater[l]->frequency; i++)
            printf("%d, ", deleteLater[l]->value);
        l++;
    }
    for (i = 0; i < l; i++)
        free(deleteLater[i]);

    free(deleteLater);
    free(hash);
    clearHeap(heap);
}
