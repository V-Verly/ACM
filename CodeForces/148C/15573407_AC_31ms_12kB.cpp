#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n,a,b,ans[105];
    scanf("%d%d%d",&n,&a,&b);
    if(n==1) return 0*printf("1\n");
    ans[0]=1;
    int mx=1,mn=1,mxsum=1;
    int i;
    for(i=1;i<n;i++)
    {
        if(!b) break;
        ans[i]=++mxsum;
        mx=mxsum;
        mxsum+=mxsum-1;
        b--;
    }
    if(i==1)
    {
        if(a==n-1) return 0*printf("-1\n");
        ans[i++]=1;
    }
    for(;i<n;i++)
    {
        if(!a) break;
        ans[i]=++mx;
        a--;
    }
    for(;i<n;i++)
        ans[i]=1;
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}
