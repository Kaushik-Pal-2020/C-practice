#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	char dest1[10]="Kaushik",src1[10]="pal",
		 dest2[10],src2[10]="Bolpur"
	;
	printf("size of dest1 = %d\n",sizeof(dest1));
	printf("Length of dest1 = %d\n",strlen(dest1));
	printf("dest 1 = %s\n",dest1);
	
	// strncat and strcpy
	strncat(dest1, src1, sizeof(dest1));
	printf("After concatanating two strings \n");
	printf("dest1 = %s\n",dest1);
	printf("src1 = %s\n",src1);
	printf("Length of dest1 = %d\n",strlen(dest1));
	printf("Length of src1 = %d\n",strlen(src1));
	
	//memset
	memset(dest2,'@',9);
	printf("dest2 = %s\n",dest2);
	system("pause");
	return 0;
}
