#include<stdio.h>
int main(void)
{
    int c,i,j,n,a[10][10];
    for(i=1;i<=9;i++)
            for(j=1;j<=9;j++)
                a[i][j]=i*j;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d",&n);
       for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j!=1) printf(" ");
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
    }
}