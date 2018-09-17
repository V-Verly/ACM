#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e7+10;
bool vis[maxn];
int prime[700000],cnt=0;

void isprime()
{
    memset(vis,false,sizeof(vis));
    for(int i=2;i<=1e4;i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
            for(int j=i*i;j<=1e7;j+=i)
            {
                vis[j]=true;
            }
        }
    }
    for(int i=1e4+1;i<=1e7;i++)
        if(!vis[i]) prime[cnt++]=i;
}

int main()
{
    int t,n;
    isprime();
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<cnt;i++)
        {
            if(prime[i]>n/2) break;
            if(!vis[n-prime[i]])
                ans++;
        }
        printf("Case %d: %d\n",k,ans);
    }
    return 0;
}
