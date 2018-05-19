#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2*1e5+10;
int pre[maxn],val[maxn];

int Find(int x)
{
    int tmp=pre[x]==x?x:Find(pre[x]);
    val[x]+=val[pre[x]];
    return pre[x]=tmp;
}

bool join(int x,int y,int k)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return val[x]+k==val[y];
    else if(fx<fy)
    {
        pre[fy]=fx;
        val[fy]=val[x]-val[y]+k;
    }
    else
    {
        pre[fx]=fy;
        val[fx]=val[y]-val[x]-k;
    }
    return true;
}

int main()
{
    int n,m,a,b,s;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n;i++)
            pre[i]=i,val[i]=0;
        int ans=0;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&s);
            if(!join(a-1,b,s)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
