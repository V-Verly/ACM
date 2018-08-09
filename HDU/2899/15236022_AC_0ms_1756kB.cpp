#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

double y;
const double e=1e-9;

double power(double x,int n)
{
    double ans=1,base=x;
    while(n)
    {
        if(n&1) ans*=base;
        base*=base;
        n>>=1;
    }
    return ans;
}

double f(double x)
{
    return 6*power(x,7)+8*power(x,6)+7*power(x,3)+5*power(x,2)-y*x;
}

double ff(double x)
{
    return 42*power(x,6)+48*power(x,5)+21*power(x,2)+10*x-y;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&y);
        double l=0,r=100;
        while(r-l>=e)
        {
            double mid=(l+r)/2;
            if(ff(l)*ff(mid)<0) r=mid;
            else l=mid;
        }
        printf("%.4lf\n",f(l));
    }
    return 0;
}
