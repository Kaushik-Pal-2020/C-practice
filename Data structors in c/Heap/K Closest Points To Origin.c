#include <stdio.h>
#include <stdlib.h>

struct pair
{
    int cordinate[2];
    unsigned int distance;
};
typedef struct pair pair;

struct maxheap
{
    pair *arr;
    unsigned int size;
    unsigned int currentIndex;
};
typedef struct maxheap maxheap;

maxheap *createMaxHeap(int);
void insertElement(maxheap *, int, int, int);
pair *deleteElement(maxheap *);
void swap(int *, int *);

void kClosestPointsOrigin(int, int m, int n, int arr[][n]);
int main()
{
    int arr[4][2] = {{1, 3},
                     {-2, 2},
                     {5, 8},
                     {0, 1}};
    int m = 4;
    int n = 2;
    int k = 2;
    kClosestPointsOrigin(k, m, n, arr);
    return 0;
}
maxheap *createMaxHeap(int baseSize)
{
    maxheap *heap = (maxheap *)malloc(sizeof(maxheap));
    heap->arr = (pair *)malloc(baseSize * sizeof(pair));
    heap->size = baseSize;
    heap->currentIndex = 0;
    return heap;
}
void insertElement(maxheap *heap, int cordinateX, int cordinateY, int distance)
{
    heap->currentIndex++;
    register int i = heap->currentIndex;
    while (i > 1 && distance > heap->arr[i / 2].distance)
    {
        heap->arr[i].distance = heap->arr[i / 2].distance;
        heap->arr[i].distance = heap->arr[i / 2].distance;
        i /= 2;
    }
    heap->arr[i].distance = distance;
    heap->arr[i].cordinate[0] = cordinateX;
    heap->arr[i].cordinate[1] = cordinateY;
}

pair *deleteElement(maxheap *heap)
{
    struct pair *temp = (struct pair *)malloc(sizeof(struct pair));
    temp->cordinate[0] = heap->arr[1].cordinate[0];
    temp->cordinate[1] = heap->arr[1].cordinate[1];
    temp->distance = heap->arr[1].distance;

    int tempSwap = 0;
    heap->arr[1].cordinate[0] = heap->arr[heap->currentIndex].cordinate[0];
    heap->arr[1].cordinate[1] = heap->arr[heap->currentIndex].cordinate[1];
    heap->arr[1].distance = heap->arr[heap->currentIndex].distance;

    heap->currentIndex--;
    register int i = 1, j = 2;
    while (j <= heap->currentIndex)
    {
        if (j + 1 <= heap->currentIndex)
        {
            if (heap->arr[j].distance < heap->arr[j + 1].distance)
                j += 1;
        }
        if (heap->arr[i].distance < heap->arr[j].distance)
        {
            swap(&(heap->arr[i].distance), &(heap->arr[j].distance));
            swap(&(heap->arr[i].cordinate[0]), &(heap->arr[j].cordinate[0]));
            swap(&(heap->arr[i].cordinate[1]), &(heap->arr[j].cordinate[1]));
            j *= 2;
        }
        else
            break;
    }
    return temp;
}

void swap(int *val1, int *val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
void kClosestPointsOrigin(int k, int m, int n, int arr[][n])
{
    maxheap *heap = createMaxHeap(m);
    int i, dist, x, y, l = 0;
    pair **deleteLater = (pair **)malloc(m * sizeof(pair *));
    for (i = 0; i < m; i++)
    {
        x = arr[i][0];
        y = arr[i][1];
        dist = (x * x) + (y * y);
        insertElement(heap, x, y, dist);
        if (heap->currentIndex > k)
            deleteLater[l++] = deleteElement(heap);
    }

    printf("%d closest points to origin(0,0) :", k);
    while (heap->currentIndex)
    {
        deleteLater[l] = deleteElement(heap);
        printf("(%d, %d), ", deleteLater[l]->cordinate[0], deleteLater[l]->cordinate[1]);
        l++;
    }
    printf("\n");
    for (i = 0; i < l; i++)
        free(deleteLater[i]);

    free(deleteLater);
    free(heap->arr);
    free(heap);
}
