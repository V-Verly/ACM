#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod=1e9+7;

int main()
{
    int n,a,b,dp[2];
    dp[0]=1,dp[1]=0;
    scanf("%d",&n);
    for(int i=2; i<=n; i++)
    {
        a=dp[0]%mod;
        dp[0]=(a*2%mod+dp[1])%mod;
        dp[1]=(a*2%mod+a)%mod;
    }
    printf("%d\n",dp[1]);
    return 0;
}
