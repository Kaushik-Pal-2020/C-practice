#include<stdio.h>
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,max_profit=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int s,p,v,tmp_profit;
            scanf("%d%d%d",&s,&p,&v);
            tmp_profit=(p/(s+1))*v;
            if(max_profit<tmp_profit)
            max_profit=tmp_profit;
        }
        printf("%d\n",max_profit);
    }
    return 0;
}