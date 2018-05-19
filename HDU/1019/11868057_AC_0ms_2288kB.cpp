#include <stdio.h>
#include <string.h>
long long lcm(long long a,long long b)
{
    if(b==0) return a;
    return lcm(b,a%b);
}
int main(void){
    int t,i,n;
    long long s,a[100000];
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
    s=1;
    for(i=0;i<n;i++)
        s=a[i]/lcm(s,a[i])*s;
    printf("%lld\n",s);
    }
    return 0;
}
