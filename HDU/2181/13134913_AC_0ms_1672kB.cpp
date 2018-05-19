#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int road[25][25],vis[25],a[25],ans=0,s;

void DFS(int x,int cur)
{
    a[cur]=x;
    if(cur==19)
    {
        if(road[x][s]){
        printf("%d: ",++ans);
        for(int i=0;i<20;i++)
            printf(" %d",a[i]);
        printf(" %d\n",a[0]);
        }
        return;
    }
    for(int i=1;i<=20;i++)
    {
        if(!vis[i]&&road[x][i])
        {
            vis[i]=1;
            DFS(i,cur+1);
            vis[i]=0;
        }
    }
}

int main()
{
    int i,a,b,c;
    memset(road,0,sizeof(road));
    for(i=1;i<=20;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        road[i][a]=1;
        road[i][b]=1;
        road[i][c]=1;

    }
    while(scanf("%d",&s)!=EOF&&s)
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        vis[s]=1;
        DFS(s,0);
    }
    return 0;
}
