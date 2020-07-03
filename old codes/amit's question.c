#include<stdio.h>
#include<stdlib.h>
void rational(int q,int e)
{
	if (q%e==0)
	{
		printf("%d ",q-1);
		return;
	}
	printf("%d ",q/e);
	rational(e,q%e);
}
int main()
{
	int q,e;
	scanf("%d %d",&q,&e);
	rational(q,e);
	system("PAUSE");
	return 0;
}
