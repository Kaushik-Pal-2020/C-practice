#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int value = 100,res = 10;
	char c = 's';
	float fvalue = 99.99;
	long long int llvalue = 100000;
	int *ptr = NULL;
	const int *ptr2 = &value;
	int *const ptr3 = &value;
	void *main_ptr,*p;
	
	ptr = &value;
	printf("Using ptr ,value = %d\n",*ptr);
	*ptr = 110;
	printf("Using pt2 ,value = %d\n",*ptr2);
	// *ptr2 = 120;
	ptr2 = &res;
	printf("Using pt2 ,value = %d\n",*ptr2);
	*ptr3 = 1000;
	// ptr3 = &res;
	main_ptr =&value;
	printf("value of void ptr = %d\n",*(int*)main_ptr);
	
	system("pause");
	return 0;
}
