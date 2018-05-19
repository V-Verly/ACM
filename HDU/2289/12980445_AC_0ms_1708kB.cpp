#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const double pi=acos(-1.0);
double r1,r2,H,V;
double cal(double h)
{
    double r=h/H*(r2-r1)+r1;
    return (r1*r+r1*r1+r*r)*h*pi/3;
}
int main()
{
    int t;
    double V;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&r1,&r2,&H,&V);
        double left=0,right=100,mid;
        while(right-left>1e-12)
        {
            mid=(left+right)/2;
            if(cal(mid)>=V) right=mid;
            else left=mid;
        }
        printf("%.6lf\n",right);
    }

    return 0;
}
