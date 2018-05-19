#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,ans,a[500],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    ans=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>0) ans+=a[i];
        else ans-=a[i];
    }
    printf("%d\n",ans);
    return 0;
}
