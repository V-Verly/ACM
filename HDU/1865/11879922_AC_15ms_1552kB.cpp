#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[201][200],s[205];
    int n,i,j,c,t,r;
    a[0][0]='1',a[0][1]=0;
    a[1][0]='1',a[1][1]=0;
    for(i=2;i<=200;i++)
    {
        j=0,c=0;
        while(j<strlen(a[i-1])||c!=0)
        {
            //c=c+a[i-1][j]-'0'+a[i-2][j]-'0';
            if(j<strlen(a[i-1]))
                c=c+a[i-1][j]-'0';
            if(j<strlen(a[i-2]))
                c=c+a[i-2][j]-'0';
            a[i][j]=c%10+'0';
            c/=10;
            j++;
        }
        a[i][j]=0;
    }
scanf("%d",&r);
getchar();
  while(r--)
    {
        gets(s);
        n=strlen(s);
        t=strlen(a[n]);
        for(j=t-1;j>=0;j--)
        printf("%c",a[n][j]);
        printf("\n");
    }

}