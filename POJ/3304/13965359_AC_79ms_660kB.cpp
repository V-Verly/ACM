#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps=1e-8;

struct point
{
    double x,y;
    point(){}
    point(double xx,double yy){x=xx;y=yy;}
    point operator -(const point &b) const
    {
        return point(x-b.x,y-b.y);
    }
    double operator ^(const point &b) const
    {
        return x*b.y-y*b.x;
    }
    double operator *(const point &b) const
    {
        return x*b.x+y*b.y;
    }
};

double dis(point &a,point &b)
{
    return sqrt((a-b)*(a-b));
}

double crossProduct(point a,point b,point t)
{
    return (b-a)^(t-a);
}

struct line
{
    point a,b;
    line(){}
    line(point aa,point bb){a=aa,b=bb;}
}l[105];

bool check(line a,line b)
{
    return crossProduct(a.a,a.b,b.a)*crossProduct(a.a,a.b,b.b)>eps;
}

bool judge(line a,int n)
{
    if(dis(a.a,a.b)<eps) return false;
    for(int i=0;i<n;i++)
    {
        if(check(a,l[i])) return false;
    }
    return true;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(judge(line(l[i].a,l[j].a),n)||judge(line(l[i].a,l[j].b),n)||judge(line(l[i].b,l[j].a),n)||judge(line(l[i].b,l[j].b),n))
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}
