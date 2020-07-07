#include<stdio.h>
int sum(int);
int main()
{
	int x = 10;
	printf("sum of %d = %d\n",x,sum(x));
	
}
int sum(int n)
{
	if(n>0)
		return n+sum(n-1);
}
