#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1e6+10;
vector <int> tree[maxn];
int N,dp1[maxn],dp2[maxn];

void dfs(int u,int pre)
{
    int sum=0;
    int mx=0,smx=0,mxid=-1,smxid=-1;
    for(int i=0;i<tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==pre) continue;
        dfs(v,u);
        sum+=dp2[v]+2;
        int tmp=dp2[v]+2-dp1[v];
        if(tmp>smx)
        {
            smx=tmp;
            smxid=v;
            if(smx>mx)
            {
                swap(smx,mx);
                swap(smxid,mxid);
            }
        }
    }
    dp1[u]=sum-mx;
    dp2[u]=dp1[u]-smx;
}

int main()
{
    int t,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(int i=0;i<=N;i++)
            tree[i].clear();
        for(int i=1;i<N;i++)
        {
            scanf("%d%d",&u,&v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1,0);
        printf("%d\n",dp2[1]+1);
    }
    return 0;
}
