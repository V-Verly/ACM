#include<stdio.h>

int main(void)
{
    int a,b,c,d,i,j,k,x,y,z,flag=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(i=a; i<=2*a; i++)
    {
        for(j=b; j<=2*b&&j<i; j++)
        {
            for(k=c; k<=2*c&&k<j; k++)
            {
                if(k>=d&&k<=2*d&&j>2*d)
                {
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag) printf("%d\n%d\n%d\n",i,j,k);
    else printf("-1\n");
    return 0;
}
