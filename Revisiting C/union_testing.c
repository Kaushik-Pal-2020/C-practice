#include<stdio.h>
#include<stdlib.h>
union test
{
    int x;
    char c; 
};
void display(union test *t)
{
    printf("----------------------------------\n");
    printf("value of x = %d\n",t->x);
    printf("value of c = %c\n",t->c);
    printf("Address of x = %u\n",&t->x);
    printf("Address of c = %u\n",&t->c);
    printf("----------------------------------\n");
}
int main(void)
{
    union test t;
    printf("Size of union test = %d bytes\n",sizeof(t));
    t.x = 100;
    display(&t);
    t.c = 'a';
    display(&t);

    system("pause");
    return 0;
}