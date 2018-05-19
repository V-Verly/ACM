#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n,a[1005],b[1005],c[1005]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int t=0,ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(!c[a[i]])
        {
            ans++;
            c[a[i]]=1;
            b[t++]=a[i];
        }
    }
    printf("%d\n",ans);
    for(int i=t-1;i>=0;i--)
        printf("%d ",b[i]);
    return 0;
}
