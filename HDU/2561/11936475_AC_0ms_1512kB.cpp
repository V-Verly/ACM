#include<stdio.h>
int main(void)
{
    int c,n,i,j,k,t,a[10];
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n-1;i++)
        {
            k=i;
            for(j=i+1;j<n;j++)
                if(a[k]>a[j]) k=j;
            if(k!=i)
            {
                t=a[i];
                a[i]=a[k];
                a[k]=t;
            }
        }
        printf("%d\n",a[1]);
    }
    return 0;
}