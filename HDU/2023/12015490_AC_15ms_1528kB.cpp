#include <stdio.h>
#include<string.h>
int main(void){
    int m,n,i,j,sum,a[50][5];
    double b[50],c[5];
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        sum=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            b[i]+=a[i][j];
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            c[i]+=a[j][i];
        for(i=0;i<n;i++)
        {
            b[i]/=m; 
            if(i) printf(" ");
            printf("%.2f",b[i]);
        }
        printf("\n");
        for(i=0;i<m;i++)
        {
            c[i]/=n;
            if(i) printf(" ");
            printf("%.2f",c[i]);
        }
        printf("\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            if(a[i][j]<c[j]) break;
            if(j==m) sum++;
        }
        printf("%d\n\n",sum);
    }
    return 0;
}