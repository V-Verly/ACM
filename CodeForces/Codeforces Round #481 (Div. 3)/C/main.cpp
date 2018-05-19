#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2e5+10;
long long a[maxn],b[maxn],c[maxn];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i) c[i]=a[i]+c[i-1];
        else c[i]=a[i];
    }
    for(int i=0;i<m;i++)
        scanf("%lld",&b[i]);
    for(int i=0;i<m;i++)
    {
        int s=lower_bound(c,c+n,b[i])-c;
        printf("%d %lld\n",s+1,b[i]-c[s-1]);
    }
    return 0;
}
