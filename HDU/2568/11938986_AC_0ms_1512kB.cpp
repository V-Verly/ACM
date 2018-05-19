#include<stdio.h>
int main(void)
{
    long long c,n,s;
    scanf("%lld",&c);
    while(c--)
    {
        scanf("%lld",&n);
        s=0;
        while(n)
        {
            if(n%2) {s++;n--;}
            else n/=2;
        }
        printf("%lld\n",s);
    }
    return 0;
}