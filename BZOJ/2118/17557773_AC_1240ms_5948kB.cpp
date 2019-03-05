#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn=5e5+10;
const int inf=0x3f3f3f3f;

int n,a[15],mod=inf;
long long dis[maxn];
bool vis[maxn]={0};

void spfa()
{
    for(int i=0;i<mod;i++) dis[i]=1e18;
    queue<int> que;
    que.push(0);
    dis[0]=0;
    vis[0]=true;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=0;i<n;i++)
        {
            int y=(u+a[i])%mod;
            if(dis[y]>dis[u]+a[i])
            {
                dis[y]=dis[u]+a[i];
                if(!vis[y])
                {
                    que.push(y);
                    vis[y]=true;
                }
            }
        }
    }
}

long long query(long long lim)
{
    long long ans=0;
    for(int i=0;i<mod;i++)
        if(dis[i]<=lim) ans+=(lim-dis[i])/mod+1;
    return ans;
}

int main()
{
    long long b1,b2;
    scanf("%d%lld%lld",&n,&b1,&b2);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(!a[i]) {
            i--; n--;
            continue;
        }
        mod=min(a[i],mod);
    }
    spfa();
    printf("%lld\n",query(b2)-query(b1-1));
    return 0;
}
