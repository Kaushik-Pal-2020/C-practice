#include<stdio.h>
// 1->True and 0->False
int isSparse(unsigned int);
int nextSparseNumber(unsigned int);
int main()
{
	int x = 6;
	int res = isSparse(x);
	if(res==1)
		printf("%d is a sparse number\n",x);
	else
		printf("%d is not a sparse number\n",x);
		
	printf("Next sparse number = %d\n",nextSparseNumber(8));
	return 0;
}
// O(logn) time complexity
int isSparse(unsigned int n)
{
	unsigned int tmp = 0;
	while(n)
	{
		tmp = n;
		n = n>>1;
		if((tmp&1)==1 && (n&1)==1)
			return 0;
	}
	return 1;
}
// O(n) time complexity
int nextSparseNumber(unsigned int n)
{
	while(1)
	{
		if(isSparse(n))
			return n;
		n++;
	}
}
// total time complexity = O(nlogn)
