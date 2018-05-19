#include <stdio.h>
int main(void)
{
    int a,b,m,n,t;
 while(~scanf("%d%d",&m,&n))
 {
    a=m,b=n;
    while(b!=0)
    {
        t=a%b;
        a=b,b=t;
    }
    printf("%d\n",m/a*n);
    }
}
