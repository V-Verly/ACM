#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1e5+10;

struct Edge
{
    int u,v,w;
    bool operator <(const Edge e) const {
        return w<e.w;
    }
}edge[maxn];

int pre[305];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

bool Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return false;
    pre[fx]=fy;
    return true;
}

int main()
{
    int n,m,u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    sort(edge,edge+m);
    printf("%d ",n-1);
    for(int i=1;i<=n;i++) pre[i]=i;
    for(int i=0,cnt=0;i<m;i++)
    {
        if(Union(edge[i].u,edge[i].v)) cnt++;
        if(cnt==n-1)
        {
            printf("%d\n",edge[i].w);
            break;
        }
    }
    return 0;
}
