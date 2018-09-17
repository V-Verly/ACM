#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;
int pre[maxn],val[maxn];

int Find(int x)
{
    int tmp=pre[x]==x?x:Find(pre[x]);
    val[x]+=val[pre[x]];
    return pre[x]=tmp;
}

bool Union(int x,int y,int w)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy)
        return val[x]+w==val[y];
    else if(fx<fy)
    {
        pre[fy]=fx;
        val[fy]=val[x]-val[y]+w;
    }
    else
    {
        pre[fx]=fy;
        val[fx]=val[y]-val[x]-w;
    }
    return true;
}

int main()
{
    int n,m,x,y,w;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            pre[i]=i,val[i]=0;
        int ans=0;
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&w);
            if(!Union(x-1,y,w)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
