#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int div2(int x)
{
    int ans=0;
    while(x%2==0)
    {
        x/=2;
        ans++;
    }
    return ans;
}

int div5(int x)
{
    int ans=0;
    while(x%5==0)
    {
        x/=5;
        ans++;
    }
    return ans;
}

int main()
{
    int n,m,i,j,k,s,a,t[105],f[105],dp[105][1005];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            t[i]=div2(a);
            f[i]=div5(a);
            s+=f[i];
        }
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;
        for(i=0;i<n;i++)
        {
            for(j=min(i+1,m);j>=0;j--)
                for(k=s;k>=0;k--)
                {
                    if(k>=f[i]&&j>=1&&dp[j-1][k-f[i]]!=-1) dp[j][k]=max(dp[j][k],dp[j-1][k-f[i]]+t[i]);
                    //printf("%d %d\n",k,dp[j][k]);
                }
        }
        int r=0;
        for(k=1;k<=s;k++)
            r=max(r,min(k,dp[m][k]));
        printf("%d\n",r);
    }
    return 0;
}
