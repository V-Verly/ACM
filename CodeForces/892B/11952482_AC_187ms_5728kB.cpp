#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,sum,i,l,a[1000000];
    scanf("%d",&n);
    sum=0;
    for(i=0;i<n;i++)
     {
        scanf("%d",&l);
        while(sum>0&&a[sum-1]>=i-l) sum--;
        a[sum++]=i;
    }
    printf("%d\n",sum);
    return 0;
}