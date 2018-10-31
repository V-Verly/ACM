#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;
int pre[maxn],dis[maxn],color[maxn]={0};
long long sum[maxn]={0},cnt[maxn]={0};

int main()
{

    int n,m,u,v,w,op;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=1;i<n;i++)
        scanf("%d",&dis[i]);
    pre[0]=-1;
    while(m--)
    {
        scanf("%d%d",&op,&u);
        if(op==1)
        {
            long long d=0;
            if(color[u]) continue;
            color[u]=1;
            while(~u)
            {
                cnt[u]++;
                sum[u]+=d;
                d+=dis[u];
                u=pre[u];
            }
        }
        else
        {
            long long ans=sum[u],d=0;
            while(~pre[u])
            {
                d+=dis[u];
                ans+=sum[pre[u]]-sum[u]+d*(cnt[pre[u]]-cnt[u])-dis[u]*cnt[u];
                u=pre[u];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}