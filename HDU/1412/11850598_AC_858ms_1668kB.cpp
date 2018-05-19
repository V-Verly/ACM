#include <stdio.h>
int main(void)
{
    int n,m,i,j,t,k,s;
    int a[20002],b[20002];
    while(~scanf("%d%d",&n,&m))
    {
        s=m+n;
        for(i=0;i<s;i++) 
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<s-1;i++)
        {
            t=i;
            for(j=i+1;j<s;j++)
            if(a[j]<a[t]) t=j;
            if(t!=i)
            {
                k=a[i];
                a[i]=a[t];
                a[t]=k;
            }
        }
        b[0]=a[0];
        j=1;
       for(i=1;i<s;i++)
           if(a[i]!=a[i-1]) b[j++]=a[i];
       for(i=0;i<j;i++)
       {
           if(i) printf(" ");
           printf("%d",b[i]);
       }
       printf("\n");
    }
    return 0;
}