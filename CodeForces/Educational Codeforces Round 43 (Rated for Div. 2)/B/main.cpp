#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    long long m,n,k,y;
    while(~scanf("%lld%lld%lld",&n,&m,&k)){
    if(k<n)
        printf("%lld 1\n",k+1);
    else
    {
        long long step=k-n+1;
        y=step/(m-1);
        //printf("%lld %lld\n",step,m);
        if(step%(m-1)==0) y--;
        //printf("%lld\n",y);
        step%=2*(m-1);
        if(step==0) step+=2*(m-1);
        //printf("%lld\n",step);
        if(step<m)
        {
            printf("%lld %lld\n",n-y,step+1);
        }
        else
        {
            step-=m;
            //printf("%lld\n",step);
           printf("%lld %lld\n",n-y,m-step);

        }
    }
    }
    return 0;
}
