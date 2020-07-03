#include<stdio.h>

char* is_divisible(unsigned long long *n)
{
	char *True = "YES", *False = "NO";
	
	if(*n%9==0)
		return True;
	else
		return False;
}

int main()
{
	unsigned long long user_input;
	scanf("%llu",&user_input);
	printf("%s",is_divisible(&user_input));
	return 0;
}
