#include <stdio.h>

int main ()
{
    int n,a,b,x,y,flag=0;
    scanf("%d%d%d",&n,&a,&b);
    for(x=0;x*a<=n;x++)
    {
        if((n-a*x)%b==0)
        {
            flag=1;
            y=(n-a*x)/b;
            break;
        }
    }
    if(flag) printf("YES\n%d %d\n",x,y);
    else printf("NO\n");
    return 0;
}
