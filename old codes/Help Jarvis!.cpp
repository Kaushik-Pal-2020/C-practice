#include<iostream>
#include<string>
using namespace std;
int main()
{
    string aa,bb;
    cin>>aa>>bb;
    bool flag=0;
    if(strlen(aa)>=strlen(bb))
    flag=1;
    for(auto it:aa)
    {
        while(auto it2=bb.begin();it2!=bb.end();it2++)
        {
             if(aa.at(it)!=bb.at(it2))
             {
                 
             }

        }


    }
    system("pause");
    
}