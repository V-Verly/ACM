#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=4000+10;
int pre[maxn];

int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}

void Union(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
        pre[fx]=fy;
}

bool judge(int x,int y)
{
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
        return true;
    return false;
}

int main()
{
    int t,m,n,x,y,count=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=2*n;i++)
            pre[i]=i;
        bool flag=true;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            if(judge(x,y)||judge(x+n,y+n))
            {
                Union(x,y+n);
                Union(x+n,y);
            }
            else flag=false;
        }
        printf("Scenario #%d:\n",++count);
        if(flag)
            printf("No suspicious bugs found!\n\n");
        else
            printf("Suspicious bugs found!\n\n");
    }
    return 0;
}
