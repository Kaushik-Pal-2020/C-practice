#include<stdio.h>
int add(int *a, int *b)
{
	return (*a)+(*b); // address of this statement is the address of add function
}
int subtract(int *a, int *b)
{
	return (*a)-(*b); // address of this statement is the address of subtract function
}
int multiply(int *a, int *b)
{
	return (*a)*(*b); // address of this statement is the address of multiply function
}
int divide(int *a, int *b)
{
	return (*a)/(*b); // address of this statement is the address of divide function
}
int main()
{
	// function pointers are those pointer who itself a pointer and it point to function
	// for every function it's base address is address of it's first statement
	int (*p)(int*, int*) = add;
	int (*function_array[4])(int*, int*) = {add,subtract,multiply,divide};
	int x = 6, y = 7,ch;
	printf("%d, %d = %d\n",x,y,p(&x,&y));
	printf("---------------------------------------------\n");
	while(1)
	{
		printf("Enter your choise -[0,3] and 9 for exit\n");
		scanf("%d",&ch);
		if(ch==9)
			break;
		printf("Enter values = \n");
		scanf("%d %d",&x, &y);
		printf("%d, %d = %d\n",x,y,function_array[ch](&x,&y));
		printf("---------------------------------------------\n");
	}
	return 0;
}
