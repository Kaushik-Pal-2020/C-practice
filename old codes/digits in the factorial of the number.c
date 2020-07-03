#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int find_no_digits(int* value)
{
	int i;
	double no_digits;
	
	if(*value <=1)
		return 1;
		
	for(i=2;i<=*value;i++)
		no_digits += log10(i);
	
	return floor(no_digits) + 1;
}

int main()
{
	int user_input;
	scanf("%d",&user_input);
	printf("%d",find_no_digits(&user_input));
	return 0;
}
