#include <stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
    int m,n,a[100][100],i,j,max,g,h; 
        while(~scanf("%d%d",&m,&n))
    {
        memset(a,0,sizeof(int));
        max=0;
    for(i=0;i<m;i++)
    {
    for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(abs(a[i][j])>max)
            {
                g=i,h=j;
                 max=abs(a[g][h]);
                 }
        }
    }
    printf("%d %d %d\n",g+1,h+1,a[g][h]);
        }
    return 0;
}