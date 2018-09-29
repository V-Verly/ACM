#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=4e4+10;
long long dp[maxn];

int main()
{
    int t,n,x,sum;
    double p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf",&n,&p);
        double r=1;
        for(int i=0;i<n;i++) r*=2;
        r*=p;
        sum=0;
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(int j=sum;j>=0;j--)
                if(dp[j]) dp[j+x]+=dp[j];
            sum+=x;
        }
        long long s=0;
        for(int i=0;i<=sum;i++)
        {
            s+=dp[i];
            if(s>=r)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
