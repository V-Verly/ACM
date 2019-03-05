#include <bits/stdc++.h>

using namespace std;

const double eps=1e-8;

struct Node
{
    double x,y;
}a,b,c,d;

double p,q,r;

double dis(Node x,Node y)
{
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}

Node pt(Node m,Node n,double x)
{
    Node tmp;
    tmp.x=(n.x-m.x)*x+m.x;
    tmp.y=(n.y-m.y)*x+m.y;
    return tmp;
}

double cal(double x,double y)
{
    Node X=pt(a,b,x),Y=pt(c,d,y);
    return dis(a,X)/p+dis(X,Y)/r+dis(Y,d)/q;
}

double check(double x)
{
    double l=0,r=1;
    while(r-l>eps)
    {
        double mid=l+(r-l)/3,mmid=r-(r-l)/3;
        if(cal(x,mid)>cal(x,mmid)) l=mid;
        else r=mmid;
    }
    return cal(x,l);
}

int main()
{
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y>>p>>q>>r;
    double l=0,r=1;
    while(r-l>eps)
    {
        double mid=l+(r-l)/3,mmid=r-(r-l)/3;
        if(check(mid)>check(mmid)) l=mid;
        else r=mmid;
    }
    printf("%.2f\n",check(l));
	return 0;
}
