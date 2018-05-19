#include <stdio.h>
#include <math.h>
int main(void)
{
    double a,s;
    int i,b;
    while(~scanf("%lf%d",&a,&b))
    {
        s=0;
        for(i=0;i<b;i++)
        {
            s+=a;
            a=sqrt(a);
        }
        printf("%.2f\n",s);
    }
}