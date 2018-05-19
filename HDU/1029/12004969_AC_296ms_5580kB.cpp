#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n,i,t,s;
    int a[1000000];
    while(~scanf("%d",&n))
    {
        t=n/2+1;
       for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       sort(a,a+n);
       s=1;
       for(i=1;i<n;i++)
       {
           if(a[i]==a[i-1]) s++;
           else s=1;
           if(s==t) {printf("%d\n",a[i]);break;}
       }
    }
}
