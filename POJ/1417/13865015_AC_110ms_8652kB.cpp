#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=1000+10;
int pre[maxn],val[maxn],dp[maxn][maxn],mark[maxn][maxn];

int Find(int x)
{
    if(pre[x]==x) return x;
    int tmp=Find(pre[x]);
    val[x]^=val[pre[x]];
    return pre[x]=tmp;
}

void Union(int x,int y,int w)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return;
    pre[fx]=fy;
    val[fx]=val[x]^val[y]^w;
}

int main()
{
    int n,p1,p2,x,y,t,a[maxn],w[maxn][2];
    char s[5];
    while(scanf("%d%d%d",&n,&p1,&p2)!=EOF&&(n||p1||p2))
    {
        for(int i=1;i<=p1+p2;i++)
            val[i]=a[i]=0,pre[i]=i;
        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        memset(mark,0,sizeof(mark));
        while(n--)
        {
            scanf("%d%d%s",&x,&y,s);
            t=s[0]=='y'?0:1;
            Union(x,y,t);
        }
        int tot=0;
        for(int i=1;i<=p1+p2;i++)
            if(Find(i)==i) a[i]=++tot;
        for(int i=1;i<=p1+p2;i++)
            w[a[pre[i]]][val[i]]++;
        dp[0][0]=1;
        for(int i=1;i<=tot;i++)
        {
            for(int j=0;j<=p1+p2;j++)
            {
                if(j>=w[i][0]&&dp[i-1][j-w[i][0]])
                {
                    dp[i][j]+=dp[i-1][j-w[i][0]];
                    mark[i][j]=w[i][0];
                }
                if(j>=w[i][1]&&dp[i-1][j-w[i][1]])
                {
                    dp[i][j]+=dp[i-1][j-w[i][1]];
                    mark[i][j]=w[i][1];
                }
            }
        }
        if(dp[tot][p1]==1)
        {
            bool ans[maxn][2]={false};
            for(int i=tot,j=p1;i&&j;i--)
            {
                if(mark[i][j]==w[i][0]) ans[i][0]=true;
                else ans[i][1]=true;
                j-=mark[i][j];
            }
            for(int i=1;i<=p1+p2;i++)
                if(ans[a[pre[i]]][val[i]]) printf("%d\n",i);
            printf("end\n");
        }
        else printf("no\n");
    }
    return 0;
}
