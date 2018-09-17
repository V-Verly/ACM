#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=5e4+10;
int pre[maxn],val[maxn];

int Find(int x)
{
    if(x==pre[x]) return x;
    int tmp=Find(pre[x]);
    val[x]=(val[x]+val[pre[x]])%3;
    return pre[x]=tmp;
}

bool Union(int x,int y,int op)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy)
    {
        if((val[x]+op)%3!=val[y]) return false;
    }
    else
    {
        pre[fy]=fx;
        val[fy]=(val[x]-val[y]+op+3)%3;
    }
    return true;
}

int main()
{
    int n,k,op,x,y,ans=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        val[i]=0,pre[i]=i;
    while(k--)
    {
        scanf("%d%d%d",&op,&x,&y);
        if(x>n||y>n||x==y&&op==2)
        {
            ans++;
            continue;
        }
        else if(!Union(x,y,op-1)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
