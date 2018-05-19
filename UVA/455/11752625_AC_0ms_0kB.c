#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[85],b[85],c[85];
    int n,k,t,i,j,ans;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",a);
        n=strlen(a);
        ans=n;
        for(i=n;i>=1;i--)
        {
            memset(b,0,sizeof(b));
            if(n%i==0)
            {
                strncpy(b,a,i);
                b[i]='\0';
                for(j=1;j<n/i;j++)
                {
                    memset(c,0,sizeof(c));
                    for(k=0;k<i;k++)
                        c[k]=a[i*j+k]; 
                        c[i]='\0';
                    if(strcmp(b,c)!=0) break;
                }
                if(j==n/i) ans=i;
            }
        }
        printf("%d\n",ans);
        if(t) printf("\n");
    }
    return 0;
}