#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1000+10;
const int mod=31011;

struct Edge {int u,v,w;}edge[maxn];
struct Data {int l,r,s;}data[maxn];

bool cmp(const Edge &a,const Edge &b) {return a.w<b.w; }

int pre[maxn],sum;

int Find(int x) {return x==pre[x]?x:Find(pre[x]); }

void dfs(int x,int pos,int cnt)
{
    if(pos==data[x].r+1)
    {
        if(cnt==data[x].s) sum++;
        return;
    }
    int fx=Find(edge[pos].u),fy=Find(edge[pos].v);
    if(fx!=fy)
    {
        pre[fx]=fy;
        dfs(x,pos+1,cnt+1);
        pre[fx]=fx,pre[fy]=fy;
    }
    dfs(x,pos+1,cnt);
}

int main()
{
    int n,m,cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    for(int i=1;i<=n;i++) pre[i]=i;
    sort(edge,edge+m,cmp);
    int tot=0;
    for(int i=0;i<m;i++)
    {
        if(i==0||edge[i].w>edge[i-1].w) data[++cnt].l=i,data[cnt-1].r=i-1;
        int fx=Find(edge[i].u),fy=Find(edge[i].v);
        if(fx!=fy) {pre[fx]=fy; data[cnt].s++; tot++; }
    }
    data[cnt].r=m-1;
    if(tot!=n-1) return 0*printf("0\n");
    int ans=1;
    for(int i=1;i<=n;i++) pre[i]=i;
    for(int i=1;i<=cnt;i++)
    {
        sum=0;
        dfs(i,data[i].l,0);
        (ans*=sum)%=mod;
        for(int pos=data[i].l;pos<=data[i].r;pos++)
        {
            int fx=Find(edge[pos].u),fy=Find(edge[pos].v);
            if(fx!=fy) pre[fx]=fy;
        }
    }
    printf("%d\n",ans);
    return 0;
}
