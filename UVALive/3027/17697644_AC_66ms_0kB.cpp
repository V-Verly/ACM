#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn=2e4+10;

int pre[maxn],d[maxn];

int Find(int x)
{
    if(pre[x]==x) return x;
    int root=Find(pre[x]);
    d[x]+=d[pre[x]];
    return pre[x]=root;
}

int main()
{
    int t,n,u,v;
    char op[5];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) d[i]=0,pre[i]=i;
        while(scanf("%s",op)!=EOF&&op[0]!='O')
        {
            if(op[0]=='I') {scanf("%d%d",&u,&v); pre[u]=v; d[u]=abs(u-v)%1000; }
            if(op[0]=='E') {scanf("%d",&u); Find(u); printf("%d\n",d[u]); }
        }
    }
    return 0;
}
