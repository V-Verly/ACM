#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int pre[1005];

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
    int n,x[1005],y[1005],u,v;
    bool repaired[1005];
    long long dis,d;
    char op[5];
    for(int i = 1;i < 1005; i++)  pre[i]=i;
    memset(repaired,false,sizeof(repaired));
    scanf("%d%lld",&n,&d);
    for(int i = 1; i <= n; i++)
        scanf("%d%d",&x[i],&y[i]);
    while(scanf("%s",op)!=EOF)
    {
        if(op[0]=='O')
        {
            scanf("%d",&u);
            repaired[u]=true;
            for(int i = 1; i <= n; i++)
            {
                if(u!=i&&repaired[i])
                {
                    dis=(x[i]-x[u])*(x[i]-x[u])+(y[i]-y[u])*(y[i]-y[u]);
                    if(dis<=d*d)
                        join(u,i);
                }
            }
        }
        else
        {
            scanf("%d%d",&u,&v);
            int a=Find(u),b=Find(v);
            printf("%s\n",a==b?"SUCCESS":"FAIL");
        }
    }
    return 0;
}
