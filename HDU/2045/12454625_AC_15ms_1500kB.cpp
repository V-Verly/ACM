#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long a[55],b[55],n,i;
    a[1]=1;
    b[1]=0;
    for(i=2;i<=50;i++){
        a[i]=b[i-1];
        b[i]=a[i-1]*2+b[i-1];
    }
    while(scanf("%lld",&n)!=EOF){
        if(n==1) printf("3\n");
        else printf("%lld\n",3*b[n]);
    }

    return 0;
}
