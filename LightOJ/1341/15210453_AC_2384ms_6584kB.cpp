#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=1e6+10;
int prime[maxn],cnt=0;
bool vis[maxn];

void init()
{
    memset(vis,false,sizeof(vis));
    vis[1]=true;
    for(int i=2;i<=1e6;i++)
    {
        if(!vis[i]) prime[cnt++]=i;
        for(int j=0;j<cnt&&i*prime[j]<=1e6;j++)
        {
            vis[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}

long long sum(long long n)
{
    if(!n) return 0;
    long long ans=1;
    for(int i=0;i<cnt&&prime[i]<=n;i++)
    {
        int tmp=0;
        while(n%prime[i]==0)
        {
            n/=prime[i];
            tmp++;
        }
        ans*=tmp+1;
    }
    if(n>1) ans*=2;
    return ans;
}

int main()
{
    int t,kase=0;
    long long a,b,ans;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(b>=sqrt(a)) ans=0;
        else
        {
            long long tmp=0;
            for(int i=1;i<b;i++)
                if(a%i==0) tmp++;
            ans=sum(a)/2-tmp;
        }
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
