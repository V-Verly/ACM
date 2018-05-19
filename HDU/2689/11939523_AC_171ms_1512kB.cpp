#include<stdio.h>
int main(void)
{
    int s,t,m,n,i,a[1000];
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        s=0;
        do{
            t=0;
            for(i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1])
                {
                    m=a[i];
                    a[i]=a[i+1];
                    a[i+1]=m;
                    t++;
                }
            }
            s+=t;
        }while(t);
        printf("%d\n",s);
    }
    return 0;
}