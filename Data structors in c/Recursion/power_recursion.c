#include<stdio.h>
long long int power(long long int m,int n)
{
	if(n==0)
		return 1;
	else
		return m*power(m,n-1);
}
int main()
{
	int m=3,n=2;
	printf("%d ^ %d value = %lld\n",m,n,power(m,n));
	return 0;
}
