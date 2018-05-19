#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct pots{
int a,b;
int step;
int r;
int prea,preb;
};
int vis[105][105];
pots s[105][105];
void print(int a,int b)
{
    if(a==0&&b==0)  return;
    print(s[a][b].prea,s[a][b].preb);
    if(s[a][b].r==1) printf("FILL(1)\n");
    else if(s[a][b].r==2) printf("FILL(2)\n");
    else if(s[a][b].r==3) printf("DROP(1)\n");
    else if(s[a][b].r==4) printf("DROP(2)\n");
    else if(s[a][b].r==5) printf("POUR(1,2)\n");
    else if(s[a][b].r==6) printf("POUR(2,1)\n");
}
void BFS(int a,int b,int c)
{
    pots st;
    st.a=0;
    st.b=0;
    st.step=0;
    st.r=0;
    st.prea=0;
    st.preb=0;
    vis[st.a][st.b]=1;
    queue <pots> que;
    que.push(st);
    int flag=1;
    while(!que.empty())
    {
        pots k=que.front();
        que.pop();
        pots r;
        if(k.a==c||k.b==c) {flag=0;printf("%d\n",k.step);print(k.a,k.b); break;}
        if(k.a<a)
        {
            r.a=a;
            r.b=k.b;
            if(!vis[r.a][r.b]){
            s[r.a][r.b].a=r.a;
            s[r.a][r.b].b=r.b;
            s[r.a][r.b].prea=k.a;
            s[r.a][r.b].preb=k.b;
            s[r.a][r.b].step=k.step+1;
            s[r.a][r.b].r=1;
            que.push(s[r.a][r.b]);
            vis[r.a][r.b]=1;
            }
        }
        if(k.b<b)
        {
            r.a=k.a;
            r.b=b;
            if(!vis[r.a][r.b]){
            s[r.a][r.b].a=r.a;
            s[r.a][r.b].b=r.b;
            s[r.a][r.b].prea=k.a;
            s[r.a][r.b].preb=k.b;
            s[r.a][r.b].step=k.step+1;
            s[r.a][r.b].r=2;
            que.push(s[r.a][r.b]);
            vis[r.a][r.b]=1;
            }
        }
        if(k.a>0)
        {
            r.a=0;
            r.b=k.b;
            if(!vis[r.a][r.b])
            {
                s[r.a][r.b].a=r.a;
                s[r.a][r.b].b=r.b;
                s[r.a][r.b].prea=k.a;
                s[r.a][r.b].preb=k.b;
                s[r.a][r.b].step=k.step+1;
                s[r.a][r.b].r=3;
                que.push(s[r.a][r.b]);
                vis[r.a][r.b]=1;
            }
        }
        if(k.b>0)
        {
            r.a=k.a;
            r.b=0;
            if(!vis[r.a][r.b])
            {
                s[r.a][r.b].a=r.a;
                s[r.a][r.b].b=r.b;
                s[r.a][r.b].prea=k.a;
                s[r.a][r.b].preb=k.b;
                s[r.a][r.b].step=k.step+1;
                s[r.a][r.b].r=4;
                que.push(s[r.a][r.b]);
                vis[r.a][r.b]=1;
            }
        }
        if(k.a>0&&k.b<b)
        {
            if(k.a>b-k.b)
            {
                r.b=b;
                r.a=k.a-b+k.b;
                if(!vis[r.a][r.b])
                {
                    s[r.a][r.b].a=r.a;
                    s[r.a][r.b].b=r.b;
                    s[r.a][r.b].prea=k.a;
                    s[r.a][r.b].preb=k.b;
                    s[r.a][r.b].step=k.step+1;
                    s[r.a][r.b].r=5;
                    que.push(s[r.a][r.b]);
                    vis[r.a][r.b]=1;
                }
            }
            else
            {
                r.a=0;
                r.b=k.a+k.b;
                if(!vis[r.a][r.b])
                {
                    s[r.a][r.b].a=r.a;
                    s[r.a][r.b].b=r.b;
                    s[r.a][r.b].prea=k.a;
                    s[r.a][r.b].preb=k.b;
                    s[r.a][r.b].step=k.step+1;
                    s[r.a][r.b].r=5;
                    que.push(s[r.a][r.b]);
                    vis[r.a][r.b]=1;
                }
            }
        }
        if(k.b>0&&k.a<a)
        {
            if(k.b>a-k.a)
            {
                r.a=a;
                r.b=k.b-a+k.a;
                if(!vis[r.a][r.b])
                {
                    s[r.a][r.b].a=r.a;
                    s[r.a][r.b].b=r.b;
                    s[r.a][r.b].prea=k.a;
                    s[r.a][r.b].preb=k.b;
                    s[r.a][r.b].step=k.step+1;
                    s[r.a][r.b].r=6;
                    que.push(s[r.a][r.b]);
                    vis[r.a][r.b]=1;
                }
            }
            else
            {
                r.b=0;
                r.a=k.a+k.b;
                if(!vis[r.a][r.b])
                {
                    s[r.a][r.b].a=r.a;
                    s[r.a][r.b].b=r.b;
                    s[r.a][r.b].prea=k.a;
                    s[r.a][r.b].preb=k.b;
                    s[r.a][r.b].step=k.step+1;
                    s[r.a][r.b].r=6;
                    que.push(s[r.a][r.b]);
                    vis[r.a][r.b]=1;
                }
            }
        }
    }
    if(flag) printf("impossible\n");
}

int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(s,0,sizeof(s));
        BFS(a,b,c);
    }
    return 0;
}
