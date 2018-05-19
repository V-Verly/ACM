#include <stdio.h>
int main(void)
{
    char a[100];
    double p,n,s;
    s=0;
    while(scanf("%s%lf%lf",a,&n,&p)!=EOF)
        s+=p*n;
    printf("%.1f\n",s);
    return 0;
}