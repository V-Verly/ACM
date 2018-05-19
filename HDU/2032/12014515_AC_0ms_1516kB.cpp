#include <stdio.h>
int main(void){
    int n,i,j,a[30][30]={0};
    for(i=0;i<30;i++)
    {
        a[i][0]=1;
        for(j=1;j<=i;j++)
        a[i][j]=a[i-1][j]+a[i-1][j-1];
    }
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(j) printf(" ");
                printf("%d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}