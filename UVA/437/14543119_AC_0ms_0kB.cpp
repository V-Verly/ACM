#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct block
{
    int length,width,height;
}b[200];

bool cmp(const block &a,const block &b)
{
    if(a.length==b.length) return a.width<b.width;
    return a.length<b.length;
}

void Set(int x,int y,int z,int t)
{
    b[t].length=x,b[t].width=y,b[t++].height=z;
    b[t].length=x,b[t].width=z,b[t++].height=y;
    b[t].length=y,b[t].width=x,b[t++].height=z;
    b[t].length=y,b[t].width=z,b[t++].height=x;
    b[t].length=z,b[t].width=x,b[t++].height=y;
    b[t].length=z,b[t].width=y,b[t++].height=x;
}

int main()
{
    int n,m,x,y,z,count=0,dp[200];
    while(scanf("%d",&n)!=EOF&&n)
    {
        m=6*n;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            Set(x,y,z,i*6);
        }
        sort(b,b+m,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            dp[i]=b[i].height;
            for(int j=0;j<i;j++)
                if(b[j].length<b[i].length&&b[j].width<b[i].width)
                    dp[i]=max(dp[i],dp[j]+b[i].height);
        }
        int sum=0;
        for(int i=0;i<m;i++)
            sum=max(dp[i],sum);
        printf("Case %d: maximum height = %d\n",++count,sum);
    }
    return 0;
}
