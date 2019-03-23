#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;
const int maxm=5e5+10;

int pre[maxn],cnt[maxn];
bool mark[maxn];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

struct Edge
{
    int u,v;
}es[maxm];

bool cmp(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    int u,v,n,m,k,x[1050];
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&x[i]);
        mark[x[i]]=true;
    }
    for(int i=1;i<=n;i++) pre[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&es[i].u,&es[i].v);
        u=es[i].u,v=es[i].v;
        if(!mark[u]&&!mark[v]) continue;
        if(mark[u]) swap(u,v);
        int fx=Find(u),fy=Find(v);
        if(fx!=fy) pre[fx]=fy;
    }
    for(int i=0;i<m;i++)
    {
        u=es[i].u,v=es[i].v;
        int fx=Find(u),fy=Find(v);
        if(fx==fy) continue;
        if(mark[fx]||mark[fy])
        {
            if(mark[fx]) pre[fy]=fx;
            else pre[fx]=fy;
        }
        else if(fx!=fy) pre[fx]=fy;
    }
    int ss=0;
    for(int i=1;i<=n;i++) cnt[Find(i)]++;
    for(int i=1;i<=n;i++) if(i==Find(i)&&!mark[Find(i)]) ss+=cnt[Find(i)];
    vector<int> res;
    for(int i=1;i<=n;i++) if(i==Find(i)&&mark[Find(i)]) res.push_back(cnt[i]);
    sort(res.begin(),res.end(),cmp);
    res[0]+=ss;
    long long ans=0;
    for(int r:res) ans+=1ll*r*(r-1)/2;
    ans-=m;
    printf("%lld\n",ans);
    return 0;
}
