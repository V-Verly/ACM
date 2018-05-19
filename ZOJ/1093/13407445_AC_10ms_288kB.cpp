#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct block
{
    int length,width,height;
};

bool cmp(const block &a,const block &b)
{
    if(a.length==b.length) return a.width<b.width;
    return a.length<b.length;
}

int main()
{
    int n,i,a,b,c,dp[200],count=0;
    block t[200];
    while(scanf("%d",&n)!=EOF&&n)
    {
        int ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            t[ans].length=a,t[ans].width=b,t[ans++].height=c;
            t[ans].length=a,t[ans].width=c,t[ans++].height=b;
            t[ans].length=b,t[ans].width=a,t[ans++].height=c;
            t[ans].length=b,t[ans].width=c,t[ans++].height=a;
            t[ans].length=c,t[ans].width=a,t[ans++].height=b;
            t[ans].length=c,t[ans].width=b,t[ans++].height=a;
        }
        sort(t,t+ans,cmp);
        memset(dp,0,sizeof(dp));
        for(i=0;i<ans;i++)
        {
            dp[i]=t[i].height;

            for(int j=0;j<i;j++)
                if(t[j].length<t[i].length&&t[j].width<t[i].width)
                {
                   // printf("%d %d %d %d\n",t[i].length,t[i].width,t[j].length,t[j].width);
                  //  printf("%d %d\n",dp[i],dp[j]);
                    dp[i]=max(dp[i],t[i].height+dp[j]);

                }
        }
        int sum=0;
        for(i=0;i<ans;i++)
            sum=max(sum,dp[i]);
        printf("Case %d: maximum height = %d\n",++count,sum);
    }
    return 0;
}
