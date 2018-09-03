#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e5+10;
int pre[maxn],val[maxn];

int Find(int x)
{
    if(x==pre[x]) return x;
    int tmp=Find(pre[x]);
    val[x]=(val[x]+val[pre[x]])%3;
    return pre[x]=tmp;
}

bool join(int op,int x,int y)
{
    if(x==y&&op) return false;
    int rx=Find(x),ry=Find(y);
    if(rx==ry)
    {
        if((val[x]+op)%3!=val[y]) return false;
    }
    else
    {
        pre[ry]=rx;
        val[ry]=(val[x]-val[y]+op+3)%3;
    }
    return true;
}

int main()
{
    int n,m,op,x,y,ans=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
        pre[i]=i,val[i]=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(ans!=-1) continue;
        op--;
        if(!join(op,x,y)) //printf("%d\n",i);
            ans=i%3+1;
    }
    printf("%d\n",ans);
    return 0;
}
