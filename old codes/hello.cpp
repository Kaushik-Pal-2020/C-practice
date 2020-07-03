#include<iostream>
#include<cmath>
using namespace std;
long fact(long num)
{
    long value2=1;
    if(num!=0){
    for(int i=1;i<=num;i++)
    {
        value2=value2*i;
    }
    return value2;
    }
}
int main()
{
    char val[6];
    long ans=0;
    cout<<"u can get any value of sinx"<<endl;
    cin>>val;
    if(val[0]=='s')
    {
        bool flag=0;
        long num1,num2,num3;
        num1=val[3]-48;
        num2=val[4]-48;
        num3=(10*num1)+num2;
        long y0=1;
        for(int i=0;i<10;i++,y0+=2)
        {
            if(flag==0)
            {
                ans+=(pow(num3,y0)/fact(y0));
                flag=1;

            }
            else
            {
                ans-=(pow(num3,y0)/fact(y0));
                flag=0;
            }
        }

    }
    cout<<"value = "<<ans<<endl;
    system("pause");
}