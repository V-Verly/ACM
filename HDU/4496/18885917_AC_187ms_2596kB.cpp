#include <bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

struct edge{int u,v; }es[maxn];
int ans[maxn];

int pre[maxn];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m;i++)
            scanf("%d%d",&es[i].u,&es[i].v);
        int cnt=n;
        for(int i=0;i<n;i++) pre[i]=i;
        for(int i=m-1;i>=0;i--)
        {
            ans[i]=cnt;
            int fx=Find(es[i].u),fy=Find(es[i].v);
            if(fx!=fy)
            {
                pre[fx]=fy;
                cnt--;
            }
        }
        for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
