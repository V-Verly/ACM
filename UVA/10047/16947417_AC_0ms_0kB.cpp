/*************************************************************************
	> File Name: 10047.cpp
	> Author: Verly
	> Mail: Verly0206@gmail.com
	> Created Time: 2018年11月10日 星期六 14时45分48秒
 ************************************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int m,n,ex,ey;
char mp[30][30];
bool vis[30][30][6][6];

struct node {
	int x,y,color,dir,step;
};

bool check(int x,int y,int col,int dir)
{
	if(x<0||x>=n||y<0||y>=m) return false;
	if(vis[x][y][col][dir]) return false;
	return mp[x][y]!='#';
}

void bfs(int x,int y)
{
	queue<node> que;
	que.push({x,y,0,0,0});
	int fx,fy;
	while(!que.empty())
	{
		node t=que.front();
		que.pop();
		if(t.x==ex&&t.y==ey&&t.color==0) {
			printf("minimum time = %d sec\n",t.step);
			return;
		}
		if(t.dir==0) fx=t.x-1,fy=t.y;
		else if(t.dir==1) fx=t.x,fy=t.y-1;
		else if(t.dir==2) fx=t.x+1,fy=t.y;
		else if(t.dir==3) fx=t.x,fy=t.y+1;
		if(check(fx,fy,(t.color+1)%5,t.dir)) {
			vis[fx][fy][(t.color+1)%5][t.dir]=1;
			que.push({fx,fy,(t.color+1)%5,t.dir,t.step+1});
		}
		if(check(t.x,t.y,t.color,(t.dir+1)%4)) {
			vis[t.x][t.y][t.color][(t.dir+1)%4];
			que.push({t.x,t.y,t.color,(t.dir+1)%4,t.step+1});
		}
		if(check(t.x,t.y,t.color,(t.dir+3)%4)) {
			vis[t.x][t.y][t.color][t.dir]=1;
			que.push({t.x,t.y,t.color,(t.dir+3)%4,t.step+1});
		}
	}
	printf("destination not reachable\n");
}

int main()
{
	int x,y,_=0;
	while(scanf("%d%d",&n,&m)!=EOF&&(n&&m))
	{
		for(int i=0;i<n;i++)
			scanf("%s",mp[i]);
		memset(vis,0,sizeof vis);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(mp[i][j]=='S') x=i,y=j;
				else if(mp[i][j]=='T') ex=i,ey=j;
		if(_++) printf("\n");
		printf("Case #%d\n",_);
		bfs(x,y);
	}
	return 0;
}