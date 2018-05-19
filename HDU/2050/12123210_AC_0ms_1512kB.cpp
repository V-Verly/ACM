#include <stdio.h>
int main(void)
{
    int n,t,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=2*n*n-n+1;
        printf("%d\n",s);
    }
    return 0;
}
