#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int a[maxn],t[maxn],s[maxn]={0};

int main()
{
    int n,k,i,sum=0,ans;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
        if(t[i]) sum+=a[i];
    }
    for(i=0;i<k;i++)
    {
        if(!t[i]) s[k-1]+=a[i];
    }

    for(i=k;i<n;i++)
    {
        ans=s[i-1];
        if(!t[i-k]) ans-=a[i-k];
        if(!t[i]) ans+=a[i];
        s[i]=ans;
    }
    int mx=0;
    for(i=k-1;i<n;i++)
    {
       mx=max(mx,s[i]);
    }
       //
    sum+=mx;
    printf("%d\n",sum);
    return 0;
}
