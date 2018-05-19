#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=2*1e5+10;
long long a[maxn],k[maxn];

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i) a[i]+=a[i-1];
    }

    for(int i=0;i<q;i++)
        scanf("%lld",&k[i]);
    int left=0;
    long long ans=0;
    for(int i=0;i<q;i++)
    {
        int s=lower_bound(a+left,a+n,k[i]+ans)-a;
        ans+=k[i];

        if(s==n)
        {
            s=0;
            ans=0;
        }
        if(ans)
        {
            if(ans==a[s]) s++;
            if(s==n)
            {
                s=0;
                ans=0;
            }
        }
        left=s;
        //printf("%d\n",s);
        printf("%d\n",n-s);

    }
    return 0;
}
