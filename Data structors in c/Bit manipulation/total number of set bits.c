#include<stdio.h>
unsigned short countSetBits(int);
unsigned int countSetBits_Brian(int); 
int main()
{
	int x = 1064813;
	int value = countSetBits(x);
	printf("No of set bits in %d = %d\n",x,value);
	return 0;
}
unsigned short countSetBits(int x)
{
	unsigned short count = 0;
	while(x)
	{
		if((x&x-1) != 0)
			count++;
		x = x>>1; 
	}
	return count;
}
/* Brian Kernighan’s Algorithm */
unsigned int countSetBits_Brian(int n) 
{ 
    unsigned int count = 0; 
    while (n) { 
        n &= (n - 1); 
        count++; 
    } 
    return count; 
} 

