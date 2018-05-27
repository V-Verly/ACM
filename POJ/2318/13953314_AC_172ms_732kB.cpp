#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct point
{
    int x,y;
};

struct Line
{
    point a,b;
}line[5010];

int crossProduct(point a,point b,point p)
{
    int x1,y1,x2,y2;
    x1=b.x-a.x,y1=b.y-a.y;
    x2=p.x-a.x,y2=p.y-a.y;
    //printf("%d %d %d %d %d %d\n",a.x,x1,y1,x2,y2,x1*y2-y1*x2);
    return x1*y2-y1*x2;
}

int main()
{
    int n,m,x1,x2,y1,y2,sum[5010],count=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        if(count++) printf("\n");
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&line[i].a.x,&line[i].b.x);
            line[i].a.y=y1;
            line[i].b.y=y2;
        }
        line[n].a.x=line[n].b.x=x2;
        line[n].a.y=y1;
        line[n].b.y=y2;
        while(m--)
        {
            point p;
            scanf("%d%d",&p.x,&p.y);
            int l=0,r=n,tmp;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(crossProduct(line[mid].a,line[mid].b,p)<0)
                {

                    tmp=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            sum[tmp]++;
        }
        for(int i=0;i<=n;i++)
            printf("%d: %d\n",i,sum[i]);
    }
    return 0;
}
