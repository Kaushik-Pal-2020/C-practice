/* A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5.
 First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), …. */
#include<stdio.h>
unsigned int nthMagicNumber(int);
int main()
{
	int x = 5;
	printf("%d th magic number = %u\n",x,nthMagicNumber(x));
	return 0;
}
unsigned int nthMagicNumber(int n)
{
	unsigned int pow = 1, answer = 0;
	while(n)
	{
		pow = pow * 5;
		if(n&1)//if last bit is set
			answer += pow;
		n = n >> 1; //left shifting one bit
	}
	return answer;
}
