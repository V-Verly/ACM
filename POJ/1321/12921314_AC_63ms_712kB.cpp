#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long ans;
int n,k;
char a[9][9];
int vis[9];
void DFS(int line,int cur)
{
    if(cur==k) {ans++;return;}
    if(line==n) return;
    DFS(line+1,cur);
    for(int i=0;i<n;i++)
    {
        if(a[line][i]=='#'&&!vis[i])
        {
            vis[i]=1;
            DFS(line+1,cur+1);
            vis[i]=0;
        }
    }
    return;
}

int main()
{
    int i;
    while(scanf("%d%d",&n,&k)!=EOF&&n!=-1&&k!=-1)
    {
        for(i=0;i<n;i++)
            scanf("%s",a[i]);
        memset(vis,0,sizeof(vis));
        ans=0;
        DFS(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
