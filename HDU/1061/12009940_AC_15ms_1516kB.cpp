#include <stdio.h>
int main()
{
    long long n,t,i,s,r;
    scanf("%lld",&r);
    while(r--){
    scanf("%lld",&n);
    t=n%10;
    s=1;
    switch(t)
    {
        case 0:case 1:case 5:case 6:printf("%lld\n",t);break;
        
        default:
        for(i=0;i<n%4+4;i++)
        s*=t;
        s%=10;
        printf("%lld\n",s);
        break;
    }
    }
    return 0;
}