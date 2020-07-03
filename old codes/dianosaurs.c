#include <stdio.h>

int main(void) {
    int T,N,K,starting_num=0,end_num=0;
    scanf("%d",&T);
    scanf("%d%d",&N,&K);
    starting_num=N-K-1;
    int i,j;
    for(i=0;i<K;i++)
    {
        end_num=N-K-1+i;
        printf("%d ",end_num);
    }
    printf("%d ",N);
    if(starting_num!=1)
    {
        for(j=1;j<starting_num;j++)
        printf("%d ",j);
    }
    if((N-end_num)!=1)
    {
        for(j=end_num+1;j<N;j++)
        printf("%d ",j);
    }
    
	// your code goes here
	return 0;
}