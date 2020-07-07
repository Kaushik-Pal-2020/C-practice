#include<stdio.h>
long long int fact(long long int);
int main()
{
	int x = 25;
	printf("Factorial of %d = %lld\n",x,fact(x));
	return 0;
}
long long int fact(long long int n)
{
	if(n>=2)
		return n*fact(n-1);
	else
		return 1;
}
