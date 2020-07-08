#include<stdio.h>
#include<stdlib.h>
struct array
{
    int *arr;
    int size,length;
};
void display(struct array*);
int del(struct array*, int);
void insert(struct array*, int, int);
void increse(struct array*);
void clear(struct array* r)
{
    printf("Clearing all heap memories ....\n");
    free(r->arr);
}
int main()
{
    int i,val[] = {8,3,7,12,6,9,10};
    struct array p = {(int*)malloc(10*sizeof(int)), 10, 0};
    for(p.length;p.length<7;p.length++)
    {
        p.arr[p.length] = val[p.length];
    }
    display(&p);
    insert(&p,3,22);
    display(&p);
    del(&p,3);
    display(&p);
    increse(&p);
	clear(&p);
    return 0;
}
void insert(struct array* r, int pos, int key)
{
    if(r->size > pos)
    {
        int i;
        for(i = r->length; i > pos ;i--)
            r->arr[i] = r->arr[i-1];
        r->arr[pos] = key;
        r->length++;
    }
    else{
        if(r->length == r->size)
            printf("Need to increase of the array\n");
        else{
            printf("wrong position");
        }
    }
}
void display(struct array *r)
{
    int i;
    printf("--------------------------------\n");
    printf("Displaying array\n");
    for(i=0;i<r->length;i++)
        printf("%d ",r->arr[i]);
    printf("\n--------------------------------\n");
}
void increse(struct array* r)
{
    r->arr = (int *)realloc(r->arr,2*r->size*sizeof(int));
    r->size *= 2;
    printf("Successfully increased size by %d to %d\n",r->size/2,r->size);
}
int del(struct array *r,int pos)
{
    if(pos>=0 && pos <= r->length){
    int i,backup = r->arr[pos];
    for(i=pos; i<r->length-1;i++)
        r->arr[i] = r->arr[i+1];
    r->length--;
    return backup;
    }
    else{
        printf("invalid position");
    }
}
