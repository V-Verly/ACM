#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct point
{
    double x,y;
};

struct Line
{
    point a,b;
}line1,line2;

double crossProduct(Line a,Line b)
{
    double x1=a.a.x-a.b.x,y1=a.a.y-a.b.y;
    double x2=b.a.x-b.b.x,y2=b.a.y-b.b.y;
    return x1*y2-y1*x2;
}

double solve(Line a,Line b)
{
    double m=(a.a.x-b.a.x)*(b.a.y-b.b.y)-(a.a.y-b.a.y)*(b.a.x-b.b.x);
    double n=(a.a.x-a.b.x)*(b.a.y-b.b.y)-(a.a.y-a.b.y)*(b.a.x-b.b.x);
    return m/n;
}

int main()
{
    int t;
    double x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d",&t);
    printf("INTERSECTING LINES OUTPUT\n");
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&line1.a.x,&line1.a.y,&line1.b.x,&line1.b.y,&line2.a.x,&line2.a.y,&line2.b.x,&line2.b.y);
        if(crossProduct(line1,line2))
        {
            double t=solve(line1,line2);
            printf("POINT %.2f %.2f\n",line1.a.x+t*(line1.b.x-line1.a.x),line1.a.y+t*(line1.b.y-line1.a.y));
        }
        else
        {
           /* if(line1.a.y-line1.b.y==0)
            {
                printf("%s\n",line1.a.y==line2.a.y?"LINE":"NONE");
            }*/
            if(line1.a.x-line1.b.x==0)
            {
                printf("%s\n",line1.a.x==line2.a.x?"LINE":"NONE");
            }
            else
            {
                double k1=(line1.a.y-line1.b.y)/(line1.a.x-line1.b.x);
                double k2=(line2.a.y-line2.b.y)/(line2.a.x-line2.b.x);
                double b1=line1.a.y-k1*line1.a.x;
                double b2=line2.a.y-k2*line2.a.x;
                //printf("%f %f\n",k1,k2);
                if(b2==b1) printf("LINE\n");
                else printf("NONE\n");
            }
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
