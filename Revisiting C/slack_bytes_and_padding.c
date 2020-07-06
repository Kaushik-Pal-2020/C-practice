#include<stdio.h>
#include<stdlib.h>
// as you can see short takes 2 bytes, int takes 4 bytes and char takes 1 byte
// so actually struct test1 space should be total of 4+2+1 = 7 bytes
// because of word boundaries and slacking bytes size of struct test1 will vary
// to minimize the size of struct test1 we need to declare variables by decreasing order of sizes
// e.g int x;shortz;char y; total size will be 8 bytes 4+2+(1+1)
// but if we do short z;int x;char y; then total size will be 12((2+2)+4+(1+3))
// slack bytes will be those byte that are unoccupied ; it's totally depends on CPU,OS,x64/x32
struct test1
{
	short z;
	int x;
	char y;
};
struct test2
{
	int x;
	short z;
	char y;
};
struct test3
{
	char y;
	short z;
	int x;
};
int main(void)
{
	printf("Size of the test 1 = %d bytes\n",sizeof(struct test1));
	printf("Size of the test 2 = %d bytes\n",sizeof(struct test2));
	printf("Size of the test 3 = %d bytes\n",sizeof(struct test3));
	system("pause");
	return 0;
}
