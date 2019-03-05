#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2000;

int lim,s[maxn]={0},c1[maxn]={0},c2[maxn][maxn]={0};
long long dp[10][2000][100]={0};

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    lim=(1<<n);
    for(int i=0;i<lim;i++)
    {
        if((i&(i>>1))==0)
        {
            c1[i]=1;
            for(int x=i;x;x>>=1)
                if(x&1) s[i]++;
            dp[1][i][s[i]]=1;
        }
    }
    for(int i=0;i<lim;i++)
    {
        if(c1[i])
            for(int j=0;j<lim;j++) if(c1[j])
                if(!(j&i)&&!((j<<1)&i)&&!((j>>1)&i)) c2[i][j]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<lim;j++)
        {
            for(int k=0;k<lim;k++)
            {
                if(c2[j][k])
                    for(int r=s[j];r+s[k]<=m;r++)
                    {
                        dp[i+1][k][r+s[k]]+=dp[i][j][r];
                    }

            }
        }
    }
    long long ans=0;
    for(int i=0;i<lim;i++) ans+=dp[n][i][m];
    printf("%lld\n",ans);
    return 0;
}
