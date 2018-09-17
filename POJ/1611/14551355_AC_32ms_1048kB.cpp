#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=3e4+10;
int pre[maxn];

int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
        pre[fx]=fy;
}

int main()
{
    int n,m,k,x,y;
    while(scanf("%d%d",&n,&m)!=EOF&&(n||m))
    {
        for(int i=0;i<n;i++)
            pre[i]=i;
        int ans=0;
        while(m--)
        {
            scanf("%d%d",&k,&x);
            for(int i=1;i<k;i++)
            {
                scanf("%d",&y);
                Union(x,y);
            }
        }
        for(int i=0;i<n;i++)
            if(Find(i)==Find(0)) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
