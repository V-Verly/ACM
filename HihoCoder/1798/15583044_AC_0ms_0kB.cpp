#include <iostream>
using namespace std;

const int mod=1e9+7;

int main()
{
    int n;
    long long dp[1010][3]={0},ans=0;
    cin>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])*9%mod;
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1];
    }
    for(int i=1;i<=n-2;i++)
        ans=(ans+dp[i][1]*dp[n-i][2])%mod;
    cout<<ans<<endl;
    return 0;
}
