#include<stdio.h>
int main(void)
{
    long long a,b,c,x,y,m,n,s;
    scanf("%lld%lld",&x,&y);
    scanf("%lld%lld%lld",&a,&b,&c);
    m=2*a+b;
    n=b+3*c;
    s=0;
    if(m>x) s+=m-x;
    if(n>y) s+=n-y;
    printf("%lld\n",s);
    return 0;
}
