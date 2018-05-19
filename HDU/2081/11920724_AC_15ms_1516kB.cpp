#include <stdio.h>
int main()
{
    int n,i;
    char a[12];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        printf("6");
        for(i=6;i<11;i++)
        printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
