#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int pre[1005];
int Find(int x){
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y){
    int fx=Find(x),fy=Find(y);
    if(fx!=fy)
        pre[fx]=fy;
}
int main()
{
    int n,m,a,b,i,sum;
    int t[1005];
    while(scanf("%d",&n)!=EOF&&n){
        scanf("%d",&m);
        memset(t,0,sizeof(t));
        sum=0;
        for(i=1;i<=n;i++)
            pre[i]=i;
        while(m--){
            scanf("%d%d",&a,&b);
            join(a,b);
        }
        for(i=1;i<=n;i++)
            t[Find(i)]=1;
        for(i=1;i<=n;i++)
            if(t[i]) sum++;
        printf("%d\n",sum-1);
    }
    return 0;
}
