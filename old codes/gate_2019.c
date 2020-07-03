#include<stdio.h>
int r(){
	static int num = 7;
	return num--;
}
int main()
{
	for(r();r();r())
		printf("%d",r());
//	float sum=0.0 , j=1.0, i=2.0;
//	while(i/j>0.0625)
//	{
//		j = j+j;
//		sum = sum + i/j;
//		printf("%f\t",sum);
//	}
	//	int a[]={2,4,6,8,10};
//	int i, sum = 0,*b = a+4;
//	for (i=0;i<5;i++)
//		sum+= (*b-i)-*(b-i);
//	printf("%d\n",sum);
	return 0;
}
