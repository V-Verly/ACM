#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long ans,a[10005],temp[10005];
void sor(int l,int r)
{
    int mid=(l+r)/2,i,j;
    if(r>l)
    {
        sor(l,mid);
        sor(mid+1,r);
        int tmp=l;
        i=l,j=mid+1;
        while(i<=mid&&j<=r)
        {
            if(a[i]>a[j])
            {
                ans+=mid-i+1;
                temp[tmp++]=a[j++];
            }
            else temp[tmp++]=a[i++];
        }
        while(i<=mid) temp[tmp++]=a[i++];
        while(j<=r) temp[tmp++]=a[j++];
        for(i=l;i<=r;i++)
            a[i]=temp[i];
    }
}

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        ans=0;
        sor(0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
