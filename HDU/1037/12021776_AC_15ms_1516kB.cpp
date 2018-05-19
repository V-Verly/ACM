#include <stdio.h>
int main ()
{
    int a[3],i,flag;
    while(~scanf("%d%d%d",&a[0],&a[1],&a[2]))
    {
        flag=1;
        for(i=0;i<3;i++)
        if(a[i]<168) {flag=0;break;}
        if(flag) printf("NO CRASH\n");
        else printf("CRASH %d\n",a[i]);
    }
    return 0;
}
