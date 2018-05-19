#include <stdio.h>
int main(void)
{
    int m,k,d;
    while(scanf("%d%d",&m,&k)!=EOF&&(m!=0||k!=0))
    {
        d=0;
        while(m!=0)
        {
            d++;
            if(d%k==0) m++;
            m--;
        }
        printf("%d\n",d);
    }
}