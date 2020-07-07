#include<stdio.h>
/* a+b = a^b */
/* from half adder equation a+b = (a^b)+(a&b)*/
int sumXor(int);
int main()
{
	int n = 12;
	printf("%d\n",sumXor(n));
	return 0;
}
int sumXor(int x)
{
	unsigned short unset_bits = 0;
	while(x)
	{
		if((x&1)==0)
			unset_bits++;
		x = x>>1;
	}
	return 1<<unset_bits;
}
