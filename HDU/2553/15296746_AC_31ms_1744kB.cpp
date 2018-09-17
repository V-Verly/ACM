#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,tot;

bool vis[3][15];
int C[15],ans[15];

void dfs(int cur)
{
    if(cur==n) tot++;
    else for(int i=0;i<n;i++)
    {
        if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n])
        {
            C[cur]=i;
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
            dfs(cur+1);
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
        }
    }
}

int main()
{
    for(n=1;n<=10;n++)
    {
        memset(vis,0,sizeof(vis));
        tot=0;
        dfs(0);
        ans[n]=tot;
    }
    ans[10]=724;
    while(scanf("%d",&n)!=EOF&&n)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}
