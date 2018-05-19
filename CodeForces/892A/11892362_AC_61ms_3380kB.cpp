#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long n,i,s,sum,t,r,a[100001],b[100001];
    scanf("%lld",&n);
    s=0,sum=0;
    for(i=0;i<n;i++)
     {
         scanf("%lld",&a[i]);
         s+=a[i];

     }
    // printf("%lld\n",s);
    for(i=0;i<n;i++)
        scanf("%lld",&b[i]);
    t=b[0];
    for(i=0;i<n;i++)
        if(b[i]>=t) {t=b[i];r=i;}
    sum+=t;
    b[r]=0;
    t=b[0];
    for(i=0;i<n;i++)
        if(b[i]>t) t=b[i];
    sum+=t;
    //printf("%lld %lld\n",sum,s);
    if(n==2) printf("YES\n");
    else
    {
        if(sum>=s) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
