#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+10;
const double inf=1e15;
struct point{
double x,y;
}p[maxn];
bool cmp(const point &a,const point &b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmpy(const int &a,const int &b)
{
    return p[a].y<p[b].y;
}
double cal(int m,int n)
{
    return sqrt((p[m].x-p[n].x)*(p[m].x-p[n].x)+(p[m].y-p[n].y)*(p[m].y-p[n].y));
}
int tmp[maxn];
double bin(int left,int right)
{
    double d=inf;
    int mid=(left+right)/2;
    if(left==right) return d;
    if(left==right-1) return cal(left,right);
    double d1=bin(left,mid-1);
    double d2=bin(mid,right);
    d=min(d1,d2);
    int k=0;
    for(int i=left;i<=right;i++)
        if(fabs(p[i].x-p[mid].x)<=d)
        tmp[k++]=i;
    sort(tmp,tmp+k,cmpy);
    for(int i=0;i<k;i++)
    {
        for(int j=i+1;j<k&&fabs(p[tmp[i]].y-p[tmp[j]].y)<=d;j++)
        {
            double d3=cal(tmp[i],tmp[j]);
            d=min(d,d3);
        }
    }
    return d;
}
int main()
{
    int n,i,j;
    double d1,d2,d;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        double d=bin(0,n-1);
        printf("%.2f\n",d/2);
    }
    return 0;
}
