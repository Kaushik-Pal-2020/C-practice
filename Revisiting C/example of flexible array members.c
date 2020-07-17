/*
before proceeding further , for me this make no sense . Absolutely no sense
liking an 0 size of array in a structure then reallocating more size ??
why even need to bother 
same thing in flexible array members, it does not give some additional functionality just randome BS
I sill prefer using pointer to that data type then using malloc/calloc then do whatever i need to do
*/

#include <stdio.h>
#include <stdlib.h>
struct flexible
{
    int size;
    int arr[]; // flexible array with no size ,
    //  int arr[0] or int arr[1] both we can do in C89
    // one thing to note that arr[] must be last member in struct
};

void takeImputs()
{
    int n;
    printf("How many students data do you want to enter\n");
    scanf("%d", &n);
    struct flexible *f = malloc(sizeof(*f) + n * sizeof(int)); // malloc(sizeof(struct flexible ) + n*sizeof(int))
    //we can not create normal struct variable in stack , we must allocate memory from free memory pool
    // n*sizeof(int) means sizeeof array; we can not use calloc here

    int i, max = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &f->arr[i]);
        max += f->arr[i];
    }
    printf("total of all numbeer = %d\n", max);
    free(f);
}
int main()
{
    takeImputs();
    return 0;
}