#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    unsigned int capacity;
    int *arr;
};

struct Stack *createStack(int); // only for stack
void push(struct Stack *, int); // only for stack
int pop(struct Stack *);        // only for stack
int peek(struct Stack *);       // only for stack
int isEmpty(struct Stack *);    // only for stack
void clear(struct Stack *);     // only for stack

int *NSNleft_stack(int arr[], int n)
{
    struct Stack *stack = createStack(n);
    push(stack, 0);
    int *left = (int *)malloc(sizeof(int) * n);
    left[0] = -1;
    int i;
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] <= arr[peek(stack)]))
            pop(stack);

        if (isEmpty(stack) == -1)
            left[i] = peek(stack);
        else
            left[i] = -1;
        push(stack, i);
    }
    clear(stack);
    return left;
}
int *NSNright_stack(int arr[], int n)
{
    int *right = (int *)malloc(sizeof(int) * n);
    struct Stack *stack = createStack(n);
    push(stack, 0);
    int i;
    for (i = 1; i < n; i++)
    {
        while ((isEmpty(stack) == -1) && (arr[i] < arr[peek(stack)]))
            right[pop(stack)] = i;

        push(stack, i);
    }
    while (isEmpty(stack) == -1)
    {
        right[pop(stack)] = n;
    }
    clear(stack);
    return right;
}
int maximumAreaHistogram(int arr[], int n)
{
    int *area = (int *)malloc(n * sizeof(int));
    int *left = NSNleft_stack(arr, n);
    int *right = NSNright_stack(arr, n);
    int i, width, max = 0, ar;
    for (i = 0; i < n; i++)
    {
        width = right[i] - left[i] - 1; // width between histogram
        area[i] = width * arr[i];
        if (area[i] > max)
            max = area[i];
    }
    free(left);
    free(right);
    free(area);
    return max;
}
void maxAreaBinaryMatrix(int m, int n, int arr[][n])
{
    // convert binary 2d array into different level 2d array
    int **binaryHeight = (int **)malloc(m * sizeof(int *)); //creating 1-d double pointers
    int k;
    // creating 1-d array to each double pointer
    for (k = 0; k < n; k++)
        binaryHeight[k] = (int *)malloc(n * sizeof(int));

    int *result = (int *)malloc(m * sizeof(int));
    int i, j;

    //initializing binary height with array's first row
    for (i = 0; i < n; i++)
        binaryHeight[0][i] = arr[0][i]; //h1

    // generating h2,h3,h4,.....,hm ; h = histogram
    for (i = 1; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                binaryHeight[i][j] = 0;
            else
                binaryHeight[i][j] = binaryHeight[i - 1][j] + arr[i][j];
        }
    }
    //calculating maximum histogram area of each h1,h2,h3,... and finding maximum
    int max = 0;
    for (i = 0; i < m; i++)
    {
        result[i] = maximumAreaHistogram(binaryHeight[i], n);
        printf("%d, ", result[i]);
        if (max < result[i])
            max = result[i];
    }
    printf("\nmaximum area in binary matrix = %d unit\n", max);

    //now free memory in free pool
    free(result);
    for (i = 0; i < m; i++)
        free(binaryHeight[i]);

    free(binaryHeight);
}
int main()
{
    int arr[4][4] = {{0, 1, 1, 0},
	 				 {1, 1, 1, 1},
	  				 {1, 1, 1, 1},
	   				 {1, 1, 0, 0}};
    int m = 4;
    int n = 4;
    maxAreaBinaryMatrix(m, n, arr);
    return 0;
}
struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int value)
{
    stack->arr[++stack->top] = value;
}

int isEmpty(struct Stack *stack)
{
    if (stack->top == -1)
        return 1;
    return -1;
}

int pop(struct Stack *stack)
{
    return stack->arr[stack->top--];
}

int peek(struct Stack *stack)
{
    return stack->arr[stack->top];
}

void clear(struct Stack *stack)
{
    free(stack->arr);
    free(stack);
}
