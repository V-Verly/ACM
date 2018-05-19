#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int pre[maxn];
bool vis[maxn];

int Find(int x)
{
    return pre[x]==x?x:(pre[x]=Find(pre[x]));
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
    int x,y,count=0;
    while(scanf("%d%d",&x,&y)!=EOF&&(x!=-1&&y!=-1))
    {
        if(x==0&&y==0)
        {
            printf("Case %d is a tree.\n",++count);
            continue;
        }
        for(int i=0;i<maxn;i++)
            vis[i]=false,pre[i]=i;
        bool flag=true;
        if(!Union(x,y)) flag=false;
        int root=y;
        while(scanf("%d%d",&x,&y)!=EOF&&(x&&y))
        {
            if(!Union(x,y)) flag=false;
        }
        for(int i=1;i<=maxn;i++)
            if(vis[i]&&Find(i)!=Find(root)) flag=false;
        if(flag)
            printf("Case %d is a tree.\n",++count);
        else
            printf("Case %d is not a tree.\n",++count);
    }
    return 0;
}
