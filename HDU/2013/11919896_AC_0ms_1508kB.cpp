#include <stdio.h>
int main(void)
{
    int n,i,s;
    while(~scanf("%d",&n))
    {
        s=1;
        for(i=1;i<n;i++)
        s=(s+1)*2;
        printf("%d\n",s);
    }
}