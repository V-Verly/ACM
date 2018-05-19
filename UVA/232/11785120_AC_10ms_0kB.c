#include <stdio.h>
int main(void)
{
    int r,c,i,j,t=0,m,k;
    char s[11][11];
    int a[11][11],b[11][11];
    while(scanf("%d",&r)!=EOF&&r!=0)
    {
        scanf("%d",&c);
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<r;i++)
        scanf("%s",s[i]);
        m=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(s[i][j]!='*') a[i][j]=1;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(a[i][j]&&(i==0||a[i-1][j]==0||j==0||a[i][j-1]==0))    b[i][j]=++m;
        if(t++) printf("\n");
        printf("puzzle #%d:\n",t);
        printf("Across\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(b[i][j]&&(j==0||a[i][j-1]==0))
                {
                    printf("%3d.",b[i][j]);
                    for(k=j;k<c&&a[i][k];k++)
                    printf("%c",s[i][k]);
                   printf("\n");
               }
            }
        }
        printf("Down\n");
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(b[i][j]&&(i==0||a[i-1][j]==0))
                {
                    printf("%3d.",b[i][j]);
                    for(k=i;k<r&&a[k][j];k++)
                    printf("%c",s[k][j]);
                    printf("\n");
                }
            }
        }
    }
    return 0;
}