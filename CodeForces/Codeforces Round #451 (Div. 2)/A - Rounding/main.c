#include <stdio.h>

int main ()
{
    int n,t;
    scanf("%d",&n);
    if(n%10>5) t=n/10*10+10;
    else t=n/10*10;
    printf("%d\n",t);
    return 0;
}
