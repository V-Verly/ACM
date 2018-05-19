#include <stdio.h>
#include<string.h>
int main(void)
{
    char ch[100];
    int i,j,t,n,a,flag;
    scanf("%d%*c",&n);
    for(j=0;j<n;j++)
    {
    memset(ch,0,sizeof(ch));
    gets (ch);
    t=strlen(ch);
    a=t-1,flag=1;
    for(i=0;i<=t/2;i++)
   {
       if(ch[i]!=ch[a])
       flag=0;
       a--;
       }
       if(flag)
       printf("yes\n");
       else
       printf("no\n");
    }
    return 0;
}