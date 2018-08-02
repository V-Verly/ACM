#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

const int maxn=1e5+10;

vector <int> tree[maxn];

int N,cnt,p[maxn],dep[maxn],fa[maxn][18];

void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    fa[u][0]=pre;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v!=pre)
        dfs(v,u);
    }
}

void init()
{
    for(int i=1;(1<<i)<=N;i++)
        for(int u=1;u<=N;u++)
            fa[u][i]=fa[fa[u][i-1]][i-1];
}

int LCA(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;(1<<i)<=d;i++)
        if((1<<i)&d) u=fa[u][i];
    if(u==v) return u;
    for(int i=(int)log(N);i>=0;i--)
    {
        if(fa[u][i]!=fa[v][i])
        {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}

int main()
{
    int t,m,root;
    string u,v;
    map<string,int> mp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&N,&m);
        for(int i=0;i<=N;i++)
        {
            tree[i].clear();
            p[i]=dep[i]=0;
        }
        memset(fa,0,sizeof(fa));
        cnt=0;
        mp.clear();
        for(int i=1;i<N;i++)
        {
            cin>>u>>v;
            if(!mp.count(u)) mp[u]=++cnt;
            if(!mp.count(v)) mp[v]=++cnt;
            tree[mp[u]].push_back(mp[v]);
            tree[mp[v]].push_back(mp[u]);
            p[mp[u]]=mp[v];
        }
        for(int i=1;i<=N;i++)
            if(!p[i]) root=i;
        dfs(root,0);
        init();
        while(m--)
        {
            cin>>u>>v;
            root=LCA(mp[u],mp[v]);
            int ans=0,pos=mp[u];
            while(pos!=root) pos=p[pos],ans++;
            if(mp[v]!=pos) ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
