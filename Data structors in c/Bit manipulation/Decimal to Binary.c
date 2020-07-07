#include<stdio.h>
long long int decimalToBinary(int);
void decimalToBinary_print(long int);
int main()
{
	int value = 11111;
	printf("%d in BinaryNumber = %lld\n",value,decimalToBinary(value));
	decimalToBinary_print(1111111);
	return 0;
}
long long int decimalToBinary(int x)
{
	long long int binary_num = 0,base = 1;
	while(x)
	{
		binary_num += (x&1)*base;
		base *= 10;
		x = x>>1;
	}
	return binary_num;
}
void decimalToBinary_print(long int x)
{
	long int temp = x;
	int digit = -1,bit=0;
	printf("%ld in binary(direct print) = ",x);
	while(temp)
	{
		digit++;
		temp = temp>>1;
	}
	while(digit>=0)
	{
		bit = (x&(1<<digit))==0 ? 0 : 1;
		digit--;
		printf("%d",bit);
	}
	printf("\n");
}
