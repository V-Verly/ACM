#include <stdio.h>
int main(void)
{
    int m,n,i,s,t,a[105];
    for(i=1;i<=100;i++)
    a[i]=i*2;
    while(~scanf("%d%d",&n,&m))
   {
   s=0,t=0;
    for(i=1;i<=n;i++)
    {
        s+=a[i];
        if(i%m==0){
            if(t++) printf(" ");
            printf("%d",s/m);
            s=0;
        }
    }
    if(s!=0) printf(" %d",s/((i-1)%m));
    printf("\n");
    }
    return 0;
}
