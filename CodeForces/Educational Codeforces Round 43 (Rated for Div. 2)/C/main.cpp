#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=3*1e5+10;
struct point
{
    int l,r,num;
}p[maxn];

bool cmp(const point &a,const point &b)
{
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}

int main()
{
    int n,l,r,left,right,na,nb;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&l,&r);
        p[i].l=l;
        p[i].r=r;
        p[i].num=i+1;
    }
    sort(p,p+n,cmp);
    left=p[0].l;
    right=p[0].r;
    na=p[0].num;
    bool flag=false;
    for(int i=1;i<n;i++)
    {
        if(p[i].l==left)
        {
            nb=p[i].num;
            swap(na,nb);
            flag=true;
            break;
        }
        else if(p[i].r<=right)
        {
            flag=true;

            nb=p[i].num;
            break;
        }
        else
        {
            left=p[i].l;
            right=p[i].r;
            na=p[i].num;
        }
    }
    if(flag)
        printf("%d %d\n",nb,na);
    else
        printf("-1 -1\n");
    return 0;
}
