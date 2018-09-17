#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

bool vis[30];
int a[30],n;

bool isprime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0) return false;
    return true;
}

void dfs(int dep,int x)
{
    a[dep]=x;
    if(dep==n&&isprime(1+x))
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]&&isprime(i+x))
        {
            vis[i]=true;
            dfs(dep+1,i);
            vis[i]=false;
        }
    }
}

int main()
{
    int count=0;
    while(scanf("%d",&n)!=EOF)
    {
        printf("Case %d:\n",++count);
        memset(vis,0,sizeof(vis));
        vis[1]=true;
        dfs(1,1);
        printf("\n");
    }
    return 0;
}
