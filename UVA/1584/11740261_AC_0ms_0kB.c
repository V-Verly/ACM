#include <stdio.h>
int main(void)
{
    char a[105];
    int t,n,i,j,ans;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(a,0,sizeof(a));
        gets(a);
        n=strlen(a);
        ans=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(a[(i+j)%n]>a[(ans+j)%n])  break;
                else if(a[(i+j)%n]==a[(ans+j)%n]);
                else 
                {
                    ans=i;
                    break;
                }
            }
        }
       
        for(i=0;i<n;i++)
        {
            printf("%c",a[(ans+i)%n]);
        }
        printf("\n");
    }
    return 0;
}