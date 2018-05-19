#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
int l[maxn],e[maxn];

int main()
{
    int q,x1,y1,x2,y2,a,b,v,m,n;
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&v);
    for(int i=0;i<a;i++)
        scanf("%d",&l[i]);
    for(int i=0;i<b;i++)
        scanf("%d",&e[i]);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
        if(y1==y2)
        {
            printf("%d\n",abs(x1-x2));
            continue;
        }
        bool flag=false;
        int r=inf;
        int tl,te;
        if(x1>x2) swap(x1,x2);
        int left=0,right=a,mid;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(l[mid]<x1)
                left=mid+1;
            else if(l[mid]>x2)
                right=mid-1;
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
            tl=x2-x1+abs(y2-y1);
        else
        {
            for(int i=0;i<a;i++)
            {
                if(l[i]<x1) r=min(r,x1-l[i]);
                else if(l[i]>x2) r=min(r,l[i]-x2);
            }
            tl=2*r+x2-x1+abs(y2-y1);
        }
        flag=false;
        left=0,right=b;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(e[mid]<x1)
                left=mid+1;
            else if(e[mid]>x2)
                right=mid-1;
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
            te=x2-x1+abs(y2-y1)/v;
        else
        {
            r=inf;
            for(int i=0;i<b;i++)
            {
                if(e[i]<x1) r=min(r,x1-e[i]);
                else if(e[i]>x2) r=min(r,e[i]-x2);
            }
            te=2*r+x2-x1+abs(y2-y1)/v;
        }
        if(abs(y2-y1)%v) te++;
        //printf("%d %d\n",tl,te);
        printf("%d\n",tl<te?tl:te);
    }
    return 0;
}
