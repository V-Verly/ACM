#include <iostream>
#include <cstdio>
using namespace std;
int pre[1005];
int Find(int x)
{
    int r=x;
    while(r!=pre[r])
        r=pre[r];
    return r;
}
void join(int x,int y)
{
    int a=Find(x),b=Find(y);
    if(a!=b)
        pre[b]=a;
}
int main()
{
    int t,i,n,m,x,y,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            pre[i]=i;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            join(x,y);
        }
        ans=0;
        for(i=1;i<=n;i++)
            if(Find(i)==i) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
