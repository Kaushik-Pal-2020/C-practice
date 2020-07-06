#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int *p1=NULL;
	char *p2=NULL;
	float *p3=NULL;
	short *p4=NULL;
	long long int *p5=NULL;
	double *p6=NULL;
	printf("Size of int pointer = %d bytes\n",sizeof(p1));
	printf("Size of char pointer = %d bytes\n",sizeof(p2));
	printf("Size of float pointer = %d bytes\n",sizeof(p3));
	printf("Size of short pointer = %d bytes\n",sizeof(p4));
	printf("Size of long long int pointer = %d bytes\n",sizeof(p5));	
	printf("Size of double pointer = %d bytes\n",sizeof(p6));
	system("pause");
	return 0;
}
