#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2e4+10;

int n,m,k,pre[maxn];

struct Edge {int u,v,w1,w2; }edge[maxn];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

bool Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return false;
    pre[fx]=fy;
    return true;
}

bool check(int x)
{
    for(int i=1;i<=n;i++) pre[i]=i;
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(edge[i].w1>x) continue;
        if(Union(edge[i].u,edge[i].v)) cnt++;
        if(cnt==k) break;
    }
    if(cnt<k) return false;
    for(int i=0;i<m;i++)
    {
        if(edge[i].w2>x) continue;
        if(Union(edge[i].u,edge[i].v)) cnt++;
    }
    return cnt==n-1;
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    m--;
    for(int i=0;i<m;i++)
        scanf("%d%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w1,&edge[i].w2);
    int l=0,r=30000,mid,ans;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
