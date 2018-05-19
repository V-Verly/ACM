#include <stdio.h>
#include <stdlib.h>
char a[2005][2005];
int main()
{
    int m,n,k,i,j,r,sum=0,flag;

    scanf("%d%d%d",&m,&n,&k);
    for(i=0; i<m; i++)
        scanf("%s",a[i]);
    for(i=0; i<m; i++)
    {
        r=0;
        for(j=0; j<n; j++)
        {
            if(a[i][j]=='.')
                r++;
            else
            {
                if(r>=k)
                    sum+=r-k+1;
                r=0;
            }
        }
        if(r>=k)
            sum+=r-k+1;
    }
    for(j=0; j<n; j++)
    {
        r=0;
        for(i=0; i<m; i++)
        {
            if(a[i][j]=='.')
                r++;
            else
            {
                if(r>=k)
                    sum+=r-k+1;
                r=0;
            }
        }
        if(r>=k)
            sum+=r-k+1;
    }
    if(k==1)
        sum/=2;
    printf("%d\n",sum);
    return 0;
}
