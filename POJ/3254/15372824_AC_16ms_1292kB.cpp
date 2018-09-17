#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int mp[15],st[10000];
int dp[15][10000];

const int mod=1e8;

int main()
{
    int n,m,a;
    while(~scanf("%d%d",&n,&m))
    {
        memset(mp,0,sizeof(mp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&a);
                if(!a) mp[i]+=(1<<j);
            }
        }
        int cnt=0;
        for(int i=0;i<(1<<m);i++)
            if(!(i&(i<<1))) st[cnt++]=i;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<cnt;i++)
            if(!(mp[0]&st[i])) dp[0][i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                if(mp[i]&st[j]) continue;
                for(int k=0;k<cnt;k++)
                {
                    if(mp[i-1]&st[k]) continue;
                    if(!(st[j]&st[k])) dp[i][j]+=dp[i-1][k];
                }
            }
        }
        int ans=0;
        for(int i=0;i<cnt;i++)
            ans=(ans+dp[n-1][i])%mod;
        printf("%d\n",ans);
    }
    return 0;
}
