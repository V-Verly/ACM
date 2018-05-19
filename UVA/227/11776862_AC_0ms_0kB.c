#include <stdio.h>
int main(void)
{
    char s[6][6],a,c;
    int t,l,i,j,m,n,flag;
    t=0;
    while(gets(s[0])!=NULL)
    {
        flag=1;
        if(strcmp(s[0],"Z")==0) break;
        for(i=1;i<=4;i++)
        gets(s[i]);
        for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                if(s[i][j]==' '||s[i][j]=='\0'){m=i,n=j;break;}
            }
        if(s[m][n]=='\0') s[m][n]=' ';
        while((a=getchar())!='0')
        {
            switch(a)
            {
                case 'A':{
                    if(m-1>=0)
                    {
                        c=s[m][n];
                        s[m][n]=s[m-1][n];
                        s[m-1][n]=c;
                        m--;
                    }
                    else flag=0;
                    break;
                }
                case 'B': {
                    if(m+1<5)
                    {
                    c=s[m][n];
                    s[m][n]=s[m+1][n];
                    s[m+1][n]=c;
                    m++;
                    }
                    else flag=0;
                    break;
                }
                case 'R': {
                    if(n+1<5)
                    {
                    c=s[m][n];
                    s[m][n]=s[m][n+1];
                    s[m][n+1]=c;
                    n++;
                    }
                    else flag=0;
                    break;
                }
                case 'L': {
                    if(n-1>=0)
                    {
                    c=s[m][n];
                    s[m][n]=s[m][n-1];
                    s[m][n-1]=c;
                    n--;
                    }
                    else flag=0;
                    break;
                }
            }
        }
        getchar();
        if(t++) printf("\n");
        printf("Puzzle #%d:\n",t);
        if(flag)
        {
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(j) printf(" ");
                printf("%c",s[i][j]);
            }
            printf("\n");
        }
        }
        else printf("This puzzle has no final configuration.\n");
        memset(s,0,sizeof(s));
    }
    return 0;
}
