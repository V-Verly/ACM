#include <stdio.h>
int main(void)
{
    int t,m,n,i,j,k,r,sum,s[4];
    char a[51][1002],b[1002];
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(a,0,sizeof(a));
        sum=0;
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
        scanf("%s",a[i]);
       for(j=0;j<n;j++)
        {
            for(i=0;i<m;i++)
            {
                switch(a[i][j])
                {
                    case 'A':s[0]++;break;
                    case 'C':s[1]++;break;
                    case 'G':s[2]++;break;
                    case 'T':s[3]++;break;
                }
            }
            r=3;
            for(k=2;k>=0;k--)
            if(s[k]>=s[r]) r=k;
            switch(r)
            {
                case 0:b[j]='A';break;
                case 1:b[j]='C';break;
                case 2:b[j]='G';break;
                case 3:b[j]='T';break;
            }
            sum+=m-s[r];
            memset(s,0,sizeof(s));
        }
        b[n]='\0';
        puts(b);
        printf("%d\n",sum);
    }
}