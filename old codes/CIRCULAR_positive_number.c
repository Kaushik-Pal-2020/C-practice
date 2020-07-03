#include<stdio.h>

int total_digits(unsigned long long* temp)
{
	int count = 0; 
    while (*temp) { 
        count++; 
        *temp /= 10; 
    } 
    return count;
}

int isCircular(unsigned long long* value,int* n)
{
	int arr[11],arr2[11];
	unsigned long long value2 = (*value)*(*n);
	int i,base=10,count=0;
	for(i=0;i<=total_digits(value);i++,base*=10)
	{
		arr[i]=*value/base;
	}
	base = 10;
	for(i=0;i<=total_digits(&value2);i++,base*=10)
	{
		arr2[i]=value2/base;
		count++;
	}
	i=0;
	while(i<count)
	{
		if(arr2[0]==*n)
		{
			if(arr2[i+1]!=arr[i])
				return 0;
			i++;	
		}
		return 0;
	}
	return 1;
}

unsigned long long Base_function(int n)
{
	unsigned long long i=n;
	while(1)
	{
		if (1==isCircular(&i,&n))
			return i;
		i++;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%llu",Base_function(n));
	return 0;
}
