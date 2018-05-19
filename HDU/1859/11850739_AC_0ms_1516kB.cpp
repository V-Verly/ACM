#include <stdio.h>
int main(void)
{
    int a,b,x1,y1,x2,y2;
    while(scanf("%d%d",&a,&b)!=EOF&&(a!=0||b!=0))
    {
        x1=a,x2=a;
        y1=b,y2=b;
        while(scanf("%d%d",&a,&b)!=EOF&&(a!=0||b!=0))
        {
            if(a>x1) x1=a;
            if(a<x2) x2=a;
            if(b>y1) y1=b;
            if(b<y2) y2=b;
        }
        printf("%d %d %d %d\n",x2,y2,x1,y1);
    }
    return 0;
}