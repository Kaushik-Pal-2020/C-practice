#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char main_arr[100],cpy_arr[100];
	int index,m;
	char *ptr=main_arr,*c_ptr=cpy_arr;
	printf("Enter your text :\t");
	scanf("%s",ptr);
	printf("\nindex ? =\t");
	scanf("%d",&index);
	printf("\nHow many element :\t");
	scanf("%d",&m);
//	ptr=(ptr+index);
//	while(*ptr!=NULL && index<=m)
//	{
//		*c_ptr=*ptr;
//		ptr++;
//		c_ptr++;
//		index++;
//	}
//	
	int len=strlen(ptr);
	ptr=ptr-index+len;
	while(*ptr!=NULL && index<=len)
	{
		*c_ptr++=*ptr++;
		index++;
	}
	printf("%s",cpy_arr);
	system("pause");
	return 0;
}
