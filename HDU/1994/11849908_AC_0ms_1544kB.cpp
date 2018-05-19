#include <stdio.h>
int main(void)
{
    int t,y,q;
    double e,f,g,s,s1,s2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%lf%lf%lf",&y,&q,&e,&f,&g);
        s=(1+e/100*q/365)*y;
        s1=s*(1+g/100);
        s2=(1+f/100*(q+365)/365)*y;
        printf("%.1f\n%.1f\n",s1,s2);
    }
    return 0;
}