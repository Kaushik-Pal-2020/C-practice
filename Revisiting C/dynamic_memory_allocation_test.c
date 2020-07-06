#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i,n=2;
	int *ptr = (int *)malloc(n*sizeof(int));
	printf("Address of ptr = %d\n",ptr);
	for(i=0;i<n;i++)
		ptr[i] = (i+1)*(i+1);
	printf("----------------------------------------------\n");	
	for(i=0; i<n; i++)
		printf("Value at ptr[%d] = %-4d and address = %d\n",i,*(ptr+i),(ptr+i));
	printf("----------------------------------------------\n\n");	
	n = 2*n;
	ptr =(int*)realloc(ptr,n*sizeof(int));
	printf("2nd time\nAddress of ptr = %d\n",ptr);
	printf("--------------------------------------------------------\n");
	for(i=0; i<2*n; i++)
		printf("Value at ptr[%d] = %-11d and address = %d\n",i,*(ptr+i),(ptr+i));	
	printf("--------------------------------------------------------\n\n");
	system("pause");
	return 0;
}
