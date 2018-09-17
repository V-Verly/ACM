#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int pre[1000+10];

int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b)
        pre[a]=b;
}

int main()
{
    int t,n,m,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            pre[i]=i;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            Union(u,v);
        }
        int sum=0;
        for(int i=1;i<=n;i++)
            if(Find(i)==i) sum++;
        printf("%d\n",sum);
    }
    return 0;
}