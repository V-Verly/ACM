#include <stdio.h>
#include <math.h>
int main()
{
   long long int n,i,j,t,l,m,kase,a[100],b[100];
   while(scanf("%lld",&n)!=EOF&&n!=0)
   {
       for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            b[i]=abs(a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            t=i;
            for(j=i+1;j<n;j++)
            {
                if(b[j]>b[t])
                    t=j;
            }
            if(t!=i)
            {
                m=b[i];
                b[i]=b[t];
                b[t]=m;
                l=a[i];
                a[i]=a[t];
                a[t]=l;
            }
        }
        kase=0;
        for(i=0;i<n;i++)
        {
            if(kase++) printf(" ");
            printf("%lld",a[i]);
        }
            printf("\n");
   }
    return 0;
}
