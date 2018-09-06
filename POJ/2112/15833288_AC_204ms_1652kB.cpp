#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=300+5;//左边最大点数
const int maxm=300+5;//右边最大点数
const int inf=0x3f3f3f3f;

int edge[maxn][maxm],graph[maxn][maxm],vis[maxm];//图G和增广路访问标记
int match[maxm][maxn];//左边元素与右边元素第n次匹配
int nx,ny,m;//左边点数，右边点数,边数
int limit;//右边点多重匹配可容纳值
int cnt[maxm];//右边点已匹配值

bool find_path(int u)//找增广路
{
    for(int i=0; i<ny; i++)//注意，这里节点是从0开始编号，题目有时是从1开始编号
    {
        if(graph[u][i] && !vis[i])//不在增广路
        {
            vis[i]=1;//放进增广路
            if(cnt[i]<limit)//如果当前已匹配数量小于可容纳量，则直接匹配
            {
                match[i][cnt[i]++]=u;
                return true;
            }
            for(int j=0; j<cnt[i]; j++)
            {
                if(find_path(match[i][j]))//如果先前已匹配右边的点能另外找到增广路，则此点仍可匹配
                {
                    match[i][j]=u;
                    return true;
                }
            }
        }
    }
    return false;
}

int max_match()//计算多重匹配的最大匹配数
{
    int res=0;
    memset(match,-1,sizeof(match));
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<nx; i++)
    {
        memset(vis,0,sizeof(vis));
        if(find_path(i)) res++;
    }
    return res;
}

bool all_match()//判断左边的点是否都与右边的点匹配了
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0; i<nx; i++)
    {
        memset(vis,0,sizeof(vis));
        if(!find_path(i)) return false;
    }
    return true;
}

int main()
{
    int w,u,v;
    while(scanf("%d%d%d",&ny,&nx,&limit)!=EOF)
    {
        for(int i=0;i<nx+ny;i++)
            for(int j=0;j<nx+ny;j++)
            {
                scanf("%d",&edge[i][j]);
                if(!edge[i][j]) edge[i][j]=inf;
            }

        for(int k=0;k<nx+ny;k++)
            for(int i=0;i<nx+ny;i++)
                for(int j=0;j<nx+ny;j++)
                    edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
        int l=0,r=inf,mid;
        while(l<r)
        {
            mid=(l+r)>>1;
            memset(graph,0,sizeof graph);
            for(int i=0;i<nx;i++)
            {
                for(int j=ny;j<nx+ny;j++)
                {
                    if(edge[i][j]<=mid) graph[j-ny][i]=1;
                }
            }
            max_match();
            if(all_match()) r=mid;
            else l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}
