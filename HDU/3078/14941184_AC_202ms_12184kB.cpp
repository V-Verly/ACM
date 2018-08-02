#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int maxn=80000+10;
int N,val[maxn],dep[maxn]={0},fa[maxn][20],p[maxn]={0};

vector<int> tree[maxn];

bool cmp(int a,int b){return a>b; }

void dfs(int u,int pre)
{
    dep[u]=dep[pre]+1;
    fa[u][0]=pre;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==pre) continue;
        p[v]=u;
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

void dfs1(int u,int pre)
{

}

int main()
{
    int q,a,b,c,u,v,root;
    scanf("%d%d",&N,&q);
    for(int i=1;i<=N;i++)
        scanf("%d",&val[i]);
    for(int i=1;i<N;i++)
    {
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for(int i=1;i<=N;i++)
        if(!p[i]) root=i;
    dfs(root,0);
    init();
    while(q--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a)
        {
            root=LCA(b,c);
            vector <int> chain;
            int g=b;
            while(g!=root) chain.push_back(val[g]),g=p[g];
            g=c;
            while(g!=root) chain.push_back(val[g]),g=p[g];
            chain.push_back(val[root]);
            if(chain.size()<a) printf("invalid request!\n");
            else
            {
                sort(chain.begin(),chain.end(),cmp);
                printf("%d\n",chain[a-1]);
            }
        }
        else val[b]=c;
    }
    return 0;
}
