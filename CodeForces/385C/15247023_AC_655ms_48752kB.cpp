#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e7+10;
int cnt[maxn]={0};
bool vis[maxn];

void solve()
{
    memset(vis,0,sizeof(vis));
    vis[0]=vis[1]=true;
    for(int i=2;i<=maxn;i++)
    {
        if(!vis[i])
        {
            for(int j=i*2;j<maxn;j+=i)
            {
                vis[j]=true;
                cnt[i]+=cnt[j];
            }
        }
    }
    for(int i=0;i<maxn;i++)
    {
        if(vis[i]) cnt[i]=0;
        if(i) cnt[i]+=cnt[i-1];
    }
}

int main()
{
    int n,a,q,l,r,MX=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        cnt[a]++;
        MX=max(a,MX);
    }
    solve();
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&l,&r);
        l=min((int)1e7,l-1);
        r=min((int)1e7,r);
        printf("%d\n",cnt[r]-cnt[l]);
    }
    return 0;
}
