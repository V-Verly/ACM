#include <stdio.h>
#include <math.h>
int main(void)
{
    double s;
    int n,a,b,c,i;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
       a=0,b=0,c=0;
       for(i=0;i<n;i++)
       {
           scanf("%lf",&s);
           if(s>0) a++;
           else if (s==0) b++;
           else c++;
       }
       printf("%d %d %d\n",c,b,a);
       }
}