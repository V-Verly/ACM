#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n;
char a[105][105];
int dx[8]={-1,0,1,-1,1,-1,0,1};
int dy[8]={1,1,1,0,0,-1,-1,-1};
int sum(int x,int y)
{
    int ans=0;
    for(int i=0;i<8;i++)
    {
        int fx=x+dx[i],fy=y+dy[i];
        if(fx>=0&&fx<n&&fy>=0&&fy<m)
        {
            if(a[fx][fy]=='*') ans++;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    int tmp;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='*') continue;
            if(a[i][j]=='.') tmp=0;
            else tmp=a[i][j]-'0';
            if(tmp!=sum(i,j)) flag=false;
        }
    }
    printf("%s\n",flag?"YES":"NO");
    return 0;
}
