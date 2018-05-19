#include<stdio.h>
int main(void)
{
    int n,count,s,t;
    while(~scanf("%d",&n))
    {
        s=0;
        while(n>0)
        {
            t=n%10;
            if(t%2==0) s+=t;
            n/=10;
        }
        if(count++) printf("\n");
        printf("%d\n",s);
    }
}