#include <stdio.h>
int main(void)
{
    int m,n,i,t,a,b,c;
    while(~scanf("%d%d",&m,&n))
   {
   t=0;
    for(i=m;i<=n;i++)
    {
        a=i/100;
        b=i%100/10;
        c=i%10;
        if(a*a*a+b*b*b+c*c*c==i)
         {
             if(t++) printf(" ");
            printf("%d",i);
        }
    }
    if(t==0) printf("no");
    printf("\n");
    }
    return 0;
}
