#include <stdio.h>
int main()
{
    long long n,a,b;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&a,&b);
        if(a%b==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
