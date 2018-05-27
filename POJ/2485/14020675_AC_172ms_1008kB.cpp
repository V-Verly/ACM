#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e6+10;
int p[maxn],w[maxn],r[maxn],u[maxn],v[maxn],n,m;

int cmp(const int i,const int j){return w[i]<w[j];}
int find(int x){return p[x]==x?x:p[x]=find(p[x]); }
int Krustal()
{
    int ans=0;
    for(int i=0;i<n;i++) p[i]=i;
    for(int i=0;i<m;i++) r[i]=i;
    sort(r,r+m,cmp);
    for(int i=0;i<m;i++)
    {
        int e=r[i]; int x=find(u[e]);int y=find(v[e]);
        if(x!=y) {ans=max(ans,w[e]);p[x]=y; }
    }
    return ans;
}

int main()
{
    int t,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        m=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&l);
                if(i<j)
                {
                    u[m]=i;
                    v[m]=j;
                    w[m++]=l;
                }
            }
        }
        printf("%d\n",Krustal());
    }
    return 0;
}
