#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int pre[maxn];

int Find(int x)
{
    if(pre[x]!=x) pre[x]=Find(pre[x]);
    return pre[x];
}

void join(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b) pre[a]=b;
}

int main()
{
    int t,m,n,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            pre[i]=i;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            join(u,v);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(Find(i)==i) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
