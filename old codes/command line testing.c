#include<stdio.h>
int main(int arc ,char *argv[])
{
	printf("no of arguments = %d\n",arc);
	printf("First argument = %s\n",argv[0]);
	printf("Rest of arguments = %s",argv[1]);
	return 0;
}
