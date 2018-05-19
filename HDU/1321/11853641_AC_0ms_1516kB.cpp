#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[75];
    int t,n,i;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(a);
        n=strlen(a);
        for(i=n-1;i>=0;i--)
        printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}