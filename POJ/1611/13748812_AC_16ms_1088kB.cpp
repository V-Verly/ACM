#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=3*1e5+10;
int pre[maxn];

int Find(int x)
{
    if(x!=pre[x]) pre[x]=Find(pre[x]);
    return pre[x];
}

void join(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b) pre[a]=b;
}

int main()
{
    int m,n,k,u,v;
    while(scanf("%d%d",&n,&m)!=EOF&&(m||n))
    {
        for(int i=0;i<n;i++)
            pre[i]=i;
        while(m--)
        {
            scanf("%d",&k);
            scanf("%d",&u);
            k--;
            while(k--)
            {
                scanf("%d",&v);
                join(u,v);
            }
        }
        int ans=0;
        int y=Find(0);
        for(int i=0;i<n;i++)
            if(Find(i)==y) ans++;
        printf("%d\n",ans);

    }
    return 0;
}
