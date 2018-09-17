#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int m,n;
char map[805][805];
int dx[4]= {1,0,-1,0};
int dy[4]= {0,1,0,-1};
int mx,my,gx,gy,zx[2],zy[2],step;
bool vis[2][805][805];
struct node {int x,y;};

inline bool Manhattan(node t)   //点t与两ghosts原点的曼哈顿距离，如果小于step×2，则该点已被ghosts覆盖
{
    return (abs(t.x-zx[0])+abs(t.y-zy[0])>2*step)&&(abs(t.x-zx[1])+abs(t.y-zy[1])>2*step);
}

queue <node> que[2];

bool BFS(int r)
{
    int ans=que[r].size();
    while(ans--)	//对上一步到达的所有点做BFS，将符合条件的点加入队列
    {
        node front=que[r].front();
        que[r].pop();
        if(Manhattan(front))
        {
            for(int i=0; i<4; i++)
            {
                node tmp;
                tmp.x=front.x+dx[i];
                tmp.y=front.y+dy[i];
                if(tmp.x>=0&&tmp.x<n&&tmp.y>=0&&tmp.y<m&&map[tmp.x][tmp.y]!='X'&&Manhattan(tmp)&&!vis[r][tmp.x][tmp.y])
                {
                    vis[r][tmp.x][tmp.y]=true;
                    if(vis[0][tmp.x][tmp.y]&&vis[1][tmp.x][tmp.y])  
                    //由于本题中任意一方可以不作移动，则如果一方到达另一方曾经到达且尚未被ghosts覆盖的一点，则可视为相遇
                        return true;
                    que[r].push(tmp);
                }
            }
        }
    }
    return false;
}

int solve()
{
    while(!que[0].empty())  que[0].pop();
    while(!que[1].empty())  que[1].pop();
    node st;
    st.x=mx;st.y=my;
    que[0].push(st);
    st.x=gx;st.y=gy;
    que[1].push(st);
    step=0;
    while(!(que[0].empty()&&que[1].empty()))
    {
        step++;       //ghosts首先移动
        for(int i=0; i<3; i++)		//每秒erriyue移动三次
            if(BFS(0))  return step;
        if(BFS(1))  return step;
    }
    return -1;
}

int main()
{
    int t,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
            scanf("%s",map[i]);
        k=0;
        memset(vis,false,sizeof(vis));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='M')
                {
                    mx=i;
                    my=j;
                    vis[0][i][j]=true;
                }
                else if(map[i][j]=='G')
                {
                    gx=i;
                    gy=j;
                    vis[1][i][j]=true;
                }
                else if(map[i][j]=='Z')
                {
                    zx[k]=i;
                    zy[k++]=j;
                }
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}