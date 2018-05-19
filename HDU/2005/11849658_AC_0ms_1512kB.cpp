#include <stdio.h>
int main(void)
{
   int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   int y,m,d,i,t;
   while(~scanf("%d/%d/%d",&y,&m,&d))
   {
       t=0;
       for(i=0;i<m;i++)
        t=t+a[i];
        t=t+d;
        if((y%4==0&&y%100!=0|| y%400==0)&&m>2)
        t++;
        printf("%d\n",t);
    }
    return 0;
}