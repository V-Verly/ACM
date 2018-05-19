#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int h[20][20],v[20][20],s[10],n,m,i,j,k,t,flag,sum[10],count=0;
    char c[5];
    while(~scanf("%d%d",&n,&m))
    {
        memset(h,0,sizeof(h));
        memset(v,0,sizeof(v));
        memset(sum,0,sizeof(sum));
        while(m--)
        {
            scanf("%s%d%d",c,&i,&j);
            if(c[0]=='H') h[i][j]=1;
            else if(c[0]=='V') v[j][i]=1;
        }
        for(k=1;k<=n;k++){
        for(i=1;i<=n-k;i++)
        {
            for(j=1;j<=n-k;j++)
            {
                    flag=1;
                    for(t=0;t<k;t++)
                    {
                        if(h[i][j+t]==0) flag=0;
                        if(v[i+t][j]==0) flag=0;
                        if(h[k+i][j+t]==0) flag=0;
                        if(v[i+t][j+k]==0) flag=0;
                        if(flag==0) break;
                    }
                    if(flag) sum[k]++;
                }
            }
        }
        if(count) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",++count);
        flag=1;
        for(i=1;i<n;i++)
            if(sum[i]) {printf("%d square (s) of size %d\n",sum[i],i);flag=0;}
        if(flag) printf("No completed squares can be found.\n");
    }
    return 0;
}