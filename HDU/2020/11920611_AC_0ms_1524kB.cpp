#include <stdio.h>
int main(void)
{
    int n,i,j,k,t,a[100],b[100];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>=0) b[i]=a[i];
            else b[i]=-a[i];
        }
        for(i=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
            if(b[k]<b[j]) k=j;
            if(k!=i)
            {
                t=a[i];
                a[i]=a[k];
                a[k]=t;
                t=b[i];
                b[i]=b[k];
                b[k]=t;
            }
        }
        for(i=0;i<n;i++)
        {
            if(i) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}