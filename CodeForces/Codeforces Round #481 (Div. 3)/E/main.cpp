#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=0x3f3f3f3f;

int main()
{
    int n,w,a[1005];
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int mx=-inf,mn=inf,sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>mx) mx=sum;
        if(sum<mn) mn=sum;
    }
    ans=w+1;
    if(mx>=0) ans-=mx;
    if(mn<0) ans+=mn;
    if(mx>w||mn<-w||ans<0) printf("0\n");
    else printf("%d\n",ans);
    return 0;
}
