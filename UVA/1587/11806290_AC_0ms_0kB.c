#include  <stdio.h>
int main(void)
{
    int s[6][2],t,i,j,k,r,flag;
    while(scanf("%d%d",&s[0][0],&s[0][1])!=EOF)
    {
        if(s[0][0]>s[0][1]) 
        t=s[0][0],s[0][0]=s[0][1],s[0][1]=t;
        flag=1;
        for(i=1;i<6;i++)
        {
            scanf("%d%d",&s[i][0],&s[i][1]);
         if(s[i][0]>s[i][1])   t=s[i][0],s[i][0]=s[i][1],s[i][1]=t;
        }
        for(i=0;i<5;i++)
        {
            r=i;
            for(j=i+1;j<6;j++)
                if(s[j][0]<s[r][0]) r=j;
            if(r!=i)
            {
                k=s[r][0];
                s[r][0]=s[i][0];
                s[i][0]=k;
                k=s[r][1];
                s[r][1]=s[i][1];
                s[i][1]=k;
            }
        }
        for(i=0;i<3;i++)
        {
            r=i;
            for(j=i+1;j<4;j++)
            if(s[j][1]<s[r][1]) r=j;
            if(r!=i)
            {
                k=s[r][1];
                s[r][1]=s[i][1];
                s[i][1]=k;
            }
        }
        if(s[0][0]!=s[1][0]||s[0][0]!=s[2][0]||s[0][0]!=s[3][0]) flag=0;
        if(s[0][1]!=s[1][1]||s[0][1]!=s[4][0]||s[0][1]!=s[5][0]) flag=0;
        if(s[2][1]!=s[3][1]||s[2][1]!=s[4][1]||s[2][1]!=s[5][1]) flag=0;
        if(flag) printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
        memset(s,0,sizeof(s));
    }
    return 0;
}