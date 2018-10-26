#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF=0x3f3f3f3f;

char s[210][210];
int vis[210][210];
int n,m,cnt,id[20][2];
int dx[4]={-1,1,-1,1};
int dy[4]={1,1,-1,-1};

bool check(int x,int y)
{
    return x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='#';
}

bool solve(int flag,int mark)
{
    for(int i=0;i<cnt;i++)
    {
        int x=id[i][0],y=id[i][1];
        if(vis[x][y]!=mark) vis[x][y]=0;
    }
    for(int i=0;i<cnt;i++)
    {
        int x=id[i][0],y=id[i][1];
        if((flag>>i)&1)
        {
            if(check(x-1,y)||check(x,y+1))
                return false;
            if(!vis[x][y]) vis[x][y]=1;
            if(x-1>=0&&!vis[x-1][y]) vis[x-1][y]=1;
            if(y+1<m&&!vis[x][y+1]) vis[x][y+1]=1;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        int x=id[i][0],y=id[i][1];
        if(!vis[x][y]) return false;
    }
    return true;
}

int getnum(int x)
{
    int ans=0;
    while(x)
    {
        if(x%2) ans++;
        x/=2;
    }
    return ans;
}

int main()
{

    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
    {
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        cnt=0;
        int ans=INF;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='.')
                {
                    id[cnt][0]=i;
                    id[cnt++][1]=j;
                }
            }
        }
        if(!cnt) {printf("0\n"); continue;}
        int lim=(1<<cnt);
        int mark=20;
        for(int i=0;i<cnt;i++)
        {
            int x=id[i][0],y=id[i][1];
            for(int j=0;j<4;j++)
            {
                memset(vis,0,sizeof vis);
                if(check(x+dx[j],y)||check(x,y+dy[j])) continue;
                vis[x][y]=mark+i;
                if(x+dx[j]>=0&&x+dx[j]<n) vis[x+dx[j]][y]=mark+i;
                if(y+dy[j]>=0&&y+dy[j]<m) vis[x][y+dy[j]]=mark+i;
                for(int k=0;k<lim;k++)
                {
                    if((k>>i)&1) continue;
                    if(solve(k,mark+i)) ans=min(ans,getnum(k)+1);
                }
            }
        }
        if(ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
