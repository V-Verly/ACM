#include <stdio.h>
 int problem(int m);
int main ()
{
    int m,n,i,t,max;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        max=0;
        printf("%d %d ",m,n);
        if(m>n) {t=m;m=n;n=t;}
        for(i=m;i<=n;i++)
        {
            t=problem(i);
            if(max<t) max=t;
        }
        printf("%d\n",max);
    }
    return 0;
}
int problem(int m)
{
    int t=1;
    while(m!=1){
    if(m%2) m=3*m+1;
    else m/=2;
    t++;
    }
    return t;
}
