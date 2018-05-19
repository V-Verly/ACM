#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    long long r=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return r;
}


int main()
{
    long long x,y,m,n,l;
    while(~scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l))
    {
        if(m==n)
            printf("Impossible\n");
        else
        {
            if(m<n)
            {
                swap(m,n);
                swap(x,y);
            }
            long long p,q,c=y-x;
            long long d=exgcd(m-n,l,p,q);
            if(c%d) printf("Impossible\n");
            else
            {
                long long r=l/d;
                long long ans=((c/d*p)%r+r)%r;
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
