#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct mice{
int w,s,num;
};

bool cmp(const mice &a,const mice &b)
{
    if(a.w==b.w) return a.s>b.s;
    return a.w<b.w;
}

int main()
{
    mice m[1005];
    int n=0,w,s,dp[1005],pre[1005],path[1005];
    while(scanf("%d%d",&w,&s)!=EOF)
    {
        m[n].w=w;
        m[n].s=s;
        m[n].num=n+1;
        n++;
    }
    sort(m,m+n,cmp);
    int mx=-1;
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        pre[i]=i;
        //printf("%d %d\n",m[i].w,m[i].s);
        for(int j=0;j<i;j++)
        {
            if(m[j].w<m[i].w&&m[j].s>m[i].s&&dp[j]+1>dp[i])
            {
                dp[i]=dp[j]+1;
                pre[i]=j;
                //printf("%d %d\n",i,j);
            }
        }
        if(mx==-1||dp[i]>dp[mx]) mx=i;
        //printf("%d\n",m[pre[i]].num);
    }
    printf("%d\n",dp[mx]);
    int r=mx,i=0;
    //path[i++]=r;
    while(r!=pre[r])
    {
        path[i++]=m[r].num;
        r=pre[r];
    }
    printf("%d\n",m[r].num);
    i--;
    for(;i>=0;i--)
        printf("%d\n",path[i]);
    return 0;
}