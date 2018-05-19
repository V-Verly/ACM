#include <stdio.h>
#include <math.h>
#define PI 3.1415927
int main(void){
double r,v;
while(~scanf("%lf",&r))
{
    v=4*PI*r*r*r/3;
    printf("%.3f\n",v);
}
return 0;
}