#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e7+10;
int pre[maxn],sum[maxn];
bool vis[maxn];

int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    vis[x]=vis[y]=true;
    if(fx!=fy)
        pre[fx]=fy;
}

int main()
{
    int n,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<maxn;i++)
            pre[i]=i,sum[i]=0,vis[i]=false;
        if(n==0)
        {
            printf("1\n");
            continue;
        }
        while(n--)
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        for(int i=1;i<maxn;i++)
            if(vis[i]) sum[Find(i)]++;
        int ans=0;
        for(int i=1;i<maxn;i++)
            ans=max(ans,sum[i]);
        printf("%d\n",ans);
    }
    return 0;
}