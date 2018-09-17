#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[105];

bool judge(int x,int y)
{
    return s[x]=='('&&s[y]==')'||s[x]=='['&&s[y]==']';
}

int main()
{
    int n,dp[105][105];
    while(scanf("%s",s+1)!=EOF&&s[1]!='e')
    {
        n=strlen(s+1);
        memset(dp,0,sizeof(dp));
        for(int k=1;k<n;k++)
        {
            for(int l=1;l+k<=n;l++)
            {
                int r=l+k;
                if(judge(l,r)) dp[l][r]=dp[l+1][r-1]+2;
                for(int m=l+1;m<r;m++)
                    dp[l][r]=max(dp[l][r],dp[l][m]+dp[m][r]);
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
