#include<stdio.h>
#include<stdlib.h>
struct test
{
    int x;
};
void display(struct test);
int main()
{
    struct test t1 = {10};
    printf("From main\naddress of test = %u\n",&t1);
    display(t1);
    printf("from main\nvalue of x = %d\n",t1.x);
    system("pause");
    return 0;

}
void display(struct test t)
{
    printf("value of x = %d\n",t.x);
    printf("address of test = %u\n",&t);
    t.x = 100;
}