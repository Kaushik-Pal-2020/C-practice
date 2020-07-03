#include<stdio.h>

int find_zero(unsigned int *value)
{
	int i,count=0;
	for(i=5;*value/i>=1;i*=5)
		count += *value/i;
	return count;
}

int main()
{
	unsigned int user_input;
	scanf("%u",&user_input);
	printf("%d",find_zero(&user_input));
	return 0;
}
