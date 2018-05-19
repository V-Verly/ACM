#include<stdio.h>
int main(void)
{
    int h,m,x,n;
    scanf("%d%d%d",&x,&h,&m);
    n=0;
    while(h%10!=7&&m%10!=7)
    {
        m-=x;
        if(m<0)
        {
            m+=60;
            h-=1;
        }
        if(h<0)
        h+=24;
        n++;
    }
    printf("%d\n",n);
    return 0;
}
