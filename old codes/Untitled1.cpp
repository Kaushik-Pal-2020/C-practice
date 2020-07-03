#include<stdio.h>
#include<stdlib.h>
int main()
{
//	char names[][10]={"kaushik","suman","akshay"};
//	printf("%s",names[1]);
//	char *name[3];
//	for (int i=0;i<3;i++)
//	{
//		scanf("%s",name[i]);
//		printf("%s",name[i]);
//	}
//	char str[100],cpy_str[100];
//	char *p=str,*cpy_p=cpy_str;
//	printf("enter two strings");
//	scanf("%s %s",p,cpy_p);
//	char tmp[100];
//	char *tmp_p=tmp;
//	while(*p && *tmp_p)
//	{
//		*tmp_p++=*p++;
//	}
//	*tmp_p=' ';
//	while(*tmp_p && *cpy_p)
//	{
//		*tmp_p++=*cpy_p++;
//	}
//	p=str;
//	tmp_p=tmp;
//	while(*p && *tmp_p)
//	{
//		*p++=*tmp_p++;
//	}
//	printf("%s",tmp);
	static int a[]={0,1,2,3,4};
	static int *p[]={a,a+1,a+2,a+3,a+4};
	printf("\n%u %u %d\n",p,*p,*(*p));
	system("pause");
	return 0;
}
