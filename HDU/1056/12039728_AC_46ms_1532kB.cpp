#include <stdio.h>
int main(void)
{
    int i=0;
    double t,s=0,n,a[276];
    for(t=2;s<=5.20;t++)
    {
        s+=1/t;
        a[i]=s;
        i++;
    }
    while(scanf("%lf",&n)!=EOF&&n)
    {
        for(i=0;i<276;i++)
            if(a[i]>=n) break;
        printf("%d card(s)\n",i+1);
    }
    return 0;
}
