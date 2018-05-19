#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 10;
int pre[maxn],val[maxn];

int Find(int x)
{
    if(pre[x]==x) return x;
    int tmp=Find(pre[x]);
    val[x]=(val[x]+val[pre[x]])%3;
    return pre[x]=tmp;
}

int main()
{
    int n,k,t,x,y;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        pre[i]=i;
        val[i]=0;
    }
    int ans=0;
    while(k--)
    {
        scanf("%d%d%d",&t,&x,&y);
        if(x>n||y>n||t==2&&x==y) ans++;
        else
        {
            int rootX=Find(x),rootY=Find(y);
            if(rootX==rootY)
            {
                if(t==1&&val[x]!=val[y]) ans++;
                else if(t==2&&(val[x]+1)%3!=val[y]) ans++;
            }
            else
            {
                if(t==1)
                {
                    pre[rootY]=rootX;
                    val[rootY]=(val[x]-val[y]+3)%3;
                }
                else
                {
                    pre[rootY]=rootX;
                    val[rootY]=(val[x]-val[y]+1+3)%3;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
