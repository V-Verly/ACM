#include <stdio.h>
int main(void)
{
    int n,i,j,count;
    char a;
    count=0;
    while(scanf("%c",&a)!=EOF&&a!='@')
    {
        scanf("%d",&n);
        getchar();
        if(count++) printf("\n");
        for(i=1;i<n;i++)
        printf(" ");
        printf("%c",a);
        printf("\n");
        for(i=1;i<n-1;i++)
        {
            for(j=1;j<n-i;j++)
            printf(" ");
            printf("%c",a);
            for(j=0;j<2*i-1;j++)
            printf(" ");
            printf("%c",a);
            printf("\n");
        }
        if(n!=1){
        for(i=0;i<2*n-1;i++)
        printf("%c",a);
        printf("\n");
        }
    }
    return 0;
}