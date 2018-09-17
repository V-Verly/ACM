#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=500+10;
int pre[maxn],val[maxn],mark[maxn];

int Find(int x)
{
    if(x==pre[x]) return x;
    int tmp=Find(pre[x]);
    val[x]=(val[x]+val[pre[x]])%3;
    return pre[x]=tmp;
}

bool Union(int x,int y,int w)
{
    int fx=Find(x),fy=Find(y);
    if(fx==fy)
        return (val[x]+w)%3==val[y];
    else
    {
        pre[fy]=fx;
        val[fy]=(val[x]-val[y]+w+3)%3;
    }
    return true;
}

int main()
{
    int n,m,x[2010],y[2010],w[2010];
    char op[10],o;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%c%d",&x[i],&o,&y[i]);
            if(o=='=') w[i]=0;
            else if(o=='>') w[i]=1;
            else w[i]=2;
        }
        memset(mark,-1,sizeof(mark));
        int ans=0,judge,round=0;
        for(int i=0;i<n;i++)
        {
            bool flag=true;
            for(int j=0;j<n;j++)
                pre[j]=j,val[j]=0;
            for(int j=1;j<=m;j++)
            {
                if(x[j]!=i&&y[j]!=i)
                {
                    if(!Union(x[j],y[j],w[j]))
                    {
                        flag=false;
                        round=max(round,j);
                        break;
                    }
                }
            }
            if(flag)
            {
                ans++;
                judge=i;
            }
        }
        if(ans==0)
            printf("Impossible\n");
        else if(ans==1)
            printf("Player %d can be determined to be the judge after %d lines\n",judge,round);
        else
            printf("Can not determine\n");
    }
    return 0;
}
