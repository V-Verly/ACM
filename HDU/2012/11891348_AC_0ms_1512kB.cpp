#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sushu(int n);
int main()
{
    int t,n,i,x,y,flag;
    while(scanf("%d%d",&x,&y)!=EOF&&(x!=0||y!=0))
    {
        if(x>y) {t=x;x=y;y=t;}
        flag=1;
        for(i=x;i<=y;i++)
            {
                n=i*i+i+41;
                if(sushu(n)==0) {flag=0;break;}
            }
        if(flag) printf("OK\n");
        else printf("Sorry\n");
    }
    return 0;
}
int sushu(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
        if(n%i==0) return 0;
    return 1;
}
