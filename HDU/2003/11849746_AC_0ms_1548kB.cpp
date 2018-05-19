#include <stdio.h>
int main(void)
{
    double x;
    while(~scanf("%lf",&x))
    {
        if(x>=0)
       printf("%.2f\n",x);
       else
       printf("%.2f\n",-x);
       }
    return 0;
}