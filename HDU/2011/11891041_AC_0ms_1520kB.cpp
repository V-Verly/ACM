#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i;
    double s,t;
    scanf("%d",&m);
    while(m--)
    {
        s=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            t=1/(double)i;
            if(i%2==1) s+=t;
            else s-=t;
        }
        printf("%.2f\n",s);
    }
    return 0;
}
