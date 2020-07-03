#include <bits/stdc++.h>
using namespace std;

int main() {
       int t;
       cin>>t;
       while(t--)
       {
              int n,k;
              cin>>n>>k;
              int a[n];
              for(int i=0;i<n;i++)
             a[i]=i+1;
             
            int l;
            l=a[n-1];
            a[n-1]=a[k];
            a[k]=l;
              for(int i=0;i<n;i++)
              cout<<a[i]<<" ";
              cout<<endl;
       }
	// your code goes here
	return 0;
}