#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=5000+10;
int a[maxn],b[maxn],w[maxn],p[30],r[maxn];
int cmp(const int i,const int j)
{
    return w[i]<w[j];
}
int Find(int x)
{
    int r=x;
    while(r!=p[r])
        r=p[r];
    return r;
}
int main()
{
    int t,u,i,x,ans;
    char m[5],n[5];
    while(scanf("%d",&t)!=EOF&&t)
    {
        for(i=1;i<=27;i++)
        {
            p[i]=i;
        }
        for(i=0;i<maxn;i++)
            r[i]=i;
        i=0;
        for(int j=1;j<t;j++)
        {
            scanf("%s%d",m,&u);
            while(u--)
            {
                scanf("%s%d",n,&x);
                a[i]=m[0]-'A'+1;
                b[i]=n[0]-'A'+1;
                w[i]=x;
                i++;
            }
        }
        int q=i;
        sort(r,r+q,cmp);
        ans=0;
        for(i=0;i<q;i++)
        {
            int e=r[i];
            int x=Find(a[e]),y=Find(b[e]);
            if(x!=y)
            {
                p[x]=y;
                ans+=w[e];
            }


        }
        printf("%d\n",ans);
    }
    return 0;
}
