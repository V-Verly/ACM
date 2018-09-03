#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn=1e5+10;

int n;
bool vis[maxn];

struct Node
{
    ll x,y;
}node[maxn];

ll cross(Node a,Node b,Node c)
{
    Node n{b.x-a.x,b.y-a.y},m{c.x-a.x,c.y-a.y};
    return m.y*n.x-m.x*n.y;
}

bool check2()
{
    int i1=-1,i2=-1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        if(i1==-1) i1=i;
        else if(i2==-1) i2=i;
    }
    if(i2==-1) return true;
    for(int i=0;i<n;i++)
        if(!vis[i]&&cross(node[i1],node[i2],node[i])) return false;
    return true;
}

bool check(Node a,Node b)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
        if(cross(a,b,node[i])==0) vis[i]=true;
    return check2();
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&node[i].x,&node[i].y);
    if(n<3) return 0*printf("YES\n");
    if(check(node[0],node[1])||check(node[0],node[2])||check(node[1],node[2]))
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
