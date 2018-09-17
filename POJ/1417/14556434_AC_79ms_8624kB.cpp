#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int maxn=1000+10;
int pre[maxn],val[maxn],dp[maxn][maxn],mark[maxn][maxn];

int Find(int x)
{
    if(x==pre[x]) return x;
    int tmp=Find(pre[x]);
    val[x]=val[x]^val[pre[x]];
    return pre[x]=tmp;
}

void Union(int x,int y,int w)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
    {
        pre[fx]=fy;
        val[fx]=val[x]^val[y]^w;
    }
}

int main()
{
    int n,p1,p2,x,y,v,a[maxn],w[maxn][2];
    char op[5];
    while(scanf("%d%d%d",&n,&p1,&p2)!=EOF&&(n||p1||p2))
    {
        int m=p1+p2,tot=0;
        for(int i=1;i<=m;i++)
            pre[i]=i,val[i]=a[i]=0;
        memset(dp,0,sizeof(dp));
        memset(mark,0,sizeof(mark));
        memset(w,0,sizeof(w));
        while(n--)
        {
            scanf("%d%d%s",&x,&y,op);
            v=op[0]=='y'?0:1;
            Union(x,y,v);
        }
        for(int i=1;i<=m;i++)
            if(Find(i)==i) a[i]=++tot;
        for(int i=1;i<=m;i++)
            w[a[pre[i]]][val[i]]++;
        dp[0][0]=1;
        for(int i=1;i<=tot;i++)
        {
            for(int j=0;j<=m;j++)
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
            for(int i=1;i<=m;i++)
                if(ans[a[pre[i]]][val[i]]) printf("%d\n",i);
            printf("end\n");
        }
        else printf("no\n");
    }
    return 0;
}
