#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[17][17];
int tmp[17][17],change[17][17];
int s[17][17],m,n;

int filp(int x,int y)
{
    change[x][y]=!change[x][y];
    if(x>0) change[x-1][y]=!change[x-1][y];
    if(x<n-1) change[x+1][y]=!change[x+1][y];
    if(y>0) change[x][y-1]=!change[x][y-1];
    if(y<m-1) change[x][y+1]=!change[x][y+1];
}

int solve()
{
    int ans=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(change[i-1][j])
            {
                filp(i,j);
                tmp[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(change[i][j]) return -1;
            ans+=tmp[i][j];
        }
    return ans;
}

int main()
{
    int i,j,ans,mn;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
        mn=-1;
        for(i=0;i<1<<m;i++)
        {
            memcpy(change,a,sizeof(a));
            memset(tmp,0,sizeof(tmp));
            for(j=0;j<m;j++)
            {
                if(i&(1<<j))
                {
                    tmp[0][j]=1;
                    filp(0,j);
                }
            }
            int t=solve();
            if(t!=-1) ans=t;
            if(t!=-1&&(mn==-1||ans<mn))
            {
                mn=ans;
                memcpy(s,tmp,sizeof(tmp));
            }
        }
        if(mn==-1) printf("IMPOSSIBLE\n");
        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(j) printf(" ");
                    printf("%d",s[i][j]);
                }
                printf("\n");
            }

        }
    }
    return 0;
}
