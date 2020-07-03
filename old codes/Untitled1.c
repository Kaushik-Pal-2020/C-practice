#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = {10, 20, 30, 40, 50};
	int *ptr = arr;
	printf("\nAddress of array = %p %p %p ",arr,&arr[0],&arr);
	char *p=NULL;
	p="kaushik";
	printf("\n%s -> size = %d\n",p,sizeof(p));
	printf("%d\n",*ptr++);
	printf("%d\n",++*ptr);
	printf("%d\n",*++ptr);
	system("PAUSE");
	return 0;
}
