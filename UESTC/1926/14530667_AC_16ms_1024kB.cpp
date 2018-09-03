#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;
int pre[maxn];

int Find(int x)
{
    return x==pre[x]?x:pre[x]=Find(pre[x]);
}

void join(int x,int y)
{
    int rx=Find(x),ry=Find(y);
    if(rx!=ry)
        pre[ry]=rx;
}

int main()
{
    int n,m,x,y,t;
    char op[5];
    scanf("%d%d",&n,&m);
    for(int i=0;i<=2*n;i++)
        pre[i]=i;
    while(m--)
    {
        scanf("%s%d%d",op,&x,&y);
        if(op[0]=='A')
        {
            scanf("%d",&t);
            if(t==1)
                join(x,y),join(x+n,y+n);
            else
                join(x,y+n),join(x+n,y);
        }
        else
        {

            if(Find(x)==Find(y)) printf("1\n");
            else if(Find(x)==Find(y+n)||Find(y)==Find(x+n)) printf("2\n");
            else printf("3\n");
        }
    }
    return 0;
}
