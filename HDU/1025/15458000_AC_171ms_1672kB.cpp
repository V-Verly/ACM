#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=5e5+10;

int p[maxn],dp[maxn];

int main()
{
    int n,a,b,cnt=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            p[a-1]=b-1;
        }
        int ans=0,tmp=0;
        for(int i=0;i<n;i++)
        {
            if(tmp==0||p[i]>dp[tmp-1])
            {
                dp[tmp++]=p[i];
                continue;
            }
            int pos=lower_bound(dp,dp+tmp,p[i])-dp;
            if(dp[pos]>p[i]) dp[pos]=p[i];
        }
        if(tmp==1)
            printf("Case %d:\nMy king, at most 1 road can be built.\n\n",++cnt);
        else
            printf("Case %d:\nMy king, at most %d roads can be built.\n\n",++cnt,tmp);
    }
    return 0;
}
