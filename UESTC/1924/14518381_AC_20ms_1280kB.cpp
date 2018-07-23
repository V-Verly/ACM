#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int pre[maxn],val[maxn];

int Find(int x)
{
    if(x==pre[x]) return x;
    int tmp=Find(pre[x]);
    val[x]+=val[pre[x]];
    return pre[x]=tmp;
}

void join(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b)
    {
        pre[a]=b;
        val[b]+=val[a];
    }
}

int main()
{
    int n,m,x,y,z,q;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        val[i]=1,pre[i]=i;
    while(m--)
    {
        scanf("%d%d",&x,&y);
        join(x,y);
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&z);
        printf("%d\n",val[Find(z)]);
    }
    return 0;
}
