#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char a[1005];

bool Palindrome(int l,int r)
{
    for(int i=0;i<=(r-l)/2;i++)
        if(a[l+i]!=a[r-i]) return false;
    return true;
}

int main()
{
    int n,len,dp[1005];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        len=strlen(a);
        for(int i=1;i<=len;i++)
            dp[i]=i;
        for(int i=1;i<=len;i++)
        {
            if(Palindrome(0,i-1))
                dp[i]=1;
            else
            {
                for(int j=0;j<i;j++)
                {
                    if(Palindrome(j,i-1))
                        dp[i]=min(dp[j]+1,dp[i]);
                }
            }
        }
        printf("%d\n",dp[len]);
    }
    return 0;
}
