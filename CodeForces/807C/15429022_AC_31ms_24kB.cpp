#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    ll x,y,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&x,&y,&p,&q);
        if(x*q==y*p) printf("0\n");
        else if(p==0||p==q) printf("-1\n");
        else
        {
            ll ans=0;
            if(x*q<p*y)
            {
                ll t=(y-x)*q/(q-p);
                if((y-x)*q%(q-p)) t++;
                x=t-y+x;
                ans=t-y;
                y=t;
            }
            ll a=x/p;
            if(x%p) a++;
            q*=a;
            ans+=q-y;
            printf("%lld\n",ans);
        }

    }
    return 0;
}
