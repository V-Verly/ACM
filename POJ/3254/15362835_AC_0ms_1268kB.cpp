#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[15][10000];
int st[10000];
int n,m,mp[15];

const int mod=1e8;

bool judge(int i,int x)
{
    return mp[i]&st[x];
}

int main()
{
    int a;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&a);
                if(!a) mp[i]+=(1<<(j-1));
            }
        }
        int k=0;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<(1<<m); i++)
            if(!(i&(i<<1))) st[k++]=i;
        for(int i=0; i<k; i++)
            if(!judge(1,i)) dp[1][i]=1;
        for(int i=2; i<=n; i++)
        {
            for(int j=0;j<k;j++)
            {
                if(judge(i,j)) continue;
                for(int r=0;r<k;r++)
                {
                    if(judge(i-1,r)) continue;
                    if(!(st[j]&st[r])) dp[i][j]+=dp[i-1][r];
                }
            }
        }
        int ans=0;
        for(int i=0;i<k;i++)
        {
            ans+=dp[n][i];
            ans%=mod;
        }
        printf("%d\n",ans);
    }


    return 0;
}
