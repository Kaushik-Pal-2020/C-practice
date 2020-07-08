#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
	printf("Size of int = %d bytes and range(%d, %d)\n",sizeof(int),INT_MIN,INT_MAX);
	
	printf("Size of char = %d bytes and range(%d, %d)\n",sizeof(char),CHAR_MIN,CHAR_MAX);
	
	printf("Size of short = %d bytes and range(%d, %d)\n",sizeof(short),SHRT_MIN,SHRT_MAX);
	
	printf("Size of long int = %d bytes and range(%ld, %ld)\n",sizeof(long int),(long) LONG_MIN,(long) LONG_MAX);
	
	printf("Size of long long int = %d bytes and range(%lld, %lld)\n",sizeof(long long int),(long long) LONG_LONG_MIN,(long long) LONG_LONG_MAX);
	
	printf("Size of float = %d bytes and range(%g, %g)\n",sizeof(float),(float) -FLT_MIN,(float)FLT_MAX);
	
	printf("Size of double = %d bytes and range(%g, %g)\n",sizeof(double),(double) -DBL_MIN,(double) DBL_MAX);
	
	printf("Size of long double = %d bytes and range()\n",sizeof(long double));
	return 0;
}

