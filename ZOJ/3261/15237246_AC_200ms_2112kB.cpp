#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn=1e4+10;
int val[maxn],pre[maxn],mx[maxn],mxid[maxn];

struct Query
{
    int op,u,v;
}query[50000+10];

struct Un
{
    int u,v;
}un[20000+10];

int Find(int x) {return x==pre[x]?x:pre[x]=Find(pre[x]); }

void Union(int a,int b)
{
    int x=Find(a),y=Find(b);
    if(x==y) return;
    pre[x]=y;
    if(mx[x]>mx[y]||mx[x]==mx[y]&&mxid[x]<mxid[y])
    {
        mx[y]=mx[x];
        mxid[y]=mxid[x];
    }
}

int main()
{
    int n,m,u,v,q,kase=0;
    char op[10];
    while(scanf("%d",&n)!=EOF)
    {
        if(kase++) printf("\n");
        map<int,int> mp[maxn];
        for(int i=0;i<n;i++)
        {
            pre[i]=mxid[i]=i;
            scanf("%d",&val[i]);
            mx[i]=val[i];
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            if(u>v) swap(u,v);
            mp[u][v]=1;
            un[i].u=u;
            un[i].v=v;
        }
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%s",op);
            if(op[0]=='q')
            {
                query[i].op=0;
                scanf("%d",&u);
                query[i].u=u;
            }
            else
            {
                query[i].op=1;
                scanf("%d%d",&u,&v);
                if(u>v) swap(u,v);
                query[i].u=u;
                query[i].v=v;
                mp[u].erase(v);
            }
        }
        for(int i=1;i<=m;i++)
        {
            u=un[i].u,v=un[i].v;
            if(mp[u].count(v)) Union(u,v);
        }
        for(int i=q;i>0;i--)
        {
            int op=query[i].op,u=query[i].u;
            if(op==1)
            {
                v=query[i].v;
                Union(u,v);
            }
            else
            {
                int x=Find(u);
                //printf("%d %d\n",x,u);
                if(mx[x]>val[u]) query[i].v=mxid[x];
                else query[i].v=-1;
            }

        }
        for(int i=1;i<=q;i++)
            if(!query[i].op) printf("%d\n",query[i].v);
    }
    return 0;
}
