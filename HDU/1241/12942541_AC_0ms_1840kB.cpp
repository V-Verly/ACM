#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dx[8]= {-1,0,1,-1,1,-1,0,1};
int dy[8]= {-1,-1,-1,0,0,1,1,1};
char oil[105][105];
int m,n,ans;

void BFS(int x,int y)
{
    for(int i=0; i<8; i++)
        if(x+dx[i]>=0&&x+dx[i]<m&&y+dy[i]>=0&&y+dy[i]<n&&oil[x+dx[i]][y+dy[i]]=='@')
        {
            oil[x+dx[i]][y+dy[i]]='*';
            BFS(x+dx[i],y+dy[i]);

        }
}

int main()
{
    while(scanf("%d%d",&m,&n)!=EOF&&m)
    {
        for(int i=0; i<m; i++)
            scanf("%s",oil[i]);
        ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(oil[i][j]=='@'){
                    oil[i][j]='*';
                    ans++;
                    BFS(i,j);
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}
