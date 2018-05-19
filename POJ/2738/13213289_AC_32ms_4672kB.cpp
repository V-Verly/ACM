#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,i,a[1005],dp[1005][1005];

int solve(int st,int en)
{
    if(dp[st][en]==0){
        if(st+1==en)
            return dp[st][en]=max(a[st],a[en]);
        int t1=a[st],t2=a[en];
        if(a[st+1]>=a[en])
            t1+=solve(st+2,en);
        else
            t1+=solve(st+1,en-1);
        if(a[st]>=a[en-1])
            t2+=solve(st+1,en-1);
        else
            t2+=solve(st,en-2);
        dp[st][en]=max(t1,t2);
        return dp[st][en];
    }
    return dp[st][en];
}

int main()
{
    int count=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int sum=0,ans,r;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }

        memset(dp,0,sizeof(dp));
        ans=solve(0,n-1);
        r=ans-sum+ans;
        printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++count,r);
    }
    return 0;
}
