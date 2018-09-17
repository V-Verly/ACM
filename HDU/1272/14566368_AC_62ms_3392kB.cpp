#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int pre[maxn];
bool vis[maxn];

int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}

bool Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    vis[x]=vis[y]=true;
    if(fx==fy) return false;
    pre[fx]=fy;
    return true;
}

int main()
{
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF&&(x!=-1&&y!=-1))
    {
        if(!(x&&y))
        {
            printf("Yes\n");
            continue;
        }
        for(int i=1;i<maxn;i++)
            pre[i]=i,vis[i]=false;
        bool flag=true;
        Union(x,y);
        int root=y;
        while(scanf("%d%d",&x,&y)!=EOF&&(x&&y))
            if(!Union(x,y)) flag=false;
        for(int i=1;i<maxn;i++)
            if(vis[i]&&Find(i)!=Find(root)) flag=false;
        printf("%s\n",flag?"Yes":"No");
    }
    return 0;
}